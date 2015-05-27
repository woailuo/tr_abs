

char *pgm = "theme";
char *output = 0;
char *pagename = 0;
char *root = 0;
int everywhere = 0;




struct stat *infop = 0;
char *
basename(char *path)
{
    char *p;

    if ( p = strrchr(path, '/') )
 return 1+p;
    return path;
}
typedef char* HERE;


HERE
pushd(char *d)
{
    HERE cwd;
    int size;

    if ( chdir(d) == -1 )
 return 0;

    for (cwd = malloc(size=40); cwd; cwd = realloc(cwd, size *= 2))
 if ( getcwd(cwd, size) )
     return cwd;

    return 0;
}

int
popd(HERE pwd)
{
    if ( pwd ) {
 int rc = chdir(pwd);
 free(pwd);

 return rc;
    }
    return -1;
}


typedef STRING(int) Istring;

void
fail(char *why, ...)
{
    va_list ptr;

    __builtin_va_start(ptr, why);
    fprintf(__stderrp, "%s: ", pgm);
    vfprintf(__stderrp, why, ptr);
    fputc('\n', __stderrp);
    __builtin_va_end(ptr);
    exit(1);
}






FILE *
open_template(char *template)
{
    char *cwd;
    int szcwd;
    HERE here = pushd(".");
    FILE *ret;

    if ( here == 0 )
 fail("cannot access the current directory");

    szcwd = root ? 1 + strlen(root) : 2;

    if ( (cwd = malloc(szcwd)) == 0 )
 return 0;

    while ( !(ret = fopen(template, "r")) ) {
 if ( getcwd(cwd, szcwd) == 0 ) {
     if ( (*__error()) == 34 )
  goto up;
     break;
 }

 if ( root && (strcmp(root, cwd) == 0) )
     break;
 else if ( (strcmp(cwd, "/") == 0) || (*cwd == 0) )
     break;

    up: if ( chdir("..") == -1 )
     break;
    }
    free(cwd);
    popd(here);
    return ret;
}


static Istring inbuf;
static int psp;

static int
prepare(FILE *input)
{
    int c;

    CREATE(inbuf);
    psp = 0;
    while ( (c = getc(input)) != (-1) )
 EXPAND(inbuf) = c;
    fclose(input);
    return 1;
}

static int
pull()
{
    return psp < S(inbuf) ? T(inbuf)[psp++] : (-1);
}

static int
peek(int offset)
{
    int pos = (psp + offset)-1;

    if ( pos >= 0 && pos < S(inbuf) )
 return T(inbuf)[pos];

    return (-1);
}

static int
shift(int shiftwidth)
{
    psp += shiftwidth;
    return psp;
}

static int*
cursor()
{
    return T(inbuf) + psp;
}


static int
thesame(int *p, char *pat)
{
    int i;

    for ( i=0; pat[i]; i++ ) {
 if ( pat[i] == ' ' ) {
     if ( !isspace(peek(i+1)) ) {
  return 0;
     }
 }
 else if ( tolower(peek(i+1)) != pat[i] ) {
     return 0;
 }
    }
    return 1;
}


static int
istag(int *p, char *pat)
{
    int c;

    if ( thesame(p, pat) ) {
 c = peek(strlen(pat)+1);
 return (c == '>' || isspace(c));
    }
    return 0;
}




static void
finclude(MMIOT *doc, FILE *out, int flags, int whence)
{
    int c;
    Cstring include;
    FILE *f;

    CREATE(include);

    while ( (c = pull()) != '(' )
 ;

    while ( (c=pull()) != ')' && c != (-1) )
 EXPAND(include) = c;

    if ( c != (-1) ) {
 EXPAND(include) = 0;
 S(include)--;

 if (( f = fopen(T(include), "r") )) {
     while ( (c = getc(f)) != (-1) )
  putc(c, out);
     fclose(f);
 }
    }
    DELETE(include);
}




static void
fdirname(MMIOT *doc, FILE *output, int flags, int whence)
{
    char *p;

    if ( pagename && (p = basename(pagename)) )
 fwrite(pagename, strlen(pagename)-strlen(p), 1, output);
}




static void
fbasename(MMIOT *doc, FILE *output, int flags, int whence)
{
    char *p;

    if ( pagename ) {
 p = basename(pagename);

 if ( !p )
     p = pagename;

 if ( p )
     fwrite(p, strlen(p), 1, output);
    }
}




static void
ftitle(MMIOT *doc, FILE* output, int flags, int whence)
{
    char *h;
    if ( (h = mkd_doc_title(doc)) == 0 && pagename )
 h = pagename;

    if ( h )
 mkd_generateline(h, strlen(h), output, flags);
}




static void
fdate(MMIOT *doc, FILE *output, int flags, int whence)
{
    char *h;

    if ( (h = mkd_doc_date(doc)) || ( infop && (h = ctime(&infop->st_mtimespec.tv_sec)) ) )
 mkd_generateline(h, strlen(h), output, flags|MKD_TAGTEXT);
}




static void
fauthor(MMIOT *doc, FILE *output, int flags, int whence)
{
    char *h = mkd_doc_author(doc);






    if ( h )
 mkd_generateline(h, strlen(h), output, flags);
}





static void
fconfig(MMIOT *doc, FILE *output, int flags, int whence)
{
    mkd_mmiot_flags(output, doc, (whence & (0x02|0x01)) ? 0 : 1);
}




static void
fversion(MMIOT *doc, FILE *output, int flags, int whence)
{
    fwrite(markdown_version, strlen(markdown_version), 1, output);
}




static void
fbody(MMIOT *doc, FILE *output, int flags, int whence)
{
    mkd_generatehtml(doc, output);
}



static void
ftoc(MMIOT *doc, FILE *output, int flags, int whence)
{
    mkd_generatetoc(doc, output);
}



static void
fstyle(MMIOT *doc, FILE *output, int flags, int whence)
{
    mkd_generatecss(doc, output);
}
static struct _keyword {
    char *kw;
    int where;
    void (*what)(MMIOT*,FILE*,int,int);
} keyword[] = {
    { "author?>", 0xffff, fauthor },
    { "body?>", 0x04, fbody },
    { "toc?>", 0x04, ftoc },
    { "date?>", 0xffff, fdate },
    { "dir?>", 0xffff, fdirname },
    { "include(", 0xffff, finclude },
    { "source?>", 0xffff, fbasename },
    { "style?>", 0x02, fstyle },
    { "title?>", 0xffff, ftitle },
    { "version?>", 0xffff, fversion },
    { "config?>", 0xffff, fconfig },
};





void
spin(FILE *template, MMIOT *doc, FILE *output)
{
    int c;
    int *p;
    int flags;
    int where = 0x0;
    int i;

    prepare(template);

    while ( (c = pull()) != (-1) ) {
 if ( c == '<' ) {
     if ( peek(1) == '!' && peek(2) == '-' && peek(3) == '-' ) {
  fputs("<!--", output);
  shift(3);
  do {
      putc(c=pull(), output);
  } while ( ! (c == '-' && peek(1) == '-' && peek(2) == '>') );
     }
     else if ( (peek(1) == '?') && thesame(cursor(), "?theme ") ) {
  shift(strlen("?theme "));

  while ( ((c = pull()) != (-1)) && isspace(c) )
      ;

  shift(-1);
  p = cursor();

  if ( where & 0x01 )
      flags = MKD_TAGTEXT;
  else if ( where & 0x02 )
      flags = MKD_NOIMAGE|MKD_NOLINKS;
  else
      flags = 0;

  for (i=0; i < (sizeof keyword / sizeof keyword[0]); i++)
      if ( thesame(p, keyword[i].kw) ) {
   if ( everywhere || (keyword[i].where & where) )
       (*keyword[i].what)(doc,output,flags,where);
   break;
      }

  while ( (c = pull()) != (-1) && (c != '?' && peek(1) != '>') )
      ;
  shift(1);
     }
     else
  putc(c, output);

     if ( istag(cursor(), "head") ) {
  where |= 0x02;
  where &= ~0x04;
     }
     else if ( istag(cursor(), "body") ) {
  where &= ~0x02;
  where |= 0x04;
     }
     where |= 0x01;
     continue;
 }
 else if ( c == '>' )
     where &= ~0x01;

 putc(c, output);
    }
}


main(argc, argv)
char **argv;
{
    char *template = "page.theme";
    char *source = "stdin";
    FILE *tmplfile;
    int opt;
    mkd_flag_t flags = MKD_TOC;
    int force = 0;
    MMIOT *doc;
    struct stat sourceinfo;

    opterr=1;
    pgm = basename(argv[0]);

    while ( (opt=getopt(argc, argv, "EfC:c:d:t:p:o:V")) != (-1) ) {
 switch (opt) {
 case 'd': root = optarg;
      break;
 case 'E': everywhere = 1;
      break;
 case 'p': pagename = optarg;
      break;
 case 'f': force = 1;
      break;
 case 't': template = optarg;
      break;
 case 'C': if ( strcmp(optarg, "?") == 0 ) {
   show_flags(0);
   exit(0);
      }
      else
   flags = strtol(optarg, 0, 0);
      break;
 case 'c': if ( strcmp(optarg, "?") == 0 ) {
   show_flags(1);
   exit(0);
      }
      else if ( !set_flag(&flags, optarg) )
   fprintf(__stderrp,"%s: unknown option <%s>", pgm, optarg);
      break;
 case 'o': output = optarg;
      break;
 case 'V': printf("theme+discount %s\n", markdown_version);
      exit(0);
 default: fprintf(__stderrp, "usage: %s [-V] [-d dir] [-p pagename] [-t template] [-o html] [file]\n", pgm);
      exit(1);
 }
    }

    tmplfile = open_template(template);

    argc -= optind;
    argv += optind;


    if ( argc > 0 ) {
 int added_text=0;

 if ( (source = malloc(strlen(argv[0]) + strlen("/index.text") + 1)) == 0 )
     fail("out of memory allocating name buffer");

 __builtin___strcpy_chk (source, argv[0], __builtin_object_size (source, 2 > 1 ? 1 : 0));
 if ( (stat(source, &sourceinfo) == 0) && (((sourceinfo.st_mode) & 0170000) == 0040000) )
     __builtin___strcat_chk (source, "/index", __builtin_object_size (source, 2 > 1 ? 1 : 0));

 if ( !freopen(source, "r", __stdinp) ) {
     __builtin___strcat_chk (source, ".text", __builtin_object_size (source, 2 > 1 ? 1 : 0));
     added_text = 1;
     if ( !freopen(source, "r", __stdinp) )
  fail("can't open either %s or %s", argv[0], source);
 }

 if ( !output ) {
     char *p, *q;
     output = __builtin_alloca(strlen(source) + strlen(".html") + 1);

     __builtin___strcpy_chk (output, source, __builtin_object_size (output, 2 > 1 ? 1 : 0));

     if (( p = strchr(output, '/') ))
  q = strrchr(p+1, '.');
     else
  q = strrchr(output, '.');

     if ( q )
  *q = 0;
     else
  q = output + strlen(output);

     __builtin___strcat_chk (q, ".html", __builtin_object_size (q, 2 > 1 ? 1 : 0));
 }
    }
    if ( output && strcmp(output, "-") ) {
 if ( force )
     unlink(output);
 if ( !freopen(output, "w", __stdoutp) )
     fail("can't write to %s", output);
    }

    if ( !pagename )
 pagename = source;

    if ( (doc = mkd_in(__stdinp, 0)) == 0 )
 fail("can't read %s", source ? source : "stdin");

    if ( fstat(fileno(__stdinp), &sourceinfo) == 0 )
 infop = &sourceinfo;
    if ( !mkd_compile(doc, flags) )
 fail("couldn't compile input");

    if ( tmplfile )
 spin(tmplfile,doc,__stdoutp);
    else
 mkd_generatehtml(doc, __stdoutp);

    mkd_cleanup(doc);
    exit(0);
}
