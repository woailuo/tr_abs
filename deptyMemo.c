********
https://github.com/luna/luna/blob/master/deps/linenoise/linenoise.c

linenoisePrompt:   NG
original:   (ua.(((0 + (ua.((ua.free;a);(free + 0) + 0);a));(ua.free;a);(free + 0) + 0) + 0);(free + (0 + (free + 0)) + (0 + (0 + (0 + (0 + ((0 + ((free + 0) + 0)) + 0))))) + 0);a)
rewritten:  (ua.((((0 + (ua.(((ua.free;a);free) + 0);a));(ua.free;a);free) + 0) + 0);(free + (0 + (free + 0)) + (0 + (0 + (0 + (0 + ((0 + ((free + 0) + 0)) + 0))))) + 0);a)

static int linenoisePrompt(int fd, char *buf, size_t buflen, const char *prompt) {
    size_t plen = strlen(prompt);
    size_t pos = 0;
    size_t len = 0;
    size_t cols = getColumns();
    int history_index = 0;

    buf[0] = '\0';
    buflen--; /* Make sure there is always space for the nulterm */

    /* The latest history entry is always our current buffer, that
     * initially is just an empty string. */
    linenoiseHistoryAdd("""");

    if (write(fd,prompt,plen) == -1) return -1;
    while(1) {
        char c;
        int nread;
        char seq[3], seq2[2];

        nread = read(fd,&c,1);
        if (nread <= 0) return len;

        /* Only autocomplete when the callback is set. It returns < 0 when
         * there was an error reading from fd. Otherwise it will return the
         * character that should be handled next. */
        if (c == 9 && completionCallback != NULL) {
            c = completeLine(fd,prompt,buf,buflen,&len,&pos,cols);
            /* Return on errors */
            if (c < 0) return len;
            /* Read next character when 0 */
            if (c == 0) continue;
        }

        switch(c) {
        case 13:    /* enter */
            history_len--;
            free(history[history_len]);
            return (int)len;
        case 3:     /* ctrl-c */
            errno = EAGAIN;
            return -1;
        case 127:   /* backspace */
        case 8:     /* ctrl-h */
            if (pos > 0 && len > 0) {
                memmove(buf+pos-1,buf+pos,len-pos);
                pos--;
                len--;
                buf[len] = '\0';
                refreshLine(fd,prompt,buf,len,pos,cols);
            }
            break;
        case 4:     /* ctrl-d, remove char at right of cursor */
            if (len > 1 && pos < (len-1)) {
                memmove(buf+pos,buf+pos+1,len-pos);
                len--;
                buf[len] = '\0';
                refreshLine(fd,prompt,buf,len,pos,cols);
            } else if (len == 0) {
                history_len--;
                free(history[history_len]);
                return -1;
            }
            break;
        case 20:    /* ctrl-t */
            if (pos > 0 && pos < len) {
                int aux = buf[pos-1];
                buf[pos-1] = buf[pos];
                buf[pos] = aux;
                if (pos != len-1) pos++;
                refreshLine(fd,prompt,buf,len,pos,cols);
            }
            break;
        case 2:     /* ctrl-b */
            goto left_arrow;
        case 6:     /* ctrl-f */
            goto right_arrow;
        case 16:    /* ctrl-p */
            seq[1] = 65;
            goto up_down_arrow;
        case 14:    /* ctrl-n */
            seq[1] = 66;
            goto up_down_arrow;
            break;
        case 27:    /* escape sequence */
            if (read(fd,seq,3) == -1) break;
            if (seq[0] == 91 && seq[1] == 53 && seq[2] == 68) {
              if (pos > 0) {
                pos = hardLeft(buf, pos);
                refreshLine(fd,prompt,buf,len,pos,cols);
              }
            } else if (seq[0] == 91 && seq[1] == 53 && seq[2] == 67) {
              if (pos != len) {
                pos = hardRight(buf, pos);
                refreshLine(fd,prompt,buf,len,pos,cols);
              }
            } else if (seq[0] == 91 && seq[1] == 68) {
left_arrow:
                /* left arrow */
                if (pos > 0) {
                    pos--;
                    refreshLine(fd,prompt,buf,len,pos,cols);
                }
            } else if (seq[0] == 91 && seq[1] == 67) {
right_arrow:
                /* right arrow */
                if (pos != len) {
                    pos++;
                    refreshLine(fd,prompt,buf,len,pos,cols);
                }
            } else if (seq[0] == 91 && (seq[1] == 65 || seq[1] == 66)) {
up_down_arrow:
                /* up and down arrow: history */
                if (history_len > 1) {
                    /* Update the current history entry before to
                     * overwrite it with tne next one. */
                    free(history[history_len-1-history_index]);
                    history[history_len-1-history_index] = strdup(buf);
                    /* Show the new entry */
                    history_index += (seq[1] == 65) ? 1 : -1;
                    if (history_index < 0) {
                        history_index = 0;
                        break;
                    } else if (history_index >= history_len) {
                        history_index = history_len-1;
                        break;
                    }
                    strncpy(buf,history[history_len-1-history_index],buflen);
                    buf[buflen] = '\0';
                    len = pos = strlen(buf);
                    refreshLine(fd,prompt,buf,len,pos,cols);
                }
            } else if (seq[0] == 91 && seq[1] > 48 && seq[1] < 55) {
                /* extended escape */
                if (read(fd,seq2,2) == -1) break;
                if (seq[1] == 51 && seq2[0] == 126) {
                    /* delete */
                    if (len > 0 && pos < len) {
                        memmove(buf+pos,buf+pos+1,len-pos-1);
                        len--;
                        buf[len] = '\0';
                        refreshLine(fd,prompt,buf,len,pos,cols);
                    }
                }
            }
            break;
        default:
            if (len < buflen) {
                if (len == pos) {
                    buf[pos] = c;
                    pos++;
                    len++;
                    buf[len] = '\0';
                    if (plen+len < cols) {
                        /* Avoid a full update of the line in the
                         * trivial case. */
                        if (write(fd,&c,1) == -1) return -1;
                    } else {
                        refreshLine(fd,prompt,buf,len,pos,cols);
                    }
                } else {
                    memmove(buf+pos+1,buf+pos,len-pos);
                    buf[pos] = c;
                    len++;
                    pos++;
                    buf[len] = '\0';
                    refreshLine(fd,prompt,buf,len,pos,cols);
                }
            }
            break;
        case 21: /* Ctrl+u, delete the whole line. */
            buf[0] = '\0';
            pos = len = 0;
            refreshLine(fd,prompt,buf,len,pos,cols);
            break;
        case 11: /* Ctrl+k, delete from current to end of line. */
            buf[pos] = '\0';
            len = pos;
            refreshLine(fd,prompt,buf,len,pos,cols);
            break;
        case 1: /* Ctrl+a, go to the start of the line */
            pos = 0;
            refreshLine(fd,prompt,buf,len,pos,cols);
            break;
        case 5: /* ctrl+e, go to the end of the line */
            pos = len;
            refreshLine(fd,prompt,buf,len,pos,cols);
            break;
        case 12: /* ctrl+l, clear screen */
            linenoiseClearScreen();
            refreshLine(fd,prompt,buf,len,pos,cols);
        }
    }
    return len;
}
(* COMM: value dependent types * )

************
https://github.com/orangeduck/BuildYourOwnLisp/blob/master/src/mpc.c

mpc_print_unretained:    NG
original :  (ua.((free + 0);((free;free) + 0);(free + 0);(free + 0);(free + 0)))
rewritten:  (ua.((free + 0);((free;free) + 0);(free + 0);(free + 0);(free + 0)))

static void mpc_print_unretained(mpc_parser_t *p, int force) {

  /* TODO: Print Everything Escaped */

  int i;
  char *s, *e;
  char buff[2];

  if (p->retained && !force) {;
    if (p->name) { printf(""<%s>"", p->name); }
    else { printf(""<anon>""); }
    return;
  }

  if (p->type == MPC_TYPE_UNDEFINED) { printf(""<?>""); }
  if (p->type == MPC_TYPE_PASS)   { printf(""<:>""); }
  if (p->type == MPC_TYPE_FAIL)   { printf(""<!>""); }
  if (p->type == MPC_TYPE_LIFT)   { printf(""<#>""); }
  if (p->type == MPC_TYPE_STATE)  { printf(""<S>""); }
  if (p->type == MPC_TYPE_ANCHOR) { printf(""<@>""); }
  if (p->type == MPC_TYPE_EXPECT) {
    printf(""%s"", p->data.expect.m);
    /*mpc_print_unretained(p->data.expect.x, 0);*/
  }

  if (p->type == MPC_TYPE_ANY) { printf(""<.>""); }
  if (p->type == MPC_TYPE_SATISFY) { printf(""<f>""); }

  if (p->type == MPC_TYPE_SINGLE) {
    buff[0] = p->data.single.x; buff[1] = '\0';
    s = mpcf_escape_new(
      buff,
      mpc_escape_input_c,
      mpc_escape_output_c);
    printf(""'%s'"", s);
    free(s);
  }

  if (p->type == MPC_TYPE_RANGE) {
    buff[0] = p->data.range.x; buff[1] = '\0';
    s = mpcf_escape_new(
      buff,
      mpc_escape_input_c,
      mpc_escape_output_c);
    buff[0] = p->data.range.y; buff[1] = '\0';
    e = mpcf_escape_new(
      buff,
      mpc_escape_input_c,
      mpc_escape_output_c);
    printf(""[%s-%s]"", s, e);
    free(s);
    free(e);
  }

  if (p->type == MPC_TYPE_ONEOF) {
    s = mpcf_escape_new(
      p->data.string.x,
      mpc_escape_input_c,
      mpc_escape_output_c);
    printf(""[%s]"", s);
    free(s);
  }

  if (p->type == MPC_TYPE_NONEOF) {
    s = mpcf_escape_new(
      p->data.string.x,
      mpc_escape_input_c,
      mpc_escape_output_c);
    printf(""[^%s]"", s);
    free(s);
  }

  if (p->type == MPC_TYPE_STRING) {
    s = mpcf_escape_new(
      p->data.string.x,
      mpc_escape_input_c,
      mpc_escape_output_c);
    printf(""\""%s\"""", s);
    free(s);
  }

  if (p->type == MPC_TYPE_APPLY)    { mpc_print_unretained(p->data.apply.x, 0); }
  if (p->type == MPC_TYPE_APPLY_TO) { mpc_print_unretained(p->data.apply_to.x, 0); }
  if (p->type == MPC_TYPE_PREDICT)  { mpc_print_unretained(p->data.predict.x, 0); }

  if (p->type == MPC_TYPE_NOT)   { mpc_print_unretained(p->data.not.x, 0); printf(""!""); }
  if (p->type == MPC_TYPE_MAYBE) { mpc_print_unretained(p->data.not.x, 0); printf(""?""); }

  if (p->type == MPC_TYPE_MANY)  { mpc_print_unretained(p->data.repeat.x, 0); printf(""*""); }
  if (p->type == MPC_TYPE_MANY1) { mpc_print_unretained(p->data.repeat.x, 0); printf(""+""); }
  if (p->type == MPC_TYPE_COUNT) { mpc_print_unretained(p->data.repeat.x, 0); printf(""{%i}"", p->data.repeat.n); }

  if (p->type == MPC_TYPE_OR) {
    printf(""("");
    for(i = 0; i < p->data.or.n-1; i++) {
      mpc_print_unretained(p->data.or.xs[i], 0);
      printf("" | "");
    }
    mpc_print_unretained(p->data.or.xs[p->data.or.n-1], 0);
    printf("")"");
  }

  if (p->type == MPC_TYPE_AND) {
    printf(""("");
    for(i = 0; i < p->data.and.n-1; i++) {
      mpc_print_unretained(p->data.and.xs[i], 0);
      printf("" "");
    }
    mpc_print_unretained(p->data.and.xs[p->data.and.n-1], 0);
    printf("")"");
  }

}
(* type dependent  *)

***********
https://github.com/orangeduck/BuildYourOwnLisp/blob/master/src/mpc.c

mpcf_nth_free:   NG
original: (ua.(free + 0);a)
rewritten:  (ua.(free + 0);a)
-- array of pointers

static mpc_val_t *mpcf_nth_free(int n, mpc_val_t **xs, int x) {
  int i;
  for (i = 0; i < n; i++) {
    if (i != x) { free(xs[i]); }
  }
  return xs[x];
}

******
https://github.com/orangeduck/BuildYourOwnLisp/blob/master/src/mpc.c

mpc_undefine_unretained:   NG
original:  (ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0)))
rewritten: (ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0)))

static void mpc_undefine_unretained(mpc_parser_t *p, int force) {

  if (p->retained && !force) { return; }

  switch (p->type) {

    case MPC_TYPE_FAIL: free(p->data.fail.m); break;

    case MPC_TYPE_ONEOF:
    case MPC_TYPE_NONEOF:
    case MPC_TYPE_STRING:
      free(p->data.string.x);
      break;

    case MPC_TYPE_APPLY:    mpc_undefine_unretained(p->data.apply.x, 0);    break;
    case MPC_TYPE_APPLY_TO: mpc_undefine_unretained(p->data.apply_to.x, 0); break;
    case MPC_TYPE_PREDICT:  mpc_undefine_unretained(p->data.predict.x, 0);  break;

    case MPC_TYPE_MAYBE:
    case MPC_TYPE_NOT:
      mpc_undefine_unretained(p->data.not.x, 0);
      break;

    case MPC_TYPE_EXPECT:
      mpc_undefine_unretained(p->data.expect.x, 0);
      free(p->data.expect.m);
      break;

    case MPC_TYPE_MANY:
    case MPC_TYPE_MANY1:
    case MPC_TYPE_COUNT:
      mpc_undefine_unretained(p->data.repeat.x, 0);
      break;

    case MPC_TYPE_OR:  mpc_undefine_or(p);  break;
    case MPC_TYPE_AND: mpc_undefine_and(p); break;

    default: break;
  }

  if (!force) {
    free(p->name);
    free(p);
  }

}

******
mpc_input_unmark:    NG
original :  ((free + 0) + 0)
rewritten:  ((free + 0) + 0)

static void mpc_input_unmark(mpc_input_t *i) {

  if (i->backtrack < 1) { return; }

  i->marks_num--;
  i->marks = realloc(i->marks, sizeof(mpc_state_t) * i->marks_num);
  i->lasts = realloc(i->lasts, sizeof(char) * i->marks_num);

  if (i->type == MPC_INPUT_PIPE && i->marks_num == 0) {
    free(i->buffer);
    i->buffer = NULL;
  }

}

*****
https://github.com/orangeduck/BuildYourOwnLisp/blob/master/src/mpc.c

mpc_input_delete:  NG
original : free;(free + 0);(free + 0);free;free;free
rewritten:  free;(free + 0);(free + 0);free;free;free

static void mpc_input_delete(mpc_input_t *i) {

  free(i->filename);

  if (i->type == MPC_INPUT_STRING) { free(i->string); }
  if (i->type == MPC_INPUT_PIPE) { free(i->buffer); }

  free(i->marks);
  free(i->lasts);
  free(i);
}

****
https://github.com/orangeduck/BuildYourOwnLisp/blob/master/src/functions.c

lval_del:    NG
original :  (ua.((free + free + free + 0);free))
rewritten: (ua.((free + free + free + 0);free))

void lval_del(lval* v) {

  switch (v->type) {
    case LVAL_NUM: break;
    case LVAL_FUN:
      if (!v->builtin) {
        lenv_del(v->env);
        lval_del(v->formals);
        lval_del(v->body);
      }
    break;
    case LVAL_ERR: free(v->err); break;
    case LVAL_SYM: free(v->sym); break;
    case LVAL_QEXPR:
    case LVAL_SEXPR:
      for (int i = 0; i < v->count; i++) {
        lval_del(v->cell[i]);
      }
      free(v->cell);
    break;
  }

  free(v);
}

******
https://github.com/Orc/discount/blob/master/css.c

mkd_css:   NG
original:  ((((0 + (0 + malloc));((0 + (0 + malloc)) + (free + 0)) + 0) + 0) + 0)
rewritten:  ((((0 + (0 + malloc));((0 + (0 + malloc)) + (free + 0)) + 0) + 0) + 0)

int mkd_css(Document *d, char **res)
{
    Cstring f;
    int size;

    if ( res && d && d->compiled ) {
 *res = 0;
 CREATE(f);
 RESERVE(f, 100);
 stylesheets(d->code, &f);

 if ( (size = S(f)) > 0 ) {
     EXPAND(f) = 0;
   /* HACK ALERT! HACK ALERT! HACK ALERT! */
     *res = T(f);/* we know that a T(Cstring) is a character pointer */
   /* so we can simply pick it up and carry it away, */
   /* leaving the husk of the Ctring on the stack */
   /* END HACK ALERT */
 }
 else
     DELETE(f);
 return size;
    }
    return EOF;
}

**********
https://github.com/APE-Project/APE_Server/blob/master/src/cmd.c

cmd_script:  NG
original : (0 + (free + 0))
rewritten: (0 + (free + 0))

unsigned int cmd_script(callbackp *callbacki)
{
 char *domain = CONFIG_VAL(Server, domain, callbacki->g_ape->srv);
 char *script = NULL;
 int alloc = 0;
 APE_PARAMS_INIT();

 if (domain == NULL) {
  send_error(callbacki->call_user, ""NO_DOMAIN"", ""201"", callbacki->g_ape);
 } else {
  char *autodom;
  if (strcmp(domain, ""auto"") == 0 && (autodom = JSTR(domain)) != NULL) {
   domain = autodom;
   #if 0
   /* http://geekandpoke.typepad.com/.a/6a00d8341d3df553ef0120a6d65b8a970b-pi */

   struct _http_header_line *hlines;
   for (hlines = callbacki->client->http.hlines; hlines != NULL; hlines = hlines->next) {
    if (strcasecmp(hlines->key.val, ""host"") == 0) {
     char *loc;
     char *newdom = xmalloc(sizeof(char) * (hlines->value.len + 1));
     memset(newdom, '\0', hlines->value.len + 1);
     if ((loc = strrchr(hlines->value.val, '.')) != NULL) {
      int i, pos = 0;
      for (i = 0; i < hlines->value.len; i++, pos++) {
       newdom[pos] = hlines->value.val[i];
       if (newdom[pos] == ':') {
        newdom[pos] = '\0';
        break;
       }
       if (hlines->value.val[i] == '.' && &hlines->value.val[i] < loc) {
        pos = -1;
       }
      }
      newdom[pos] = '\0';
      domain = newdom;
      alloc = 1;
     }
    }
   }
   #endif
  }
  sendf(callbacki->client->fd, callbacki->g_ape, ""%s<html>\n<head>\n\t<script>\n\t\tdocument.domain=\""%s\""\n\t</script>\n"", HEADER_DEFAULT, domain);

  if (alloc) {
   free(domain);
  }

  JFOREACH(scripts, script) {
   sendf(callbacki->client->fd, callbacki->g_ape, ""\t<script type=\""text/javascript\"" src=\""%s\""></script>\n"", script);
  }
  sendbin(callbacki->client->fd, ""</head>\n<body>\n</body>\n</html>"", 30, 0, callbacki->g_ape);
 }

 return (RETURN_NOTHING);
}


****
https://github.com/APE-Project/APE_Server/blob/master/src/config.c

ape_config_set_key:  NG
original:  (ua.(free + 0);a)
rewritten: (ua.(free + 0);a)

  void ape_config_set_key(apeconfig *conf, const char *key, char *value)
  {
    struct _apeconfig_def *def;
    if (conf == NULL) {
      return;
    }
    def = conf->def;
    while (def != NULL) {
      if (strcasecmp(def->key, key) == 0) {
        free(def->val);
        def->val = xstrdup(value);
        break;
      }
      def = def->next;
    }
  }

********
https://github.com/APE-Project/APE_Server/blob/master/deps/js/src/ctypes/libffi/src/dlmalloc.c

realloc:    NG
original : (malloc + ((free + 0) + malloc;(free + 0)))
rewritten: (malloc + ((free + 0) + malloc;(free + 0)))

void* dlrealloc(void* oldmem, size_t bytes) {
  if (oldmem == 0)
    return dlmalloc(bytes);
#ifdef REALLOC_ZERO_BYTES_FREES
  if (bytes == 0) {
    dlfree(oldmem);
    return 0;
  }
#endif /* REALLOC_ZERO_BYTES_FREES */
  else {
#if ! FOOTERS
    mstate m = gm;
#else /* FOOTERS */
    mstate m = get_mstate_for(mem2chunk(oldmem));
    if (!ok_magic(m)) {
      USAGE_ERROR_ACTION(m, oldmem);
      return 0;
    }
#endif /* FOOTERS */
    return internal_realloc(m, oldmem, bytes);
  }
 }

 ****
https://github.com/APE-Project/APE_Server/blob/master/src/dns.c

dnscb:  NG
original : ((free;free) + 0);((free;free;;free) + 0);free;free;free
rewritten: ((free;free) + 0);((free;free;;free) + 0);free;free;free

static void dnscb(struct dns_ctx *ctx, void *result, void *data) {
  int r = dns_status(ctx);
  struct query *q = data;
  struct dns_parse p;
  struct dns_rr rr;
  unsigned nrr;
  unsigned char dn[DNS_MAXDN];
  const unsigned char *pkt, *cur, *end;
  if (!result) {
    dnserror(q, r);
    return;
  }
  pkt = result; end = pkt + r; cur = dns_payload(pkt);
  dns_getdn(pkt, &cur, end, dn, sizeof(dn));
  dns_initparse(&p, NULL, pkt, cur, end);
  p.dnsp_qcls = p.dnsp_qtyp = 0;
  nrr = 0;
  while((r = dns_nextrr(&p, &rr)) > 0) {
    if (!dns_dnequal(dn, rr.dnsrr_dn)) continue;
    if ((qcls == DNS_C_ANY || qcls == rr.dnsrr_cls) &&
        (q->qtyp == DNS_T_ANY || q->qtyp == rr.dnsrr_typ))
      ++nrr;
    else if (rr.dnsrr_typ == DNS_T_CNAME && !nrr) {
      if (dns_getdn(pkt, &rr.dnsrr_dptr, end,
                    p.dnsp_dnbuf, sizeof(p.dnsp_dnbuf)) <= 0 ||
          rr.dnsrr_dptr != rr.dnsrr_dend) {
        r = DNS_E_PROTOCOL;
        break;
      }
      else {
        if (verbose == 1) {
          printf(""%s."", dns_dntosp(dn));
          printf("" CNAME %s.\n"", dns_dntosp(p.dnsp_dnbuf));
        }
        dns_dntodn(p.dnsp_dnbuf, dn, sizeof(dn));
      }
    }
  }
  if (!r && !nrr)
    r = DNS_E_NODATA;
  if (r < 0) {
    dnserror(q, r);
    free(result);
    return;
  }
  if (verbose < 2) { /* else it is already printed by dbgfn */
    dns_rewind(&p, NULL);
    p.dnsp_qtyp = q->qtyp == DNS_T_ANY ? 0 : q->qtyp;
    p.dnsp_qcls = qcls == DNS_C_ANY ? 0 : qcls;
    while(dns_nextrr(&p, &rr))
      printrr(&p, &rr);
  }
  free(result);
  query_free(q);
}

******
https://github.com/APE-Project/APE_Server/blob/master/src/entry.c

main:  NG
original : free;free;(ua.(free + 0);a);free;free
rewritten : free;free;(ua.(free + 0);a);free;free

int main(int argc, char **argv)
{
  apeconfig *srv;
  int random, im_r00t = 0, pidfd = 0, serverfd;
  unsigned int getrandom = 0;
  const char *pidfile = NULL;
  char *confs_path = NULL;
  struct _fdevent fdev;
  char cfgfile[513] = APE_CONFIG_FILE;
  acetables *g_ape;
  int argi = 0;
  int overrule_daemon = -1; //nothing fancy, -1: no, just the configuration, 0: yes overrule config, but do no daemon, 1: yes overrule config, but daemonize
  if (argc > 1 ) {
    for (argi = 1; argi < argc; argi++ ) {
      if (strcmp(argv[argi], ""--version"") == 0) {
        printf(""\n AJAX Push Engine Server %s - (C) Anthony Catel <a.catel@weelya.com>\n http://www.ape-project.org/\n\n"", _VERSION);
               return 0;
               } else if (strcmp(argv[argi], ""--help"") == 0) {
          printf(""\n AJAX Push Engine Server %s - (C) Anthony Catel <a.catel@weelya.com>\n http://www.ape-project.org/\n"", _VERSION);
                 printf(""\n usage: aped [options]\n\n"");
                 printf("" Options:\n --help : Display this help\n --version : Show version number\n --daemon yes|no : Overrule the daemon settings in Server section of the config file\n --cfg FILE : Load a specific config file (default is %s)\n\n"", cfgfile);
                 return 0;
                 } else if (argc > argi + 1 && strcmp(argv[argi], ""--cfg"") == 0) {
            memset(cfgfile, 0, 513);
            strncpy(cfgfile, argv[argi + 1], 512);
            confs_path = get_path(cfgfile);
            argi++;
          } else if (argc > argi + 1 && strcmp(argv[argi], ""--daemon"") == 0) {
            overrule_daemon = (strcmp(argv[argi + 1], ""yes"") == 0 );
            argi++;
          } else {
            printf(""\n AJAX Push Engine Server %s - (C) Anthony Catel <a.catel@weelya.com>\n http://www.ape-project.org/\n\n"", _VERSION);
                   printf("" Unknown parameters - check \""aped --help\""\n\n"");
                   exit(1);
                   }
          }
        }
        if (NULL == (srv = ape_config_load(cfgfile))) {
          printf(""\nExiting...\n\n"");
          exit(1);
        }
        if (getuid() == 0) {
          im_r00t = 1;
        }
        signal(SIGINT, &signal_handler);
        signal(SIGTERM, &signal_handler);
        g_ape = xmalloc(sizeof(*g_ape));
        g_ape->basemem = 1; // set 1 for testing if growup works
        g_ape->srv = srv;
        g_ape->confs_path = confs_path;
        if (overrule_daemon == 0) {
          ape_config_set_key(ape_config_get_section(g_ape->srv, ""Server""), ""daemon"", ""no"");
        } else if (overrule_daemon == 1) {
          ape_config_set_key(ape_config_get_section(g_ape->srv, ""Server""), ""daemon"", ""yes"");
        }
        g_ape->is_daemon = (strcmp(CONFIG_VAL(Server, daemon, srv), ""yes"") == 0 )? 1 :0;
        ape_log_init(g_ape);
        if (VTICKS_RATE < 1) {
          if (!g_ape->is_daemon) {
            printf(""[ERR] TICKS_RATE cannot be less than 1... exiting\n"");
          }
          ape_log(APE_ERR, __FILE__, __LINE__, g_ape, ""[ERR] TICKS_RATE cannot be less than 1... exiting"");
          exit(1);
        }
        random = open(""/dev/urandom"", O_RDONLY);
        if (!random) {
          if (!g_ape->is_daemon) {
            printf(""[ERR] Cannot open /dev/urandom... exiting\n"");
          }
          ape_log(APE_ERR, __FILE__, __LINE__, g_ape, ""[ERR] Cannot open /dev/urandom... exiting"");
          exit(1);
        }
        read(random, &getrandom, 3);
        srand(getrandom);
        close(random);
        fdev.handler = EVENT_UNKNOWN;
#ifdef USE_EPOLL_HANDLER
        fdev.handler = EVENT_EPOLL;
#endif
#ifdef USE_KQUEUE_HANDLER
        fdev.handler = EVENT_KQUEUE;
#endif
#ifdef USE_SELECT_HANDLER
        fdev.handler = EVENT_SELECT;
#endif
        g_ape->co = xmalloc(sizeof(*g_ape->co) * g_ape->basemem);
        memset(g_ape->co, 0, sizeof(*g_ape->co) * g_ape->basemem);
        g_ape->bad_cmd_callbacks = NULL;
        g_ape->bufout = xmalloc(sizeof(struct _socks_bufout) * g_ape->basemem);
        g_ape->timers.timers = NULL;
        g_ape->timers.ntimers = 0;
        g_ape->events = &fdev;
        if (events_init(g_ape, &g_ape->basemem) == -1) {
          if (!g_ape->is_daemon) {
            printf(""[ERR] Fatal error: APE compiled without an event handler... exiting\n"");
          }
          ape_log(APE_ERR, __FILE__, __LINE__, g_ape, ""[ERR] Fatal error: APE compiled without an event handler... exiting"");
          exit(1);
        }
        serverfd = servers_init(g_ape);
        //printf(""APE starting up %s:%i\n"", CONFIG_VAL(Server, ip_listen, g_ape->srv), atoi(CONFIG_VAL(Server, port, srv)));
        //ape_log(APE_INFO, __FILE__, __LINE__, g_ape, ""APE starting up %s:%i\n"", CONFIG_VAL(Server, ip_listen, g_ape->srv), atoi(CONFIG_VAL(Server, port, srv)));
        if ((pidfile = CONFIG_VAL(Server, pid_file, srv)) != NULL) {
          if ((pidfd = open(pidfile, O_TRUNC | O_WRONLY | O_CREAT, 0655)) == -1) {
            if (!g_ape->is_daemon) {
              printf(""[WARN] Cannot open pid file : %s\n"", CONFIG_VAL(Server, pid_file, srv));
            }
            ape_log(APE_WARN, __FILE__, __LINE__, g_ape, ""[WARN] Cannot open pid file : %s"", CONFIG_VAL(Server, pid_file, srv));
          }
        }
        if (im_r00t) {
          struct group *grp = NULL;
          struct passwd *pwd = NULL;
          if (inc_rlimit(atoi(CONFIG_VAL(Server, rlimit_nofile, srv))) == -1) {
            if (!g_ape->is_daemon) {
              printf(""[WARN] Cannot set the max filedescriptor limit (setrlimit) %s\n"", strerror(errno));
            }
            ape_log(APE_WARN, __FILE__, __LINE__, g_ape, ""[WARN] Cannot set the max filedescriptor limit (setrlimit) %s"", strerror(errno));
          }
          /* Set uid when uid section exists */
          if (ape_config_get_section(srv, ""uid"")) {
            /* Get the user information (uid section) */
            if ((pwd = getpwnam(CONFIG_VAL(uid, user, srv))) == NULL) {
              if (!g_ape->is_daemon) {
                printf(""[ERR] Cannot find username %s\n"", CONFIG_VAL(uid, user, srv));
              }
              ape_log(APE_ERR, __FILE__, __LINE__, g_ape, ""[ERR] Cannot find username %s"", CONFIG_VAL(uid, user, srv));
              return -1;
            }
            if (pwd->pw_uid == 0) {
              if (!g_ape->is_daemon) {
                printf(""[ERR] %s uid can\'t be 0\n"", CONFIG_VAL(uid, user, srv));
              }
              ape_log(APE_ERR, __FILE__, __LINE__, g_ape, ""[ERR] %s uid can\'t be 0"", CONFIG_VAL(uid, user, srv));
              return -1;
            }
            /* Get the group information (uid section) */
            if ((grp = getgrnam(CONFIG_VAL(uid, group, srv))) == NULL) {
              if (!g_ape->is_daemon) {
                printf(""[ERR] Cannot find group %s\n"", CONFIG_VAL(uid, group, srv));
              }
              ape_log(APE_ERR, __FILE__, __LINE__, g_ape, ""[ERR] Cannot find group %s"", CONFIG_VAL(uid, group, srv));
              return -1;
            }
            if (grp->gr_gid == 0) {
              if (!g_ape->is_daemon) {
                printf(""[ERR] %s gid cannot be 0\n"", CONFIG_VAL(uid, group, srv));
              }
              ape_log(APE_ERR, __FILE__, __LINE__, g_ape, ""[ERR] %s gid cannot be 0"", CONFIG_VAL(uid, group, srv));
              return -1;
            }
            setgid(grp->gr_gid);
            setgroups(0, NULL);
            initgroups(CONFIG_VAL(uid, user, srv), grp->gr_gid);
            setuid(pwd->pw_uid);
          }
        } else {
          if (!g_ape->is_daemon) {
            printf(""[WARN] You have to run \'aped\' as root to increase r_limit\n"");
          }
          ape_log(APE_WARN, __FILE__, __LINE__, g_ape, ""[WARN] You have to run \'aped\' as root to increase r_limit"");
        }
        if (g_ape->is_daemon) {
          ape_log(APE_INFO, __FILE__, __LINE__, g_ape, ""Starting daemon on %s:%i, pid: %i"", CONFIG_VAL(Server, ip_listen, g_ape->srv), atoi(CONFIG_VAL(Server, port, srv)), getpid());
          ape_daemon(pidfd, g_ape);
          printf(""Started daemon on %s:%i, pid: %i\n"", CONFIG_VAL(Server, ip_listen, g_ape->srv), atoi(CONFIG_VAL(Server, port, srv)), getpid());
          events_reload(g_ape->events);
          events_add(g_ape->events, serverfd, EVENT_READ);
        } else {
          printf("" _ ___ ___ \n"");
          printf("" /_\\ | _ \\ __|\n"");
          printf("" / _ \\| _/ _| \n"");
          printf(""/_/ \\_\\_| |___|\nAJAX Push Engine\n\n"");
          printf(""Bind on : %s:%i\nPid : %i\n"", CONFIG_VAL(Server, ip_listen, g_ape->srv), atoi(CONFIG_VAL(Server, port, srv)), getpid());
          printf(""Version : %s\n"", _VERSION);
          printf(""Build : %s %s\n"", __DATE__, __TIME__);
          printf(""Author : Weelya (contact@weelya.com)\n\n"");
          ape_log(APE_INFO, __FILE__, __LINE__, g_ape, ""Started on %s:%i, pid: %i\n\n"", CONFIG_VAL(Server, ip_listen, g_ape->srv), atoi(CONFIG_VAL(Server, port, srv)), getpid());
          write_pid_file(pidfd, (int) getpid());
        }
        signal(SIGPIPE, SIG_IGN);
        ape_dns_init(g_ape);
        g_ape->cmd_hook.head = NULL;
        g_ape->cmd_hook.foot = NULL;
        g_ape->hLogin = hashtbl_init();
        g_ape->hSessid = hashtbl_init();
        g_ape->hLusers = hashtbl_init();
        g_ape->hPubid = hashtbl_init();
        g_ape->proxy.list = NULL;
        g_ape->proxy.hosts = NULL;
        g_ape->hCallback = hashtbl_init();
        g_ape->uHead = NULL;
        g_ape->nConnected = 0;
        g_ape->plugins = NULL;
        g_ape->properties = NULL;
        add_ticked(check_timeout, g_ape);
        do_register(g_ape);
        transport_start(g_ape);
        findandloadplugin(g_ape);
        server_is_running = 1;
        /* Starting Up */
        sockroutine(g_ape); /* loop */
        /* Shutdown */
        if (pidfile != NULL) {
          unlink(pidfile);
        }
        //fixme: unregister commands, register_bad_cmd and register_hook_cmd
        free(confs_path);
        timers_free(g_ape);
        events_free(g_ape);
        transport_free(g_ape);
        hashtbl_free(g_ape->hLogin);
        hashtbl_free(g_ape->hSessid);
        hashtbl_free(g_ape->hLusers);
        hashtbl_free(g_ape->hPubid);
        hashtbl_free(g_ape->hCallback);
        free(g_ape->bufout);
        ape_config_free(srv);
        int i;
        for (i = 0; i < g_ape->basemem; i++) {
          if (g_ape->co[i] != NULL) {
            free(g_ape->co[i]);
          }
        }
        free(g_ape->co);
        free_all_plugins(g_ape);
        free(g_ape);
        return 0;
      }

*****
https://github.com/APE-Project/APE_Server/blob/master/src/events.c

events_free:  NG
original : (free + 0)
rewritten : (free + 0)

void events_free(acetables *g_ape)
{
if (g_ape->events->handler != EVENT_UNKNOWN) {
free(g_ape->events->events);
}
}

*****
https://github.com/APE-Project/APE_Server/blob/master/src/extend.c

clear_properties: NG
original : (ua.(free + 0);free;a)
rewritten :  (ua.(free + 0);free;a)

void clear_properties(extend **entry)
{
 extend *pEntry = *entry, *pTmp;

 while (pEntry != NULL) {
  pTmp = pEntry->next;
  switch(pEntry->type) {
   case EXTEND_STR:
    free(pEntry->val);
    break;
   case EXTEND_JSON:
    free_json_item(pEntry->val);
    break;
   default:
    break;
  }
  free(pEntry);
  pEntry = pTmp;
 }
 *entry = NULL;
}

******
https://github.com/APE-Project/APE_Server/blob/master/src/hash.c

hashtbl_erase:  NG
original : (ua.((free;free) + 0);a)
rewritten : (ua.((free;free) + 0);a)

void hashtbl_erase(HTBL *htbl, const char *key)
{
 unsigned int key_hash;
 HTBL_ITEM *hTmp, *hPrev;

 if (key == NULL) {
  return;
 }

 key_hash = hach_string(key);

 hTmp = htbl->table[key_hash];
 hPrev = NULL;

 while (hTmp != NULL) {
  if (strcasecmp(hTmp->key, key) == 0) {
   if (hPrev != NULL) {
    hPrev->next = hTmp->next;
   } else {
    htbl->table[key_hash] = hTmp->next;
   }

   if (hTmp->lprev == NULL) {
    htbl->first = hTmp->lnext;
   } else {
    hTmp->lprev->lnext = hTmp->lnext;
   }
   if (hTmp->lnext != NULL) {
    hTmp->lnext->lprev = hTmp->lprev;
   }

   free(hTmp->key);
   free(hTmp);
   return;
  }
  hPrev = hTmp;
  hTmp = hTmp->next;
 }
}


****
hashtbl_append:  NG
original : ((ua.((free;free) + 0);a) + 0)
rewritten : ((ua.((free;free) + 0);a) + 0)

  void hashtbl_append(HTBL *htbl, const char *key, void *structaddr)
  {
    unsigned int key_hash, key_len;
    HTBL_ITEM *hTmp, *hDbl;
    if (key == NULL) {
      return;
    }
    key_len = strlen(key);
    key_hash = hach_string(key);
    hTmp = (HTBL_ITEM *)xmalloc(sizeof(*hTmp));
    hTmp->next = NULL;
    hTmp->lnext = htbl->first;
    hTmp->lprev = NULL;
    hTmp->key = xmalloc(sizeof(char) * (key_len+1));
    hTmp->addrs = (void *)structaddr;
    memcpy(hTmp->key, key, key_len+1);
    if (htbl->table[key_hash] != NULL) {
      hDbl = htbl->table[key_hash];
      while (hDbl != NULL) {
        if (strcasecmp(hDbl->key, key) == 0) {
          free(hTmp->key);
          free(hTmp);
          hDbl->addrs = (void *)structaddr;
          return;
        } else {
          hDbl = hDbl->next;
        }
      }
      hTmp->next = htbl->table[key_hash];
    }
    if (htbl->first != NULL) {
      htbl->first->lprev = hTmp;
    }
    htbl->first = hTmp;
    htbl->table[key_hash] = hTmp;
  }

*****
https://github.com/APE-Project/APE_Server/blob/master/src/http.c

 parse_header_line:  NG
original :  (ua.(((free + (free + 0)) + ((free + 0) + (free + 0))) + 0);a);(free + 0)
rewritten : (ua.(((free + (free + 0)) + ((free + 0) + (free + 0))) + 0);a);(free + 0)

static struct _http_header_line *parse_header_line(const char *line)
{
 unsigned int i;
 unsigned short int state = 0;
 struct _http_header_line *hline = NULL;
 for (i = 0; i < 1024 && line[i] != '\0' && line[i] != '\r' && line[i] != '\n'; i++) {
  if (i == 0) {
   hline = xmalloc(sizeof(*hline));
   hline->key.len = 0;
   hline->value.len = 0;
  }
  switch(state) {
   case 0:
    if ((i == 0 && (line[i] == ':' || line[i] == ' ')) || (line[i] == ':' && line[i+1] != ' ') || (i > 63)) {
     free(hline);
     return NULL;
    }
    if (line[i] == ':') {
     hline->key.val[hline->key.len] = '\0';
     state = 1;
     i++;
    } else {
     hline->key.val[hline->key.len++] = line[i];
    }
    break;
   case 1:
    hline->value.val[hline->value.len++] = line[i];
    break;
  }
 }
 if (!state) {
  free(hline);
  return NULL;
 }
 hline->value.val[hline->value.len] = '\0';

 return hline;
}

*****
https://github.com/APE-Project/APE_Server/blob/master/src/json.c

json_lookup:  NG
original : (ua.(((free + 0) + 0) + 0);a);free
rewritten : (ua.(((free + 0) + 0) + 0);a);free

json_item *json_lookup(json_item *head, char *path)
{
 char *split[16];
 char *base;
 size_t nTok;
 int i = 0;

 if (head == NULL || path == NULL) {
  return NULL;
 }

 base = xstrdup(path);

 nTok = explode('.', base, split, 15);

 while (head != NULL && i <= nTok) {

  if (head->key.val != NULL && strcasecmp(split[i], head->key.val) == 0) {
   /*
   printf(""Array %s : %i\n"", split[i], key_is_array(split[i], strlen(split[i])-1));
   printf(""Comparing : %s with %s\n"", head->key.val, split[i]);
   printf(""Find !\n"");
   */
   if (i == nTok) {
    free(base);
    return (head->jchild.child != NULL ? head->jchild.child : head);
   }
   i++;
   head = head->jchild.child;
   continue;
  }

  head = head->next;
 }
 free(base);
 return NULL;
}


*****
json_to_string:  NG
original : (ua.((ua.((free + 0) + 0);((free + 0) + 0);(free + 0);a)))
rewritten : (ua.((ua.((free + 0) + 0);((free + 0) + 0);(free + 0);a)))

struct jsontring *json_to_string(json_item *head, struct jsontring *string, int free_tree)
{
 if (string == NULL) {
  string = xmalloc(sizeof(struct jsontring));

  /* Ok, this can cost a lot (traversing the tree), but avoid realloc at each iteration */
  string->jsize = json_evaluate_string_size(head) * 2; /* TODO : Remove * 2, add some padding, realloc when necessary (or at least just x2 str val) */

  string->jstring = xmalloc(sizeof(char) * (string->jsize + 1));
  string->len = 0;
 }

 while (head != NULL) {

  if (head->key.val != NULL) {
   string->jstring[string->len++] = '""';
   memcpy(string->jstring + string->len, head->key.val, head->key.len);
   string->len += head->key.len;
   string->jstring[string->len++] = '""';
   string->jstring[string->len++] = ':';

   if (free_tree) {
    free(head->key.val);
   }
  }

  if (head->jval.vu.str.value != NULL) {

   string->jstring[string->len++] = '""';
   string->len += escape_json_string(head->jval.vu.str.value, string->jstring + string->len, head->jval.vu.str.length); /* TODO : Add a ""escape"" argument to json_to_string */
   string->jstring[string->len++] = '""';

   if (free_tree) {
    free(head->jval.vu.str.value);
   }
  } else if (head->jval.vu.integer_value) {

   long int l = LENGTH_N(head->jval.vu.integer_value);
   long int offset;
   char integer_str[l+2];

   offset = itos(head->jval.vu.integer_value, integer_str, l+2);

   memcpy(string->jstring + string->len, &integer_str[offset], ((l+2)-1)-offset);

   string->len += ((l+2)-1)-offset;

  } else if (head->jval.vu.float_value) {
   int length;

   /* TODO: check for -1 */
   /* TODO: fix max length 16 together with json_evaluate_string_size() */
   length = snprintf(string->jstring + string->len, 16 + 1, ""%f"", head->jval.vu.float_value);
   if(length > 16) /* cut-off number */
    length = 16;

   string->len += length;
  } else if (head->type == JSON_T_TRUE) {
   memcpy(string->jstring + string->len, ""true"", 4);
   string->len += 4;
  } else if (head->type == JSON_T_FALSE) {
   memcpy(string->jstring + string->len, ""false"", 5);
   string->len += 5;
  } else if (head->type == JSON_T_NULL) {
   memcpy(string->jstring + string->len, ""null"", 4);
   string->len += 4;
  } else if (head->jchild.child == NULL) {
   memcpy(string->jstring + string->len, ""0"", 1);
   string->len++;
  }

  if (head->jchild.child != NULL) {
   switch(head->jchild.type) {
    case JSON_C_T_OBJ:
     string->jstring[string->len++] = '{';
     break;
    case JSON_C_T_ARR:
     string->jstring[string->len++] = '[';
     break;
    default:
     break;
   }
   json_to_string(head->jchild.child, string, free_tree);

  }

  if (head->father != NULL) {
   if (head->next != NULL) {
    string->jstring[string->len++] = ',';
   } else {
    switch(head->father->jchild.type) {
     case JSON_C_T_OBJ:
      string->jstring[string->len++] = '}';
      break;
     case JSON_C_T_ARR:
      string->jstring[string->len++] = ']';
      break;
     default:
      break;
    }
   }
  }
  if (free_tree) {
   json_item *jtmp = head->next;
   free(head);
   head = jtmp;
  } else {
   head = head->next;
  }
 }
 string->jstring[string->len] = '\0';

 return string;
}


****
https://github.com/APE-Project/APE_Server/blob/master/src/log.c

ape_log:  NG
original : (0 + ((0 + (free + 0));free))
rewritten : (0 + ((0 + (free + 0));free))

void ape_log(ape_log_lvl_t lvl, const char *file, unsigned long int line, acetables *g_ape, char *buf, ...)
{
 if (lvl == APE_DEBUG && !g_ape->logs.lvl&APE_DEBUG) {
  return;
 } else {
  char *buff;
  int len;
  va_list val;

  va_start(val, buf);
  len = vasprintf(&buff, buf, val);
  va_end(val);

  if (g_ape->logs.use_syslog) {
   int level = LOG_ERR;
   switch (lvl) {
    case APE_DEBUG:
     level = LOG_DEBUG;
     break;
    case APE_WARN:
     level = LOG_WARNING;
     break;
    case APE_ERR:
     level = LOG_ERR;
     break;
    case APE_INFO:
     level = LOG_INFO;
     break;
   }
   syslog(level, ""%s:%li - %s"", file, line, buff);
  } else {
   int datelen;
   char date[32];
   time_t log_ts;
   log_ts = time(NULL);

   datelen = strftime(date, 32, ""%Y-%m-%d %H:%M:%S - "", localtime(&log_ts));

   write(g_ape->logs.fd, date, datelen);
   if (g_ape->logs.lvl&APE_DEBUG) {
    char *debug_file;
    int dlen;
    dlen = asprintf(&debug_file, ""%s:%li - "", file, line);
    write(g_ape->logs.fd, debug_file, dlen);
    free(debug_file);
   }
   write(g_ape->logs.fd, buff, len);
   write(g_ape->logs.fd, ""\n"", 1);
  }

  free(buff);
 }
}

******
https://github.com/APE-Project/APE_Server/blob/master/deps/js/src/config/nsinstall.c

*****
main:  NG
original : (ua.(0 + ((free + 0) + (((ua.((free + 0);(0 + free);free;free;free)) + 0) + 0)));free;a);free;free
rewritten: (ua.(0 + ((free + 0) + (((ua.((free + 0);(0 + free);free;free;free)) + 0) + 0)));free;a);free;free

int main(int argc, char **argv)
{
    int onlydir, dodir, dolink, dorelsymlink, dotimes, opt, len, lplen, tdlen, bnlen, exists, fromfd, tofd, cc, wc;
    mode_t mode = 0755;
    char *linkprefix, *owner, *group, *cp, *cwd, *todir, *toname, *name, *base, *linkname, *bp, buf[BUFSIZ];
    uid_t uid;
    gid_t gid;
    struct stat sb, tosb, fromsb;
    struct utimbuf utb;

    program = argv[0];
    cwd = linkname = linkprefix = owner = group = 0;
    onlydir = dodir = dolink = dorelsymlink = dotimes = lplen = 0;

    while ((opt = getopt(argc, argv, ""C:DdlL:Rm:o:g:t"")) != EOF) {
 switch (opt) {
   case 'C':
     cwd = optarg;
     break;
   case 'D':
     onlydir = 1;
     break;
   case 'd':
     dodir = 1;
     break;
   case 'l':
     dolink = 1;
     break;
   case 'L':
     linkprefix = optarg;
     lplen = strlen(linkprefix);
     dolink = 1;
     break;
     case 'R':
     dolink = dorelsymlink = 1;
     break;
   case 'm':
     mode = strtoul(optarg, &cp, 8);
     if (mode == 0 && cp == optarg)
  usage();
     break;
   case 'o':
     owner = optarg;
     break;
   case 'g':
     group = optarg;
     break;
   case 't':
     dotimes = 1;
     break;
   default:
     usage();
 }
    }

    argc -= optind;
    argv += optind;
    if (argc < 2 - onlydir)
 usage();

    todir = argv[argc-1];
    if ((stat(todir, &sb) < 0 || !S_ISDIR(sb.st_mode)) &&
 mkdirs(todir, 0777) < 0) {
 fail(""cannot make directory %s"", todir);
    }
    if (onlydir)
 return 0;

    if (!cwd) {
#ifndef NEEDS_GETCWD
#ifndef GETCWD_CANT_MALLOC
 cwd = getcwd(0, PATH_MAX);
#else
 cwd = malloc(PATH_MAX + 1);
 cwd = getcwd(cwd, PATH_MAX);
#endif
#else
 cwd = malloc(PATH_MAX + 1);
 cwd = getwd(cwd);
#endif
    }

    xchdir(todir);
#ifndef NEEDS_GETCWD
#ifndef GETCWD_CANT_MALLOC
    todir = getcwd(0, PATH_MAX);
#else
    todir = malloc(PATH_MAX + 1);
    todir = getcwd(todir, PATH_MAX);
#endif
#else
    todir = malloc(PATH_MAX + 1);
    todir = getwd(todir);
#endif
    tdlen = strlen(todir);
    xchdir(cwd);
    tdlen = strlen(todir);

    uid = owner ? touid(owner) : (uid_t)(-1);
    gid = group ? togid(group) : (gid_t)(-1);

    while (--argc > 0) {
 name = *argv++;
 len = strlen(name);
 base = xbasename(name);
 bnlen = strlen(base);
 toname = xmalloc((unsigned int)(tdlen + 1 + bnlen + 1));
 sprintf(toname, ""%s%s%s"", todir, _DIRECTORY_SEPARATOR, base);
 exists = (lstat(toname, &tosb) == 0);

 if (dodir) {
     /* -d means create a directory, always */
     if (exists && !S_ISDIR(tosb.st_mode)) {
  (void) unlink(toname);
  exists = 0;
     }
     if (!exists && mkdir(toname, mode) < 0)
  fail(""cannot make directory %s"", toname);
     if ((owner || group) && chown(toname, uid, gid) < 0)
  fail(""cannot change owner of %s"", toname);
 } else if (dolink) {
            if (access(name, R_OK) != 0) {
                fail(""cannot access %s"", name);
            }
     if (*name == '/') {
  /* source is absolute pathname, link to it directly */
  linkname = 0;
     } else {
  if (linkprefix) {
      /* -L implies -l and prefixes names with a $cwd arg. */
      len += lplen + 1;
      linkname = xmalloc((unsigned int)(len + 1));
      sprintf(linkname, ""%s/%s"", linkprefix, name);
  } else if (dorelsymlink) {
      /* Symlink the relative path from todir to source name. */
      linkname = xmalloc(PATH_MAX);

      if (*todir == '/') {
   /* todir is absolute: skip over common prefix. */
   lplen = relatepaths(todir, cwd, linkname);
   strcpy(linkname + lplen, name);
      } else {
   /* todir is named by a relative path: reverse it. */
   reversepath(todir, name, len, linkname);
   xchdir(cwd);
      }

      len = strlen(linkname);
  }
  name = linkname;
     }

     /* Check for a pre-existing symlink with identical content. */
     if ((exists && (!S_ISLNK(tosb.st_mode) ||
      readlink(toname, buf, sizeof buf) != len ||
      strncmp(buf, name, (unsigned int)len) != 0)) ||
   ((stat(name, &fromsb) == 0) &&
    (fromsb.st_mtime > tosb.st_mtime))) {
  (void) (S_ISDIR(tosb.st_mode) ? rmdir : unlink)(toname);
  exists = 0;
     }
     if (!exists && symlink(name, toname) < 0)
  fail(""cannot make symbolic link %s"", toname);
#ifdef HAVE_LCHOWN
     if ((owner || group) && lchown(toname, uid, gid) < 0)
  fail(""cannot change owner of %s"", toname);
#endif

     if (linkname) {
  free(linkname);
  linkname = 0;
     }
 } else {
     /* Copy from name to toname, which might be the same file. */
      if( stat(name, &sb) == 0 && S_IFDIR & sb.st_mode )
      {
        /* then is directory: must explicitly create destination dir  */
        /*  and manually copy files over                              */
        copydir( name, todir, mode, group, owner, dotimes, uid, gid );
      }
      else
      {
        copyfile(name, toname, mode, group, owner, dotimes, uid, gid);
      }
    }

 free(toname);
    }

    free(cwd);
    free(todir);
    return 0;
}

*****
copydir: NG
original : (ua.((free + 0);(0 + free);free;free;free))
rewritten : (ua.((free + 0);(0 + free);free;free;free))

static void
copydir( char *from, char *to, mode_t mode, char *group, char *owner,
         int dotimes, uid_t uid, gid_t gid)
{
  int i;
  DIR *dir;
  struct dirent *ep;
  struct stat sb;
  char *base, *destdir, *direntry, *destentry;

  base = xbasename(from);

  /* create destination directory */
  destdir = xmalloc((unsigned int)(strlen(to) + 1 + strlen(base) + 1));
  sprintf(destdir, ""%s%s%s"", to, _DIRECTORY_SEPARATOR, base);
  if (mkdirs(destdir, mode) != 0) {
    fail(""cannot make directory %s\n"", destdir);
    free(destdir);
    return;
  }

  if (!(dir = opendir(from))) {
    fail(""cannot open directory %s\n"", from);
    free(destdir);
    return;
  }

  direntry = xmalloc((unsigned int)PATH_MAX);
  destentry = xmalloc((unsigned int)PATH_MAX);

  while ((ep = readdir(dir)))
  {
    if (strcmp(ep->d_name, ""."") == 0 || strcmp(ep->d_name, "".."") == 0)
      continue;

    sprintf(direntry, ""%s/%s"", from, ep->d_name);
    sprintf(destentry, ""%s%s%s"", destdir, _DIRECTORY_SEPARATOR, ep->d_name);

    if (stat(direntry, &sb) == 0 && S_ISDIR(sb.st_mode))
      copydir( direntry, destdir, mode, group, owner, dotimes, uid, gid );
    else
      copyfile( direntry, destentry, mode, group, owner, dotimes, uid, gid );
  }

  free(destdir);
  free(direntry);
  free(destentry);
  closedir(dir);
}

*****
https://github.com/APE-Project/APE_Server/blob/master/src/raw.c

****
destroy_raw_pool:  NG
original : (ua.(((free;free) + 0) + 0);((free + 0) + 0);a);(free + 0)
rewritten : (ua.(((free;free) + 0) + 0);((free + 0) + 0);a);free

void destroy_raw_pool(struct _raw_pool *ptr)
{
 struct _raw_pool *pool = ptr, *tpool = NULL;

 while (pool != NULL) {
  if (pool->raw != NULL) {
   free_raw(pool->raw);
  }
  if (pool->start) {
   if (tpool != NULL) {
    free(tpool);
   }
   tpool = pool;
  }
  pool = pool->next;
 }
 if (tpool != NULL) {
  free(tpool);
 }
}




****
free_raw:  NG
original : ((free;free;) + 0)
rewritten : ((free;free) + 0)

int free_raw(RAW *fraw)
{
 if (--(fraw->refcount) <= 0) {
  free(fraw->data);
  free(fraw);

  return 0;
 }
 return fraw->refcount;
}


******
https://github.com/dinhviethoa/libetpan/blob/master/src/data-types/carray.c

****
carray_free:
original :  free;free
rewritten  :  free;free

******

carray_new:     NG
original :  malloc;malloc;(free + 0)
rewritten :  malloc;malloc;(free + 0)


LIBETPAN_EXPORT
carray * carray_new(unsigned int initsize) {
  carray * array;

  array = (carray *) malloc(sizeof(carray));
  if (!array) return NULL;

  if (initsize < MIN_ARRAY_SIZE)
    initsize = MIN_ARRAY_SIZE;

  array->len = 0;
  array->max = initsize;
  array->array = (void **) malloc(sizeof(void *) * initsize);
  if (!array->array) {
    free(array);
    return NULL;
  }
  return array;
}


****
  https://github.com/dinhviethoa/libetpan/blob/master/src/data-types/chash.c

  chash_set:     NG
original : (ua.(((0 + ((malloc;free) + 0)) + 0) + 0);a);malloc;(malloc + 0);(malloc + 0);(free + 0);free
rewritten : (ua.(((0 + ((malloc;free) + 0)) + 0) + 0);a);malloc;(malloc + 0);(malloc + 0);(free + 0);free

LIBETPAN_EXPORT int chash_set(chash * hash,
       chashdatum * key,
       chashdatum * value,
       chashdatum * oldvalue)
{
  unsigned int func, indx;
  chashiter * iter, * cell;
  int r;

  if (hash->count > hash->size * CHASH_MAXDEPTH) {
    r = chash_resize(hash, (hash->count / CHASH_MAXDEPTH) * 2 + 1);
    if (r < 0)
      goto err;
  }

  func = chash_func(key->data, key->len);
  indx = func % hash->size;

  /* look for the key in existing cells */
  iter = hash->cells[indx];
  while (iter) {
    if (iter->key.len == key->len && iter->func == func
 && !memcmp(iter->key.data, key->data, key->len)) {
      /* found, replacing entry */
      if (hash->copyvalue) {
 char * data;

 data = chash_dup(value->data, value->len);
 if (data == NULL)
   goto err;

 free(iter->value.data);
 iter->value.data = data;
 iter->value.len = value->len;
      } else {
 if (oldvalue != NULL) {
   oldvalue->data = iter->value.data;
   oldvalue->len = iter->value.len;
 }
 iter->value.data = value->data;
 iter->value.len = value->len;
      }
      if (!hash->copykey)
 iter->key.data = key->data;

      if (oldvalue != NULL) {
 oldvalue->data = value->data;
 oldvalue->len = value->len;
      }

      return 0;
    }
    iter = iter->next;
  }

  if (oldvalue != NULL) {
    oldvalue->data = NULL;
    oldvalue->len = 0;
  }

  /* not found, adding entry */
  cell = (struct chashcell *) malloc(sizeof(struct chashcell));
  if (cell == NULL)
    goto err;

  if (hash->copykey) {
    cell->key.data = chash_dup(key->data, key->len);
    if (cell->key.data == NULL)
      goto free;
  }
  else
    cell->key.data = key->data;

  cell->key.len = key->len;
  if (hash->copyvalue) {
    cell->value.data = chash_dup(value->data, value->len);
    if (cell->value.data == NULL)
      goto free_key_data;
  }
  else
    cell->value.data = value->data;

  cell->value.len = value->len;
  cell->func = func;
  cell->next = hash->cells[indx];
  hash->cells[indx] = cell;
  hash->count++;

  return 0;

 free_key_data:
  if (hash->copykey)
    free(cell->key.data);
 free:
  free(cell);
 err:
  return -1;


****
chash_new:      NG
original : malloc;(free + 0)
rewritten : malloc;(free + 0)

LIBETPAN_EXPORT chash * chash_new(unsigned int size, int flags)
{
  chash * h;

  h = (chash *) malloc(sizeof(chash));
  if (h == NULL)
    return NULL;

  if (size < CHASH_DEFAULTSIZE)
    size = CHASH_DEFAULTSIZE;

  h->count = 0;
  h->cells = (struct chashcell **) calloc(size, sizeof(struct chashcell *));
  if (h->cells == NULL) {
    free(h);
    return NULL;
  }
  h->size = size;
  h->copykey = flags & CHASH_COPYKEY;
  h->copyvalue = flags & CHASH_COPYVALUE;

  return h;
}

*****
