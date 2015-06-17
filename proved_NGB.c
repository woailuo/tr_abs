--------------------------------------------------------------------------------------------------------------
https://github.com/luna/luna/blob/master/deps/linenoise/linenoise.c


********
linenoiseHistoryLoad:                  NGB
original :    (ua.(malloc + 0);(free + 0);a)
rewritten:   (ua.(malloc + 0);(free + 0);a)

int linenoiseHistoryLoad(char *filename) {
    FILE *fp = fopen(filename,""r"");
    char buf[LINENOISE_MAX_LINE];

    if (fp == NULL) return -1;

    while (fgets(buf,LINENOISE_MAX_LINE,fp) != NULL) {
        char *p;

        p = strchr(buf,'\r');
        if (!p) p = strchr(buf,'\n');
        if (p) *p = '\0';
        linenoiseHistoryAdd(buf);
    }
    fclose(fp);
    return 0;
}

***************

linenoise:     NGB
original :   (0 + ((ua.(((0 + (ua.((ua.free;a);(free + 0) + 0);a));(ua.free;a);(free + 0) + 0) + 0);(free + (0 + (free + 0)) + (0 + (0 + (0 + (0 + ((0 + ((free + 0) + 0)) + 0))))) + 0);a) + 0))
rewritten:  (0 + ((ua.((((0 + (ua.(((ua.free;a);free) + 0);a));(ua.free;a);free) + 0) + 0);(free + (0 + (free + 0)) + (0 + (0 + (0 + (0 + ((0 + ((free + 0) + 0)) + 0))))) + 0);a) + 0))

char *linenoise(const char *prompt) {
    char buf[LINENOISE_MAX_LINE];
    int count;

    if (isUnsupportedTerm()) {
        size_t len;

        printf(""%s"",prompt);
        fflush(stdout);
        if (fgets(buf,LINENOISE_MAX_LINE,stdin) == NULL) return NULL;
        len = strlen(buf);
        while(len && (buf[len-1] == '\n' || buf[len-1] == '\r')) {
            len--;
            buf[len] = '\0';
        }
        return strdup(buf);
    } else {
        count = linenoiseRaw(buf,LINENOISE_MAX_LINE,prompt);
        if (count == -1) return NULL;
        return strdup(buf);
    }
}

***********

linenoiseRaw:    NGB
original:  ((ua.(((0 + (ua.((ua.free;a);(free + 0) + 0);a));(ua.free;a);(free + 0) + 0) + 0);(free + (0 + (free + 0)) + (0 + (0 + (0 + (0 + ((0 + ((free + 0) + 0)) + 0))))) + 0);a) + 0)
rewritten:   ((ua.((((0 + (ua.(((ua.free;a);free) + 0);a));(ua.free;a);free) + 0) + 0);(free + (0 + (free + 0)) + (0 + (0 + (0 + (0 + ((0 + ((free + 0) + 0)) + 0))))) + 0);a) + 0)

static int linenoiseRaw(char *buf, size_t buflen, const char *prompt) {
    int fd = STDIN_FILENO;
    int count;

    if (buflen == 0) {
        errno = EINVAL;
        return -1;
    }
    if (!isatty(STDIN_FILENO)) {
        if (fgets(buf, buflen, stdin) == NULL) return -1;
        count = strlen(buf);
        if (count && buf[count-1] == '\n') {
            count--;
            buf[count] = '\0';
        }
    } else {
        if (enableRawMode(fd) == -1) return -1;
        count = linenoisePrompt(fd, buf, buflen, prompt);
        disableRawMode(fd);
        printf(""\n"");
    }
    return count;
}

********

completeLine:          NGB
original :  (0 + (ua.((ua.free;a);(free + 0) + 0);a));(ua.free;a);(free + 0)
rewritten:  (0 + (ua.(((ua.free;a);free) + 0);a));(ua.free;a);free

static int completeLine(int fd, const char *prompt, char *buf, size_t buflen, size_t *len, size_t *pos, size_t cols) {
    linenoiseCompletions lc = { 0, NULL };
    int nread, nwritten;
    char c = 0;

    completionCallback(buf,&lc);
    if (lc.len == 0) {
        beep();
    } else {
        size_t stop = 0, i = 0;
        size_t clen;

        while(!stop) {
            /* Show completion or original buffer */
            if (i < lc.len) {
                clen = strlen(lc.cvec[i]);
                refreshLine(fd,prompt,lc.cvec[i],clen,clen,cols);
            } else {
                refreshLine(fd,prompt,buf,*len,*pos,cols);
            }

            nread = read(fd,&c,1);
            if (nread <= 0) {
                freeCompletions(&lc);
                return -1;
            }

            switch(c) {
                case 9: /* tab */
                    i = (i+1) % (lc.len+1);
                    if (i == lc.len) beep();
                    break;
                case 27: /* escape */
                    /* Re-show original buffer */
                    if (i < lc.len) {
                        refreshLine(fd,prompt,buf,*len,*pos,cols);
                    }
                    stop = 1;
                    break;
                default:
                    /* Update buffer and return */
                    if (i < lc.len) {
                        nwritten = snprintf(buf,buflen,""%s"",lc.cvec[i]);
                        *len = *pos = nwritten;
                    }
                    stop = 1;
                    break;
            }
        }
    }

    freeCompletions(&lc);
    return c; /* Return last read character */
}

*****

---------------------------------------------------------------------------------------------------------------
https://github.com/riolet/nope.c/blob/master/nope.c

*********
shutdown_connection:   NGB
original :  ((free;free;free;free) + 0)
rewritten:  ((free;free;free;free) + 0)

void shutdown_connection(FdData * fds, int i, ssize_t nbytes, fd_set * pMaster)
{
    /* got error or connection closed by client */
    if (nbytes == 0) {
        /* connection closed */
        dbgprintf(""selectserver: socket %d hung up\n"", i);
    } else {
        perror(""recv"");
    }
    if (fds[i].state != STATE_PRE_REQUEST)
        free_fd_data(&fds[i]);
    fds[i].state = STATE_PRE_REQUEST;

    FD_CLR(i, pMaster);         // remove from master set

    close(i);
}

*******

freeHeaders:	(ua.free;a);free	(ua.free;a);free
free_fd_data:	free;free;free;free	free;free;free;free

*******

********
select_loop:   NGB
original :  (ua.(ua.((0 + (ua.malloc;a);(ua.malloc;a);(ua.malloc;a);(ua.malloc;a);(ua.malloc;a)) + 0);(((free;free;free;free) + 0) + 0);((ua.(0 + (0 + (malloc + 0)));a) + 0);(((free;free;free;free) + 0) + 0);a);a)
rewritten:  (ua.(ua.((0 + (ua.malloc;a);(ua.malloc;a);(ua.malloc;a);(ua.malloc;a);(ua.malloc;a)) + 0);(((free;free;free;free) + 0) + 0);((ua.(0 + (0 + (malloc + 0)));a) + 0);(((free;free;free;free) + 0) + 0);a);a)

void select_loop(int listenfd)
{

    /* Common vars */

    char socket_pair_buffer[2];
    int nbytes;

    char remote_ip[INET6_ADDRSTRLEN];

    int fd, fdmax;
    int done = 0;

#ifndef NOPE_MAX_CON_CONS
    FdData fdDataList[MAX_NO_FDS];
#else
    FdData *fdDataList;
    LOG_ERROR_ON_NULL(fdDataList =
                      malloc(sizeof(FdData) * MAX_NO_FDS),
                      ""Can't malloc() on fdDataList"");
#endif

    struct timeval tv;
    int poll_timeout = POLL_TIMEOUT;
    tv.tv_sec = 0;
    tv.tv_usec = POLL_TIMEOUT * 1000;

    /* keep track of the biggest file descriptor */
    fdmax = listenfd;           /* so far, it's this one */

    for (fd = 0; fd < fdmax; fd++) {
        fdDataList[fd].state = STATE_PRE_REQUEST;
    }
#ifdef NOPE_EPOLL

    int eventfd;
    struct epoll_event event;
    struct epoll_event *events;

    eventfd = epoll_create(1234);       /*Number is ignored */

    if (eventfd == -1) {
        perror(""epoll_create"");
        return;
    }

    event.data.fd = listenfd;
    event.events = EPOLLIN | EPOLLET;

    if (epoll_ctl(eventfd, EPOLL_CTL_ADD, listenfd, &event)) {
        perror(""epoll_ctl"");
        return;
    }
#ifdef NOPE_THREADS
    /* Socket Pair */
    event.data.fd = socketpair_fd[1];
    event.events = EPOLLIN | EPOLLET;

    if (epoll_ctl(eventfd, EPOLL_CTL_ADD, socketpair_fd[1], &event)) {
        perror(""epoll_ctl_socketpair"");
        return;
    }
#endif

    events = calloc(MAX_EVENTS, sizeof event);
    /* Epoll main loop */
    while (1) {

#ifdef NOPE_THREADS
        cleaner_thread();       /*Run the thread clearer */
#endif
        int n, e;
        dbgprintf(KCYN ""Waiting for events \n"" KNRM);
        n = epoll_wait(eventfd, events, MAX_EVENTS, poll_timeout);
        dbgprintf(KCYN ""Detected %d events \n"" KNRM, n);
        for (e = 0; e < n; e++) {
            if ((events[e].events & EPOLLERR) ||
                (events[e].events & EPOLLHUP) || (!(events[e].events & EPOLLIN))) {
                fprintf(stderr, ""epoll error detected in line %d\n"", __LINE__);
                close(events[e].data.fd);
                continue;
            }

            else if (listenfd == events[e].data.fd) {
                while (1) {
                    struct sockaddr in_addr;
                    socklen_t in_len;
                    int newfd;
                    char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];

                    in_len = sizeof in_addr;

                    newfd = accept(listenfd, &in_addr, &in_len);

                    if (newfd == -1) {
                        if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
                            /* We have processed all incoming  connections. */
                            break;
                        } else {
                            perror(""accept"");
                            break;
                        }
                    } else if (newfd >= MAX_NO_FDS) {
                        /* Process some events before accepting more */
                        fprintf(stderr, ""Reached MAX_NO_FDS at %d\n"", newfd);
                        break;
                    }

                    if (getnameinfo(&in_addr, in_len,
                                    hbuf, sizeof hbuf,
                                    sbuf, sizeof sbuf,
                                    NI_NUMERICHOST | NI_NUMERICSERV) == 0) {

                        /*dbgprintf(""accept()ed connection on  %d (host=%s, port=%s)\n"",
                           newfd, hbuf, sbuf); */

                        fdDataList[newfd].state = STATE_PRE_REQUEST;
                        new_fd_data(&fdDataList[newfd]);
                    }

                    /* Make the incoming socket non-blocking and add it to the list of fds to monitor. */
                    if (FCNTL_NONBLOCK(newfd) < 0) {
                        perror(""fcntl"");
                        return;
                    }

                    event.data.fd = newfd;
                    event.events = EPOLLIN | EPOLLET;
                    if (epoll_ctl(eventfd, EPOLL_CTL_ADD, newfd, &event) < 0) {
                        perror(""epoll_ctl"");
                        return;
                    }
                }
                continue;
            }
#ifdef  NOPE_THREADS
            else if (socketpair_fd[1] == events[e].data.fd) {
                nbytes = read(events[e].data.fd, socket_pair_buffer, 1);
                dbgprintf(KCYN ""SocketPair Read %d : %d\n"" KCYN, events[e].data.fd,
                          nbytes);
                if (nbytes == -1) {
                    if (errno != EAGAIN) {      /* EAGAINs we have read all data */
                        perror(""read"");
                    }
                }
            }
#endif
            else {
                fd = events[e].data.fd;
                while (1) {
                    nbytes =
                        read(fd, fdDataList[fd].readBuffer + fdDataList[fd].readBufferIdx,
                             MAX_REQUEST_SIZE - fdDataList[fd].readBufferLen);
                    dbgprintf(KCYN ""Read %d : %d\n"" KCYN, fd, nbytes);
                    if (nbytes == -1) {
                        if (errno != EAGAIN) {  /* EAGAINs we have read all data */
                            perror(""read"");
                            done = true;
                        }
                        break;
                    } else if (nbytes == 0) {
                        done = true;
                        break;
                    }
                    if ((done = state_machine(fdDataList, fd, nbytes, NULL))) {
                        break;
                    }
                }

                if (done) {
                    clear_connection_baggage(fdDataList, fd, NULL);
                }

            }
        }
    }
#else
    /* Select stuff
     * Thank you Brian ""Beej Jorgensen"" Hall */
    fd_set master;              // pMaster file descriptor list
    fd_set read_fds;            // temp file descriptor list for select()

    FD_ZERO(&master);           /* clear the pMaster and temp sets */
    FD_ZERO(&read_fds);

    /* add the listener to the master set */
    FD_SET(listenfd, &master);

    /* Select main loop */
    while (1) {

#ifdef NOPE_THREADS
        cleaner_thread();       /*Run the thread clearer */
#endif

        read_fds = master;      /* copy it */

        dbgprintf(KRED ""Select blocking\n"" KNRM);
        if (select(fdmax + 1, &read_fds, NULL, NULL, NULL) == -1) {
            perror(""select"");
            exit(4);
        }
        dbgprintf(KRED ""Select blocked\n"" KNRM);
        /* run through the existing connections looking for data to read */
        for (fd = 0; fd <= fdmax; fd++) {
            if (!FD_ISSET(fd, &read_fds))       // we got one!!
                continue;
            if (fd == listenfd) {
                accept_connection(fdDataList, listenfd, remote_ip, &fdmax, &master);
                break;
            }
            nbytes =
                recv(fd, fdDataList[fd].readBuffer + fdDataList[fd].readBufferIdx,
                     MAX_REQUEST_SIZE - fdDataList[fd].readBufferLen, 0);
            /* read failure */
            if (nbytes <= 0) {
                shutdown_connection(fdDataList, fd, nbytes, &master);
                break;
            }

            /* State Machine */
            done = state_machine(fdDataList, fd, nbytes, &master);
            if (done) {
                clear_connection_baggage(fdDataList, fd, &master);
            }
        }                       // END looping through file descriptors
    }                           // END for(;;)--and you thought it would never end!
#endif
    return;
}


---------------------------------------------------------------------------------------------------------
https://github.com/orangeduck/BuildYourOwnLisp/blob/master/src/mpc.c

*******

  mpcf_fold_ast:     NGB
original:   malloc;malloc;malloc;(ua.(((free;free;free;free) + 0) + 0);a)
rewritten:  malloc;malloc;malloc;(ua.(((free;free;free;free) + 0) + 0);a)

mpc_val_t *mpcf_fold_ast(int n, mpc_val_t **xs) {

  int i, j;
  mpc_ast_t** as = (mpc_ast_t**)xs;
  mpc_ast_t *r;

  if (n == 0) { return NULL; }
  if (n == 1) { return xs[0]; }
  if (n == 2 && xs[1] == NULL) { return xs[0]; }
  if (n == 2 && xs[0] == NULL) { return xs[1]; }

  r = mpc_ast_new("">"", """");

  for (i = 0; i < n; i++) {

    if (as[i] == NULL) { continue; }

    if (as[i] && as[i]->children_num > 0) {

      for (j = 0; j < as[i]->children_num; j++) {
        mpc_ast_add_child(r, as[i]->children[j]);
      }

      mpc_ast_delete_no_children(as[i]);

    } else if (as[i] && as[i]->children_num == 0) {
      mpc_ast_add_child(r, as[i]);
    }

  }

  if (r->children_num) {
    r->state = r->children[0]->state;
  }

  return r;
}



*********
mpcf_trd_free:     NGB
original :  (ua.(free + 0);a)
rewritten:  (ua.(free + 0);a)

mpc_val_t *mpcf_trd_free(int n, mpc_val_t **xs) { return mpcf_nth_free(n, xs, 2); }

********
mpcf_snd_free:    NGB
original :  (ua.(free + 0);a)
rewritten: (ua.(free + 0);a)

mpc_val_t *mpcf_snd_free(int n, mpc_val_t **xs) { return mpcf_nth_free(n, xs, 1); }

*******
mpcf_fst_free:    NGB
original : (ua.(free + 0);a)
rewritten: (ua.(free + 0);a)

mpc_val_t *mpcf_fst_free(int n, mpc_val_t **xs) { return mpcf_nth_free(n, xs, 0); }

******

  *****
mpc_cleanup:   NGB
original:  malloc;(ua.(ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0)));a);(ua.((((ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0))) + 0);free;free) + (ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0))));a);free
rewritten:  malloc;(ua.(ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0)));a);(ua.((((ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0))) + 0);free;free) + (ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0))));a);free

void mpc_cleanup(int n, ...) {
  int i;
  mpc_parser_t **list = malloc(sizeof(mpc_parser_t*) * n);

  va_list va;
  va_start(va, n);
  for (i = 0; i < n; i++) { list[i] = va_arg(va, mpc_parser_t*); }
  for (i = 0; i < n; i++) { mpc_undefine(list[i]); }   /*  B here */
  for (i = 0; i < n; i++) { mpc_delete(list[i]); }     /*   B here */
  va_end(va);

  free(list);
}


 ****


mpc_undefine:  NGB
original:  (ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0)))
rewritten: (ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0)))

mpc_parser_t *mpc_undefine(mpc_parser_t *p) {
  mpc_undefine_unretained(p, 1);    /*   B here */
  p->type = MPC_TYPE_UNDEFINED;
  return p;
}

******
mpc_soft_delete:   NGB
original : (ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0)))
rewritten: (ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0)))

static void mpc_soft_delete(mpc_val_t *x) {
  mpc_undefine_unretained(x, 0);   /*   B here */
}

*****

mpc_delete:  NGB
original:  ((((ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0))) + 0);free;free) + (ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0))))
rewritten:((((ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0))) + 0);free;free) + (ua.((free + free + (a;free) + free + (free;free) + 0);((free;free) + 0))))

void mpc_delete(mpc_parser_t *p) {
  if (p->retained) {

    if (p->type != MPC_TYPE_UNDEFINED) {
      mpc_undefine_unretained(p, 0);         /*  B here  */
    }

    free(p->name);
    free(p);

  } else {
    mpc_undefine_unretained(p, 0);    /*  B here  */
  }
}


****
mpc_input_string:  NGB
original:  (ua.((malloc + 0) + 0);(free + ((free + 0) + 0));a);((free + 0) + 0);;malloc
rewritten: (ua.(malloc + 0);(free + ((free + 0) + 0));a);((free + 0) + 0);;malloc

static int mpc_input_string(mpc_input_t *i, const char *c, char **o) {

  char *co = NULL;
  const char *x = c;

  mpc_input_mark(i);
  while (*x) {
    if (mpc_input_char(i, *x, &co)) {
      free(co);
    } else {
      mpc_input_rewind(i);    /*  B here */
      return 0;
    }
    x++;
  }
  mpc_input_unmark(i);   /*   B here  */

  *o = malloc(strlen(c) + 1);
  strcpy(*o, c);
  return 1;
}

******

mpc_input_rewind:    NGB
original : ((free + 0) + 0)
rewritten:  ((free + 0) + 0)

static void mpc_input_rewind(mpc_input_t *i) {

  if (i->backtrack < 1) { return; }

  i->state = i->marks[i->marks_num-1];
  i->last  = i->lasts[i->marks_num-1];

  if (i->type == MPC_INPUT_FILE) {
    fseek(i->file, i->state.pos, SEEK_SET);
  }

  mpc_input_unmark(i);
}

********

---------------------------------------------------------------------------------------------------------
https://github.com/orangeduck/BuildYourOwnLisp/blob/master/src/functions.c

 *******

lval_take:     NGB
original: (ua.((free + free + free + 0);free))
rewritten: (ua.((free + free + free + 0);free))

lval* lval_take(lval* v, int i) {
  lval* x = lval_pop(v, i);
  lval_del(v);    /*  B here */
  return x;
}

 --------------------------------------------------------------------------------------------------------------
https://github.com/orangeduck/BuildYourOwnLisp/blob/master/src/q_expressions.c

 ******
mkd_generatecss:    NGB
original:  ((((0 + (0 + malloc));((0 + (0 + malloc)) + (free + 0)) + 0) + 0) + 0);(free + 0)
rewritten: ((((0 + (0 + malloc));((0 + (0 + malloc)) + (free + 0)) + 0) + 0) + 0);free

int mkd_generatecss(Document *d, FILE *f)
{
    char *res;
    int written = EOF, size = mkd_css(d, &res);  /*   B here */

    if ( size > 0 )
 written = fwrite(res, 1, size, f);
    if ( res )
 free(res);
    return (written == size) ? size : EOF;
}


 ------------------------------------------------------------------------------------------------------------------------
https://github.com/APE-Project/APE_Server/blob/master/deps/js/src/ctypes/libffi/src/dlmalloc.c

 ******

pvalloc:   NGB
original : (malloc + 0);(0 + malloc;((free + 0);(free + 0) + 0))
rewritten: (malloc + 0);(0 + malloc;((free + 0);(free + 0) + 0))

void* dlpvalloc(size_t bytes) {
  size_t pagesz;
  init_mparams();
  pagesz = mparams.page_size;
  return dlmemalign(pagesz, (bytes + pagesz - SIZE_T_ONE) & ~(pagesz - SIZE_T_ONE));
 }

******

valloc:   NGB
original : (malloc + 0);(0 + malloc;((free + 0);(free + 0) + 0))
rewritten:(malloc + 0);(0 + malloc;((free + 0);(free + 0) + 0))

void* dlvalloc(size_t bytes) {
  size_t pagesz;
  init_mparams();
  pagesz = mparams.page_size;
  return dlmemalign(pagesz, bytes);
 }

******

memalign:   NGB
original : (malloc + 0);(0 + malloc;((free + 0);(free + 0) + 0))
rewritten:(malloc + 0);(0 + malloc;((free + 0);(free + 0) + 0))

void* dlmemalign(size_t alignment, size_t bytes) {
  return internal_memalign(gm, alignment, bytes);   /*  B here */
}

 ****

*******

internal_memalign:   NGB
original:  (malloc + 0);(0 + malloc;((free + 0);(free + 0) + 0))
rewritten:  (malloc + 0);(0 + malloc;((free + 0);(free + 0) + 0))

static void* internal_memalign(mstate m, size_t alignment, size_t bytes) {
   if (alignment <= MALLOC_ALIGNMENT) /* Can just use malloc */
     return internal_malloc(m, bytes);
   if (alignment < MIN_CHUNK_SIZE) /* must be at least a minimum chunk size */
     alignment = MIN_CHUNK_SIZE;
   if ((alignment & (alignment-SIZE_T_ONE)) != 0) {/* Ensure a power of 2 */
     size_t a = MALLOC_ALIGNMENT << 1;
     while (a < alignment) a <<= 1;
     alignment = a;
   }
   if (bytes >= MAX_REQUEST - alignment) {
     if (m != 0) { /* Test isn't needed but avoids compiler warning */
       MALLOC_FAILURE_ACTION;
     }
   }
   else {
     size_t nb = request2size(bytes);
     size_t req = nb + alignment + MIN_CHUNK_SIZE - CHUNK_OVERHEAD;
     char* mem = (char*)internal_malloc(m, req);
     if (mem != 0) {
       void* leader = 0;
       void* trailer = 0;
       mchunkptr p = mem2chunk(mem);
       if (PREACTION(m)) return 0;
       if ((((size_t)(mem)) % alignment) != 0) { /* misaligned */
         /*
           Find an aligned spot inside chunk. Since we need to give
           back leading space in a chunk of at least MIN_CHUNK_SIZE, if
           the first calculation places us at a spot with less than
           MIN_CHUNK_SIZE leader, we can move to the next aligned spot.
           We've allocated enough total room so that this is always
           possible.
         */
         char* br = (char*)mem2chunk((size_t)(((size_t)(mem +
                                                        alignment -
                                                        SIZE_T_ONE)) &
                                              -alignment));
         char* pos = ((size_t)(br - (char*)(p)) >= MIN_CHUNK_SIZE)?
           br : br+alignment;
         mchunkptr newp = (mchunkptr)pos;
         size_t leadsize = pos - (char*)(p);
         size_t newsize = chunksize(p) - leadsize;
         if (is_mmapped(p)) { /* For mmapped chunks, just adjust offset */
           newp->prev_foot = p->prev_foot + leadsize;
           newp->head = (newsize|CINUSE_BIT);
         }
         else { /* Otherwise, give back leader, use the rest */
           set_inuse(m, newp, newsize);
           set_inuse(m, p, leadsize);
           leader = chunk2mem(p);
         }
         p = newp;
       }
       /* Give back spare room at the end */
       if (!is_mmapped(p)) {
         size_t size = chunksize(p);
         if (size > nb + MIN_CHUNK_SIZE) {
           size_t remainder_size = size - nb;
           mchunkptr remainder = chunk_plus_offset(p, nb);
           set_inuse(m, p, nb);
           set_inuse(m, remainder, remainder_size);
           trailer = chunk2mem(remainder);
         }
       }
       assert (chunksize(p) >= nb);
       assert((((size_t)(chunk2mem(p))) % alignment) == 0);
       check_inuse_chunk(m, p);
       POSTACTION(m);
       if (leader != 0) {
         internal_free(m, leader);
       }
       if (trailer != 0) {
         internal_free(m, trailer);
       }
       return chunk2mem(p);
     }
   }
   return 0;
 }

*****

*******

internal_realloc:   NGB
original : ((free + 0) + malloc;(free + 0))
rewritten: ((free + 0) + malloc;(free + 0))

  static void* internal_realloc(mstate m, void* oldmem, size_t bytes) {
  if (bytes >= MAX_REQUEST) {
    MALLOC_FAILURE_ACTION;
    return 0;
  }
  if (!PREACTION(m)) {
    mchunkptr oldp = mem2chunk(oldmem);
    size_t oldsize = chunksize(oldp);
    mchunkptr next = chunk_plus_offset(oldp, oldsize);
    mchunkptr newp = 0;
    void* extra = 0;
    /* Try to either shrink or extend into top. Else malloc-copy-free */
    if (RTCHECK(ok_address(m, oldp) && ok_cinuse(oldp) &&
                ok_next(oldp, next) && ok_pinuse(next))) {
      size_t nb = request2size(bytes);
      if (is_mmapped(oldp))
        newp = mmap_resize(m, oldp, nb);
      else if (oldsize >= nb) { /* already big enough */
        size_t rsize = oldsize - nb;
        newp = oldp;
        if (rsize >= MIN_CHUNK_SIZE) {
          mchunkptr remainder = chunk_plus_offset(newp, nb);
          set_inuse(m, newp, nb);
          set_inuse(m, remainder, rsize);
          extra = chunk2mem(remainder);
        }
      }
      else if (next == m->top && oldsize + m->topsize > nb) {
        /* Expand into top */
        size_t newsize = oldsize + m->topsize;
        size_t newtopsize = newsize - nb;
        mchunkptr newtop = chunk_plus_offset(oldp, nb);
        set_inuse(m, oldp, nb);
        newtop->head = newtopsize |PINUSE_BIT;
        m->top = newtop;
        m->topsize = newtopsize;
        newp = oldp;
      }
    }
    else {
      USAGE_ERROR_ACTION(m, oldmem);
      POSTACTION(m);
      return 0;
    }
    POSTACTION(m);
    if (newp != 0) {
      if (extra != 0) {
        internal_free(m, extra);
      }
      check_inuse_chunk(m, newp);
      return chunk2mem(newp);
    }
    else {
      void* newmem = internal_malloc(m, bytes);
      if (newmem != 0) {
        size_t oc = oldsize - overhead_for(oldp);
        memcpy(newmem, oldmem, (oc < bytes)? oc : bytes);
        internal_free(m, oldmem);
      }
      return newmem;
    }
  }
  return 0;
 }


---------------------------------------------------------------------------------------------------------
https://github.com/APE-Project/APE_Server/blob/master/deps/udns-0.0.9/dnsget.c

*****

main:  NGB
original : ((ua.(free + 0);a) + 0);(ua.malloc;malloc;(0 + (free;free));a)
rewritten: ((ua.(free + 0);a) + 0);(ua.malloc;malloc;(0 + (free;free));a)

int main(int argc, char **argv) {
  int i;
  int fd;
  fd_set fds;
  struct timeval tv;
  time_t now;
  char *ns[DNS_MAXSERV];
  int nns = 0;
  struct query *q;
  enum dns_type qtyp = 0;
  struct dns_ctx *nctx = NULL;

  if (!(progname = strrchr(argv[0], '/'))) progname = argv[0];
  else argv[0] = ++progname;

  if (argc <= 1)
    die(0, ""try `%s -h' for help"", progname);

  if (dns_init(NULL, 0) < 0 || !(nctx = dns_new(NULL)))
    die(errno, ""unable to initialize dns library"");
  /* we keep two dns contexts: one may be needed to resolve
   * nameservers if given as names, using default options.
   */

  while((i = getopt(argc, argv, ""vqt:c:an:o:h"")) != EOF) switch(i) {
  case 'v': ++verbose; break;
  case 'q': --verbose; break;
  case 't':
    if (optarg[0] == '*' && !optarg[1])
      i = DNS_T_ANY;
    else if ((i = dns_findtypename(optarg)) <= 0)
      die(0, ""unrecognized query type `%s'"", optarg);
    qtyp = i;
    break;
  case 'c':
    if (optarg[0] == '*' && !optarg[1])
      i = DNS_C_ANY;
    else if ((i = dns_findclassname(optarg)) < 0)
      die(0, ""unrecognized query class `%s'"", optarg);
    qcls = i;
    break;
  case 'a':
    qtyp = DNS_T_ANY;
    ++verbose;
    break;
  case 'n':
    if (nns >= DNS_MAXSERV)
      die(0, ""too many nameservers, %d max"", DNS_MAXSERV);
    ns[nns++] = optarg;
    break;
  case 'o':
    if (dns_set_opts(NULL, optarg) != 0)
      die(0, ""invalid option string: `%s'"", optarg);
    break;
  case 'h':
    printf(
""%s: simple DNS query tool (using udns version %s)\n""
""Usage: %s [options] domain-name...\n""
""where options are:\n""
"" -h - print this help and exit\n""
"" -v - be more verbose\n""
"" -q - be less verbose\n""
"" -t type - set query type (A, AAA, PTR etc)\n""
"" -c class - set query class (IN (default), CH, HS, *)\n""
"" -a - equivalent to -t ANY -v\n""
"" -n ns - use given nameserver(s) instead of default\n""
""  (may be specified multiple times)\n""
"" -o option:value - set resovler option (the same as setting $RES_OPTIONS):\n""
""  timeout:sec  - initial query timeout\n""
""  attempts:num - number of attempt to resovle a query\n""
""  ndots:num    - if name has more than num dots, lookup it before search\n""
""  port:num     - port number for queries instead of default 53\n""
""  udpbuf:num   - size of UDP buffer (use EDNS0 if >512)\n""
""  (may be specified more than once)\n""
      , progname, dns_version(), progname);
    return 0;
  default:
    die(0, ""try `%s -h' for help"", progname);
  }

  argc -= optind; argv += optind;
  if (!argc)
    die(0, ""no name(s) to query specified"");

  if (nns) {
    /* if nameservers given as names, resolve them.
     * We only allow IPv4 nameservers as names for now.
     * Ok, it is easy enouth to try both AAAA and A,
     * but the question is what to do by default.
     */
    struct sockaddr_in sin;
    int j, r = 0, opened = 0;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(dns_set_opt(NULL, DNS_OPT_PORT, -1));
    dns_add_serv(NULL, NULL);
    for(i = 0; i < nns; ++i) {
      if (dns_pton(AF_INET, ns[i], &sin.sin_addr) <= 0) {
        struct dns_rr_a4 *rr;
        if (!opened) {
          if (dns_open(nctx) < 0)
            die(errno, ""unable to initialize dns context"");
          opened = 1;
        }
        rr = dns_resolve_a4(nctx, ns[i], 0);
        if (!rr)
          die(0, ""unable to resolve nameserver %s: %s"",
              ns[i], dns_strerror(dns_status(nctx)));
        for(j = 0; j < rr->dnsa4_nrr; ++j) {
          sin.sin_addr = rr->dnsa4_addr[j];
          if ((r = dns_add_serv_s(NULL, (struct sockaddr *)&sin)) < 0)
            break;
        }
        free(rr);
      }
      else
        r = dns_add_serv_s(NULL, (struct sockaddr *)&sin);
      if (r < 0)
        die(errno, ""unable to add nameserver %s"",
             dns_xntop(AF_INET, &sin.sin_addr));
    }
  }
  dns_free(nctx);

  fd = dns_open(NULL);
  if (fd < 0)
    die(errno, ""unable to initialize dns context"");

  if (verbose > 1)
    dns_set_dbgfn(NULL, dbgcb);

  for (i = 0; i < argc; ++i) {
    char *name = argv[i];
    union {
      struct in_addr addr;
      struct in6_addr addr6;
    } a;
    unsigned char dn[DNS_MAXDN];
    enum dns_type l_qtyp = 0;
    int abs;
    if (dns_pton(AF_INET, name, &a.addr) > 0) {
      dns_a4todn(&a.addr, 0, dn, sizeof(dn));
      l_qtyp = DNS_T_PTR;
      abs = 1;
    }
#ifdef HAVE_IPv6
    else if (dns_pton(AF_INET6, name, &a.addr6) > 0) {
      dns_a6todn(&a.addr6, 0, dn, sizeof(dn));
      l_qtyp = DNS_T_PTR;
      abs = 1;
    }
#endif
    else if (!dns_ptodn(name, strlen(name), dn, sizeof(dn), &abs))
      die(0, ""invalid name `%s'\n"", name);
    else
      l_qtyp = DNS_T_A;
    if (qtyp) l_qtyp = qtyp;
    q = query_new(name, dn, l_qtyp);
    if (abs) abs = DNS_NOSRCH;
    if (!dns_submit_dn(NULL, dn, qcls, l_qtyp, abs, 0, dnscb, q))
      dnserror(q, dns_status(NULL));
  }

  FD_ZERO(&fds);
  now = 0;
  while((i = dns_timeouts(NULL, -1, now)) > 0) {
    FD_SET(fd, &fds);
    tv.tv_sec = i;
    tv.tv_usec = 0;
    i = select(fd+1, &fds, 0, 0, &tv);
    now = time(NULL);
    if (i > 0) dns_ioevent(NULL, now);
  }

  return errors ? 1 : notfound ? 100 : 0;
}

******

------------------------------------------------------------------------------------------------------------
https://github.com/APE-Project/APE_Server/blob/master/deps/js/src/editline/editline.c

******

last_argument:  NGB
original : malloc;(ua.(((((malloc;free) + 0) + 0) + 0) + 0);a);(((malloc;(free + 0) + 0) + 0) + ((malloc;(free + 0) + 0) + 0));(free + 0);free
rewritten:  malloc;(ua.(((((malloc;free) + 0) + 0) + 0) + 0);a);(((malloc;(free + 0) + 0) + 0) + ((malloc;(free + 0) + 0) + 0));(free + 0);free

STATIC STATUS  last_argument()
{
    CHAR **av;
    CHAR *p;
    STATUS s;
    int  ac;

    if (H.Size == 1 || (p = H.Lines[H.Size - 2]) == NULL)
 return ring_bell();

    if ((p = (CHAR *)strdup((char *)p)) == NULL)
 return CSstay;
    ac = argify(p, &av);

    if (Repeat != NO_ARG)
 s = Repeat < ac ? insert_string(av[Repeat]) : ring_bell();
    else
 s = ac ? insert_string(av[ac - 1]) : CSstay;

    if (ac)
 DISPOSE(av);
    DISPOSE(p);
    return s;
}

******

argify:
original : malloc;(ua.(((((malloc;free) + 0) + 0) + 0) + 0);a)
rewritten:  malloc;(ua.(((((malloc;free) + 0) + 0) + 0) + 0);a)


*****

yank:           NGB
original:   (((malloc;(free + 0) + 0) + 0) + 0)
rewritten :  ((malloc;(free + 0) + 0) + 0)

STATIC STATUS yank()
{
    if (Yanked && *Yanked)
 return insert_string(Yanked);
    return CSstay;
}



***

quote:          NGB
original : (0 + (((malloc;(free + 0) + 0) + ((malloc;(free + 0) + 0) + 0));malloc;(malloc;(free + 0) + 0);;free))
rewritten :  (0 + (((malloc;(free + 0) + 0) + ((malloc;(free + 0) + 0) + 0));malloc;(malloc;(free + 0) + 0);;free))

STATIC STATUS
quote()
{
    unsigned int c;

    return (int)(c = TTYget()) == EOF ? CSeof : insert_char((int)c);
}

******

add_history:   NGB
original : (0 + free)
rewritten   : (0 + free)

void add_history(p)
    char *p;
{
    if (p == NULL || *p == '\0')
 return;

#if defined(UNIQUE_HISTORY)
    if (H.Size && strcmp(p, (char *)H.Lines[H.Size - 1]) == 0)
        return;
#endif /* defined(UNIQUE_HISTORY) */
    hist_add((CHAR *)p);
}


****

*******
emacs:   NGB
original : (0 + (((malloc;(free + 0) + 0) + ((malloc;(free + 0) + 0) + 0));malloc;(malloc;(free + 0) + 0);;free))
rewritten : (0 + (((malloc;(free + 0) + 0) + ((malloc;(free + 0) + 0) + 0));malloc;(malloc;(free + 0) + 0);;free))

STATIC STATUS emacs(c)
    unsigned int c;
{
    STATUS  s;
    KEYMAP  *kp;

    if (rl_meta_chars && ISMETA(c)) {
 Pushed = 1;
 PushBack = UNMETA(c);
 return meta();
    }
    for (kp = Map; kp->Function; kp++)
 if (kp->Key == c)
     break;
    s = kp->Function ? (*kp->Function)() : insert_char((int)c);
    if (!Pushed)
 /* No pushback means no repeat count; hacky, but true. */
 Repeat = NO_ARG;
    return s;
}

******
*****

insert_char:  NGB
orginal : ((malloc;(free + 0) + 0) + ((malloc;(free + 0) + 0) + 0));malloc;(malloc;(free + 0) + 0);;free
rewritten:  ((malloc;(free + 0) + 0) + ((malloc;(free + 0) + 0) + 0));malloc;(malloc;(free + 0) + 0);;free

STATIC STATUS
insert_char(c)
    int  c;
{
    STATUS s;
    CHAR buff[2];
    CHAR *p;
    CHAR *q;
    int  i;

    if (Repeat == NO_ARG || Repeat < 2) {
 buff[0] = c;
 buff[1] = '\0';
 return insert_string(buff);
    }

    if ((p = NEW(CHAR, Repeat + 1)) == NULL)
 return CSstay;
    for (i = Repeat, q = p; --i >= 0; )
 *q++ = c;
    *q = '\0';
    Repeat = 0;
    s = insert_string(p);
    DISPOSE(p);
    return s;
}



*****
h_search:    NGB
original : (((free + 0) + 0) + 0);(malloc;(free + 0) + 0)
rewritten : (((free + 0) + 0) + 0);(malloc;(free + 0) + 0)

STATIC STATUS h_search()
{
    static int Searching;
    CONST char *old_prompt;
    CHAR *(*move)();
    CHAR *p;

    if (Searching)
 return ring_bell();
    Searching = 1;

    clear_line();
    old_prompt = Prompt;
    Prompt = ""Search: "";
    TTYputs((CONST CHAR *)Prompt);
    move = Repeat == NO_ARG ? prev_hist : next_hist;
    p = editinput();
    Prompt = old_prompt;
    Searching = 0;
    TTYputs((CONST CHAR *)Prompt);
    if (p == NULL && Signal > 0) {
 Signal = 0;
 clear_line();
 return redisplay();
    }
    p = search_hist(p, move);
    clear_line();
    if (p == NULL) {
 (void)ring_bell();
 return redisplay();
    }
    return do_insert_hist(p);
}

*****

*****

h_last:  NGB
original : (malloc;(free + 0) + 0)
rewritten : (malloc;(free + 0) + 0)

STATIC STATUS h_last()
{
    return do_insert_hist(H.Lines[H.Pos = H.Size - 1]);
}

*****

h_first:    NGB
original :  (malloc;(free + 0) + 0)
rewritten : (malloc;(free + 0) + 0)

STATIC STATUS h_first()
{
    return do_insert_hist(H.Lines[H.Pos = 0]);
}

*****

*****

h_prev:  NGB
original : (malloc;(free + 0) + 0)
rewritten : (malloc;(free + 0) + 0)

STATIC STATUS
h_prev()
{
    return do_hist(prev_hist);
}

******
h_next:   NGB
origianl : (malloc;(free + 0) + 0)
rewritten:  (malloc;(free + 0) + 0)

STATIC STATUS
h_next()
{
    return do_hist(next_hist);
}

******

do_hist:  NGB
original : (malloc;(free + 0) + 0)
rewritten : (malloc;(free + 0) + 0)

STATIC STATUS
do_hist(move)
    CHAR *(*move)();
{
    CHAR *p;
    int  i;

    i = 0;
    do {
 if ((p = (*move)()) == NULL)
     return ring_bell();
    } while (++i < Repeat);
    return do_insert_hist(p);
}

****

do_insert_hist:  NGB
original : (malloc;(free + 0) + 0)
rewritten : (malloc;(free + 0) + 0)

STATIC STATUS do_insert_hist(p)
    CHAR *p;
{
    if (p == NULL)
 return ring_bell();
    Point = 0;
    reposition();
    ceol();
    End = 0;
    return insert_string(p);
}

****


------------------------------------------------------------------------------------
https://github.com/APE-Project/APE_Server/blob/master/src/http.c

****
process_http:  NGB
original : (ua.(((0 + (0 + (ua.(((free + (free + 0)) + ((free + 0) + (free + 0))) + 0);a);(free + 0))) + 0)))
rewritten : (ua.(((0 + (0 + (ua.(((free + (free + 0)) + ((free + 0) + (free + 0))) + 0);a);(free + 0))) + 0)))

void process_http(ape_socket *co, acetables *g_ape)
{
 ape_buffer *buffer = &co->buffer_in;
 http_state *http = co->parser.data;
 ape_parser *parser = &co->parser;

 char *data = buffer->data;
 int pos, read, p = 0;

 if (buffer->length == 0 || parser->ready == 1 || http->error == 1) {
  return;
 }

 /* 0 will be erased by the next read()'ing loop */
 data[buffer->length] = '\0';

 data = &data[http->pos];

 if (*data == '\0') {
  return;
 }

 /* Update the address of http->data and http->uri if buffer->data has changed (realloc) */
 if (http->buffer_addr != NULL && buffer->data != http->buffer_addr) {
  if (http->data != NULL) http->data = &buffer->data[(void *)http->data - (void *)http->buffer_addr];
  if (http->uri != NULL) http->uri = &buffer->data[(void *)http->uri - (void *)http->buffer_addr];
  http->buffer_addr = buffer->data;
 }

 switch(http->step) {
  case 0:
   pos = seof(data, '\n');
   if (pos == -1) {
    return;
   }

   switch(*(unsigned int *)data) {
#ifdef _LITTLE_ENDIAN
    case 0x20544547: /* GET + space */
#endif
#ifdef _BIG_ENDIAN
    case 0x47455420: /* GET + space */
#endif
     http->type = HTTP_GET;
     p = 4;
     break;
#ifdef _LITTLE_ENDIAN
    case 0x54534F50: /* POST */
#endif
#ifdef _BIG_ENDIAN
    case 0x504F5354: /* POST */
#endif
     http->type = HTTP_POST;
     p = 5;
     break;
    default:
     ape_log(APE_INFO, __FILE__, __LINE__, g_ape, ""Invalid HTTP method in request: %s"", data);
     http->error = 1;
     shutdown(co->fd, 2);
     return;
   }

   if (data[p] != '/') {
    http->error = 1;
    shutdown(co->fd, 2);
    return;
   } else {
    int i = p;
    while (p++) {
     switch(data[p]) {
      case ' ':
       http->pos = pos;
       http->step = 1;
       http->uri = &data[i];
       http->buffer_addr = buffer->data;
       data[p] = '\0';
       process_http(co, g_ape);
       return;
      case '?':
       if (data[p+1] != ' ' && data[p+1] != '\r' && data[p+1] != '\n') {
        http->buffer_addr = buffer->data;
        http->data = &data[p+1];
       }
       break;
      case '\r':
      case '\n':
      case '\0':
       ape_log(APE_INFO, __FILE__, __LINE__, g_ape, ""Invalid line ending in request: %s"", data);
       http->error = 1;
       shutdown(co->fd, 2);
       return;
     }
    }
   }
   break;
  case 1:
   pos = seof(data, '\n');
   if (pos == -1) {

    return;
   }
   if (pos == 1 || (pos == 2 && *data == '\r')) {
    if (http->type == HTTP_GET) {
     /* Ok, at this point we have a blank line. Ready for GET */
     buffer->data[http->pos] = '\0';
     urldecode(http->uri);
     parser->onready(parser, g_ape);
     parser->ready = -1;
     buffer->length = 0;
     http->pos = 0;
     return;
    } else if (http->type == HTTP_GET_WS) { /* WebSockets handshake needs to read 8 bytes */
     //urldecode(http->uri);
     http->contentlength = 8;
     http->buffer_addr = buffer->data;
     http->data = &buffer->data[http->pos+(pos)];
     http->step = 2;
    } else {
     /* Content-Length is mandatory in case of POST */
     if (http->contentlength == 0) {
      http->error = 1;
      shutdown(co->fd, 2);
      return;
     } else {
      http->buffer_addr = buffer->data; // save the addr
      http->data = &buffer->data[http->pos+(pos)];
      http->step = 2;
     }
    }
   } else {
    struct _http_header_line *hl;

    if ((hl = parse_header_line(data)) != NULL) {
     hl->next = http->hlines;
     http->hlines = hl;
     if (strcasecmp(hl->key.val, ""host"") == 0) {
      http->host = hl->value.val;
     }
    }
    if (http->type == HTTP_POST) {
     /* looking for content-length instruction */
     if (pos <= 25 && strncasecmp(""content-length: "", data, 16) == 0) {
      int cl = atoi(&data[16]);

      /* Content-length can't be negative... */
      if (cl < 1 || cl > MAX_CONTENT_LENGTH) {
       http->error = 1;
       shutdown(co->fd, 2);
       return;
      }
      /* At this time we are ready to read ""cl"" bytes contents */
      http->contentlength = cl;

     }
    } else if (http->type == HTTP_GET) {
     if (strncasecmp(""Sec-WebSocket-Key1: "", data, 20) == 0) {
      http->type = HTTP_GET_WS;
     }
    }
   }
   http->pos += pos;
   process_http(co, g_ape);
   break;
  case 2:
   read = buffer->length - http->pos; // data length
   http->pos += read;
   http->read += read;

   if (http->read >= http->contentlength) {

    parser->ready = 1;
    urldecode(http->uri);
    /* no more than content-length */
    buffer->data[http->pos - (http->read - http->contentlength)] = '\0';

    parser->onready(parser, g_ape);
    parser->ready = -1;
    buffer->length = 0;
   }
   break;
  default:
   break;
 }
}

*****

--------------------------------------------------------------------------------------
https://github.com/APE-Project/APE_Server/blob/master/src/json.c

*****
*****
init_json_parser:  NGB
original : (ua.(0 + (ua.((ua.(free + 0);(free + 0);free;a))));a);(0 + (ua.((ua.(free + 0);(free + 0);free;a))))
rewritten : (ua.(0 + (ua.((ua.(free + 0);(free + 0);free;a))));a);(0 + (ua.((ua.(free + 0);(free + 0);free;a))))

json_item *init_json_parser(const char *json_string)
{
 const char *pRaw;
 JSON_config config;

 struct JSON_parser_struct* jc = NULL;

 json_context jcx = {0, 0, NULL, NULL};

 init_JSON_config(&config);

 config.depth  = 15;
 config.callback  = &json_callback;
 config.callback_ctx = &jcx;

 config.allow_comments = 0;
 config.handle_floats_manually = 0;

 jc = new_JSON_parser(&config);

 for (pRaw = json_string; (unsigned char)*pRaw; pRaw++) {
  if (!JSON_parser_char(jc, *pRaw)) {
   free_json_item(jcx.head);
      delete_JSON_parser(jc);
      return NULL;
  }
 }

 if (!JSON_parser_done(jc)) {
  free_json_item(jcx.head);
  delete_JSON_parser(jc);
  return NULL;
 }

 delete_JSON_parser(jc);

 return jcx.head;
}

******

------------------------------------------------------------------------------------------
https://github.com/APE-Project/APE_Server/blob/master/src/raw.c

****

send_raws:  NGB
original : (ua.((free;free) + 0);a)
rewritten  : (ua.((free;free) + 0);a)

int send_raws(subuser *user, acetables *g_ape)
{
 int finish = 1, state = 0;
 struct _raw_pool *pool;
 struct _transport_properties *properties;

 if (user->raw_pools.nraw == 0) {
  return 1;
 }

 PACK_TCP(user->client->fd); /* Activate TCP_CORK */

 properties = transport_get_properties(user->user->transport, g_ape);

 if (!user->headers.sent) {
  user->headers.sent = 1;

  switch(user->user->transport) {
   case TRANSPORT_XHRSTREAMING:
    finish &= http_send_headers(user->headers.content, HEADER_XHR, HEADER_XHR_LEN, user->client, g_ape);
    break;
   case TRANSPORT_SSE_LONGPOLLING:
    finish &= http_send_headers(user->headers.content, HEADER_SSE, HEADER_SSE_LEN, user->client, g_ape);
    break;
   case TRANSPORT_JSONP:
    finish &= http_send_headers(user->headers.content, HEADER_JSONP, HEADER_JSONP_LEN, user->client, g_ape);
   break;
   case TRANSPORT_WEBSOCKET:
   case TRANSPORT_WEBSOCKET_IETF:
    break;
   default:
    finish &= http_send_headers(user->headers.content, HEADER_DEFAULT, HEADER_DEFAULT_LEN, user->client, g_ape);
    break;
  }

 }

 if (properties != NULL && properties->padding.left.val != NULL) {
  finish &= sendbin(user->client->fd, properties->padding.left.val, properties->padding.left.len, 0, g_ape);
 }

 if (user->raw_pools.high.nraw) {
  pool = user->raw_pools.high.rawfoot->prev;
 } else {
  pool = user->raw_pools.low.rawhead;
  state = 1;
 }

 if (user->user->transport == TRANSPORT_WEBSOCKET_IETF) {
     websocket_state *websocket = user->client->parser.data;
     char payload_head[32] = { websocket->version == WS_IETF_06 ? 0x84 : 0x81 };

     int payload_size = raws_size(user); /* TODO: fragmentation? */
     int payload_length = 0;

     if (payload_size <= 125) {
         payload_head[1] = (unsigned char)payload_size & 0x7F;
         payload_length = 2;
     } else if (payload_size <= 65535) {
         unsigned short int s = htons(payload_size);
         payload_head[1] = 126;

         memcpy(&payload_head[2], &s, 2);

         payload_length = 4;
     } else if (payload_size <= 0xFFFFFFFF) {
         unsigned int s = htonl(payload_size);

         payload_head[1] = 127;
         payload_head[2] = 0;
         payload_head[3] = 0;
         payload_head[4] = 0;
         payload_head[5] = 0;

            memcpy(&payload_head[6], &s, 4);

         payload_length = 10;
     }

        finish &= sendbin(user->client->fd, payload_head, payload_length, 0, g_ape);

 }
 finish &= sendbin(user->client->fd, ""["", 1, 0, g_ape);

 while (pool->raw != NULL) {
  struct _raw_pool *pool_next = (state ? pool->next : pool->prev);

  finish &= sendbin(user->client->fd, pool->raw->data, pool->raw->len, 0, g_ape);

  if ((pool_next != NULL && pool_next->raw != NULL) || (!state && user->raw_pools.low.nraw)) {
   finish &= sendbin(user->client->fd, "","", 1, 0, g_ape);
  } else {
   finish &= sendbin(user->client->fd, ""]"", 1, 0, g_ape);

   if (properties != NULL && properties->padding.right.val != NULL) {
    finish &= sendbin(user->client->fd, properties->padding.right.val, properties->padding.right.len, 0, g_ape);
   }
  }

  free_raw(pool->raw);
  pool->raw = NULL;

  pool = pool_next;

  if ((pool == NULL || pool->raw == NULL) && !state) {
   pool = user->raw_pools.low.rawhead;
   state = 1;
  }
 }

 user->raw_pools.high.nraw = 0;
 user->raw_pools.low.nraw = 0;
 user->raw_pools.nraw = 0;

 user->raw_pools.high.rawfoot = user->raw_pools.high.rawhead;
 user->raw_pools.low.rawfoot = user->raw_pools.low.rawhead;

 FLUSH_TCP(user->client->fd);

 return finish;
}

*****
****
send_raw_inline:  NGB
original : ((free;free) + 0)
rewritten : ((free;free) + 0)

int send_raw_inline(ape_socket *client, transport_t transport, RAW *raw, acetables *g_ape)
{
 struct _transport_properties *properties;
 int finish = 1;

 properties = transport_get_properties(transport, g_ape);

 switch(transport) {
  case TRANSPORT_XHRSTREAMING:
   finish &= http_send_headers(NULL, HEADER_XHR, HEADER_XHR_LEN, client, g_ape);
   break;
  case TRANSPORT_SSE_LONGPOLLING:
   finish &= http_send_headers(NULL, HEADER_SSE, HEADER_SSE_LEN, client, g_ape);
   break;
  case TRANSPORT_JSONP:
   finish &= http_send_headers(NULL, HEADER_JSONP, HEADER_JSONP_LEN, client, g_ape);
   break;
  case TRANSPORT_WEBSOCKET:
  case TRANSPORT_WEBSOCKET_IETF:
   break;
  default:
   finish &= http_send_headers(NULL, HEADER_DEFAULT, HEADER_DEFAULT_LEN, client, g_ape);
   break;
 }

 if (properties != NULL && properties->padding.left.val != NULL) {
  finish &= sendbin(client->fd, properties->padding.left.val, properties->padding.left.len, 0, g_ape);
 }


 if (transport == TRANSPORT_WEBSOCKET_IETF) {
     websocket_state *websocket = client->parser.data;
     char payload_head[32] = { websocket->version == WS_IETF_06 ? 0x84 : 0x81 };
     int payload_size = raw->len+2; /* TODO: fragmentation? */
     int payload_length = 0;

     if (payload_size <= 125) {
         payload_head[1] = (unsigned char)payload_size & 0x7F;
         payload_length = 2;
     } else if (payload_size <= 65535) {
         unsigned short int s = htons(payload_size);
         payload_head[1] = 126;

         memcpy(&payload_head[2], &s, 2);

         payload_length = 4;
     } else if (payload_size <= 0xFFFFFFFF) {
         unsigned int s = htonl(payload_size);

         payload_head[1] = 127;
         payload_head[2] = 0;
         payload_head[3] = 0;
         payload_head[4] = 0;
         payload_head[5] = 0;

            memcpy(&payload_head[6], &s, 4);

         payload_length = 10;
     }

        finish &= sendbin(client->fd, payload_head, payload_length, 0, g_ape);
 }

 finish &= sendbin(client->fd, ""["", 1, 0, g_ape);

 finish &= sendbin(client->fd, raw->data, raw->len, 0, g_ape);

 finish &= sendbin(client->fd, ""]"", 1, 0, g_ape);

 if (properties != NULL && properties->padding.right.val != NULL) {
  finish &= sendbin(client->fd, properties->padding.right.val, properties->padding.right.len, 0, g_ape);
 }

 free_raw(raw);

 return finish;
}

***

***
post_to_pipe: NGB
original : ((free + 0) + 0);(free + ((free + 0) + 0) + 0)
rewritten : (free + 0);(free + ((free + 0) + 0) + 0)

int post_to_pipe(json_item *jlist, const char *rawname, const char *pipe, subuser *from, acetables *g_ape)
{
 USERS *sender = from->user;
 transpipe *recver = get_pipe_strict(pipe, sender, g_ape);
 json_item *jlist_copy = NULL;
 RAW *newraw;

 if (sender != NULL) {
  if (recver == NULL) {
   send_error(sender, ""UNKNOWN_PIPE"", ""109"", g_ape);
   return 0;
  }
  json_set_property_objN(jlist, ""from"", 4, get_json_object_user(sender));

 }

 if (sender != NULL && sender->nsub > 1) {
  jlist_copy = json_item_copy(jlist, NULL);

  json_set_property_objN(jlist_copy, ""pipe"", 4, get_json_object_pipe(recver));
  newraw = forge_raw(rawname, jlist_copy);
  post_raw_restricted(newraw, sender, from, g_ape);
 }
 switch(recver->type) {
  case USER_PIPE:
   json_set_property_objN(jlist, ""pipe"", 4, get_json_object_user(sender));
   newraw = forge_raw(rawname, jlist);
   post_raw(newraw, recver->pipe, g_ape);
   break;
  case CHANNEL_PIPE:
   if (((CHANNEL*)recver->pipe)->head != NULL && ((CHANNEL*)recver->pipe)->head->next != NULL) {
    json_set_property_objN(jlist, ""pipe"", 4, get_json_object_channel(recver->pipe));
    newraw = forge_raw(rawname, jlist);
    post_raw_channel_restricted(newraw, recver->pipe, sender, g_ape);
   }
   break;
  case CUSTOM_PIPE:
   json_set_property_objN(jlist, ""pipe"", 4, get_json_object_user(sender));
   post_json_custom(jlist, sender, recver, g_ape);
   break;
  default:
   break;
 }

 return 1;
}

*****
