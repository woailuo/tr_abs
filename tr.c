typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;

typedef long unsigned int size_t;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef int __daddr_t;
typedef long int __swblk_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void * __timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __ssize_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;

typedef __clock_t clock_t;



typedef __time_t time_t;


typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };

struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long int tm_gmtoff;
  __const char *tm_zone;
};


struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };
struct sigevent;
typedef __pid_t pid_t;

extern clock_t clock (void) __attribute__ ((__nothrow__));
extern time_t time (time_t *__timer) __attribute__ ((__nothrow__));
extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__));
extern size_t strftime (char *__restrict __s, size_t __maxsize,
   __const char *__restrict __format,
   __const struct tm *__restrict __tp) __attribute__ ((__nothrow__));

typedef struct __locale_struct
{
  struct locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
} *__locale_t;
typedef __locale_t locale_t;
extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     __const char *__restrict __format,
     __const struct tm *__restrict __tp,
     __locale_t __loc) __attribute__ ((__nothrow__));

extern struct tm *gmtime (__const time_t *__timer) __attribute__ ((__nothrow__));
extern struct tm *localtime (__const time_t *__timer) __attribute__ ((__nothrow__));

extern struct tm *gmtime_r (__const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__));
extern struct tm *localtime_r (__const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__));

extern char *asctime (__const struct tm *__tp) __attribute__ ((__nothrow__));
extern char *ctime (__const time_t *__timer) __attribute__ ((__nothrow__));

extern char *asctime_r (__const struct tm *__restrict __tp,
   char *__restrict __buf) __attribute__ ((__nothrow__));
extern char *ctime_r (__const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern char *tzname[2];
extern void tzset (void) __attribute__ ((__nothrow__));
extern int daylight;
extern long int timezone;
extern int stime (__const time_t *__when) __attribute__ ((__nothrow__));
extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__));
extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__));
extern int dysize (int __year) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int nanosleep (__const struct timespec *__requested_time,
        struct timespec *__remaining);
extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__));
extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __attribute__ ((__nothrow__));
extern int clock_settime (clockid_t __clock_id, __const struct timespec *__tp)
     __attribute__ ((__nothrow__));
extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       __const struct timespec *__req,
       struct timespec *__rem);
extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__));
extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) __attribute__ ((__nothrow__));
extern int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__));
extern int timer_settime (timer_t __timerid, int __flags,
     __const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__));
extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __attribute__ ((__nothrow__));
extern int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__));


struct _IO_FILE;

typedef struct _IO_FILE FILE;


typedef struct _IO_FILE __FILE;
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
typedef int _G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__)));
struct _IO_jump_t; struct _IO_FILE;
typedef void _IO_lock_t;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;
};
enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
struct _IO_FILE {
  int _flags;
  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
typedef struct _IO_FILE _IO_FILE;
struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);
typedef __ssize_t __io_write_fn (void *__cookie, __const char *__buf,
     size_t __n);
typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);
typedef int __io_close_fn (void *__cookie);
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern int _IO_peekc_locked (_IO_FILE *__fp);
extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);
extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);
extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__));

typedef _G_fpos_t fpos_t;

extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;

extern int remove (__const char *__filename) __attribute__ ((__nothrow__));
extern int rename (__const char *__old, __const char *__new) __attribute__ ((__nothrow__));

extern int renameat (int __oldfd, __const char *__old, int __newfd,
       __const char *__new) __attribute__ ((__nothrow__));

extern FILE *tmpfile (void) ;
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__)) ;

extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__)) ;
extern char *tempnam (__const char *__dir, __const char *__pfx)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;

extern int fclose (FILE *__stream);
extern int fflush (FILE *__stream);

extern int fflush_unlocked (FILE *__stream);

extern FILE *fopen (__const char *__restrict __filename,
      __const char *__restrict __modes) ;
extern FILE *freopen (__const char *__restrict __filename,
        __const char *__restrict __modes,
        FILE *__restrict __stream) ;

extern FILE *fdopen (int __fd, __const char *__modes) __attribute__ ((__nothrow__)) ;
extern FILE *fmemopen (void *__s, size_t __len, __const char *__modes)
  __attribute__ ((__nothrow__)) ;
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__)) ;

extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__));
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__));

extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__));
extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__));

extern int fprintf (FILE *__restrict __stream,
      __const char *__restrict __format, ...);
extern int printf (__const char *__restrict __format, ...);
extern int sprintf (char *__restrict __s,
      __const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int vfprintf (FILE *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg);
extern int vprintf (__const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf (char *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));


extern int snprintf (char *__restrict __s, size_t __maxlen,
       __const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));

extern int vdprintf (int __fd, __const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, __const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));

extern int fscanf (FILE *__restrict __stream,
     __const char *__restrict __format, ...) ;
extern int scanf (__const char *__restrict __format, ...) ;
extern int sscanf (__const char *__restrict __s,
     __const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int fscanf (FILE *__restrict __stream, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf") ;
extern int scanf (__const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf") ;
extern int sscanf (__const char *__restrict __s, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__));


extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (__const char *__restrict __s,
      __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (__const char *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__))
     __attribute__ ((__format__ (__scanf__, 2, 0)));


extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);

extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream);

extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);

extern int fputc_unlocked (int __c, FILE *__stream);
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream);
extern int putw (int __w, FILE *__stream);

extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;
extern char *gets (char *__s) ;

extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;
extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;

extern int fputs (__const char *__restrict __s, FILE *__restrict __stream);
extern int puts (__const char *__s);
extern int ungetc (int __c, FILE *__stream);
extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite (__const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s) ;

extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (__const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream) ;

extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) ;
extern void rewind (FILE *__stream);

extern int fseeko (FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello (FILE *__stream) ;

extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos (FILE *__stream, __const fpos_t *__pos);


extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__));
extern int feof (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int ferror (FILE *__stream) __attribute__ ((__nothrow__)) ;

extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;

extern void perror (__const char *__s);

extern int sys_nerr;
extern __const char *__const sys_errlist[];
extern int fileno (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern FILE *popen (__const char *__command, __const char *__modes) ;
extern int pclose (FILE *__stream);
extern char *ctermid (char *__s) __attribute__ ((__nothrow__));
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__));
extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__));



extern void *memcpy (void *__restrict __dest,
       __const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memmove (void *__dest, __const void *__src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern void *memccpy (void *__restrict __dest, __const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int memcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memchr (__const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


extern char *strcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strcat (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncat (char *__restrict __dest, __const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcoll (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strxfrm (char *__restrict __dest,
         __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));

extern int strcoll_l (__const char *__s1, __const char *__s2, __locale_t __l)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern size_t strxfrm_l (char *__dest, __const char *__src, size_t __n,
    __locale_t __l) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));
extern char *strdup (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strndup (__const char *__string, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));

extern char *strchr (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strrchr (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


extern size_t strcspn (__const char *__s, __const char *__reject)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strspn (__const char *__s, __const char *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strpbrk (__const char *__s, __const char *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strstr (__const char *__haystack, __const char *__needle)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strtok (char *__restrict __s, __const char *__restrict __delim)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));

extern char *__strtok_r (char *__restrict __s,
    __const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));
extern char *strtok_r (char *__restrict __s, __const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));

extern size_t strlen (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));

extern size_t strnlen (__const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));

extern char *strerror (int __errnum) __attribute__ ((__nothrow__));

extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern char *strerror_l (int __errnum, __locale_t __l) __attribute__ ((__nothrow__));
extern void __bzero (void *__s, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void bcopy (__const void *__src, void *__dest, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int bcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *index (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *rindex (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern int ffs (int __i) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int strcasecmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncasecmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsep (char **__restrict __stringp,
       __const char *__restrict __delim)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsignal (int __sig) __attribute__ ((__nothrow__));
extern char *__stpcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *__stpncpy (char *__restrict __dest,
   __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

typedef int wchar_t;


typedef struct
  {
    int quot;
    int rem;
  } div_t;
typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;


__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;

extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__)) ;

extern double atof (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern int atoi (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern long int atol (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;


__extension__ extern long long int atoll (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;


extern double strtod (__const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;


extern float strtof (__const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern long double strtold (__const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;


extern long int strtol (__const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern unsigned long int strtoul (__const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

__extension__
extern long long int strtoq (__const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
__extension__
extern unsigned long long int strtouq (__const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

__extension__
extern long long int strtoll (__const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
__extension__
extern unsigned long long int strtoull (__const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern char *l64a (long int __n) __attribute__ ((__nothrow__)) ;
extern long int a64l (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __off_t off_t;
typedef __id_t id_t;
typedef __ssize_t ssize_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));
typedef int register_t __attribute__ ((__mode__ (__word__)));
typedef int __sig_atomic_t;
typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
typedef __sigset_t sigset_t;
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
typedef __suseconds_t suseconds_t;
typedef long int __fd_mask;
typedef struct
  {
    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];
  } fd_set;
typedef __fd_mask fd_mask;

extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);

__extension__
extern unsigned int gnu_dev_major (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned long long int gnu_dev_makedev (unsigned int __major,
            unsigned int __minor)
     __attribute__ ((__nothrow__));
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef unsigned long int pthread_t;
typedef union
{
  char __size[56];
  long int __align;
} pthread_attr_t;
typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;
    unsigned int __nusers;
    int __kind;
    int __spins;
    __pthread_list_t __list;
  } __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;
typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
typedef union
{
  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    int __writer;
    int __shared;
    unsigned long int __pad1;
    unsigned long int __pad2;
    unsigned int __flags;
  } __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;

extern long int random (void) __attribute__ ((__nothrow__));
extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__));
extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };
extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));
extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern int rand (void) __attribute__ ((__nothrow__));
extern void srand (unsigned int __seed) __attribute__ ((__nothrow__));

extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__));
extern double drand48 (void) __attribute__ ((__nothrow__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern long int lrand48 (void) __attribute__ ((__nothrow__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern long int mrand48 (void) __attribute__ ((__nothrow__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void srand48 (long int __seedval) __attribute__ ((__nothrow__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };
extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern void *malloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;
extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;


extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__warn_unused_result__));
extern void free (void *__ptr) __attribute__ ((__nothrow__));

extern void cfree (void *__ptr) __attribute__ ((__nothrow__));

extern void *alloca (size_t __size) __attribute__ ((__nothrow__));

extern void *valloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern void abort (void) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));
extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));

extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));

extern void exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));


extern void _Exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));


extern char *getenv (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern char *__secure_getenv (__const char *__name)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int putenv (char *__string) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int setenv (__const char *__name, __const char *__value, int __replace)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int unsetenv (__const char *__name) __attribute__ ((__nothrow__));
extern int clearenv (void) __attribute__ ((__nothrow__));
extern char *mktemp (char *__template) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern int system (__const char *__command) ;

extern char *realpath (__const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__)) ;
typedef int (*__compar_fn_t) (__const void *, __const void *);

extern void *bsearch (__const void *__key, __const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;
extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
extern int abs (int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;

__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;

extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;


__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;

extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3))) ;
extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3))) ;
extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int mblen (__const char *__s, size_t __n) __attribute__ ((__nothrow__)) ;
extern int mbtowc (wchar_t *__restrict __pwc,
     __const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__)) ;
extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__)) ;
extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   __const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__));
extern size_t wcstombs (char *__restrict __s,
   __const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__));

extern int rpmatch (__const char *__response) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int posix_openpt (int __oflag) ;
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


typedef __useconds_t useconds_t;
typedef __intptr_t intptr_t;
typedef __socklen_t socklen_t;
extern int access (__const char *__name, int __type) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int faccessat (int __fd, __const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2))) ;
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__));
extern int close (int __fd);
extern ssize_t read (int __fd, void *__buf, size_t __nbytes) ;
extern ssize_t write (int __fd, __const void *__buf, size_t __n) ;
extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__)) ;
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__));
extern unsigned int sleep (unsigned int __seconds);
extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__));
extern int usleep (__useconds_t __useconds);
extern int pause (void);
extern int chown (__const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__)) ;
extern int lchown (__const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchownat (int __fd, __const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2))) ;
extern int chdir (__const char *__path) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchdir (int __fd) __attribute__ ((__nothrow__)) ;
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__)) ;
extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__)) ;
extern int dup (int __fd) __attribute__ ((__nothrow__)) ;
extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__));
extern char **__environ;
extern int execve (__const char *__path, char *__const __argv[],
     char *__const __envp[]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int fexecve (int __fd, char *__const __argv[], char *__const __envp[])
     __attribute__ ((__nothrow__));
extern int execv (__const char *__path, char *__const __argv[])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int execle (__const char *__path, __const char *__arg, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int execl (__const char *__path, __const char *__arg, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int execvp (__const char *__file, char *__const __argv[])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int execlp (__const char *__file, __const char *__arg, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int nice (int __inc) __attribute__ ((__nothrow__)) ;
extern void _exit (int __status) __attribute__ ((__noreturn__));
enum
  {
    _PC_LINK_MAX,
    _PC_MAX_CANON,
    _PC_MAX_INPUT,
    _PC_NAME_MAX,
    _PC_PATH_MAX,
    _PC_PIPE_BUF,
    _PC_CHOWN_RESTRICTED,
    _PC_NO_TRUNC,
    _PC_VDISABLE,
    _PC_SYNC_IO,
    _PC_ASYNC_IO,
    _PC_PRIO_IO,
    _PC_SOCK_MAXBUF,
    _PC_FILESIZEBITS,
    _PC_REC_INCR_XFER_SIZE,
    _PC_REC_MAX_XFER_SIZE,
    _PC_REC_MIN_XFER_SIZE,
    _PC_REC_XFER_ALIGN,
    _PC_ALLOC_SIZE_MIN,
    _PC_SYMLINK_MAX,
    _PC_2_SYMLINKS
  };
enum
  {
    _SC_ARG_MAX,
    _SC_CHILD_MAX,
    _SC_CLK_TCK,
    _SC_NGROUPS_MAX,
    _SC_OPEN_MAX,
    _SC_STREAM_MAX,
    _SC_TZNAME_MAX,
    _SC_JOB_CONTROL,
    _SC_SAVED_IDS,
    _SC_REALTIME_SIGNALS,
    _SC_PRIORITY_SCHEDULING,
    _SC_TIMERS,
    _SC_ASYNCHRONOUS_IO,
    _SC_PRIORITIZED_IO,
    _SC_SYNCHRONIZED_IO,
    _SC_FSYNC,
    _SC_MAPPED_FILES,
    _SC_MEMLOCK,
    _SC_MEMLOCK_RANGE,
    _SC_MEMORY_PROTECTION,
    _SC_MESSAGE_PASSING,
    _SC_SEMAPHORES,
    _SC_SHARED_MEMORY_OBJECTS,
    _SC_AIO_LISTIO_MAX,
    _SC_AIO_MAX,
    _SC_AIO_PRIO_DELTA_MAX,
    _SC_DELAYTIMER_MAX,
    _SC_MQ_OPEN_MAX,
    _SC_MQ_PRIO_MAX,
    _SC_VERSION,
    _SC_PAGESIZE,
    _SC_RTSIG_MAX,
    _SC_SEM_NSEMS_MAX,
    _SC_SEM_VALUE_MAX,
    _SC_SIGQUEUE_MAX,
    _SC_TIMER_MAX,
    _SC_BC_BASE_MAX,
    _SC_BC_DIM_MAX,
    _SC_BC_SCALE_MAX,
    _SC_BC_STRING_MAX,
    _SC_COLL_WEIGHTS_MAX,
    _SC_EQUIV_CLASS_MAX,
    _SC_EXPR_NEST_MAX,
    _SC_LINE_MAX,
    _SC_RE_DUP_MAX,
    _SC_CHARCLASS_NAME_MAX,
    _SC_2_VERSION,
    _SC_2_C_BIND,
    _SC_2_C_DEV,
    _SC_2_FORT_DEV,
    _SC_2_FORT_RUN,
    _SC_2_SW_DEV,
    _SC_2_LOCALEDEF,
    _SC_PII,
    _SC_PII_XTI,
    _SC_PII_SOCKET,
    _SC_PII_INTERNET,
    _SC_PII_OSI,
    _SC_POLL,
    _SC_SELECT,
    _SC_UIO_MAXIOV,
    _SC_IOV_MAX = _SC_UIO_MAXIOV,
    _SC_PII_INTERNET_STREAM,
    _SC_PII_INTERNET_DGRAM,
    _SC_PII_OSI_COTS,
    _SC_PII_OSI_CLTS,
    _SC_PII_OSI_M,
    _SC_T_IOV_MAX,
    _SC_THREADS,
    _SC_THREAD_SAFE_FUNCTIONS,
    _SC_GETGR_R_SIZE_MAX,
    _SC_GETPW_R_SIZE_MAX,
    _SC_LOGIN_NAME_MAX,
    _SC_TTY_NAME_MAX,
    _SC_THREAD_DESTRUCTOR_ITERATIONS,
    _SC_THREAD_KEYS_MAX,
    _SC_THREAD_STACK_MIN,
    _SC_THREAD_THREADS_MAX,
    _SC_THREAD_ATTR_STACKADDR,
    _SC_THREAD_ATTR_STACKSIZE,
    _SC_THREAD_PRIORITY_SCHEDULING,
    _SC_THREAD_PRIO_INHERIT,
    _SC_THREAD_PRIO_PROTECT,
    _SC_THREAD_PROCESS_SHARED,
    _SC_NPROCESSORS_CONF,
    _SC_NPROCESSORS_ONLN,
    _SC_PHYS_PAGES,
    _SC_AVPHYS_PAGES,
    _SC_ATEXIT_MAX,
    _SC_PASS_MAX,
    _SC_XOPEN_VERSION,
    _SC_XOPEN_XCU_VERSION,
    _SC_XOPEN_UNIX,
    _SC_XOPEN_CRYPT,
    _SC_XOPEN_ENH_I18N,
    _SC_XOPEN_SHM,
    _SC_2_CHAR_TERM,
    _SC_2_C_VERSION,
    _SC_2_UPE,
    _SC_XOPEN_XPG2,
    _SC_XOPEN_XPG3,
    _SC_XOPEN_XPG4,
    _SC_CHAR_BIT,
    _SC_CHAR_MAX,
    _SC_CHAR_MIN,
    _SC_INT_MAX,
    _SC_INT_MIN,
    _SC_LONG_BIT,
    _SC_WORD_BIT,
    _SC_MB_LEN_MAX,
    _SC_NZERO,
    _SC_SSIZE_MAX,
    _SC_SCHAR_MAX,
    _SC_SCHAR_MIN,
    _SC_SHRT_MAX,
    _SC_SHRT_MIN,
    _SC_UCHAR_MAX,
    _SC_UINT_MAX,
    _SC_ULONG_MAX,
    _SC_USHRT_MAX,
    _SC_NL_ARGMAX,
    _SC_NL_LANGMAX,
    _SC_NL_MSGMAX,
    _SC_NL_NMAX,
    _SC_NL_SETMAX,
    _SC_NL_TEXTMAX,
    _SC_XBS5_ILP32_OFF32,
    _SC_XBS5_ILP32_OFFBIG,
    _SC_XBS5_LP64_OFF64,
    _SC_XBS5_LPBIG_OFFBIG,
    _SC_XOPEN_LEGACY,
    _SC_XOPEN_REALTIME,
    _SC_XOPEN_REALTIME_THREADS,
    _SC_ADVISORY_INFO,
    _SC_BARRIERS,
    _SC_BASE,
    _SC_C_LANG_SUPPORT,
    _SC_C_LANG_SUPPORT_R,
    _SC_CLOCK_SELECTION,
    _SC_CPUTIME,
    _SC_THREAD_CPUTIME,
    _SC_DEVICE_IO,
    _SC_DEVICE_SPECIFIC,
    _SC_DEVICE_SPECIFIC_R,
    _SC_FD_MGMT,
    _SC_FIFO,
    _SC_PIPE,
    _SC_FILE_ATTRIBUTES,
    _SC_FILE_LOCKING,
    _SC_FILE_SYSTEM,
    _SC_MONOTONIC_CLOCK,
    _SC_MULTI_PROCESS,
    _SC_SINGLE_PROCESS,
    _SC_NETWORKING,
    _SC_READER_WRITER_LOCKS,
    _SC_SPIN_LOCKS,
    _SC_REGEXP,
    _SC_REGEX_VERSION,
    _SC_SHELL,
    _SC_SIGNALS,
    _SC_SPAWN,
    _SC_SPORADIC_SERVER,
    _SC_THREAD_SPORADIC_SERVER,
    _SC_SYSTEM_DATABASE,
    _SC_SYSTEM_DATABASE_R,
    _SC_TIMEOUTS,
    _SC_TYPED_MEMORY_OBJECTS,
    _SC_USER_GROUPS,
    _SC_USER_GROUPS_R,
    _SC_2_PBS,
    _SC_2_PBS_ACCOUNTING,
    _SC_2_PBS_LOCATE,
    _SC_2_PBS_MESSAGE,
    _SC_2_PBS_TRACK,
    _SC_SYMLOOP_MAX,
    _SC_STREAMS,
    _SC_2_PBS_CHECKPOINT,
    _SC_V6_ILP32_OFF32,
    _SC_V6_ILP32_OFFBIG,
    _SC_V6_LP64_OFF64,
    _SC_V6_LPBIG_OFFBIG,
    _SC_HOST_NAME_MAX,
    _SC_TRACE,
    _SC_TRACE_EVENT_FILTER,
    _SC_TRACE_INHERIT,
    _SC_TRACE_LOG,
    _SC_LEVEL1_ICACHE_SIZE,
    _SC_LEVEL1_ICACHE_ASSOC,
    _SC_LEVEL1_ICACHE_LINESIZE,
    _SC_LEVEL1_DCACHE_SIZE,
    _SC_LEVEL1_DCACHE_ASSOC,
    _SC_LEVEL1_DCACHE_LINESIZE,
    _SC_LEVEL2_CACHE_SIZE,
    _SC_LEVEL2_CACHE_ASSOC,
    _SC_LEVEL2_CACHE_LINESIZE,
    _SC_LEVEL3_CACHE_SIZE,
    _SC_LEVEL3_CACHE_ASSOC,
    _SC_LEVEL3_CACHE_LINESIZE,
    _SC_LEVEL4_CACHE_SIZE,
    _SC_LEVEL4_CACHE_ASSOC,
    _SC_LEVEL4_CACHE_LINESIZE,
    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,
    _SC_RAW_SOCKETS,
    _SC_V7_ILP32_OFF32,
    _SC_V7_ILP32_OFFBIG,
    _SC_V7_LP64_OFF64,
    _SC_V7_LPBIG_OFFBIG,
    _SC_SS_REPL_MAX,
    _SC_TRACE_EVENT_NAME_MAX,
    _SC_TRACE_NAME_MAX,
    _SC_TRACE_SYS_MAX,
    _SC_TRACE_USER_EVENT_MAX,
    _SC_XOPEN_STREAMS,
    _SC_THREAD_ROBUST_PRIO_INHERIT,
    _SC_THREAD_ROBUST_PRIO_PROTECT
  };
enum
  {
    _CS_PATH,
    _CS_V6_WIDTH_RESTRICTED_ENVS,
    _CS_GNU_LIBC_VERSION,
    _CS_GNU_LIBPTHREAD_VERSION,
    _CS_V5_WIDTH_RESTRICTED_ENVS,
    _CS_V7_WIDTH_RESTRICTED_ENVS,
    _CS_LFS_CFLAGS = 1000,
    _CS_LFS_LDFLAGS,
    _CS_LFS_LIBS,
    _CS_LFS_LINTFLAGS,
    _CS_LFS64_CFLAGS,
    _CS_LFS64_LDFLAGS,
    _CS_LFS64_LIBS,
    _CS_LFS64_LINTFLAGS,
    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS,
    _CS_XBS5_ILP32_OFF32_LIBS,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LIBS,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
    _CS_XBS5_LP64_OFF64_CFLAGS,
    _CS_XBS5_LP64_OFF64_LDFLAGS,
    _CS_XBS5_LP64_OFF64_LIBS,
    _CS_XBS5_LP64_OFF64_LINTFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LIBS,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LIBS,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LIBS,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LIBS,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LIBS,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS
  };
extern long int pathconf (__const char *__path, int __name)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__));
extern long int sysconf (int __name) __attribute__ ((__nothrow__));
extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__));
extern __pid_t getpid (void) __attribute__ ((__nothrow__));
extern __pid_t getppid (void) __attribute__ ((__nothrow__));
extern __pid_t getpgrp (void) __attribute__ ((__nothrow__));
extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__));
extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__));
extern int setpgrp (void) __attribute__ ((__nothrow__));
extern __pid_t setsid (void) __attribute__ ((__nothrow__));
extern __uid_t getuid (void) __attribute__ ((__nothrow__));
extern __uid_t geteuid (void) __attribute__ ((__nothrow__));
extern __gid_t getgid (void) __attribute__ ((__nothrow__));
extern __gid_t getegid (void) __attribute__ ((__nothrow__));
extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__)) ;
extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__));
extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__));
extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__));
extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__));
extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__));
extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__));
extern __pid_t fork (void) __attribute__ ((__nothrow__));
extern __pid_t vfork (void) __attribute__ ((__nothrow__));
extern char *ttyname (int __fd) __attribute__ ((__nothrow__));
extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2))) ;
extern int isatty (int __fd) __attribute__ ((__nothrow__));
extern int ttyslot (void) __attribute__ ((__nothrow__));
extern int link (__const char *__from, __const char *__to)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern int linkat (int __fromfd, __const char *__from, int __tofd,
     __const char *__to, int __flags)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4))) ;
extern int symlink (__const char *__from, __const char *__to)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern ssize_t readlink (__const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern int symlinkat (__const char *__from, int __tofd,
        __const char *__to) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3))) ;
extern ssize_t readlinkat (int __fd, __const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3))) ;
extern int unlink (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int unlinkat (int __fd, __const char *__name, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int rmdir (__const char *__path) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__));
extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__));
extern char *getlogin (void);
extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)));
extern int setlogin (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__));
extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int sethostname (__const char *__name, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int sethostid (long int __id) __attribute__ ((__nothrow__)) ;
extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int setdomainname (__const char *__name, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int vhangup (void) __attribute__ ((__nothrow__));
extern int revoke (__const char *__file) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int acct (__const char *__name) __attribute__ ((__nothrow__));
extern char *getusershell (void) __attribute__ ((__nothrow__));
extern void endusershell (void) __attribute__ ((__nothrow__));
extern void setusershell (void) __attribute__ ((__nothrow__));
extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__)) ;
extern int chroot (__const char *__path) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern char *getpass (__const char *__prompt) __attribute__ ((__nonnull__ (1)));
extern int fsync (int __fd);
extern long int gethostid (void);
extern void sync (void) __attribute__ ((__nothrow__));
extern int getpagesize (void) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int getdtablesize (void) __attribute__ ((__nothrow__));
extern int truncate (__const char *__file, __off_t __length)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__)) ;
extern int brk (void *__addr) __attribute__ ((__nothrow__)) ;
extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__));
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__));
extern int lockf (int __fd, int __cmd, __off_t __len) ;
extern int fdatasync (int __fildes);


enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
extern __const unsigned short int **__ctype_b_loc (void)
     __attribute__ ((__nothrow__)) __attribute__ ((__const));
extern __const __int32_t **__ctype_tolower_loc (void)
     __attribute__ ((__nothrow__)) __attribute__ ((__const));
extern __const __int32_t **__ctype_toupper_loc (void)
     __attribute__ ((__nothrow__)) __attribute__ ((__const));

extern int isalnum (int) __attribute__ ((__nothrow__));
extern int isalpha (int) __attribute__ ((__nothrow__));
extern int iscntrl (int) __attribute__ ((__nothrow__));
extern int isdigit (int) __attribute__ ((__nothrow__));
extern int islower (int) __attribute__ ((__nothrow__));
extern int isgraph (int) __attribute__ ((__nothrow__));
extern int isprint (int) __attribute__ ((__nothrow__));
extern int ispunct (int) __attribute__ ((__nothrow__));
extern int isspace (int) __attribute__ ((__nothrow__));
extern int isupper (int) __attribute__ ((__nothrow__));
extern int isxdigit (int) __attribute__ ((__nothrow__));
extern int tolower (int __c) __attribute__ ((__nothrow__));
extern int toupper (int __c) __attribute__ ((__nothrow__));


extern int isblank (int) __attribute__ ((__nothrow__));

extern int isascii (int __c) __attribute__ ((__nothrow__));
extern int toascii (int __c) __attribute__ ((__nothrow__));
extern int _toupper (int) __attribute__ ((__nothrow__));
extern int _tolower (int) __attribute__ ((__nothrow__));
extern int isalnum_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isalpha_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int iscntrl_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isdigit_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int islower_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isgraph_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isprint_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int ispunct_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isspace_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isupper_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isxdigit_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isblank_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int __tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));
extern int tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));
extern int __toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));
extern int toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));

typedef struct HTBL
{
 struct _htbl_item *first;
 struct _htbl_item **table;
} HTBL;
typedef struct _htbl_item
{
 char *key;
 void *addrs;
 struct _htbl_item *next;
 struct _htbl_item *lnext;
 struct _htbl_item *lprev;
} HTBL_ITEM;
HTBL *hashtbl_init();
void hashtbl_free(HTBL *htbl);
void *hashtbl_seek(HTBL *htbl, const char *key);
void hashtbl_erase(HTBL *htbl, const char *key);
void hashtbl_append(HTBL *htbl, const char *key, void *structaddr);
int server_is_running;
struct _transport_properties {
 struct {
  struct {
   char *val;
   int len;
  } left;
  struct {
   char *val;
   int len;
  } right;
 } padding;
};
struct _ape_transports {
 struct {
  struct _transport_properties properties;
 } jsonp;
 struct {
  struct _transport_properties properties;
 } xhrstreaming;
 struct {
  struct _transport_properties properties;
 } sse;
 struct {
  struct _transport_properties properties;
 } websocket;
 struct {
     struct _transport_properties properties;
 } websocket_ietf;
};
typedef struct _http_state http_state;
struct _http_state
{
 struct _http_header_line *hlines;
 char *uri;
 void *buffer_addr;
 const char *data;
 const char *host;
 int pos;
 int contentlength;
 int read;
 unsigned short int step;
 unsigned short int type;
 unsigned short int error;
};
typedef enum {
    WS_OLD,
    WS_76,
    WS_IETF_06,
    WS_IETF_07
} ws_version;
typedef enum {
    WS_STEP_KEY,
    WS_STEP_START,
    WS_STEP_LENGTH,
    WS_STEP_SHORT_LENGTH,
    WS_STEP_EXTENDED_LENGTH,
    WS_STEP_DATA,
    WS_STEP_END
} ws_payload_step;
typedef struct _websocket_state
{
 struct _http_state *http;
 const char *data;
 unsigned int offset;
 unsigned short int error;
 ws_version version;
 struct {
  unsigned char val[4];
  int pos;
 } key;
#pragma pack(2)
 struct {
     unsigned char start;
     unsigned char length;
     union {
         unsigned short short_length;
         unsigned long long int extended_length;
     };
 } frame_payload;
#pragma pack()
 ws_payload_step step;
 int data_pos;
 int data_inkey;
 int frame_pos;
} websocket_state;
typedef enum {
 STREAM_IN,
 STREAM_OUT,
 STREAM_SERVER,
 STREAM_DELEGATE
} ape_socket_t;
typedef enum {
 STREAM_ONLINE,
 STREAM_PROGRESS
} ape_socket_state_t;
typedef struct _ape_buffer ape_buffer;
struct _ape_buffer {
 char *data;
 void *slot;
 unsigned int size;
 unsigned int length;
 int islot;
};
typedef struct _acetables
{
 struct {
  struct _callback_hook *head;
  struct _callback_hook *foot;
 } cmd_hook;
 struct {
  struct _ape_proxy *list;
  struct _ape_proxy_cache *hosts;
 } proxy;
 struct {
  struct _ticks_callback *timers;
  unsigned int ntimers;
 } timers;
 struct {
  unsigned int lvl;
  unsigned int use_syslog;
  int fd;
 } logs;
 struct _ape_transports transports;
 HTBL *hLogin;
 HTBL *hSessid;
 HTBL *hLusers;
 HTBL *hCallback;
 HTBL *hPubid;
 struct apeconfig *srv;
 struct _callback_hook *bad_cmd_callbacks;
 struct USERS *uHead;
 struct _socks_bufout *bufout;
 struct _ace_plugins *plugins;
 struct _fdevent *events;
 struct _ape_socket **co;
 struct _extend *properties;
 const char *confs_path;
 int is_daemon;
 int basemem;
 unsigned int nConnected;
} acetables;
typedef struct _ape_parser ape_parser;
struct _ape_parser {
 void (*parser_func)(struct _ape_socket *, acetables *);
 void (*destroy)(struct _ape_parser *);
 void (*onready)(struct _ape_parser *, acetables *);
 void *data;
 struct _ape_socket *socket;
 short int ready;
};
typedef struct _ape_socket ape_socket;
struct _ape_socket {
 struct {
  void (*on_accept)(struct _ape_socket *client, acetables *g_ape);
  void (*on_connect)(struct _ape_socket *client, acetables *g_ape);
  void (*on_disconnect)(struct _ape_socket *client, acetables *g_ape);
  void (*on_read)(struct _ape_socket *client, struct _ape_buffer *buf, size_t offset, acetables *g_ape);
  void (*on_read_lf)(struct _ape_socket *client, char *data, acetables *g_ape);
  void (*on_data_completly_sent)(struct _ape_socket *client, acetables *g_ape);
  void (*on_write)(struct _ape_socket *client, acetables *g_ape);
 } callbacks;
 ape_parser parser;
 ape_buffer buffer_in;
 char ip_client[16];
 long int idle;
 void *attach;
 void *data;
 int fd;
 int burn_after_writing;
 ape_socket_state_t state;
 ape_socket_t stream_type;
};
typedef long int ptrdiff_t;
typedef long long JSON_int_t;
typedef enum
{
    JSON_E_NONE = 0,
    JSON_E_INVALID_CHAR,
    JSON_E_INVALID_KEYWORD,
    JSON_E_INVALID_ESCAPE_SEQUENCE,
    JSON_E_INVALID_UNICODE_SEQUENCE,
    JSON_E_INVALID_NUMBER,
    JSON_E_NESTING_DEPTH_REACHED,
    JSON_E_UNBALANCED_COLLECTION,
    JSON_E_EXPECTED_KEY,
    JSON_E_EXPECTED_COLON,
    JSON_E_OUT_OF_MEMORY
} JSON_error;
typedef enum
{
    JSON_T_NONE = 0,
    JSON_T_ARRAY_BEGIN,
    JSON_T_ARRAY_END,
    JSON_T_OBJECT_BEGIN,
    JSON_T_OBJECT_END,
    JSON_T_INTEGER,
    JSON_T_FLOAT,
    JSON_T_NULL,
    JSON_T_TRUE,
    JSON_T_FALSE,
    JSON_T_STRING,
    JSON_T_KEY,
    JSON_T_MAX
} JSON_type;
typedef struct JSON_value_struct {
    struct {
        JSON_int_t integer_value;
        double float_value;
        struct {
            char* value;
            size_t length;
        } str;
    } vu;
} JSON_value;
typedef struct JSON_parser_struct* JSON_parser;
typedef int (*JSON_parser_callback)(void* ctx, int type, const struct JSON_value_struct* value);
typedef void* (*JSON_malloc_t)(size_t n);
typedef void (*JSON_free_t)(void* mem);
typedef struct {
    JSON_parser_callback callback;
    void* callback_ctx;
    int depth;
    int allow_comments;
    int handle_floats_manually;
    JSON_malloc_t malloc;
    JSON_free_t free;
} JSON_config;
 void init_JSON_config(JSON_config * config);
 JSON_parser new_JSON_parser(JSON_config const* config);
 void delete_JSON_parser(JSON_parser jc);
 int JSON_parser_char(JSON_parser jc, int next_char);
 int JSON_parser_done(JSON_parser jc);
 int JSON_parser_is_legal_white_space_string(const char* s);
 int JSON_parser_get_last_error(JSON_parser jc);
 int JSON_parser_reset(JSON_parser jc);
typedef char* jpath;
enum {
 JSON_ARRAY = 0,
 JSON_OBJECT
};
typedef struct json {
 struct {
  char *buf;
  size_t len;
 } name;
 struct {
  char *buf;
  size_t len;
 } value;
 struct json_childs *jchilds;
 struct json *jfather;
 struct json *next;
 struct json *prev;
} json;
struct json_childs {
 struct json *child;
 struct json_childs *next;
 unsigned int type;
};
struct jsontring {
 char *jstring;
 size_t jsize;
 size_t len;
};
typedef enum {
 JSON_C_T_OBJ,
 JSON_C_T_ARR,
 JSON_C_T_VAL,
 JSON_C_T_NULL,
} json_child_t;
typedef struct _json_item {
 struct JSON_value_struct jval;
 struct {
  struct _json_item *child;
  struct _json_item *head;
  json_child_t type;
 } jchild;
 struct {
         char *val;
         size_t len;
 } key;
 struct _json_item *father;
 struct _json_item *next;
 int type;
} json_item;
typedef struct _json_context {
 int key_under;
 int start_depth;
 json_item *head;
 json_item *current_cx;
} json_context;
void set_json(const char *name, const char *value, struct json **jprev);
struct json *json_copy(struct json *jbase);
void json_attach(struct json *json_father, struct json *json_child, unsigned int type);
void json_concat(struct json *json_father, struct json *json_child);
void json_free(struct json *jbase);
json_item *init_json_parser(const char *json_string);
json_item *json_lookup(json_item *head, char *path);
void free_json_item(json_item *cx);
json_item *json_new_object();
json_item *json_new_array();
json_item *json_set_property_objN(json_item *obj, const char *key, int keylen, json_item *value);
void json_set_property_objZ(json_item *obj, const char *key, json_item *value);
json_item *json_set_property_strN(json_item *obj, const char *key, int keylen, const char *value, int valuelen);
void json_set_property_strZ(json_item *obj, const char *key, const char *value);
json_item *json_set_element_strN(json_item *obj, const char *value, int valuelen);
void json_set_element_strZ(json_item *obj, const char *value);
void json_set_element_int(json_item *obj, long int value);
void json_set_element_float(json_item *obj, long double value);
void json_set_element_boolean(json_item *obj, int value);
void json_set_element_null(json_item *obj);
void json_set_element_obj(json_item *obj, json_item *value);
json_item *json_set_property_intN(json_item *obj, const char *key, int keylen, JSON_int_t value);
void json_set_property_intZ(json_item *obj, const char *key, JSON_int_t value);
json_item *json_set_property_floatN(json_item *obj, const char *key, int keylen, long double value);
json_item *json_set_property_boolean(json_item *obj, const char *key, int keylen, int value);
json_item *json_set_property_null(json_item *obj, const char *key, int keylen);
struct jsontring *json_to_string(json_item *head, struct jsontring *string, int free_tree);
json_item *json_item_copy(json_item *cx, json_item *father);
void json_aff(json_item *cx, int depth);
enum {
 CHANNEL_PIPE = 0,
 USER_PIPE,
 PROXY_PIPE,
 CUSTOM_PIPE
};
typedef struct _pipe_link pipe_link;
struct _pipe_link {
 struct _transpipe *plink;
 struct _pipe_link *next;
 void (*on_unlink)(struct _transpipe *, struct _transpipe *, acetables *);
};
typedef struct _transpipe transpipe;
struct _transpipe
{
 void *pipe;
 void *data;
 struct _pipe_link *link;
 struct _extend *properties;
 void (*on_send)(struct _transpipe *, struct USERS *, json_item *, acetables *);
 int type;
 char pubid[33];
};
transpipe *init_pipe(void *pipe, int type, acetables *g_ape);
void destroy_pipe(transpipe *pipe, acetables *g_ape);
void link_pipe(transpipe *pipe_origin, transpipe *pipe_to, void (*on_unlink)(struct _transpipe *, struct _transpipe *, acetables *));
transpipe *get_pipe(const char *pubid, acetables *g_ape);
transpipe *get_pipe_strict(const char *pubid, struct USERS *user, acetables *g_ape);
void post_json_custom(json_item *jstr, struct USERS *user, struct _transpipe *pipe, acetables *g_ape);
void gen_sessid_new(char *input, acetables *g_ape);
void unlink_all_pipe(transpipe *origin, acetables *g_ape);
json_item *get_json_object_pipe(transpipe *pipe);
json_item *get_json_object_pipe_custom(transpipe *pipe);
typedef enum {
 EXTEND_STR,
 EXTEND_JSON,
 EXTEND_POINTER
} EXTEND_TYPE;
typedef enum {
 EXTEND_ISPUBLIC,
 EXTEND_ISPRIVATE
} EXTEND_PUBLIC;
typedef struct _extend extend;
struct _extend
{
 void *val;
 EXTEND_TYPE type;
 EXTEND_PUBLIC visibility;
 struct _extend *next;
 char key[32 +1];
};
extend *get_property(extend *entry, const char *key);
void clear_properties(extend **entry);
void del_property(extend **entry, const char *key);
extend *add_property(extend **entry, const char *key, void *val, EXTEND_TYPE etype, EXTEND_PUBLIC visibility);
typedef struct CHANNEL
{
 struct _transpipe *pipe;
 struct userslist *head;
 struct BANNED *banned;
 extend *properties;
 int flags;
 char name[40 +1];
} CHANNEL;
typedef struct BANNED
{
 char ip[16];
 char reason[257];
 long int expire;
 struct BANNED *next;
} BANNED;
CHANNEL *mkchan(char *chan, int flags, acetables *g_ape);
CHANNEL *getchan(const char *chan, acetables *g_ape);
BANNED *getban(CHANNEL *chan, const char *ip);
CHANNEL *getchanbypubid(const char *pubid, acetables *g_ape);
int mkallchan(acetables *g_ape);
void rmchan(CHANNEL *chan, acetables *g_ape);
void join(struct USERS *user, CHANNEL *chan, acetables *g_ape);
void left(struct USERS *user, CHANNEL *chan, acetables *g_ape);
void left_all(struct USERS *user, acetables *g_ape);
void ban(CHANNEL *chan, struct USERS *banner, const char *ip, char *reason, unsigned int expire, acetables *g_ape);
void rmban(CHANNEL *chan, const char *ip);
void rmallban(CHANNEL *chan);
struct userslist *getlist(const char *chan, acetables *g_ape);
struct userslist *getuchan(struct USERS *user, CHANNEL *chan);
unsigned int setlevel(struct USERS *user_actif, struct USERS *user_passif, CHANNEL *chan, unsigned int lvl, acetables *g_ape);
unsigned int isvalidchan(char *name);
json_item *get_json_object_channel(CHANNEL *chan);
struct _raw_pool {
 struct RAW *raw;
 struct _raw_pool *next;
 struct _raw_pool *prev;
 int start;
};
typedef struct USERS
{
 struct {
  struct _link_list *ulink;
  int nlink;
 } links;
 struct {
  struct _session *data;
  int length;
 } sessions;
 struct USERS *next;
 struct USERS *prev;
 struct CHANLIST *chan_foot;
 struct _transpipe *pipe;
 struct _extend *properties;
 struct _subuser *subuser;
 json_item *cmdqueue;
 time_t idle;
 int transport;
 int nsub;
 unsigned int nraw;
 unsigned int flags;
 unsigned short int type;
 unsigned short int istmp;
 char ip[16];
 char lastping[24];
 char sessid[33];
} USERS;
struct _raw_pool_user {
 int nraw;
 int size;
 struct _raw_pool *rawhead;
 struct _raw_pool *rawfoot;
};
typedef struct _subuser subuser;
struct _subuser
{
 struct {
  struct _raw_pool_user low;
  struct _raw_pool_user high;
  int nraw;
 } raw_pools;
 struct {
  struct _http_headers_response *content;
  int sent;
 } headers;
 struct _extend *properties;
 struct _subuser *next;
 ape_socket *client;
 USERS *user;
 time_t idle;
 int state;
 int need_update;
 int wait_for_free;
 int nraw;
 int burn_after_writing;
 int current_chl;
 char channel[256 +1];
};
typedef struct CHANLIST
{
 struct CHANNEL *chaninfo;
 struct CHANLIST *next;
} CHANLIST;
struct _users_link
{
 USERS *a;
 USERS *b;
 int link_type;
};
struct _link_list
{
 struct _users_link *link;
 struct _link_list *next;
};
typedef struct userslist
{
 struct USERS *userinfo;
 struct userslist *next;
 unsigned int level;
} userslist;
typedef struct _session session;
struct _session
{
 char *val;
 struct _session *next;
 char key[33];
};
enum {
 ALIVE = 0,
 ADIED
};
enum {
 HUMAN = 0,
 BOT
};
enum {
 PRIVMSG = 0,
 CHANMSG,
 INFOMSG
};
enum {
 RAW_MSG = 0,
 RAW_LOGIN,
 RAW_JOIN,
 RAW_LEFT,
 RAW_SETLEVEL
};
USERS *seek_user(const char *nick, const char *linkid, acetables *g_ape);
USERS *init_user(acetables *g_ape);
USERS *adduser(ape_socket *client, const char *host, const char *ip, USERS *allocated, acetables *g_ape);
USERS *seek_user_id(const char *sessid, acetables *g_ape);
USERS *seek_user_simple(const char *nick, acetables *g_ape);
void deluser(USERS *user, acetables *g_ape);
void do_died(subuser *user, acetables *g_ape);
void check_timeout(acetables *g_ape, int *last);
void grant_aceop(USERS *user);
void send_error(USERS *user, const char *msg, const char *code, acetables *g_ape);
void send_msg(USERS *user, const char *msg, const char *type, acetables *g_ape);
void send_msg_sub(subuser *sub, const char *msg, const char *type, acetables *g_ape);
void send_msg_channel(struct CHANNEL *chan, const char *msg, const char *type, acetables *g_ape);
unsigned int isonchannel(USERS *user, struct CHANNEL *chan);
json_item *get_json_object_user(USERS *user);
session *get_session(USERS *user, const char *key);
session *set_session(USERS *user, const char *key, const char *val, int update, acetables *g_ape);
void clear_sessions(USERS *user);
void sendback_session(USERS *user, session *sess, acetables *g_ape);
subuser *addsubuser(ape_socket *client, const char *channel, USERS *user, acetables *g_ape);
subuser *getsubuser(USERS *user, const char *channel);
void delsubuser(subuser **current, acetables *g_ape);
void subuser_restor(subuser *sub, acetables *g_ape);
void clear_subusers(USERS *user, acetables *g_ape);
void ping_request(USERS *user, acetables *g_ape);
void make_link(USERS *a, USERS *b);
struct _users_link *are_linked(USERS *a, USERS *b);
void destroy_link(USERS *a, USERS *b);
struct _http_headers_fields
{
 struct {
  char val[32];
  int len;
 } key;
 struct {
  char *val;
  int len;
 } value;
 struct _http_headers_fields *next;
};
typedef struct _http_headers_response http_headers_response;
struct _http_headers_response
{
 int code;
 struct {
  char val[64];
  int len;
 } detail;
 struct _http_headers_fields *fields;
 struct _http_headers_fields *last;
};
typedef enum {
 HTTP_NULL = 0,
 HTTP_GET,
 HTTP_GET_WS,
 HTTP_POST,
 HTTP_OPTIONS
} http_method;
struct _http_header_line
{
 struct {
  char val[64];
  unsigned int len;
 } key;
 struct {
  char val[1024];
  unsigned int len;
 } value;
 struct _http_header_line *next;
};
void process_websocket(ape_socket *co, acetables *g_ape);
void process_http(ape_socket *co, acetables *g_ape);
http_headers_response *http_headers_init(int code, char *detail, int detail_len);
void http_headers_set_field(http_headers_response *headers, const char *key, int keylen, const char *value, int valuelen);
int http_send_headers(http_headers_response *headers, const char *default_h, unsigned int default_len, ape_socket *client, acetables *g_ape);
void http_headers_free(http_headers_response *headers);
void free_header_line(struct _http_header_line *line);
char *get_header_line(struct _http_header_line *lines, const char *key);
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
typedef long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long int uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef unsigned long int uintptr_t;
typedef long int intmax_t;
typedef unsigned long int uintmax_t;


struct iovec
  {
    void *iov_base;
    size_t iov_len;
  };
extern ssize_t readv (int __fd, __const struct iovec *__iovec, int __count)
  ;
extern ssize_t writev (int __fd, __const struct iovec *__iovec, int __count)
  ;
extern ssize_t preadv (int __fd, __const struct iovec *__iovec, int __count,
         __off_t __offset) ;
extern ssize_t pwritev (int __fd, __const struct iovec *__iovec, int __count,
   __off_t __offset) ;

enum __socket_type
{
  SOCK_STREAM = 1,
  SOCK_DGRAM = 2,
  SOCK_RAW = 3,
  SOCK_RDM = 4,
  SOCK_SEQPACKET = 5,
  SOCK_DCCP = 6,
  SOCK_PACKET = 10,
  SOCK_CLOEXEC = 02000000,
  SOCK_NONBLOCK = 04000
};
typedef unsigned short int sa_family_t;
struct sockaddr
  {
    sa_family_t sa_family;
    char sa_data[14];
  };
struct sockaddr_storage
  {
    sa_family_t ss_family;
    unsigned long int __ss_align;
    char __ss_padding[(128 - (2 * sizeof (unsigned long int)))];
  };
enum
  {
    MSG_OOB = 0x01,
    MSG_PEEK = 0x02,
    MSG_DONTROUTE = 0x04,
    MSG_CTRUNC = 0x08,
    MSG_PROXY = 0x10,
    MSG_TRUNC = 0x20,
    MSG_DONTWAIT = 0x40,
    MSG_EOR = 0x80,
    MSG_WAITALL = 0x100,
    MSG_FIN = 0x200,
    MSG_SYN = 0x400,
    MSG_CONFIRM = 0x800,
    MSG_RST = 0x1000,
    MSG_ERRQUEUE = 0x2000,
    MSG_NOSIGNAL = 0x4000,
    MSG_MORE = 0x8000,
    MSG_CMSG_CLOEXEC = 0x40000000
  };
struct msghdr
  {
    void *msg_name;
    socklen_t msg_namelen;
    struct iovec *msg_iov;
    size_t msg_iovlen;
    void *msg_control;
    size_t msg_controllen;
    int msg_flags;
  };
struct cmsghdr
  {
    size_t cmsg_len;
    int cmsg_level;
    int cmsg_type;
    __extension__ unsigned char __cmsg_data [];
  };
extern struct cmsghdr *__cmsg_nxthdr (struct msghdr *__mhdr,
          struct cmsghdr *__cmsg) __attribute__ ((__nothrow__));
enum
  {
    SCM_RIGHTS = 0x01
  };
struct linger
  {
    int l_onoff;
    int l_linger;
  };
struct osockaddr
  {
    unsigned short int sa_family;
    unsigned char sa_data[14];
  };
enum
{
  SHUT_RD = 0,
  SHUT_WR,
  SHUT_RDWR
};
extern int socket (int __domain, int __type, int __protocol) __attribute__ ((__nothrow__));
extern int socketpair (int __domain, int __type, int __protocol,
         int __fds[2]) __attribute__ ((__nothrow__));
extern int bind (int __fd, __const struct sockaddr * __addr, socklen_t __len)
     __attribute__ ((__nothrow__));
extern int getsockname (int __fd, struct sockaddr *__restrict __addr,
   socklen_t *__restrict __len) __attribute__ ((__nothrow__));
extern int connect (int __fd, __const struct sockaddr * __addr, socklen_t __len);
extern int getpeername (int __fd, struct sockaddr *__restrict __addr,
   socklen_t *__restrict __len) __attribute__ ((__nothrow__));
extern ssize_t send (int __fd, __const void *__buf, size_t __n, int __flags);
extern ssize_t recv (int __fd, void *__buf, size_t __n, int __flags);
extern ssize_t sendto (int __fd, __const void *__buf, size_t __n,
         int __flags, __const struct sockaddr * __addr,
         socklen_t __addr_len);
extern ssize_t recvfrom (int __fd, void *__restrict __buf, size_t __n,
    int __flags, struct sockaddr *__restrict __addr,
    socklen_t *__restrict __addr_len);
extern ssize_t sendmsg (int __fd, __const struct msghdr *__message,
   int __flags);
extern ssize_t recvmsg (int __fd, struct msghdr *__message, int __flags);
extern int getsockopt (int __fd, int __level, int __optname,
         void *__restrict __optval,
         socklen_t *__restrict __optlen) __attribute__ ((__nothrow__));
extern int setsockopt (int __fd, int __level, int __optname,
         __const void *__optval, socklen_t __optlen) __attribute__ ((__nothrow__));
extern int listen (int __fd, int __n) __attribute__ ((__nothrow__));
extern int accept (int __fd, struct sockaddr *__restrict __addr,
     socklen_t *__restrict __addr_len);
extern int shutdown (int __fd, int __how) __attribute__ ((__nothrow__));
extern int sockatmark (int __fd) __attribute__ ((__nothrow__));
extern int isfdtype (int __fd, int __fdtype) __attribute__ ((__nothrow__));


enum
  {
    IPPROTO_IP = 0,
    IPPROTO_HOPOPTS = 0,
    IPPROTO_ICMP = 1,
    IPPROTO_IGMP = 2,
    IPPROTO_IPIP = 4,
    IPPROTO_TCP = 6,
    IPPROTO_EGP = 8,
    IPPROTO_PUP = 12,
    IPPROTO_UDP = 17,
    IPPROTO_IDP = 22,
    IPPROTO_TP = 29,
    IPPROTO_DCCP = 33,
    IPPROTO_IPV6 = 41,
    IPPROTO_ROUTING = 43,
    IPPROTO_FRAGMENT = 44,
    IPPROTO_RSVP = 46,
    IPPROTO_GRE = 47,
    IPPROTO_ESP = 50,
    IPPROTO_AH = 51,
    IPPROTO_ICMPV6 = 58,
    IPPROTO_NONE = 59,
    IPPROTO_DSTOPTS = 60,
    IPPROTO_MTP = 92,
    IPPROTO_ENCAP = 98,
    IPPROTO_PIM = 103,
    IPPROTO_COMP = 108,
    IPPROTO_SCTP = 132,
    IPPROTO_UDPLITE = 136,
    IPPROTO_RAW = 255,
    IPPROTO_MAX
  };
typedef uint16_t in_port_t;
enum
  {
    IPPORT_ECHO = 7,
    IPPORT_DISCARD = 9,
    IPPORT_SYSTAT = 11,
    IPPORT_DAYTIME = 13,
    IPPORT_NETSTAT = 15,
    IPPORT_FTP = 21,
    IPPORT_TELNET = 23,
    IPPORT_SMTP = 25,
    IPPORT_TIMESERVER = 37,
    IPPORT_NAMESERVER = 42,
    IPPORT_WHOIS = 43,
    IPPORT_MTP = 57,
    IPPORT_TFTP = 69,
    IPPORT_RJE = 77,
    IPPORT_FINGER = 79,
    IPPORT_TTYLINK = 87,
    IPPORT_SUPDUP = 95,
    IPPORT_EXECSERVER = 512,
    IPPORT_LOGINSERVER = 513,
    IPPORT_CMDSERVER = 514,
    IPPORT_EFSSERVER = 520,
    IPPORT_BIFFUDP = 512,
    IPPORT_WHOSERVER = 513,
    IPPORT_ROUTESERVER = 520,
    IPPORT_RESERVED = 1024,
    IPPORT_USERRESERVED = 5000
  };
typedef uint32_t in_addr_t;
struct in_addr
  {
    in_addr_t s_addr;
  };
struct in6_addr
  {
    union
      {
 uint8_t __u6_addr8[16];
 uint16_t __u6_addr16[8];
 uint32_t __u6_addr32[4];
      } __in6_u;
  };
extern const struct in6_addr in6addr_any;
extern const struct in6_addr in6addr_loopback;
struct sockaddr_in
  {
    sa_family_t sin_family;
    in_port_t sin_port;
    struct in_addr sin_addr;
    unsigned char sin_zero[sizeof (struct sockaddr) -
      (sizeof (unsigned short int)) -
      sizeof (in_port_t) -
      sizeof (struct in_addr)];
  };
struct sockaddr_in6
  {
    sa_family_t sin6_family;
    in_port_t sin6_port;
    uint32_t sin6_flowinfo;
    struct in6_addr sin6_addr;
    uint32_t sin6_scope_id;
  };
struct ip_mreq
  {
    struct in_addr imr_multiaddr;
    struct in_addr imr_interface;
  };
struct ip_mreq_source
  {
    struct in_addr imr_multiaddr;
    struct in_addr imr_interface;
    struct in_addr imr_sourceaddr;
  };
struct ipv6_mreq
  {
    struct in6_addr ipv6mr_multiaddr;
    unsigned int ipv6mr_interface;
  };
struct group_req
  {
    uint32_t gr_interface;
    struct sockaddr_storage gr_group;
  };
struct group_source_req
  {
    uint32_t gsr_interface;
    struct sockaddr_storage gsr_group;
    struct sockaddr_storage gsr_source;
  };
struct ip_msfilter
  {
    struct in_addr imsf_multiaddr;
    struct in_addr imsf_interface;
    uint32_t imsf_fmode;
    uint32_t imsf_numsrc;
    struct in_addr imsf_slist[1];
  };
struct group_filter
  {
    uint32_t gf_interface;
    struct sockaddr_storage gf_group;
    uint32_t gf_fmode;
    uint32_t gf_numsrc;
    struct sockaddr_storage gf_slist[1];
};
struct ip_opts
  {
    struct in_addr ip_dst;
    char ip_opts[40];
  };
struct ip_mreqn
  {
    struct in_addr imr_multiaddr;
    struct in_addr imr_address;
    int imr_ifindex;
  };
struct in_pktinfo
  {
    int ipi_ifindex;
    struct in_addr ipi_spec_dst;
    struct in_addr ipi_addr;
  };
extern uint32_t ntohl (uint32_t __netlong) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern uint16_t ntohs (uint16_t __netshort)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern uint32_t htonl (uint32_t __hostlong)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern uint16_t htons (uint16_t __hostshort)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int bindresvport (int __sockfd, struct sockaddr_in *__sock_in) __attribute__ ((__nothrow__));
extern int bindresvport6 (int __sockfd, struct sockaddr_in6 *__sock_in)
     __attribute__ ((__nothrow__));

struct tcphdr
  {
    u_int16_t source;
    u_int16_t dest;
    u_int32_t seq;
    u_int32_t ack_seq;
    u_int16_t res1:4;
    u_int16_t doff:4;
    u_int16_t fin:1;
    u_int16_t syn:1;
    u_int16_t rst:1;
    u_int16_t psh:1;
    u_int16_t ack:1;
    u_int16_t urg:1;
    u_int16_t res2:2;
    u_int16_t window;
    u_int16_t check;
    u_int16_t urg_ptr;
};
enum
{
  TCP_ESTABLISHED = 1,
  TCP_SYN_SENT,
  TCP_SYN_RECV,
  TCP_FIN_WAIT1,
  TCP_FIN_WAIT2,
  TCP_TIME_WAIT,
  TCP_CLOSE,
  TCP_CLOSE_WAIT,
  TCP_LAST_ACK,
  TCP_LISTEN,
  TCP_CLOSING
};
enum tcp_ca_state
{
  TCP_CA_Open = 0,
  TCP_CA_Disorder = 1,
  TCP_CA_CWR = 2,
  TCP_CA_Recovery = 3,
  TCP_CA_Loss = 4
};
struct tcp_info
{
  u_int8_t tcpi_state;
  u_int8_t tcpi_ca_state;
  u_int8_t tcpi_retransmits;
  u_int8_t tcpi_probes;
  u_int8_t tcpi_backoff;
  u_int8_t tcpi_options;
  u_int8_t tcpi_snd_wscale : 4, tcpi_rcv_wscale : 4;
  u_int32_t tcpi_rto;
  u_int32_t tcpi_ato;
  u_int32_t tcpi_snd_mss;
  u_int32_t tcpi_rcv_mss;
  u_int32_t tcpi_unacked;
  u_int32_t tcpi_sacked;
  u_int32_t tcpi_lost;
  u_int32_t tcpi_retrans;
  u_int32_t tcpi_fackets;
  u_int32_t tcpi_last_data_sent;
  u_int32_t tcpi_last_ack_sent;
  u_int32_t tcpi_last_data_recv;
  u_int32_t tcpi_last_ack_recv;
  u_int32_t tcpi_pmtu;
  u_int32_t tcpi_rcv_ssthresh;
  u_int32_t tcpi_rtt;
  u_int32_t tcpi_rttvar;
  u_int32_t tcpi_snd_ssthresh;
  u_int32_t tcpi_snd_cwnd;
  u_int32_t tcpi_advmss;
  u_int32_t tcpi_reordering;
  u_int32_t tcpi_rcv_rtt;
  u_int32_t tcpi_rcv_space;
  u_int32_t tcpi_total_retrans;
};
struct tcp_md5sig
{
  struct sockaddr_storage tcpm_addr;
  u_int16_t __tcpm_pad1;
  u_int16_t tcpm_keylen;
  u_int32_t __tcpm_pad2;
  u_int8_t tcpm_key[80];
};


extern int __sigismember (__const __sigset_t *, int);
extern int __sigaddset (__sigset_t *, int);
extern int __sigdelset (__sigset_t *, int);

typedef __sig_atomic_t sig_atomic_t;

typedef union sigval
  {
    int sival_int;
    void *sival_ptr;
  } sigval_t;
typedef struct siginfo
  {
    int si_signo;
    int si_errno;
    int si_code;
    union
      {
 int _pad[((128 / sizeof (int)) - 4)];
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
   } _kill;
 struct
   {
     int si_tid;
     int si_overrun;
     sigval_t si_sigval;
   } _timer;
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     sigval_t si_sigval;
   } _rt;
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     int si_status;
     __clock_t si_utime;
     __clock_t si_stime;
   } _sigchld;
 struct
   {
     void *si_addr;
   } _sigfault;
 struct
   {
     long int si_band;
     int si_fd;
   } _sigpoll;
      } _sifields;
  } siginfo_t;
enum
{
  SI_ASYNCNL = -60,
  SI_TKILL = -6,
  SI_SIGIO,
  SI_ASYNCIO,
  SI_MESGQ,
  SI_TIMER,
  SI_QUEUE,
  SI_USER,
  SI_KERNEL = 0x80
};
enum
{
  ILL_ILLOPC = 1,
  ILL_ILLOPN,
  ILL_ILLADR,
  ILL_ILLTRP,
  ILL_PRVOPC,
  ILL_PRVREG,
  ILL_COPROC,
  ILL_BADSTK
};
enum
{
  FPE_INTDIV = 1,
  FPE_INTOVF,
  FPE_FLTDIV,
  FPE_FLTOVF,
  FPE_FLTUND,
  FPE_FLTRES,
  FPE_FLTINV,
  FPE_FLTSUB
};
enum
{
  SEGV_MAPERR = 1,
  SEGV_ACCERR
};
enum
{
  BUS_ADRALN = 1,
  BUS_ADRERR,
  BUS_OBJERR
};
enum
{
  TRAP_BRKPT = 1,
  TRAP_TRACE
};
enum
{
  CLD_EXITED = 1,
  CLD_KILLED,
  CLD_DUMPED,
  CLD_TRAPPED,
  CLD_STOPPED,
  CLD_CONTINUED
};
enum
{
  POLL_IN = 1,
  POLL_OUT,
  POLL_MSG,
  POLL_ERR,
  POLL_PRI,
  POLL_HUP
};
typedef struct sigevent
  {
    sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;
    union
      {
 int _pad[((64 / sizeof (int)) - 4)];
 __pid_t _tid;
 struct
   {
     void (*_function) (sigval_t);
     void *_attribute;
   } _sigev_thread;
      } _sigev_un;
  } sigevent_t;
enum
{
  SIGEV_SIGNAL = 0,
  SIGEV_NONE,
  SIGEV_THREAD,
  SIGEV_THREAD_ID = 4
};
typedef void (*__sighandler_t) (int);
extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__));

extern __sighandler_t signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__));

extern int kill (__pid_t __pid, int __sig) __attribute__ ((__nothrow__));
extern int killpg (__pid_t __pgrp, int __sig) __attribute__ ((__nothrow__));

extern int raise (int __sig) __attribute__ ((__nothrow__));

extern __sighandler_t ssignal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__));
extern int gsignal (int __sig) __attribute__ ((__nothrow__));
extern void psignal (int __sig, __const char *__s);
extern void psiginfo (__const siginfo_t *__pinfo, __const char *__s);
extern int __sigpause (int __sig_or_mask, int __is_sig);
extern int sigblock (int __mask) __attribute__ ((__nothrow__)) __attribute__ ((__deprecated__));
extern int sigsetmask (int __mask) __attribute__ ((__nothrow__)) __attribute__ ((__deprecated__));
extern int siggetmask (void) __attribute__ ((__nothrow__)) __attribute__ ((__deprecated__));
typedef __sighandler_t sig_t;
extern int sigemptyset (sigset_t *__set) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int sigfillset (sigset_t *__set) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int sigaddset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int sigdelset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int sigismember (__const sigset_t *__set, int __signo)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
struct sigaction
  {
    union
      {
 __sighandler_t sa_handler;
 void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;
    __sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer) (void);
  };
extern int sigprocmask (int __how, __const sigset_t *__restrict __set,
   sigset_t *__restrict __oset) __attribute__ ((__nothrow__));
extern int sigsuspend (__const sigset_t *__set) __attribute__ ((__nonnull__ (1)));
extern int sigaction (int __sig, __const struct sigaction *__restrict __act,
        struct sigaction *__restrict __oact) __attribute__ ((__nothrow__));
extern int sigpending (sigset_t *__set) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int sigwait (__const sigset_t *__restrict __set, int *__restrict __sig)
     __attribute__ ((__nonnull__ (1, 2)));
extern int sigwaitinfo (__const sigset_t *__restrict __set,
   siginfo_t *__restrict __info) __attribute__ ((__nonnull__ (1)));
extern int sigtimedwait (__const sigset_t *__restrict __set,
    siginfo_t *__restrict __info,
    __const struct timespec *__restrict __timeout)
     __attribute__ ((__nonnull__ (1)));
extern int sigqueue (__pid_t __pid, int __sig, __const union sigval __val)
     __attribute__ ((__nothrow__));
extern __const char *__const _sys_siglist[65];
extern __const char *__const sys_siglist[65];
struct sigvec
  {
    __sighandler_t sv_handler;
    int sv_mask;
    int sv_flags;
  };
extern int sigvec (int __sig, __const struct sigvec *__vec,
     struct sigvec *__ovec) __attribute__ ((__nothrow__));
struct _fpreg
{
  unsigned short significand[4];
  unsigned short exponent;
};
struct _fpxreg
{
  unsigned short significand[4];
  unsigned short exponent;
  unsigned short padding[3];
};
struct _xmmreg
{
  __uint32_t element[4];
};
struct _fpstate
{
  __uint16_t cwd;
  __uint16_t swd;
  __uint16_t ftw;
  __uint16_t fop;
  __uint64_t rip;
  __uint64_t rdp;
  __uint32_t mxcsr;
  __uint32_t mxcr_mask;
  struct _fpxreg _st[8];
  struct _xmmreg _xmm[16];
  __uint32_t padding[24];
};
struct sigcontext
{
  unsigned long r8;
  unsigned long r9;
  unsigned long r10;
  unsigned long r11;
  unsigned long r12;
  unsigned long r13;
  unsigned long r14;
  unsigned long r15;
  unsigned long rdi;
  unsigned long rsi;
  unsigned long rbp;
  unsigned long rbx;
  unsigned long rdx;
  unsigned long rax;
  unsigned long rcx;
  unsigned long rsp;
  unsigned long rip;
  unsigned long eflags;
  unsigned short cs;
  unsigned short gs;
  unsigned short fs;
  unsigned short __pad0;
  unsigned long err;
  unsigned long trapno;
  unsigned long oldmask;
  unsigned long cr2;
  struct _fpstate * fpstate;
  unsigned long __reserved1 [8];
};
extern int sigreturn (struct sigcontext *__scp) __attribute__ ((__nothrow__));
extern int siginterrupt (int __sig, int __interrupt) __attribute__ ((__nothrow__));
struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };
enum
{
  SS_ONSTACK = 1,
  SS_DISABLE
};
typedef struct sigaltstack
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;
extern int sigstack (struct sigstack *__ss, struct sigstack *__oss)
     __attribute__ ((__nothrow__)) __attribute__ ((__deprecated__));
extern int sigaltstack (__const struct sigaltstack *__restrict __ss,
   struct sigaltstack *__restrict __oss) __attribute__ ((__nothrow__));
extern int pthread_sigmask (int __how,
       __const __sigset_t *__restrict __newmask,
       __sigset_t *__restrict __oldmask)__attribute__ ((__nothrow__));
extern int pthread_kill (pthread_t __threadid, int __signo) __attribute__ ((__nothrow__));
extern int __libc_current_sigrtmin (void) __attribute__ ((__nothrow__));
extern int __libc_current_sigrtmax (void) __attribute__ ((__nothrow__));

enum __rlimit_resource
{
  RLIMIT_CPU = 0,
  RLIMIT_FSIZE = 1,
  RLIMIT_DATA = 2,
  RLIMIT_STACK = 3,
  RLIMIT_CORE = 4,
  __RLIMIT_RSS = 5,
  RLIMIT_NOFILE = 7,
  __RLIMIT_OFILE = RLIMIT_NOFILE,
  RLIMIT_AS = 9,
  __RLIMIT_NPROC = 6,
  __RLIMIT_MEMLOCK = 8,
  __RLIMIT_LOCKS = 10,
  __RLIMIT_SIGPENDING = 11,
  __RLIMIT_MSGQUEUE = 12,
  __RLIMIT_NICE = 13,
  __RLIMIT_RTPRIO = 14,
  __RLIMIT_NLIMITS = 15,
  __RLIM_NLIMITS = __RLIMIT_NLIMITS
};
typedef __rlim_t rlim_t;
struct rlimit
  {
    rlim_t rlim_cur;
    rlim_t rlim_max;
  };
enum __rusage_who
{
  RUSAGE_SELF = 0,
  RUSAGE_CHILDREN = -1
};
struct rusage
  {
    struct timeval ru_utime;
    struct timeval ru_stime;
    long int ru_maxrss;
    long int ru_ixrss;
    long int ru_idrss;
    long int ru_isrss;
    long int ru_minflt;
    long int ru_majflt;
    long int ru_nswap;
    long int ru_inblock;
    long int ru_oublock;
    long int ru_msgsnd;
    long int ru_msgrcv;
    long int ru_nsignals;
    long int ru_nvcsw;
    long int ru_nivcsw;
  };
enum __priority_which
{
  PRIO_PROCESS = 0,
  PRIO_PGRP = 1,
  PRIO_USER = 2
};

typedef int __rlimit_resource_t;
typedef int __rusage_who_t;
typedef int __priority_which_t;
extern int getrlimit (__rlimit_resource_t __resource,
        struct rlimit *__rlimits) __attribute__ ((__nothrow__));
extern int setrlimit (__rlimit_resource_t __resource,
        __const struct rlimit *__rlimits) __attribute__ ((__nothrow__));
extern int getrusage (__rusage_who_t __who, struct rusage *__usage) __attribute__ ((__nothrow__));
extern int getpriority (__priority_which_t __which, id_t __who) __attribute__ ((__nothrow__));
extern int setpriority (__priority_which_t __which, id_t __who, int __prio)
     __attribute__ ((__nothrow__));

typedef union
  {
    union wait *__uptr;
    int *__iptr;
  } __WAIT_STATUS __attribute__ ((__transparent_union__));
union wait
  {
    int w_status;
    struct
      {
 unsigned int __w_termsig:7;
 unsigned int __w_coredump:1;
 unsigned int __w_retcode:8;
 unsigned int:16;
      } __wait_terminated;
    struct
      {
 unsigned int __w_stopval:8;
 unsigned int __w_stopsig:8;
 unsigned int:16;
      } __wait_stopped;
  };
typedef enum
{
  P_ALL,
  P_PID,
  P_PGID
} idtype_t;
extern __pid_t wait (__WAIT_STATUS __stat_loc);
extern __pid_t waitpid (__pid_t __pid, int *__stat_loc, int __options);
extern int waitid (idtype_t __idtype, __id_t __id, siginfo_t *__infop,
     int __options);
struct rusage;
extern __pid_t wait3 (__WAIT_STATUS __stat_loc, int __options,
        struct rusage * __usage) __attribute__ ((__nothrow__));
extern __pid_t wait4 (__pid_t __pid, __WAIT_STATUS __stat_loc, int __options,
        struct rusage *__usage) __attribute__ ((__nothrow__));


extern in_addr_t inet_addr (__const char *__cp) __attribute__ ((__nothrow__));
extern in_addr_t inet_lnaof (struct in_addr __in) __attribute__ ((__nothrow__));
extern struct in_addr inet_makeaddr (in_addr_t __net, in_addr_t __host)
     __attribute__ ((__nothrow__));
extern in_addr_t inet_netof (struct in_addr __in) __attribute__ ((__nothrow__));
extern in_addr_t inet_network (__const char *__cp) __attribute__ ((__nothrow__));
extern char *inet_ntoa (struct in_addr __in) __attribute__ ((__nothrow__));
extern int inet_pton (int __af, __const char *__restrict __cp,
        void *__restrict __buf) __attribute__ ((__nothrow__));
extern __const char *inet_ntop (int __af, __const void *__restrict __cp,
    char *__restrict __buf, socklen_t __len)
     __attribute__ ((__nothrow__));
extern int inet_aton (__const char *__cp, struct in_addr *__inp) __attribute__ ((__nothrow__));
extern char *inet_neta (in_addr_t __net, char *__buf, size_t __len) __attribute__ ((__nothrow__));
extern char *inet_net_ntop (int __af, __const void *__cp, int __bits,
       char *__buf, size_t __len) __attribute__ ((__nothrow__));
extern int inet_net_pton (int __af, __const char *__cp,
     void *__buf, size_t __len) __attribute__ ((__nothrow__));
extern unsigned int inet_nsap_addr (__const char *__cp,
        unsigned char *__buf, int __len) __attribute__ ((__nothrow__));
extern char *inet_nsap_ntoa (int __len, __const unsigned char *__cp,
        char *__buf) __attribute__ ((__nothrow__));


struct flock
  {
    short int l_type;
    short int l_whence;
    __off_t l_start;
    __off_t l_len;
    __pid_t l_pid;
  };


extern int fcntl (int __fd, int __cmd, ...);
extern int open (__const char *__file, int __oflag, ...) __attribute__ ((__nonnull__ (1)));
extern int openat (int __fd, __const char *__file, int __oflag, ...)
     __attribute__ ((__nonnull__ (2)));
extern int openat64 (int __fd, __const char *__file, int __oflag, ...)
     __attribute__ ((__nonnull__ (2)));
extern int creat (__const char *__file, __mode_t __mode) __attribute__ ((__nonnull__ (1)));
extern int posix_fadvise (int __fd, __off_t __offset, __off_t __len,
     int __advise) __attribute__ ((__nothrow__));
extern int posix_fallocate (int __fd, __off_t __offset, __off_t __len);

struct _socks_bufout
{
 char *buf;
 int fd;
 int buflen;
 int allocsize;
};
struct _socks_list
{
 struct _ape_socket *co;
 int *tfd;
};
struct _ape_sock_connect_async
{
 ape_socket *sock;
 int port;
};
ape_socket *ape_listen(unsigned int port, char *listen_ip, acetables *g_ape);
ape_socket *ape_connect(char *ip, int port, acetables *g_ape);
void ape_connect_name(char *name, int port, ape_socket *pattern, acetables *g_ape);
void prepare_ape_socket(int fd, acetables *g_ape);
void setnonblocking(int fd);
int sendf(int sock, acetables *g_ape, char *buf, ...);
int sendbin(int sock, const char *bin, unsigned int len, unsigned int burn_after_writing, acetables *g_ape);
void safe_shutdown(int sock, acetables *g_ape);
unsigned int sockroutine(acetables *g_ape);
typedef struct _ape_proxy_pipe ape_proxy_pipe;
struct _ape_proxy_pipe
{
 int allow_write;
 char pipe[33];
 struct _ape_proxy_pipe *next;
};
typedef struct _ape_proxy ape_proxy;
struct _ape_proxy
{
 char identifier[33];
 int eol;
 struct _transpipe *pipe;
 struct {
  struct _ape_proxy_cache *host;
  int port;
  int fd;
 } sock;
 int state;
 int nlink;
 ape_proxy_pipe *to;
 struct _ape_proxy *next;
 struct _ape_proxy *prev;
 struct _extend *properties;
};
typedef struct _ape_proxy_cache ape_proxy_cache;
struct _ape_proxy_cache
{
 char *host;
 char ip[16];
 struct _ape_proxy_cache *next;
};
enum {
 PROXY_NOT_CONNECTED = 0,
 PROXY_IN_PROGRESS,
 PROXY_CONNECTED,
 PROXY_THROTTLED,
 PROXY_TOFREE
};
ape_proxy *proxy_init(char *ident, char *host, int port, acetables *g_ape);
ape_proxy_cache *proxy_cache_gethostbyname(char *name, acetables *g_ape);
void proxy_cache_addip(char *name, char *ip, acetables *g_ape);
void proxy_attach(ape_proxy *proxy, char *pipe, int allow_write, acetables *g_ape);
int proxy_connect(ape_proxy *proxy, acetables *g_ape);
void proxy_connect_all(acetables *g_ape);
void proxy_onevent(ape_proxy *proxy, char *event, acetables *g_ape);
void proxy_process_eol(ape_socket *co, acetables *g_ape);
void proxy_init_from_conf(acetables *g_ape);
ape_proxy *proxy_init_by_host_port(char *host, char *port, acetables *g_ape);
json_item *get_json_object_proxy(ape_proxy *proxy);
ape_proxy *proxy_are_linked(char *pubid, char *pubid_proxy, acetables *g_ape);
void proxy_write(ape_proxy *proxy, char *data, acetables *g_ape);
void proxy_detach(struct _transpipe *unlinker, struct _transpipe *tproxy, acetables *g_ape);
void proxy_shutdown(ape_proxy *proxy, acetables *g_ape);
struct _transport_open_same_host_p
{
 ape_socket *client_close;
 ape_socket *client_listener;
 int attach;
 int substate;
};
typedef enum {
 TRANSPORT_LONGPOLLING,
 TRANSPORT_XHRSTREAMING,
 TRANSPORT_JSONP,
 TRANSPORT_PERSISTANT,
 TRANSPORT_SSE_LONGPOLLING,
 TRANSPORT_SSE_JSONP,
    TRANSPORT_WEBSOCKET,
    TRANSPORT_WEBSOCKET_IETF
} transport_t;
struct _transport_open_same_host_p transport_open_same_host(subuser *sub, ape_socket *client, transport_t transport);
void transport_data_completly_sent(subuser *sub, transport_t transport, acetables *g_ape);
void transport_start(acetables *g_ape);
void transport_free(acetables *g_ape);
struct _transport_properties *transport_get_properties(transport_t transport, acetables *g_ape);
typedef enum {
 RAW_PRI_LO,
 RAW_PRI_HI
} raw_priority_t;
typedef struct RAW
{
 char *data;
 struct RAW *next;
 raw_priority_t priority;
 int len;
 int refcount;
} RAW;
RAW *forge_raw(const char *raw, json_item *jlist);
int free_raw(RAW *fraw);
RAW *copy_raw(RAW *input);
RAW *copy_raw_z(RAW *input);
void post_raw(RAW *raw, USERS *user, acetables *g_ape);
void post_raw_sub(RAW *raw, subuser *sub, acetables *g_ape);
void post_raw_channel(RAW *raw, struct CHANNEL *chan, acetables *g_ape);
void post_raw_restricted(RAW *raw, USERS *user, subuser *sub, acetables *g_ape);
void post_raw_channel_restricted(RAW *raw, struct CHANNEL *chan, USERS *ruser, acetables *g_ape);
void proxy_post_raw(RAW *raw, ape_proxy *proxy, acetables *g_ape);
int post_raw_pipe(RAW *raw, const char *pipe, acetables *g_ape);
int post_to_pipe(json_item *jlist, const char *rawname, const char *pipe, subuser *from, acetables *g_ape);
int send_raw_inline(ape_socket *client, transport_t transport, RAW *raw, acetables *g_ape);
int send_raws(subuser *user, acetables *g_ape);
struct _raw_pool *init_raw_pool(int n);
struct _raw_pool *expend_raw_pool(struct _raw_pool *ptr, int n);
void destroy_raw_pool(struct _raw_pool *ptr);

typedef float float_t;
typedef double double_t;

extern double acos (double __x) __attribute__ ((__nothrow__)); extern double __acos (double __x) __attribute__ ((__nothrow__));
extern double asin (double __x) __attribute__ ((__nothrow__)); extern double __asin (double __x) __attribute__ ((__nothrow__));
extern double atan (double __x) __attribute__ ((__nothrow__)); extern double __atan (double __x) __attribute__ ((__nothrow__));
extern double atan2 (double __y, double __x) __attribute__ ((__nothrow__)); extern double __atan2 (double __y, double __x) __attribute__ ((__nothrow__));
extern double cos (double __x) __attribute__ ((__nothrow__)); extern double __cos (double __x) __attribute__ ((__nothrow__));
extern double sin (double __x) __attribute__ ((__nothrow__)); extern double __sin (double __x) __attribute__ ((__nothrow__));
extern double tan (double __x) __attribute__ ((__nothrow__)); extern double __tan (double __x) __attribute__ ((__nothrow__));
extern double cosh (double __x) __attribute__ ((__nothrow__)); extern double __cosh (double __x) __attribute__ ((__nothrow__));
extern double sinh (double __x) __attribute__ ((__nothrow__)); extern double __sinh (double __x) __attribute__ ((__nothrow__));
extern double tanh (double __x) __attribute__ ((__nothrow__)); extern double __tanh (double __x) __attribute__ ((__nothrow__));


extern double acosh (double __x) __attribute__ ((__nothrow__)); extern double __acosh (double __x) __attribute__ ((__nothrow__));
extern double asinh (double __x) __attribute__ ((__nothrow__)); extern double __asinh (double __x) __attribute__ ((__nothrow__));
extern double atanh (double __x) __attribute__ ((__nothrow__)); extern double __atanh (double __x) __attribute__ ((__nothrow__));


extern double exp (double __x) __attribute__ ((__nothrow__)); extern double __exp (double __x) __attribute__ ((__nothrow__));
extern double frexp (double __x, int *__exponent) __attribute__ ((__nothrow__)); extern double __frexp (double __x, int *__exponent) __attribute__ ((__nothrow__));
extern double ldexp (double __x, int __exponent) __attribute__ ((__nothrow__)); extern double __ldexp (double __x, int __exponent) __attribute__ ((__nothrow__));
extern double log (double __x) __attribute__ ((__nothrow__)); extern double __log (double __x) __attribute__ ((__nothrow__));
extern double log10 (double __x) __attribute__ ((__nothrow__)); extern double __log10 (double __x) __attribute__ ((__nothrow__));
extern double modf (double __x, double *__iptr) __attribute__ ((__nothrow__)); extern double __modf (double __x, double *__iptr) __attribute__ ((__nothrow__));


extern double expm1 (double __x) __attribute__ ((__nothrow__)); extern double __expm1 (double __x) __attribute__ ((__nothrow__));
extern double log1p (double __x) __attribute__ ((__nothrow__)); extern double __log1p (double __x) __attribute__ ((__nothrow__));
extern double logb (double __x) __attribute__ ((__nothrow__)); extern double __logb (double __x) __attribute__ ((__nothrow__));


extern double exp2 (double __x) __attribute__ ((__nothrow__)); extern double __exp2 (double __x) __attribute__ ((__nothrow__));
extern double log2 (double __x) __attribute__ ((__nothrow__)); extern double __log2 (double __x) __attribute__ ((__nothrow__));


extern double pow (double __x, double __y) __attribute__ ((__nothrow__)); extern double __pow (double __x, double __y) __attribute__ ((__nothrow__));
extern double sqrt (double __x) __attribute__ ((__nothrow__)); extern double __sqrt (double __x) __attribute__ ((__nothrow__));


extern double hypot (double __x, double __y) __attribute__ ((__nothrow__)); extern double __hypot (double __x, double __y) __attribute__ ((__nothrow__));


extern double cbrt (double __x) __attribute__ ((__nothrow__)); extern double __cbrt (double __x) __attribute__ ((__nothrow__));


extern double ceil (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __ceil (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern double fabs (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __fabs (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern double floor (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __floor (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern double fmod (double __x, double __y) __attribute__ ((__nothrow__)); extern double __fmod (double __x, double __y) __attribute__ ((__nothrow__));
extern int __isinf (double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int __finite (double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));

extern int isinf (double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int finite (double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern double drem (double __x, double __y) __attribute__ ((__nothrow__)); extern double __drem (double __x, double __y) __attribute__ ((__nothrow__));
extern double significand (double __x) __attribute__ ((__nothrow__)); extern double __significand (double __x) __attribute__ ((__nothrow__));

extern double copysign (double __x, double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __copysign (double __x, double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern double nan (__const char *__tagb) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __nan (__const char *__tagb) __attribute__ ((__nothrow__)) __attribute__ ((__const__));

extern int __isnan (double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int isnan (double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern double j0 (double) __attribute__ ((__nothrow__)); extern double __j0 (double) __attribute__ ((__nothrow__));
extern double j1 (double) __attribute__ ((__nothrow__)); extern double __j1 (double) __attribute__ ((__nothrow__));
extern double jn (int, double) __attribute__ ((__nothrow__)); extern double __jn (int, double) __attribute__ ((__nothrow__));
extern double y0 (double) __attribute__ ((__nothrow__)); extern double __y0 (double) __attribute__ ((__nothrow__));
extern double y1 (double) __attribute__ ((__nothrow__)); extern double __y1 (double) __attribute__ ((__nothrow__));
extern double yn (int, double) __attribute__ ((__nothrow__)); extern double __yn (int, double) __attribute__ ((__nothrow__));

extern double erf (double) __attribute__ ((__nothrow__)); extern double __erf (double) __attribute__ ((__nothrow__));
extern double erfc (double) __attribute__ ((__nothrow__)); extern double __erfc (double) __attribute__ ((__nothrow__));
extern double lgamma (double) __attribute__ ((__nothrow__)); extern double __lgamma (double) __attribute__ ((__nothrow__));


extern double tgamma (double) __attribute__ ((__nothrow__)); extern double __tgamma (double) __attribute__ ((__nothrow__));

extern double gamma (double) __attribute__ ((__nothrow__)); extern double __gamma (double) __attribute__ ((__nothrow__));
extern double lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__)); extern double __lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__));

extern double rint (double __x) __attribute__ ((__nothrow__)); extern double __rint (double __x) __attribute__ ((__nothrow__));
extern double nextafter (double __x, double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __nextafter (double __x, double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern double nexttoward (double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __nexttoward (double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern double remainder (double __x, double __y) __attribute__ ((__nothrow__)); extern double __remainder (double __x, double __y) __attribute__ ((__nothrow__));
extern double scalbn (double __x, int __n) __attribute__ ((__nothrow__)); extern double __scalbn (double __x, int __n) __attribute__ ((__nothrow__));
extern int ilogb (double __x) __attribute__ ((__nothrow__)); extern int __ilogb (double __x) __attribute__ ((__nothrow__));
extern double scalbln (double __x, long int __n) __attribute__ ((__nothrow__)); extern double __scalbln (double __x, long int __n) __attribute__ ((__nothrow__));
extern double nearbyint (double __x) __attribute__ ((__nothrow__)); extern double __nearbyint (double __x) __attribute__ ((__nothrow__));
extern double round (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __round (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern double trunc (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __trunc (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern double remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__)); extern double __remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__));
extern long int lrint (double __x) __attribute__ ((__nothrow__)); extern long int __lrint (double __x) __attribute__ ((__nothrow__));
extern long long int llrint (double __x) __attribute__ ((__nothrow__)); extern long long int __llrint (double __x) __attribute__ ((__nothrow__));
extern long int lround (double __x) __attribute__ ((__nothrow__)); extern long int __lround (double __x) __attribute__ ((__nothrow__));
extern long long int llround (double __x) __attribute__ ((__nothrow__)); extern long long int __llround (double __x) __attribute__ ((__nothrow__));
extern double fdim (double __x, double __y) __attribute__ ((__nothrow__)); extern double __fdim (double __x, double __y) __attribute__ ((__nothrow__));
extern double fmax (double __x, double __y) __attribute__ ((__nothrow__)); extern double __fmax (double __x, double __y) __attribute__ ((__nothrow__));
extern double fmin (double __x, double __y) __attribute__ ((__nothrow__)); extern double __fmin (double __x, double __y) __attribute__ ((__nothrow__));
extern int __fpclassify (double __value) __attribute__ ((__nothrow__))
     __attribute__ ((__const__));
extern int __signbit (double __value) __attribute__ ((__nothrow__))
     __attribute__ ((__const__));
extern double fma (double __x, double __y, double __z) __attribute__ ((__nothrow__)); extern double __fma (double __x, double __y, double __z) __attribute__ ((__nothrow__));

extern double scalb (double __x, double __n) __attribute__ ((__nothrow__)); extern double __scalb (double __x, double __n) __attribute__ ((__nothrow__));

extern float acosf (float __x) __attribute__ ((__nothrow__)); extern float __acosf (float __x) __attribute__ ((__nothrow__));
extern float asinf (float __x) __attribute__ ((__nothrow__)); extern float __asinf (float __x) __attribute__ ((__nothrow__));
extern float atanf (float __x) __attribute__ ((__nothrow__)); extern float __atanf (float __x) __attribute__ ((__nothrow__));
extern float atan2f (float __y, float __x) __attribute__ ((__nothrow__)); extern float __atan2f (float __y, float __x) __attribute__ ((__nothrow__));
extern float cosf (float __x) __attribute__ ((__nothrow__)); extern float __cosf (float __x) __attribute__ ((__nothrow__));
extern float sinf (float __x) __attribute__ ((__nothrow__)); extern float __sinf (float __x) __attribute__ ((__nothrow__));
extern float tanf (float __x) __attribute__ ((__nothrow__)); extern float __tanf (float __x) __attribute__ ((__nothrow__));
extern float coshf (float __x) __attribute__ ((__nothrow__)); extern float __coshf (float __x) __attribute__ ((__nothrow__));
extern float sinhf (float __x) __attribute__ ((__nothrow__)); extern float __sinhf (float __x) __attribute__ ((__nothrow__));
extern float tanhf (float __x) __attribute__ ((__nothrow__)); extern float __tanhf (float __x) __attribute__ ((__nothrow__));


extern float acoshf (float __x) __attribute__ ((__nothrow__)); extern float __acoshf (float __x) __attribute__ ((__nothrow__));
extern float asinhf (float __x) __attribute__ ((__nothrow__)); extern float __asinhf (float __x) __attribute__ ((__nothrow__));
extern float atanhf (float __x) __attribute__ ((__nothrow__)); extern float __atanhf (float __x) __attribute__ ((__nothrow__));


extern float expf (float __x) __attribute__ ((__nothrow__)); extern float __expf (float __x) __attribute__ ((__nothrow__));
extern float frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__)); extern float __frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__));
extern float ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__)); extern float __ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__));
extern float logf (float __x) __attribute__ ((__nothrow__)); extern float __logf (float __x) __attribute__ ((__nothrow__));
extern float log10f (float __x) __attribute__ ((__nothrow__)); extern float __log10f (float __x) __attribute__ ((__nothrow__));
extern float modff (float __x, float *__iptr) __attribute__ ((__nothrow__)); extern float __modff (float __x, float *__iptr) __attribute__ ((__nothrow__));


extern float expm1f (float __x) __attribute__ ((__nothrow__)); extern float __expm1f (float __x) __attribute__ ((__nothrow__));
extern float log1pf (float __x) __attribute__ ((__nothrow__)); extern float __log1pf (float __x) __attribute__ ((__nothrow__));
extern float logbf (float __x) __attribute__ ((__nothrow__)); extern float __logbf (float __x) __attribute__ ((__nothrow__));


extern float exp2f (float __x) __attribute__ ((__nothrow__)); extern float __exp2f (float __x) __attribute__ ((__nothrow__));
extern float log2f (float __x) __attribute__ ((__nothrow__)); extern float __log2f (float __x) __attribute__ ((__nothrow__));


extern float powf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __powf (float __x, float __y) __attribute__ ((__nothrow__));
extern float sqrtf (float __x) __attribute__ ((__nothrow__)); extern float __sqrtf (float __x) __attribute__ ((__nothrow__));


extern float hypotf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __hypotf (float __x, float __y) __attribute__ ((__nothrow__));


extern float cbrtf (float __x) __attribute__ ((__nothrow__)); extern float __cbrtf (float __x) __attribute__ ((__nothrow__));


extern float ceilf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __ceilf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern float fabsf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __fabsf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern float floorf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __floorf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern float fmodf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __fmodf (float __x, float __y) __attribute__ ((__nothrow__));
extern int __isinff (float __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int __finitef (float __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));

extern int isinff (float __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int finitef (float __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern float dremf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __dremf (float __x, float __y) __attribute__ ((__nothrow__));
extern float significandf (float __x) __attribute__ ((__nothrow__)); extern float __significandf (float __x) __attribute__ ((__nothrow__));

extern float copysignf (float __x, float __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __copysignf (float __x, float __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern float nanf (__const char *__tagb) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __nanf (__const char *__tagb) __attribute__ ((__nothrow__)) __attribute__ ((__const__));

extern int __isnanf (float __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int isnanf (float __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern float j0f (float) __attribute__ ((__nothrow__)); extern float __j0f (float) __attribute__ ((__nothrow__));
extern float j1f (float) __attribute__ ((__nothrow__)); extern float __j1f (float) __attribute__ ((__nothrow__));
extern float jnf (int, float) __attribute__ ((__nothrow__)); extern float __jnf (int, float) __attribute__ ((__nothrow__));
extern float y0f (float) __attribute__ ((__nothrow__)); extern float __y0f (float) __attribute__ ((__nothrow__));
extern float y1f (float) __attribute__ ((__nothrow__)); extern float __y1f (float) __attribute__ ((__nothrow__));
extern float ynf (int, float) __attribute__ ((__nothrow__)); extern float __ynf (int, float) __attribute__ ((__nothrow__));

extern float erff (float) __attribute__ ((__nothrow__)); extern float __erff (float) __attribute__ ((__nothrow__));
extern float erfcf (float) __attribute__ ((__nothrow__)); extern float __erfcf (float) __attribute__ ((__nothrow__));
extern float lgammaf (float) __attribute__ ((__nothrow__)); extern float __lgammaf (float) __attribute__ ((__nothrow__));


extern float tgammaf (float) __attribute__ ((__nothrow__)); extern float __tgammaf (float) __attribute__ ((__nothrow__));

extern float gammaf (float) __attribute__ ((__nothrow__)); extern float __gammaf (float) __attribute__ ((__nothrow__));
extern float lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__)); extern float __lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__));

extern float rintf (float __x) __attribute__ ((__nothrow__)); extern float __rintf (float __x) __attribute__ ((__nothrow__));
extern float nextafterf (float __x, float __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __nextafterf (float __x, float __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern float nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern float remainderf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __remainderf (float __x, float __y) __attribute__ ((__nothrow__));
extern float scalbnf (float __x, int __n) __attribute__ ((__nothrow__)); extern float __scalbnf (float __x, int __n) __attribute__ ((__nothrow__));
extern int ilogbf (float __x) __attribute__ ((__nothrow__)); extern int __ilogbf (float __x) __attribute__ ((__nothrow__));
extern float scalblnf (float __x, long int __n) __attribute__ ((__nothrow__)); extern float __scalblnf (float __x, long int __n) __attribute__ ((__nothrow__));
extern float nearbyintf (float __x) __attribute__ ((__nothrow__)); extern float __nearbyintf (float __x) __attribute__ ((__nothrow__));
extern float roundf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __roundf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern float truncf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __truncf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern float remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__)); extern float __remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__));
extern long int lrintf (float __x) __attribute__ ((__nothrow__)); extern long int __lrintf (float __x) __attribute__ ((__nothrow__));
extern long long int llrintf (float __x) __attribute__ ((__nothrow__)); extern long long int __llrintf (float __x) __attribute__ ((__nothrow__));
extern long int lroundf (float __x) __attribute__ ((__nothrow__)); extern long int __lroundf (float __x) __attribute__ ((__nothrow__));
extern long long int llroundf (float __x) __attribute__ ((__nothrow__)); extern long long int __llroundf (float __x) __attribute__ ((__nothrow__));
extern float fdimf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __fdimf (float __x, float __y) __attribute__ ((__nothrow__));
extern float fmaxf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __fmaxf (float __x, float __y) __attribute__ ((__nothrow__));
extern float fminf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __fminf (float __x, float __y) __attribute__ ((__nothrow__));
extern int __fpclassifyf (float __value) __attribute__ ((__nothrow__))
     __attribute__ ((__const__));
extern int __signbitf (float __value) __attribute__ ((__nothrow__))
     __attribute__ ((__const__));
extern float fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__)); extern float __fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__));

extern float scalbf (float __x, float __n) __attribute__ ((__nothrow__)); extern float __scalbf (float __x, float __n) __attribute__ ((__nothrow__));

extern long double acosl (long double __x) __attribute__ ((__nothrow__)); extern long double __acosl (long double __x) __attribute__ ((__nothrow__));
extern long double asinl (long double __x) __attribute__ ((__nothrow__)); extern long double __asinl (long double __x) __attribute__ ((__nothrow__));
extern long double atanl (long double __x) __attribute__ ((__nothrow__)); extern long double __atanl (long double __x) __attribute__ ((__nothrow__));
extern long double atan2l (long double __y, long double __x) __attribute__ ((__nothrow__)); extern long double __atan2l (long double __y, long double __x) __attribute__ ((__nothrow__));
extern long double cosl (long double __x) __attribute__ ((__nothrow__)); extern long double __cosl (long double __x) __attribute__ ((__nothrow__));
extern long double sinl (long double __x) __attribute__ ((__nothrow__)); extern long double __sinl (long double __x) __attribute__ ((__nothrow__));
extern long double tanl (long double __x) __attribute__ ((__nothrow__)); extern long double __tanl (long double __x) __attribute__ ((__nothrow__));
extern long double coshl (long double __x) __attribute__ ((__nothrow__)); extern long double __coshl (long double __x) __attribute__ ((__nothrow__));
extern long double sinhl (long double __x) __attribute__ ((__nothrow__)); extern long double __sinhl (long double __x) __attribute__ ((__nothrow__));
extern long double tanhl (long double __x) __attribute__ ((__nothrow__)); extern long double __tanhl (long double __x) __attribute__ ((__nothrow__));


extern long double acoshl (long double __x) __attribute__ ((__nothrow__)); extern long double __acoshl (long double __x) __attribute__ ((__nothrow__));
extern long double asinhl (long double __x) __attribute__ ((__nothrow__)); extern long double __asinhl (long double __x) __attribute__ ((__nothrow__));
extern long double atanhl (long double __x) __attribute__ ((__nothrow__)); extern long double __atanhl (long double __x) __attribute__ ((__nothrow__));


extern long double expl (long double __x) __attribute__ ((__nothrow__)); extern long double __expl (long double __x) __attribute__ ((__nothrow__));
extern long double frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__)); extern long double __frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__));
extern long double ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__)); extern long double __ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__));
extern long double logl (long double __x) __attribute__ ((__nothrow__)); extern long double __logl (long double __x) __attribute__ ((__nothrow__));
extern long double log10l (long double __x) __attribute__ ((__nothrow__)); extern long double __log10l (long double __x) __attribute__ ((__nothrow__));
extern long double modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__)); extern long double __modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__));


extern long double expm1l (long double __x) __attribute__ ((__nothrow__)); extern long double __expm1l (long double __x) __attribute__ ((__nothrow__));
extern long double log1pl (long double __x) __attribute__ ((__nothrow__)); extern long double __log1pl (long double __x) __attribute__ ((__nothrow__));
extern long double logbl (long double __x) __attribute__ ((__nothrow__)); extern long double __logbl (long double __x) __attribute__ ((__nothrow__));


extern long double exp2l (long double __x) __attribute__ ((__nothrow__)); extern long double __exp2l (long double __x) __attribute__ ((__nothrow__));
extern long double log2l (long double __x) __attribute__ ((__nothrow__)); extern long double __log2l (long double __x) __attribute__ ((__nothrow__));


extern long double powl (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __powl (long double __x, long double __y) __attribute__ ((__nothrow__));
extern long double sqrtl (long double __x) __attribute__ ((__nothrow__)); extern long double __sqrtl (long double __x) __attribute__ ((__nothrow__));


extern long double hypotl (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __hypotl (long double __x, long double __y) __attribute__ ((__nothrow__));


extern long double cbrtl (long double __x) __attribute__ ((__nothrow__)); extern long double __cbrtl (long double __x) __attribute__ ((__nothrow__));


extern long double ceill (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __ceill (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern long double fabsl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __fabsl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern long double floorl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __floorl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern long double fmodl (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __fmodl (long double __x, long double __y) __attribute__ ((__nothrow__));
extern int __isinfl (long double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int __finitel (long double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));

extern int isinfl (long double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int finitel (long double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern long double dreml (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __dreml (long double __x, long double __y) __attribute__ ((__nothrow__));
extern long double significandl (long double __x) __attribute__ ((__nothrow__)); extern long double __significandl (long double __x) __attribute__ ((__nothrow__));

extern long double copysignl (long double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __copysignl (long double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern long double nanl (__const char *__tagb) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __nanl (__const char *__tagb) __attribute__ ((__nothrow__)) __attribute__ ((__const__));

extern int __isnanl (long double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int isnanl (long double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern long double j0l (long double) __attribute__ ((__nothrow__)); extern long double __j0l (long double) __attribute__ ((__nothrow__));
extern long double j1l (long double) __attribute__ ((__nothrow__)); extern long double __j1l (long double) __attribute__ ((__nothrow__));
extern long double jnl (int, long double) __attribute__ ((__nothrow__)); extern long double __jnl (int, long double) __attribute__ ((__nothrow__));
extern long double y0l (long double) __attribute__ ((__nothrow__)); extern long double __y0l (long double) __attribute__ ((__nothrow__));
extern long double y1l (long double) __attribute__ ((__nothrow__)); extern long double __y1l (long double) __attribute__ ((__nothrow__));
extern long double ynl (int, long double) __attribute__ ((__nothrow__)); extern long double __ynl (int, long double) __attribute__ ((__nothrow__));

extern long double erfl (long double) __attribute__ ((__nothrow__)); extern long double __erfl (long double) __attribute__ ((__nothrow__));
extern long double erfcl (long double) __attribute__ ((__nothrow__)); extern long double __erfcl (long double) __attribute__ ((__nothrow__));
extern long double lgammal (long double) __attribute__ ((__nothrow__)); extern long double __lgammal (long double) __attribute__ ((__nothrow__));


extern long double tgammal (long double) __attribute__ ((__nothrow__)); extern long double __tgammal (long double) __attribute__ ((__nothrow__));

extern long double gammal (long double) __attribute__ ((__nothrow__)); extern long double __gammal (long double) __attribute__ ((__nothrow__));
extern long double lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__)); extern long double __lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__));

extern long double rintl (long double __x) __attribute__ ((__nothrow__)); extern long double __rintl (long double __x) __attribute__ ((__nothrow__));
extern long double nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern long double nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern long double remainderl (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __remainderl (long double __x, long double __y) __attribute__ ((__nothrow__));
extern long double scalbnl (long double __x, int __n) __attribute__ ((__nothrow__)); extern long double __scalbnl (long double __x, int __n) __attribute__ ((__nothrow__));
extern int ilogbl (long double __x) __attribute__ ((__nothrow__)); extern int __ilogbl (long double __x) __attribute__ ((__nothrow__));
extern long double scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__)); extern long double __scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__));
extern long double nearbyintl (long double __x) __attribute__ ((__nothrow__)); extern long double __nearbyintl (long double __x) __attribute__ ((__nothrow__));
extern long double roundl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __roundl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern long double truncl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __truncl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern long double remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__)); extern long double __remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__));
extern long int lrintl (long double __x) __attribute__ ((__nothrow__)); extern long int __lrintl (long double __x) __attribute__ ((__nothrow__));
extern long long int llrintl (long double __x) __attribute__ ((__nothrow__)); extern long long int __llrintl (long double __x) __attribute__ ((__nothrow__));
extern long int lroundl (long double __x) __attribute__ ((__nothrow__)); extern long int __lroundl (long double __x) __attribute__ ((__nothrow__));
extern long long int llroundl (long double __x) __attribute__ ((__nothrow__)); extern long long int __llroundl (long double __x) __attribute__ ((__nothrow__));
extern long double fdiml (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __fdiml (long double __x, long double __y) __attribute__ ((__nothrow__));
extern long double fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__));
extern long double fminl (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __fminl (long double __x, long double __y) __attribute__ ((__nothrow__));
extern int __fpclassifyl (long double __value) __attribute__ ((__nothrow__))
     __attribute__ ((__const__));
extern int __signbitl (long double __value) __attribute__ ((__nothrow__))
     __attribute__ ((__const__));
extern long double fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__)); extern long double __fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__));

extern long double scalbl (long double __x, long double __n) __attribute__ ((__nothrow__)); extern long double __scalbl (long double __x, long double __n) __attribute__ ((__nothrow__));
extern int signgam;
enum
  {
    FP_NAN,
    FP_INFINITE,
    FP_ZERO,
    FP_SUBNORMAL,
    FP_NORMAL
  };
typedef enum
{
  _IEEE_ = -1,
  _SVID_,
  _XOPEN_,
  _POSIX_,
  _ISOC_
} _LIB_VERSION_TYPE;
extern _LIB_VERSION_TYPE _LIB_VERSION;
struct exception
  {
    int type;
    char *name;
    double arg1;
    double arg2;
    double retval;
  };
extern int matherr (struct exception *__exc);

void *xmalloc(size_t size);
void *xrealloc(void *ptr, size_t size);
char *xstrdup(const char *s);
int seof(char *buf, unsigned short int stop);
int sneof(char *buf, size_t len, size_t max);
long int itos(long long int input, char *output, long int len);
char *trim(char *s);
char *removelast(char *input, unsigned int n);
size_t explode(const char split, char *input, char **tP, unsigned int limit);
char hex2int(unsigned char hex);
int urldecode(char *string);
int rand_n(int n);
void s_tolower(char *upper, unsigned int len);
char *get_path(const char *full_path);
subuser *checkrecv(ape_socket *co, acetables *g_ape);
subuser *checkrecv_websocket(ape_socket *co, acetables *g_ape);
typedef struct clientget
{
 struct _http_header_line *hlines;
 ape_socket *client;
 const char *ip_get;
 const char *get;
 const char *host;
} clientget ;
enum {
 CONNECT_SHUTDOWN = 0,
 CONNECT_KEEPALIVE
};
unsigned int checkcmd(clientget *cget, transport_t transport, subuser **iuser, acetables *g_ape);
void do_register(acetables *g_ape);
typedef struct _callbackp callbackp;
struct _callbackp
{
 ape_socket *client;
 json_item *param;
 struct _http_header_line *hlines;
 struct USERS *call_user;
 const char *ip;
 const char *host;
 const char *cmd;
 void *data;
 subuser *call_subuser;
 acetables *g_ape;
 transport_t transport;
 int chl;
};
typedef struct callback
{
 unsigned int (*func)(struct _callbackp *);
 unsigned int need;
} callback;
typedef struct _callback_hook
{
 const char *cmd;
 void *data;
 unsigned int (*func)(struct _callbackp *);
 struct _callback_hook *next;
} callback_hook;
enum {
 NEED_NICK = 0,
 NEED_SESSID,
 NEED_NOTHING
};
struct _cmd_process {
 struct _http_header_line *hlines;
 USERS *guser;
 subuser *sub;
 ape_socket *client;
 const char *host;
 const char *ip;
 transport_t transport;
};
unsigned int cmd_connect(struct _callbackp *);
unsigned int cmd_check(struct _callbackp *);
unsigned int cmd_send(struct _callbackp *);
unsigned int cmd_quit(struct _callbackp *);
unsigned int cmd_setlevel(struct _callbackp *);
unsigned int cmd_settopic(struct _callbackp *);
unsigned int cmd_join(struct _callbackp *);
unsigned int cmd_left(struct _callbackp *);
unsigned int cmd_kick(struct _callbackp *);
unsigned int cmd_ban(struct _callbackp *);
unsigned int cmd_session(struct _callbackp *);
unsigned int cmd_pconnect(struct _callbackp *);
unsigned int cmd_script(struct _callbackp *);
unsigned int cmd_pong(struct _callbackp *);
unsigned int cmd_proxy_connect(struct _callbackp *);
unsigned int cmd_proxy_write(struct _callbackp *);
int process_cmd(json_item *ijson, struct _cmd_process *pc, subuser **iuser, acetables *g_ape);
void register_cmd(const char *cmd, unsigned int (*func)(callbackp *), unsigned int need, acetables *g_ape);
void unregister_cmd(const char *cmd, acetables *g_ape);
void register_bad_cmd(unsigned int (*func)(callbackp *), void *data, acetables *g_ape);
int register_hook_cmd(const char *cmd, unsigned int (*func)(callbackp *), void *data, acetables *g_ape);
int call_cmd_hook(const char *cmd, callbackp *cp, acetables *g_ape);
struct _ticks_callback
{
 int ticks_need;
 int delta;
 int times;
 unsigned int identifier;
 unsigned int protect;
 void *func;
 void *params;
 struct _ticks_callback *next;
};
void process_tick(acetables *g_ape);
struct _ticks_callback *add_timeout(unsigned int msec, void *callback, void *params, acetables *g_ape);
struct _ticks_callback *add_periodical(unsigned int msec, int times, void *callback, void *params, acetables *g_ape);
void del_timer_identifier(unsigned int identifier, acetables *g_ape);
struct _ticks_callback *get_timer_identifier(unsigned int identifier, acetables *g_ape);
int get_first_timer_ms(acetables *g_ape);
void timers_free(acetables *g_ape);
int base64_decode(unsigned char * out, const char *in, int out_length);
char *base64_encode(unsigned char * src, int len);
typedef struct
{
    unsigned long int total[2];
    unsigned long int state[5];
    unsigned char buffer[64];
}
sha1_context;
void sha1_starts( sha1_context *ctx );
void sha1_update( sha1_context *ctx, unsigned char *input, unsigned int length );
void sha1_finish( sha1_context *ctx, unsigned char digest[20] );
int sha1_file( char *filename, unsigned char digest[20] );
void sha1_csum( unsigned char *buf, unsigned int buflen, unsigned char digest[20] );
void sha1_hmac( unsigned char *key, unsigned int keylen, unsigned char *buf, unsigned int buflen,
                unsigned char digest[20] );
typedef enum {
 EVENT_UNKNOWN,
 EVENT_EPOLL,
 EVENT_KQUEUE,
 EVENT_DEVPOLL,
 EVENT_POLL,
 EVENT_SELECT
} fdevent_handler_t;
struct _fdevent {
 int *basemem;
 int (*add)(struct _fdevent *, int, int);
 int (*remove)(struct _fdevent *, int);
 int (*poll)(struct _fdevent *, int);
 int (*get_current_fd)(struct _fdevent *, int);
 void (*growup)(struct _fdevent *);
 int (*revent)(struct _fdevent *, int);
 int (*reload)(struct _fdevent *);
 fdevent_handler_t handler;
};
int events_init(acetables *g_ape, int *basemem);
void events_free(acetables *g_ape);
int events_add(struct _fdevent *ev, int fd, int bitadd);
int events_remove(struct _fdevent *ev, int fd);
int events_poll(struct _fdevent *ev, int timeout_ms);
int events_get_current_fd(struct _fdevent *ev, int i);
void events_growup(struct _fdevent *ev);
int events_revent(struct _fdevent *ev, int i);
int events_reload(struct _fdevent *ev);
int event_kqueue_init(struct _fdevent *ev);
int event_epoll_init(struct _fdevent *ev);
int event_select_init(struct _fdevent *ev);
typedef enum {
 APE_DEBUG = 0x01,
 APE_WARN = 0x02,
 APE_ERR = 0x04,
 APE_INFO = 0x08
} ape_log_lvl_t;
void ape_log_init(acetables *g_ape);
void ape_log(ape_log_lvl_t lvl, const char *file, unsigned long int line, acetables *g_ape, char *buf, ...);
struct in_addr;
struct in6_addr;
struct sockaddr;
 const char *
dns_version(void);
struct dns_ctx;
struct dns_query;
typedef unsigned char dnsc_t;
typedef const unsigned char dnscc_t;
enum dns_class {
  DNS_C_INVALID = 0,
  DNS_C_IN = 1,
  DNS_C_CH = 3,
  DNS_C_HS = 4,
  DNS_C_ANY = 255
};
enum dns_type {
  DNS_T_INVALID = 0,
  DNS_T_A = 1,
  DNS_T_NS = 2,
  DNS_T_MD = 3,
  DNS_T_MF = 4,
  DNS_T_CNAME = 5,
  DNS_T_SOA = 6,
  DNS_T_MB = 7,
  DNS_T_MG = 8,
  DNS_T_MR = 9,
  DNS_T_NULL = 10,
  DNS_T_WKS = 11,
  DNS_T_PTR = 12,
  DNS_T_HINFO = 13,
  DNS_T_MINFO = 14,
  DNS_T_MX = 15,
  DNS_T_TXT = 16,
  DNS_T_RP = 17,
  DNS_T_AFSDB = 18,
  DNS_T_X25 = 19,
  DNS_T_ISDN = 20,
  DNS_T_RT = 21,
  DNS_T_NSAP = 22,
  DNS_T_NSAP_PTR = 23,
  DNS_T_SIG = 24,
  DNS_T_KEY = 25,
  DNS_T_PX = 26,
  DNS_T_GPOS = 27,
  DNS_T_AAAA = 28,
  DNS_T_LOC = 29,
  DNS_T_NXT = 30,
  DNS_T_EID = 31,
  DNS_T_NIMLOC = 32,
  DNS_T_SRV = 33,
  DNS_T_ATMA = 34,
  DNS_T_NAPTR = 35,
  DNS_T_KX = 36,
  DNS_T_CERT = 37,
  DNS_T_A6 = 38,
  DNS_T_DNAME = 39,
  DNS_T_SINK = 40,
  DNS_T_OPT = 41,
  DNS_T_DS = 43,
  DNS_T_NSEC = 47,
  DNS_T_TSIG = 250,
  DNS_T_IXFR = 251,
  DNS_T_AXFR = 252,
  DNS_T_MAILB = 253,
  DNS_T_MAILA = 254,
  DNS_T_ANY = 255,
  DNS_T_ZXFR = 256,
  DNS_T_MAX = 65536
};
 unsigned
dns_dnlen(dnscc_t *dn);
 unsigned
dns_dnlabels(dnscc_t *dn);
 unsigned
dns_dnequal(dnscc_t *dn1, dnscc_t *dn2);
 unsigned
dns_dntodn(dnscc_t *sdn, dnsc_t *ddn, unsigned ddnsiz);
 int
dns_ptodn(const char *name, unsigned namelen,
          dnsc_t *dn, unsigned dnsiz, int *isabs);
 extern dnscc_t dns_inaddr_arpa_dn[14];
 int
dns_a4todn(const struct in_addr *addr, dnscc_t *tdn,
           dnsc_t *dn, unsigned dnsiz);
 int
dns_a4ptodn(const struct in_addr *addr, const char *tname,
            dnsc_t *dn, unsigned dnsiz);
 dnsc_t *
dns_a4todn_(const struct in_addr *addr, dnsc_t *dn, dnsc_t *dne);
 extern dnscc_t dns_ip6_arpa_dn[10];
 int
dns_a6todn(const struct in6_addr *addr, dnscc_t *tdn,
           dnsc_t *dn, unsigned dnsiz);
 int
dns_a6ptodn(const struct in6_addr *addr, const char *tname,
            dnsc_t *dn, unsigned dnsiz);
 dnsc_t *
dns_a6todn_(const struct in6_addr *addr, dnsc_t *dn, dnsc_t *dne);
 int
dns_dntop(dnscc_t *dn, char *name, unsigned namesiz);
 const char *
dns_dntosp(dnscc_t *dn);
 unsigned
dns_dntop_size(dnscc_t *dn);
 const char *dns_ntop(int af, const void *src, char *dst, int size);
 int dns_pton(int af, const char *src, void *dst);
enum dns_rcode {
  DNS_R_NOERROR = 0,
  DNS_R_FORMERR = 1,
  DNS_R_SERVFAIL = 2,
  DNS_R_NXDOMAIN = 3,
  DNS_R_NOTIMPL = 4,
  DNS_R_REFUSED = 5,
  DNS_R_YXDOMAIN = 6,
  DNS_R_YXRRSET = 7,
  DNS_R_NXRRSET = 8,
  DNS_R_NOTAUTH = 9,
  DNS_R_NOTZONE = 10,
  DNS_R_BADSIG = 16,
  DNS_R_BADKEY = 17,
  DNS_R_BADTIME = 18
};
static __inline unsigned dns_get16(dnscc_t *s) {
  return ((unsigned)s[0]<<8) | s[1];
}
static __inline unsigned dns_get32(dnscc_t *s) {
  return ((unsigned)s[0]<<24) | ((unsigned)s[1]<<16)
        | ((unsigned)s[2]<<8) | s[3];
}
static __inline dnsc_t *dns_put16(dnsc_t *d, unsigned n) {
  *d++ = (dnsc_t)((n >> 8) & 255); *d++ = (dnsc_t)(n & 255); return d;
}
static __inline dnsc_t *dns_put32(dnsc_t *d, unsigned n) {
  *d++ = (dnsc_t)((n >> 24) & 255); *d++ = (dnsc_t)((n >> 16) & 255);
  *d++ = (dnsc_t)((n >> 8) & 255); *d++ = (dnsc_t)(n & 255);
  return d;
}
 unsigned dns_random16(void);
enum {
  DNS_H_QID1 = 0,
  DNS_H_QID2 = 1,
  DNS_H_QID = DNS_H_QID1,
  DNS_H_F1 = 2,
  DNS_HF1_QR = 0x80,
  DNS_HF1_OPCODE = 0x78,
  DNS_HF1_AA = 0x04,
  DNS_HF1_TC = 0x02,
  DNS_HF1_RD = 0x01,
  DNS_H_F2 = 3,
  DNS_HF2_RA = 0x80,
  DNS_HF2_Z = 0x70,
  DNS_HF2_RCODE = 0x0f,
  DNS_H_QDCNT1 = 4,
  DNS_H_QDCNT2 = 5,
  DNS_H_QDCNT = DNS_H_QDCNT1,
  DNS_H_ANCNT1 = 6,
  DNS_H_ANCNT2 = 7,
  DNS_H_ANCNT = DNS_H_ANCNT1,
  DNS_H_NSCNT1 = 8,
  DNS_H_NSCNT2 = 9,
  DNS_H_NSCNT = DNS_H_NSCNT1,
  DNS_H_ARCNT1 = 10,
  DNS_H_ARCNT2 = 11,
  DNS_H_ARCNT = DNS_H_ARCNT1,
};
 int
dns_getdn(dnscc_t *pkt, dnscc_t **curp, dnscc_t *end,
          dnsc_t *dn, unsigned dnsiz);
 dnscc_t *
dns_skipdn(dnscc_t *end, dnscc_t *cur);
struct dns_rr {
  dnsc_t dnsrr_dn[255];
  enum dns_class dnsrr_cls;
  enum dns_type dnsrr_typ;
  unsigned dnsrr_ttl;
  unsigned dnsrr_dsz;
  dnscc_t *dnsrr_dptr;
  dnscc_t *dnsrr_dend;
};
struct dns_parse {
  dnscc_t *dnsp_pkt;
  dnscc_t *dnsp_end;
  dnscc_t *dnsp_cur;
  dnscc_t *dnsp_ans;
  int dnsp_rrl;
  int dnsp_nrr;
  unsigned dnsp_ttl;
  dnscc_t *dnsp_qdn;
  enum dns_class dnsp_qcls;
  enum dns_type dnsp_qtyp;
  dnsc_t dnsp_dnbuf[255];
};
 void
dns_initparse(struct dns_parse *p, dnscc_t *qdn,
              dnscc_t *pkt, dnscc_t *cur, dnscc_t *end);
 int
dns_nextrr(struct dns_parse *p, struct dns_rr *rr);
 void
dns_rewind(struct dns_parse *p, dnscc_t *qdn);
 extern struct dns_ctx dns_defctx;
 void
dns_reset(struct dns_ctx *ctx);
 int
dns_init(struct dns_ctx *ctx, int do_open);
 struct dns_ctx *
dns_new(const struct dns_ctx *copy);
 void
dns_free(struct dns_ctx *ctx);
 int
dns_add_serv(struct dns_ctx *ctx, const char *serv);
 int
dns_add_serv_s(struct dns_ctx *ctx, const struct sockaddr *sa);
 int
dns_add_srch(struct dns_ctx *ctx, const char *srch);
 int
dns_set_opts(struct dns_ctx *ctx, const char *opts);
enum dns_opt {
  DNS_OPT_FLAGS,
  DNS_OPT_TIMEOUT,
  DNS_OPT_NTRIES,
  DNS_OPT_NDOTS,
  DNS_OPT_UDPSIZE,
  DNS_OPT_PORT,
};
 int
dns_set_opt(struct dns_ctx *ctx, enum dns_opt opt, int val);
enum dns_flags {
  DNS_NOSRCH = 0x00010000,
  DNS_NORD = 0x00020000,
  DNS_AAONLY = 0x00040000,
};
typedef void
(dns_dbgfn)(int code, const struct sockaddr *sa, unsigned salen,
            dnscc_t *pkt, int plen,
            const struct dns_query *q, void *data);
 void
dns_set_dbgfn(struct dns_ctx *ctx, dns_dbgfn *dbgfn);
 int
dns_open(struct dns_ctx *ctx);
 int
dns_sock(const struct dns_ctx *ctx);
 void
dns_close(struct dns_ctx *ctx);
 int
dns_active(const struct dns_ctx *ctx);
 int
dns_status(const struct dns_ctx *ctx);
 void
dns_setstatus(struct dns_ctx *ctx, int status);
 void
dns_ioevent(struct dns_ctx *ctx, time_t now);
 int
dns_timeouts(struct dns_ctx *ctx, int maxwait, time_t now);
typedef void dns_utm_fn(struct dns_ctx *ctx, int timeout, void *data);
 void
dns_set_tmcbck(struct dns_ctx *ctx, dns_utm_fn *fn, void *data);
typedef void dns_query_fn(struct dns_ctx *ctx, void *result, void *data);
typedef int
dns_parse_fn(dnscc_t *qdn, dnscc_t *pkt, dnscc_t *cur, dnscc_t *end,
             void **res);
enum dns_status {
  DNS_E_NOERROR = 0,
  DNS_E_TEMPFAIL = -1,
  DNS_E_PROTOCOL = -2,
  DNS_E_NXDOMAIN = -3,
  DNS_E_NODATA = -4,
  DNS_E_NOMEM = -5,
  DNS_E_BADQUERY = -6
};
 struct dns_query *
dns_submit_dn(struct dns_ctx *ctx,
              dnscc_t *dn, int qcls, int qtyp, int flags,
              dns_parse_fn *parse, dns_query_fn *cbck, void *data);
 struct dns_query *
dns_submit_p(struct dns_ctx *ctx,
             const char *name, int qcls, int qtyp, int flags,
             dns_parse_fn *parse, dns_query_fn *cbck, void *data);
 int
dns_cancel(struct dns_ctx *ctx, struct dns_query *q);
 void *
dns_resolve_dn(struct dns_ctx *ctx,
               dnscc_t *qdn, int qcls, int qtyp, int flags,
               dns_parse_fn *parse);
 void *
dns_resolve_p(struct dns_ctx *ctx,
              const char *qname, int qcls, int qtyp, int flags,
              dns_parse_fn *parse);
 void *
dns_resolve(struct dns_ctx *ctx, struct dns_query *q);
struct dns_rr_null {
  char *dnsn_cname; char *dnsn_qname; unsigned dnsn_ttl; int dnsn_nrr;
};
 int
dns_stdrr_size(const struct dns_parse *p);
 void *
dns_stdrr_finish(struct dns_rr_null *ret, char *cp, const struct dns_parse *p);
struct dns_rr_a4 {
  char *dnsa4_cname; char *dnsa4_qname; unsigned dnsa4_ttl; int dnsa4_nrr;
  struct in_addr *dnsa4_addr;
};
 dns_parse_fn dns_parse_a4;
typedef void
dns_query_a4_fn(struct dns_ctx *ctx, struct dns_rr_a4 *result, void *data);
 struct dns_query *
dns_submit_a4(struct dns_ctx *ctx, const char *name, int flags,
              dns_query_a4_fn *cbck, void *data);
 struct dns_rr_a4 *
dns_resolve_a4(struct dns_ctx *ctx, const char *name, int flags);
struct dns_rr_a6 {
  char *dnsa6_cname; char *dnsa6_qname; unsigned dnsa6_ttl; int dnsa6_nrr;
  struct in6_addr *dnsa6_addr;
};
 dns_parse_fn dns_parse_a6;
typedef void
dns_query_a6_fn(struct dns_ctx *ctx, struct dns_rr_a6 *result, void *data);
 struct dns_query *
dns_submit_a6(struct dns_ctx *ctx, const char *name, int flags,
              dns_query_a6_fn *cbck, void *data);
 struct dns_rr_a6 *
dns_resolve_a6(struct dns_ctx *ctx, const char *name, int flags);
struct dns_rr_ptr {
  char *dnsptr_cname; char *dnsptr_qname; unsigned dnsptr_ttl; int dnsptr_nrr;
  char **dnsptr_ptr;
};
 dns_parse_fn dns_parse_ptr;
typedef void
dns_query_ptr_fn(struct dns_ctx *ctx, struct dns_rr_ptr *result, void *data);
 struct dns_query *
dns_submit_a4ptr(struct dns_ctx *ctx, const struct in_addr *addr,
                 dns_query_ptr_fn *cbck, void *data);
 struct dns_rr_ptr *
dns_resolve_a4ptr(struct dns_ctx *ctx, const struct in_addr *addr);
 struct dns_query *
dns_submit_a6ptr(struct dns_ctx *ctx, const struct in6_addr *addr,
                 dns_query_ptr_fn *cbck, void *data);
 struct dns_rr_ptr *
dns_resolve_a6ptr(struct dns_ctx *ctx, const struct in6_addr *addr);
struct dns_mx {
  int priority;
  char *name;
};
struct dns_rr_mx {
  char *dnsmx_cname; char *dnsmx_qname; unsigned dnsmx_ttl; int dnsmx_nrr;
  struct dns_mx *dnsmx_mx;
};
 dns_parse_fn dns_parse_mx;
typedef void
dns_query_mx_fn(struct dns_ctx *ctx, struct dns_rr_mx *result, void *data);
 struct dns_query *
dns_submit_mx(struct dns_ctx *ctx, const char *name, int flags,
              dns_query_mx_fn *cbck, void *data);
 struct dns_rr_mx *
dns_resolve_mx(struct dns_ctx *ctx, const char *name, int flags);
struct dns_txt {
  int len;
  dnsc_t *txt;
};
struct dns_rr_txt {
  char *dnstxt_cname; char *dnstxt_qname; unsigned dnstxt_ttl; int dnstxt_nrr;
  struct dns_txt *dnstxt_txt;
};
 dns_parse_fn dns_parse_txt;
typedef void
dns_query_txt_fn(struct dns_ctx *ctx, struct dns_rr_txt *result, void *data);
 struct dns_query *
dns_submit_txt(struct dns_ctx *ctx, const char *name, int qcls, int flags,
               dns_query_txt_fn *cbck, void *data);
 struct dns_rr_txt *
dns_resolve_txt(struct dns_ctx *ctx, const char *name, int qcls, int flags);
struct dns_srv {
  int priority;
  int weight;
  int port;
  char *name;
};
struct dns_rr_srv {
  char *dnssrv_cname; char *dnssrv_qname; unsigned dnssrv_ttl; int dnssrv_nrr;
  struct dns_srv *dnssrv_srv;
};
 dns_parse_fn dns_parse_srv;
typedef void
dns_query_srv_fn(struct dns_ctx *ctx, struct dns_rr_srv *result, void *data);
 struct dns_query *
dns_submit_srv(struct dns_ctx *ctx,
               const char *name, const char *srv, const char *proto,
               int flags, dns_query_srv_fn *cbck, void *data);
 struct dns_rr_srv *
dns_resolve_srv(struct dns_ctx *ctx,
                const char *name, const char *srv, const char *proto,
                int flags);
struct dns_naptr {
  int order;
  int preference;
  char *flags;
  char *service;
  char *regexp;
  char *replacement;
};
struct dns_rr_naptr {
  char *dnsnaptr_cname; char *dnsnaptr_qname; unsigned dnsnaptr_ttl; int dnsnaptr_nrr;
  struct dns_naptr *dnsnaptr_naptr;
};
 dns_parse_fn dns_parse_naptr;
typedef void
dns_query_naptr_fn(struct dns_ctx *ctx,
                   struct dns_rr_naptr *result, void *data);
 struct dns_query *
dns_submit_naptr(struct dns_ctx *ctx, const char *name, int flags,
                 dns_query_naptr_fn *cbck, void *data);
 struct dns_rr_naptr *
dns_resolve_naptr(struct dns_ctx *ctx, const char *name, int flags);
 struct dns_query *
dns_submit_a4dnsbl(struct dns_ctx *ctx,
                   const struct in_addr *addr, const char *dnsbl,
                   dns_query_a4_fn *cbck, void *data);
 struct dns_query *
dns_submit_a4dnsbl_txt(struct dns_ctx *ctx,
                       const struct in_addr *addr, const char *dnsbl,
                       dns_query_txt_fn *cbck, void *data);
 struct dns_rr_a4 *
dns_resolve_a4dnsbl(struct dns_ctx *ctx,
                    const struct in_addr *addr, const char *dnsbl);
 struct dns_rr_txt *
dns_resolve_a4dnsbl_txt(struct dns_ctx *ctx,
                        const struct in_addr *addr, const char *dnsbl);
 struct dns_query *
dns_submit_a6dnsbl(struct dns_ctx *ctx,
                   const struct in6_addr *addr, const char *dnsbl,
                   dns_query_a4_fn *cbck, void *data);
 struct dns_query *
dns_submit_a6dnsbl_txt(struct dns_ctx *ctx,
                       const struct in6_addr *addr, const char *dnsbl,
                       dns_query_txt_fn *cbck, void *data);
 struct dns_rr_a4 *
dns_resolve_a6dnsbl(struct dns_ctx *ctx,
                    const struct in6_addr *addr, const char *dnsbl);
 struct dns_rr_txt *
dns_resolve_a6dnsbl_txt(struct dns_ctx *ctx,
                        const struct in6_addr *addr, const char *dnsbl);
 struct dns_query *
dns_submit_rhsbl(struct dns_ctx *ctx,
                 const char *name, const char *rhsbl,
                 dns_query_a4_fn *cbck, void *data);
 struct dns_query *
dns_submit_rhsbl_txt(struct dns_ctx *ctx,
                     const char *name, const char *rhsbl,
                     dns_query_txt_fn *cbck, void *data);
 struct dns_rr_a4 *
dns_resolve_rhsbl(struct dns_ctx *ctx, const char *name, const char *rhsbl);
 struct dns_rr_txt *
dns_resolve_rhsbl_txt(struct dns_ctx *ctx, const char *name, const char *rhsbl);
struct dns_nameval {
  int val;
  const char *name;
};
 extern const struct dns_nameval dns_classtab[];
 extern const struct dns_nameval dns_typetab[];
 extern const struct dns_nameval dns_rcodetab[];
 int
dns_findname(const struct dns_nameval *nv, const char *name);
 const char *dns_classname(enum dns_class cls);
 const char *dns_typename(enum dns_type type);
 const char *dns_rcodename(enum dns_rcode rcode);
const char *_dns_format_code(char *buf, const char *prefix, int code);
 const char *dns_strerror(int errnum);
struct query {
 char *name;
 unsigned char *dn;
 void (*callback)(char *ip, void *data, acetables *g_ape);
 void *data;
 acetables *g_ape;
 enum dns_type qtyp;
};
void ape_dns_init();
void ape_gethostbyname(char *name, void (*callback)(char *, void *, acetables *), void *data, acetables *g_ape);
typedef struct _apeconfig_def {
 char *val;
 struct _apeconfig_def *next;
 char key[33];
} apeconfig_def;
typedef struct apeconfig {
 apeconfig_def *def;
 struct apeconfig *next;
 char section[33];
} apeconfig;
apeconfig *ape_config_load(const char *filename);
char *ape_config_get_key(apeconfig *conf, const char *key);
void ape_config_set_key(apeconfig *conf, const char *key, char * value);
apeconfig *ape_config_get_section(apeconfig *conf, const char *section);
void ape_config_free(apeconfig *conf);
typedef struct _ace_callbacks ace_callbacks;
struct _ace_callbacks
{
 USERS *(*c_adduser)(USERS *, acetables *);
 void (*c_deluser)(USERS *, int istmp, acetables *);
 CHANNEL *(*c_mkchan)(char *, int, acetables *);
 void (*c_rmchan)(CHANNEL *, acetables *);
 void (*c_join)(USERS *, CHANNEL *, acetables *);
 void (*c_left)(USERS *, CHANNEL *, acetables *);
 void (*c_tickuser)(subuser *, acetables *);
 void (*c_post_raw_sub)(RAW *, subuser *, acetables *);
 USERS *(*c_allocateuser)(ape_socket *, const char *, const char *, acetables *);
 void (*c_addsubuser)(subuser *, acetables *);
 void (*c_delsubuser)(subuser *, acetables *);
};
typedef struct _plug_config plug_config;
struct _plug_config
{
 char *key;
 char *value;
 struct _plug_config *next;
};
typedef struct _ace_plugin_infos ace_plugin_infos;
typedef struct _ace_plugins ace_plugins;
struct _ace_plugin_infos
{
 const char *name;
 const char *version;
 const char *author;
 const char *conf_file;
 struct _plug_config *conf;
};
struct _ace_plugins
{
 struct {
  unsigned short int c_adduser;
  unsigned short int c_deluser;
  unsigned short int c_mkchan;
  unsigned short int c_rmchan;
  unsigned short int c_join;
  unsigned short int c_left;
  unsigned short int c_tickuser;
  unsigned short int c_post_raw_sub;
  unsigned short int c_allocateuser;
  unsigned short int c_addsubuser;
  unsigned short int c_delsubuser;
 } fire;
 void *hPlug;
 void (*loader)(acetables *g_ape);
 void (*unloader)(acetables *g_ape);
 const char *modulename;
 struct _ace_callbacks *cb;
 ace_plugin_infos *infos;
 ace_plugins *next;
};
enum {
 CALLBACK_PLUGIN = 0,
 CALLBACK_NULL
};
ace_plugins *loadplugin(char *file);
void findandloadplugin(acetables *g_ape);
void free_all_plugins(acetables *g_ape);
struct _plug_config *plugin_parse_conf(const char *file);
void plugin_read_config(ace_plugins *plug, const char *path);
char *plugin_get_conf(struct _plug_config *conf, char *key);
RAW *forge_raw(const char *raw, json_item *jlist)
{
 RAW *new_raw;
 char unixtime[16];
 struct jsontring *string;
 json_item *jstruct = ((void *)0);
 sprintf(unixtime, "%li", time(((void *)0)));
 jstruct = json_new_object();
 json_set_property_strN(jstruct, "time", 4, unixtime, strlen(unixtime));
 json_set_property_strN(jstruct, "raw", 3, raw, strlen(raw));
 json_set_property_objN(jstruct, "data", 4, jlist);
 string = json_to_string(jstruct, ((void *)0), 1);
 new_raw = xmalloc(sizeof(*new_raw));
 new_raw->len = string->len;
 new_raw->next = ((void *)0);
 new_raw->priority = RAW_PRI_LO;
 new_raw->refcount = 0;
 new_raw->data = string->jstring;
 free(string);
 return new_raw;
}
int free_raw(RAW *fraw)
{
 if (--(fraw->refcount) <= 0) {
  free(fraw->data);
  free(fraw);
  return 0;
 }
 return fraw->refcount;
}
RAW *copy_raw(RAW *input)
{
 RAW *new_raw;
 new_raw = xmalloc(sizeof(*new_raw));
 new_raw->len = input->len;
 new_raw->next = input->next;
 new_raw->priority = input->priority;
 new_raw->refcount = 0;
 new_raw->data = xmalloc(sizeof(char) * (new_raw->len + 1));
 memcpy(new_raw->data, input->data, new_raw->len + 1);
 return new_raw;
}
RAW *copy_raw_z(RAW *input)
{
 (input->refcount)++;
 return input;
}
void post_raw_sub(RAW *raw, subuser *sub, acetables *g_ape)
{
 if (g_ape->plugins != ((void *)0)) { ace_plugins *cplug = g_ape->plugins; while (cplug != ((void *)0)) { if (cplug->cb != ((void *)0) && cplug->cb->c_post_raw_sub != ((void *)0) && cplug->fire.c_post_raw_sub == 0) { cplug->fire.c_post_raw_sub = 1; cplug->cb->c_post_raw_sub(raw, sub, g_ape); cplug->fire.c_post_raw_sub = 0; return; break; } cplug = cplug->next; } };
 int add_size = 16;
 struct _raw_pool_user *pool = (raw->priority == RAW_PRI_LO ? &sub->raw_pools.low : &sub->raw_pools.high);
 if (++pool->nraw == pool->size) {
  pool->size += add_size;
  expend_raw_pool(pool->rawfoot, add_size);
 }
 pool->rawfoot->raw = raw;
 pool->rawfoot = pool->rawfoot->next;
 (sub->raw_pools.nraw)++;
}
void post_raw(RAW *raw, USERS *user, acetables *g_ape)
{
 subuser *sub = user->subuser;
 while (sub != ((void *)0)) {
  post_raw_sub(copy_raw_z(raw), sub, g_ape);
  sub = sub->next;
 }
}
void post_raw_restricted(RAW *raw, USERS *user, subuser *sub, acetables *g_ape)
{
 subuser *tSub = user->subuser;
 if (sub == ((void *)0)) {
  return;
 }
 while (tSub != ((void *)0)) {
  if (sub != tSub) {
   post_raw_sub(copy_raw_z(raw), tSub, g_ape);
  }
  tSub = tSub->next;
 }
}
void post_raw_channel(RAW *raw, struct CHANNEL *chan, acetables *g_ape)
{
 userslist *list;
 if (chan == ((void *)0) || raw == ((void *)0) || chan->head == ((void *)0)) {
  return;
 }
 list = chan->head;
 while (list) {
  post_raw(raw, list->userinfo, g_ape);
  list = list->next;
 }
}
void post_raw_channel_restricted(RAW *raw, struct CHANNEL *chan, USERS *ruser, acetables *g_ape)
{
 userslist *list;
 if (chan == ((void *)0) || raw == ((void *)0) || chan->head == ((void *)0)) {
  return;
 }
 list = chan->head;
 while (list) {
  if (list->userinfo != ruser) {
   post_raw(raw, list->userinfo, g_ape);
  }
  list = list->next;
 }
}
void proxy_post_raw(RAW *raw, ape_proxy *proxy, acetables *g_ape)
{
 ape_proxy_pipe *to = proxy->to;
 transpipe *pipe;
 while (to != ((void *)0)) {
  pipe = get_pipe(to->pipe, g_ape);
  if (pipe != ((void *)0) && pipe->type == USER_PIPE) {
   post_raw(raw, pipe->pipe, g_ape);
  } else {
   ;
  }
  to = to->next;
 }
}
int post_raw_pipe(RAW *raw, const char *pipe, acetables *g_ape)
{
 transpipe *spipe;
 if ((spipe = get_pipe(pipe, g_ape)) != ((void *)0)) {
  if (spipe->type == CHANNEL_PIPE) {
   post_raw_channel(raw, spipe->pipe, g_ape);
   return 1;
  } else {
   post_raw(raw, spipe->pipe, g_ape);
   return 1;
  }
 }
 return 0;
}
int post_to_pipe(json_item *jlist, const char *rawname, const char *pipe, subuser *from, acetables *g_ape)
{
 USERS *sender = from->user;
 transpipe *recver = get_pipe_strict(pipe, sender, g_ape);
 json_item *jlist_copy = ((void *)0);
 RAW *newraw;
 if (sender != ((void *)0)) {
  if (recver == ((void *)0)) {
   send_error(sender, "UNKNOWN_PIPE", "109", g_ape);
   return 0;
  }
  json_set_property_objN(jlist, "from", 4, get_json_object_user(sender));
 }
 if (sender != ((void *)0) && sender->nsub > 1) {
  jlist_copy = json_item_copy(jlist, ((void *)0));
  json_set_property_objN(jlist_copy, "pipe", 4, get_json_object_pipe(recver));
  newraw = forge_raw(rawname, jlist_copy);
  post_raw_restricted(newraw, sender, from, g_ape);
 }
 switch(recver->type) {
  case USER_PIPE:
   json_set_property_objN(jlist, "pipe", 4, get_json_object_user(sender));
   newraw = forge_raw(rawname, jlist);
   post_raw(newraw, recver->pipe, g_ape);
   break;
  case CHANNEL_PIPE:
   if (((CHANNEL*)recver->pipe)->head != ((void *)0) && ((CHANNEL*)recver->pipe)->head->next != ((void *)0)) {
    json_set_property_objN(jlist, "pipe", 4, get_json_object_channel(recver->pipe));
    newraw = forge_raw(rawname, jlist);
    post_raw_channel_restricted(newraw, recver->pipe, sender, g_ape);
   }
   break;
  case CUSTOM_PIPE:
   json_set_property_objN(jlist, "pipe", 4, get_json_object_user(sender));
   post_json_custom(jlist, sender, recver, g_ape);
   break;
  default:
   break;
 }
 return 1;
}
int send_raw_inline(ape_socket *client, transport_t transport, RAW *raw, acetables *g_ape)
{
 struct _transport_properties *properties;
 int finish = 1;
 properties = transport_get_properties(transport, g_ape);
 switch(transport) {
  case TRANSPORT_XHRSTREAMING:
   finish &= http_send_headers(((void *)0), "HTTP/1.1 200 OK\r\nPragma: no-cache\r\nCache-Control: no-cache, must-revalidate\r\nExpires: Thu, 27 Dec 1986 07:30:00 GMT\r\nContent-Type: application/x-ape-event-stream\r\n\r\n                                                                                                                                                                                                                                                                ", 421, client, g_ape);
   break;
  case TRANSPORT_SSE_LONGPOLLING:
   finish &= http_send_headers(((void *)0), "HTTP/1.1 200 OK\r\nPragma: no-cache\r\nCache-Control: no-cache, must-revalidate\r\nExpires: Thu, 27 Dec 1986 07:30:00 GMT\r\nContent-Type: application/x-dom-event-stream\r\n\r\n", 165, client, g_ape);
   break;
  case TRANSPORT_JSONP:
   finish &= http_send_headers(((void *)0), "HTTP/1.1 200 OK\r\nPragma: no-cache\r\nCache-Control: no-cache, must-revalidate\r\nExpires: Thu, 27 Dec 1986 07:30:00 GMT\r\nContent-Type: application/javascript\r\n\r\n", 157, client, g_ape);
   break;
  case TRANSPORT_WEBSOCKET:
  case TRANSPORT_WEBSOCKET_IETF:
   break;
  default:
   finish &= http_send_headers(((void *)0), "HTTP/1.1 200 OK\r\nPragma: no-cache\r\nCache-Control: no-cache, must-revalidate\r\nExpires: Thu, 27 Dec 1986 07:30:00 GMT\r\nContent-Type: text/html\r\n\r\n", 144, client, g_ape);
   break;
 }
 if (properties != ((void *)0) && properties->padding.left.val != ((void *)0)) {
  finish &= sendbin(client->fd, properties->padding.left.val, properties->padding.left.len, 0, g_ape);
 }
 if (transport == TRANSPORT_WEBSOCKET_IETF) {
     websocket_state *websocket = client->parser.data;
     char payload_head[32] = { websocket->version == WS_IETF_06 ? 0x84 : 0x81 };
     int payload_size = raw->len+2;
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
 finish &= sendbin(client->fd, "[", 1, 0, g_ape);
 finish &= sendbin(client->fd, raw->data, raw->len, 0, g_ape);
 finish &= sendbin(client->fd, "]", 1, 0, g_ape);
 if (properties != ((void *)0) && properties->padding.right.val != ((void *)0)) {
  finish &= sendbin(client->fd, properties->padding.right.val, properties->padding.right.len, 0, g_ape);
 }
 free_raw(raw);
 return finish;
}
static unsigned int raws_size(subuser *user)
{
    struct _raw_pool *pool;
    int state = 0;
    unsigned int size = 1;
 if (user->raw_pools.nraw == 0) {
  return 0;
 }
 if (user->raw_pools.high.nraw) {
  pool = user->raw_pools.high.rawfoot->prev;
 } else {
  pool = user->raw_pools.low.rawhead;
  state = 1;
 }
 while (pool->raw != ((void *)0)) {
  struct _raw_pool *pool_next = (state ? pool->next : pool->prev);
  size += pool->raw->len + 1;
  pool = pool_next;
  if ((pool == ((void *)0) || pool->raw == ((void *)0)) && !state) {
   pool = user->raw_pools.low.rawhead;
   state = 1;
  }
 }
    return size;
}
int send_raws(subuser *user, acetables *g_ape)
{
 int finish = 1, state = 0;
 struct _raw_pool *pool;
 struct _transport_properties *properties;
 if (user->raw_pools.nraw == 0) {
  return 1;
 }
 do { int __state = 1; setsockopt(user->client->fd, IPPROTO_TCP, 3, &__state, sizeof(__state)); } while(0);
 properties = transport_get_properties(user->user->transport, g_ape);
 if (!user->headers.sent) {
  user->headers.sent = 1;
  switch(user->user->transport) {
   case TRANSPORT_XHRSTREAMING:
    finish &= http_send_headers(user->headers.content, "HTTP/1.1 200 OK\r\nPragma: no-cache\r\nCache-Control: no-cache, must-revalidate\r\nExpires: Thu, 27 Dec 1986 07:30:00 GMT\r\nContent-Type: application/x-ape-event-stream\r\n\r\n                                                                                                                                                                                                                                                                ", 421, user->client, g_ape);
    break;
   case TRANSPORT_SSE_LONGPOLLING:
    finish &= http_send_headers(user->headers.content, "HTTP/1.1 200 OK\r\nPragma: no-cache\r\nCache-Control: no-cache, must-revalidate\r\nExpires: Thu, 27 Dec 1986 07:30:00 GMT\r\nContent-Type: application/x-dom-event-stream\r\n\r\n", 165, user->client, g_ape);
    break;
   case TRANSPORT_JSONP:
    finish &= http_send_headers(user->headers.content, "HTTP/1.1 200 OK\r\nPragma: no-cache\r\nCache-Control: no-cache, must-revalidate\r\nExpires: Thu, 27 Dec 1986 07:30:00 GMT\r\nContent-Type: application/javascript\r\n\r\n", 157, user->client, g_ape);
   break;
   case TRANSPORT_WEBSOCKET:
   case TRANSPORT_WEBSOCKET_IETF:
    break;
   default:
    finish &= http_send_headers(user->headers.content, "HTTP/1.1 200 OK\r\nPragma: no-cache\r\nCache-Control: no-cache, must-revalidate\r\nExpires: Thu, 27 Dec 1986 07:30:00 GMT\r\nContent-Type: text/html\r\n\r\n", 144, user->client, g_ape);
    break;
  }
 }
 if (properties != ((void *)0) && properties->padding.left.val != ((void *)0)) {
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
     int payload_size = raws_size(user);
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
 finish &= sendbin(user->client->fd, "[", 1, 0, g_ape);
 while (pool->raw != ((void *)0)) {
  struct _raw_pool *pool_next = (state ? pool->next : pool->prev);
  finish &= sendbin(user->client->fd, pool->raw->data, pool->raw->len, 0, g_ape);
  if ((pool_next != ((void *)0) && pool_next->raw != ((void *)0)) || (!state && user->raw_pools.low.nraw)) {
   finish &= sendbin(user->client->fd, ",", 1, 0, g_ape);
  } else {
   finish &= sendbin(user->client->fd, "]", 1, 0, g_ape);
   if (properties != ((void *)0) && properties->padding.right.val != ((void *)0)) {
    finish &= sendbin(user->client->fd, properties->padding.right.val, properties->padding.right.len, 0, g_ape);
   }
  }
  free_raw(pool->raw);
  pool->raw = ((void *)0);
  pool = pool_next;
  if ((pool == ((void *)0) || pool->raw == ((void *)0)) && !state) {
   pool = user->raw_pools.low.rawhead;
   state = 1;
  }
 }
 user->raw_pools.high.nraw = 0;
 user->raw_pools.low.nraw = 0;
 user->raw_pools.nraw = 0;
 user->raw_pools.high.rawfoot = user->raw_pools.high.rawhead;
 user->raw_pools.low.rawfoot = user->raw_pools.low.rawhead;
 do { int __state = 0; setsockopt(user->client->fd, IPPROTO_TCP, 3, &__state, sizeof(__state)); } while(0);
 return finish;
}
struct _raw_pool *init_raw_pool(int n)
{
 int i;
 struct _raw_pool *pool = xmalloc(sizeof(*pool) * n);
 for (i = 0; i < n; i++) {
  pool[i].raw = ((void *)0);
  pool[i].next = (i == n-1 ? ((void *)0) : &pool[i+1]);
  pool[i].prev = (i == 0 ? ((void *)0) : &pool[i-1]);
  pool[i].start = (i == 0);
 }
 return pool;
}
struct _raw_pool *expend_raw_pool(struct _raw_pool *ptr, int n)
{
 struct _raw_pool *pool = init_raw_pool(n);
 ptr->next = pool;
 pool->prev = ptr;
 return pool;
}
void destroy_raw_pool(struct _raw_pool *ptr)
{
 struct _raw_pool *pool = ptr, *tpool = ((void *)0);
 while (pool != ((void *)0)) {
  if (pool->raw != ((void *)0)) {
   free_raw(pool->raw);
  }
  if (pool->start) {
   if (tpool != ((void *)0)) {
    free(tpool);
   }
   tpool = pool;
  }
  pool = pool->next;
 }
 if (tpool != ((void *)0)) {
  free(tpool);
 }
}
