------------------------------------------------------------------------------------------------------------
https://github.com/ark-lang/ark-c/blob/master/src/compiler.c

****
destroyCompiler:  OK
original : (free + 0)
rewritten:  free

void destroyCompiler(Compiler *self) {
        if (self) {
                if (self->lexer) destroyLexer(self->lexer);
                if (self->parser) destroyParser(self->parser);
                if (self->generatorLLVM) destroyLLVMCodeGenerator(self->generatorLLVM);
                if (self->semantic) destroySemanticAnalyzer(self->semantic);
                if (self->sourceFiles) destroyVector(self->sourceFiles);
                free(self);
                verboseModeMessage("Destroyed compiler");
        }

****

--------------------------------------------------------------------------------------------------------------
https://github.com/luna/luna/blob/master/deps/linenoise/linenoise.c

*********

linenoiseHistorySetMaxLen:    OK
original :  ((malloc;free) + 0)
rewritten:  malloc;free

int linenoiseHistorySetMaxLen(int len) {
    char **new;

    if (len < 1) return 0;
    if (history) {
        int tocopy = history_len;

        new = malloc(sizeof(char*)*len);
        if (new == NULL) return 0;
        if (len < tocopy) tocopy = len;
        memcpy(new,history+(history_max_len-tocopy), sizeof(char*)*tocopy);
        free(history);
        history = new;
    }
    history_max_len = len;
    if (history_len > history_max_len)
        history_len = history_max_len;
    return 1;
}

*************

completeLine:   OK
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

**********

freeCompletions:           OK
original :  (ua.free;a);(free + 0)
rewritten: (ua.free;a);free

static void freeCompletions(linenoiseCompletions *lc) {
    size_t i;
    for (i = 0; i < lc->len; i++)
        free(lc->cvec[i]);
    if (lc->cvec != NULL)
        free(lc->cvec);
}


********
linenoiseAtExit:              OK
original :(((ua.free;a);free) + 0)
rewritten:    (ua.free;a);free

static void linenoiseAtExit(void) {
    disableRawMode(STDIN_FILENO);
    freeHistory();
}

**********
freeHistory:          OK
original : (((ua.free;a);free) + 0)
rewritten:  (ua.free;a);free

static void freeHistory(void) {
    if (history) {
        int j;

        for (j = 0; j < history_len; j++)
            free(history[j]);
        free(history);
    }
}

*******



--------------------------------------------------------------------------------
https://github.com/Orc/discount/blob/master/basename.c

*****
e_free:          OK
original : (free + 0)
rewritten: free

 static void e_free(char *string, void *context)
{
    if ( string ) free(string);
}

******


------------------------------------------------------------------------------------------------------------
https://github.com/APE-Project/APE_Server/blob/master/deps/js/src/editline/editline.c

*****

bk_kill_word:        OK
original : ((((free + 0);malloc) + 0) + 0)
rewritten :  (((free;malloc) + 0) + 0)

STATIC STATUS bk_kill_word()
{
    (void)bk_word();
    if (OldPoint != Point)
        return delete_string(OldPoint - Point);
    return CSstay;
}

***

fd_kill_word:         OK
original : ((((free + 0);malloc) + 0) + 0)
rewritten:  (((free;malloc) + 0) + 0)

STATIC STATUS  fd_kill_word()
{
    int		i;

    (void)do_forward(CSstay);
    if (OldPoint != Point) {
        i = Point - OldPoint;
        Point = OldPoint;
        return delete_string(i);
    }
    return CSstay;
}

*****

copy_region:  OK
original (((free + 0);malloc) + ((free + 0);malloc))
rewritten : ((free;malloc) + (free;malloc))

STATIC STATUS  copy_region()
{
    if (Mark > End)
        return ring_bell();

    if (Point > Mark)
        save_yank(Mark, Point - Mark);
    else
        save_yank(Point, Mark - Point);

    return CSstay;
}

*****
wipe:  OK
original : (((free + 0);malloc) + 0)
rewritten : ((free;malloc) + 0)

STATIC STATUS
wipe()
{
    int		i;

    if (Mark > End)
        return ring_bell();

    if (Point > Mark) {
        i = Point;
        Point = Mark;
        Mark = i;
        reposition();
    }

    return delete_string(Mark - Point);
}

******

del_char:     OK
original :  (((free + 0);malloc) + 0)
rewritten:   ((free;malloc) + 0)

STATIC STATUS  del_char()
{
    return delete_string(Repeat == NO_ARG ? 1 : Repeat);
}


*******

editinput:    OK
original : (ua.((((free + 0);malloc) + 0) + ((((free + 0);malloc) + 0) + 0));(((((((free + 0);malloc) + 0) + ((((free + 0);malloc) + 0) + 0)) + 0);(free + 0);malloc) + 0);a);free
rewritten : (ua.(((free;malloc) + 0) + (((free;malloc) + 0) + 0));((((((free;malloc) + 0) + (((free;malloc) + 0) + 0)) + 0);free;malloc) + 0);a);free

STATIC CHAR * editinput()
{
    unsigned int	c;

    Repeat = NO_ARG;
    OldPoint = Point = Mark = End = 0;
    Line[0] = '\0';

    Signal = -1;
    while ((int)(c = TTYget()) != EOF)
        switch (TTYspecial(c)) {
        case CSdone:
            return Line;
        case CSeof:
            return NULL;
        case CSsignal:
            return (CHAR *)"";
        case CSmove:
            reposition();
            break;
        case CSdispatch:
            switch (emacs(c)) {
            case CSdone:
                return Line;
            case CSeof:
                return NULL;
            case CSsignal:
                return (CHAR *)"";
            case CSmove:
                reposition();
                break;
            case CSdispatch:
            case CSstay:
                break;
            }
            break;
        case CSstay:
            break;
        }
    if (strlen((char *)Line))
        return Line;
    free(Line);
    return NULL;
}


****

TTYspecial:  OK
original :((((free + 0);malloc) + 0) + ((((free + 0);malloc) + 0) + 0));(((((((free + 0);malloc) + 0) + ((((free + 0);malloc) + 0) + 0)) + 0);(free + 0);malloc) + 0)
rewritten : (((free;malloc) + 0) + (((free;malloc) + 0) + 0));((((((free;malloc) + 0) + (((free;malloc) + 0) + 0)) + 0);free;malloc) + 0)

STATIC STATUS
TTYspecial(c)
    unsigned int	c;
{
    if (ISMETA(c))
        return CSdispatch;

    if (c == rl_erase || (int)c == DEL)
        return bk_del_char();
    if (c == rl_kill) {
        if (Point != 0) {
            Point = 0;
            reposition();
        }
        Repeat = NO_ARG;
        return kill_line();
    }
    if (c == rl_eof && Point == 0 && End == 0)
        return CSeof;
    if (c == rl_intr) {
        Signal = SIGINT;
        return CSsignal;
    }
    if (c == rl_quit) {
        Signal = SIGQUIT;
        return CSeof;
    }

    return CSdispatch;
}


*****

kill_line:       OK
original : (((((free + 0);malloc) + 0) + ((((free + 0);malloc) + 0) + 0)) + 0);(free + 0);malloc
rewritten: ((((free;malloc) + 0) + (((free;malloc) + 0) + 0)) + 0);free;malloc

STATIC STATUS  kill_line()
{
    int		i;

    if (Repeat != NO_ARG) {
        if (Repeat < Point) {
            i = Point;
            Point = Repeat;
            reposition();
            (void)delete_string(i - Point);
        }
        else if (Repeat > Point) {
            right(CSmove);
            (void)delete_string(Repeat - Point - 1);
        }
        return CSmove;
    }

    save_yank(Point, End - Point);
    Line[Point] = '\0';
    ceol();
    End = Point;
    return CSstay;
}

****

bk_del_char:     OK
original :  (((free + 0);malloc) + 0)
rewritten: ((free;malloc) + 0)

STATIC STATUS bk_del_char()
{
    int		i;

    i = 0;
    do {
        if (Point == 0)
            break;
        left(CSmove);
    } while (++i < Repeat);

    return delete_string(i);
}

******
delete_string:    OK
original :  (((free + 0);malloc) + 0)
rewritten : ((free;malloc) + 0)

  STATIC STATUS  delete_string(count)
    int		count;
{
    int		i;
    CHAR	*p;

    if (count <= 0 || End == Point)
        return ring_bell();

    if (count == 1 && Point == End - 1) {
        /* Optimize common case of delete at end of line. */
        End--;
        p = &Line[Point];
        i = 1;
        TTYput(' ');
        if (ISCTL(*p)) {
            i = 2;
            TTYput(' ');
        }
        else if (rl_meta_chars && ISMETA(*p)) {
            i = 3;
            TTYput(' ');
            TTYput(' ');
        }
        TTYbackn(i);
        *p = '\0';
        return CSmove;
    }
    if (Point + count > End && (count = End - Point) <= 0)
        return CSstay;

    if (count > 1)
        save_yank(Point, count);

    for (p = &Line[Point], i = End - (Point + count) + 1; --i >= 0; p++)
        p[0] = p[count];
    ceol();
    End -= count;
    TTYstring(&Line[Point]);
    return CSmove;
}

******
save_yank:   OK
original :   (free + 0);malloc
rewritten :  free;malloc

STATIC void  save_yank(begin, i)
                    int     begin;
 int		i;
 {
   if (Yanked) {
     DISPOSE(Yanked);
     Yanked = NULL;
   }

   if (i < 1)
     return;

   if ((Yanked = NEW(CHAR, (SIZE_T)i + 1)) != NULL) {
     COPYFROMTO(Yanked, &Line[begin], i);
     Yanked[i] = '\0';
   }
 }

--------------------------------------------------------------------------------------
https://github.com/APE-Project/APE_Server/blob/master/src/json.c

****

json_free:    OK
original : (ua.(free;(free + 0);free))
rewritten : (ua.(free;free;free))

  void json_free(struct json *jbase)
{
        struct json_childs *jchilds = jbase->jchilds;

        free(jbase->name.buf);

        if (jbase->value.buf != NULL) {
                free(jbase->value.buf);
        }

        if (jbase->next != NULL) {
                json_free(jbase->next);
        }

        while (jchilds != NULL) {
                json_free(jchilds->child);

                jchilds = jchilds->next;
        }

        free(jbase);
}

****


------------------------------------------------------------------------------------------------------------------------
https://github.com/APE-Project/APE_Server/blob/master/deps/js/src/config/mkdepend/parse.c

******

merge2defines:
original : (malloc + 0);(free + 0)
rewritten :  (malloc + 0);free

static int
merge2defines(struct inclist *file1, struct inclist *file2)
{
        int i;

        if ((file1==NULL) || (file2==NULL) ||
            !(file2->i_flags & FINISHED))
                return 0;

        for (i=0; i < file2->i_listlen; i++)
                if (file2->i_merged[i]==FALSE)
                        return 0;

        {
                int first1 = 0;
                int last1 = file1->i_ndefs - 1;

                int first2 = 0;
                int last2 = file2->i_ndefs - 1;

                int first=0;
                struct symtab** i_defs = NULL;
                int deflen=file1->i_ndefs+file2->i_ndefs;

                debug(2,("merging %s into %s\n",
                        file2->i_file, file1->i_file));

                if (deflen>0)
                {
                        /* make sure deflen % SYMTABINC == 0 is still true */
                        deflen += (SYMTABINC - deflen % SYMTABINC) % SYMTABINC;
                        i_defs=(struct symtab**)
                            malloc(deflen*sizeof(struct symtab*));
                        if (i_defs==NULL) return 0;
                }

                while ((last1 >= first1) && (last2 >= first2))
                {
                        char *s1=file1->i_defs[first1]->s_name;
                        char *s2=file2->i_defs[first2]->s_name;

                        if (strcmp(s1,s2) < 0)
                                i_defs[first++]=file1->i_defs[first1++];
                        else if (strcmp(s1,s2) > 0)
                                i_defs[first++]=file2->i_defs[first2++];
                        else /* equal */
                        {
                                i_defs[first++]=file2->i_defs[first2++];
                                first1++;
                        }
                }
                while (last1 >= first1)
                {
                        i_defs[first++]=file1->i_defs[first1++];
                }
                while (last2 >= first2)
                {
                        i_defs[first++]=file2->i_defs[first2++];
                }

                if (file1->i_defs) free(file1->i_defs);
                file1->i_defs=i_defs;
                file1->i_ndefs=first;

                return 1;
        }
}

*****
define:   OK
original (malloc + 0);(free + 0);malloc
rewritten : (malloc + 0);free;;malloc

void
define(char *def, struct inclist *file)
{
    char *val;

    /* Separate symbol name and its value */
    val = def;
    while (isalnum(*val) || *val == '_')
        val++;
    if (*val)
        *val++ = '\0';
    while (*val == ' ' || *val == '\t')
        val++;

    if (!*val)
        val = "1";
    define2(def, val, file);
}

*******
define2:       OK
original : (malloc + 0);(free + 0);malloc
rewritten :  (malloc + 0);free;;malloc

void
define2(char *name, char *val, struct inclist *file)
{
    int first, last, below;
    register struct symtab **sp = NULL, **dest;
    struct symtab *stab;

    /* Make space if it's needed */
    if (file->i_defs == NULL)
    {
        file->i_defs = (struct symtab **)
                        malloc(sizeof (struct symtab*) * SYMTABINC);
        file->i_ndefs = 0;
    }
    else if (!(file->i_ndefs % SYMTABINC))
        file->i_defs = (struct symtab **)
                        realloc(file->i_defs,
                           sizeof(struct symtab*)*(file->i_ndefs+SYMTABINC));

    if (file->i_defs == NULL)
        fatalerr("malloc()/realloc() failure in insert_defn()\n");

    below = first = 0;
    last = file->i_ndefs - 1;
    while (last >= first)
    {
        /* Fast inline binary search */
        register char *s1;
        register char *s2;
        register int middle = (first + last) / 2;

        /* Fast inline strchr() */
        s1 = name;
        s2 = file->i_defs[middle]->s_name;
        while (*s1++ == *s2++)
            if (s2[-1] == '\0') break;

        /* If exact match, set sp and break */
        if (*--s1 == *--s2)
        {
            sp = file->i_defs + middle;
            break;
        }

        /* If name > i_defs[middle] ... */
        if (*s1 > *s2)
        {
            below = first;
            first = middle + 1;
        }
        /* else ... */
        else
        {
            below = last = middle - 1;
        }
    }

    /* Search is done.  If we found an exact match to the symbol name,
       just replace its s_value */
    if (sp != NULL)
    {
        debug(1,("redefining %s from %s to %s in file %s\n",
                name, (*sp)->s_value, val, file->i_file));
        free((*sp)->s_value);
        (*sp)->s_value = copy(val);
        return;
    }

    sp = file->i_defs + file->i_ndefs++;
    dest = file->i_defs + below + 1;
    while (sp > dest)
    {
        *sp = sp[-1];
        sp--;
    }
    stab = (struct symtab *) malloc(sizeof (struct symtab));
    if (stab == NULL)
        fatalerr("malloc()/realloc() failure in insert_defn()\n");

    debug(1,("defining %s to %s in file %s\n", name, val, file->i_file));
    stab->s_name = copy(name);
    stab->s_value = copy(val);
    *sp = stab;
}
