typedef unsigned long ULong;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long long __int64_t;
typedef unsigned long long __uint64_t;
typedef long __darwin_intptr_t;
typedef unsigned int __darwin_natural_t;
typedef int __darwin_ct_rune_t;
typedef union {
 char __mbstate8[128];
 long long _mbstateL;
} __mbstate_t;
typedef __mbstate_t __darwin_mbstate_t;
typedef long int __darwin_ptrdiff_t;
typedef long unsigned int __darwin_size_t;
typedef __builtin_va_list __darwin_va_list;
typedef int __darwin_wchar_t;
typedef __darwin_wchar_t __darwin_rune_t;
typedef int __darwin_wint_t;
typedef unsigned long __darwin_clock_t;
typedef __uint32_t __darwin_socklen_t;
typedef long __darwin_ssize_t;
typedef long __darwin_time_t;
struct __darwin_pthread_handler_rec
{
 void (*__routine)(void *);
 void *__arg;
 struct __darwin_pthread_handler_rec *__next;
};
struct _opaque_pthread_attr_t { long __sig; char __opaque[56]; };
struct _opaque_pthread_cond_t { long __sig; char __opaque[40]; };
struct _opaque_pthread_condattr_t { long __sig; char __opaque[8]; };
struct _opaque_pthread_mutex_t { long __sig; char __opaque[56]; };
struct _opaque_pthread_mutexattr_t { long __sig; char __opaque[8]; };
struct _opaque_pthread_once_t { long __sig; char __opaque[8]; };
struct _opaque_pthread_rwlock_t { long __sig; char __opaque[192]; };
struct _opaque_pthread_rwlockattr_t { long __sig; char __opaque[16]; };
struct _opaque_pthread_t { long __sig; struct __darwin_pthread_handler_rec *__cleanup_stack; char __opaque[1168]; };
typedef __int64_t __darwin_blkcnt_t;
typedef __int32_t __darwin_blksize_t;
typedef __int32_t __darwin_dev_t;
typedef unsigned int __darwin_fsblkcnt_t;
typedef unsigned int __darwin_fsfilcnt_t;
typedef __uint32_t __darwin_gid_t;
typedef __uint32_t __darwin_id_t;
typedef __uint64_t __darwin_ino64_t;
typedef __darwin_ino64_t __darwin_ino_t;
typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
typedef __uint16_t __darwin_mode_t;
typedef __int64_t __darwin_off_t;
typedef __int32_t __darwin_pid_t;
typedef struct _opaque_pthread_attr_t
   __darwin_pthread_attr_t;
typedef struct _opaque_pthread_cond_t
   __darwin_pthread_cond_t;
typedef struct _opaque_pthread_condattr_t
   __darwin_pthread_condattr_t;
typedef unsigned long __darwin_pthread_key_t;
typedef struct _opaque_pthread_mutex_t
   __darwin_pthread_mutex_t;
typedef struct _opaque_pthread_mutexattr_t
   __darwin_pthread_mutexattr_t;
typedef struct _opaque_pthread_once_t
   __darwin_pthread_once_t;
typedef struct _opaque_pthread_rwlock_t
   __darwin_pthread_rwlock_t;
typedef struct _opaque_pthread_rwlockattr_t
   __darwin_pthread_rwlockattr_t;
typedef struct _opaque_pthread_t
   *__darwin_pthread_t;
typedef __uint32_t __darwin_sigset_t;
typedef __int32_t __darwin_suseconds_t;
typedef __uint32_t __darwin_uid_t;
typedef __uint32_t __darwin_useconds_t;
typedef unsigned char __darwin_uuid_t[16];
typedef char __darwin_uuid_string_t[37];
typedef int __darwin_nl_item;
typedef int __darwin_wctrans_t;
typedef __uint32_t __darwin_wctype_t;
typedef enum {
 P_ALL,
 P_PID,
 P_PGID
} idtype_t;
typedef __darwin_pid_t pid_t;
typedef __darwin_id_t id_t;
typedef int sig_atomic_t;
struct __darwin_i386_thread_state
{
    unsigned int __eax;
    unsigned int __ebx;
    unsigned int __ecx;
    unsigned int __edx;
    unsigned int __edi;
    unsigned int __esi;
    unsigned int __ebp;
    unsigned int __esp;
    unsigned int __ss;
    unsigned int __eflags;
    unsigned int __eip;
    unsigned int __cs;
    unsigned int __ds;
    unsigned int __es;
    unsigned int __fs;
    unsigned int __gs;
};
struct __darwin_fp_control
{
    unsigned short __invalid :1,
        __denorm :1,
    __zdiv :1,
    __ovrfl :1,
    __undfl :1,
    __precis :1,
      :2,
    __pc :2,
    __rc :2,
             :1,
      :3;
};
typedef struct __darwin_fp_control __darwin_fp_control_t;
struct __darwin_fp_status
{
    unsigned short __invalid :1,
        __denorm :1,
    __zdiv :1,
    __ovrfl :1,
    __undfl :1,
    __precis :1,
    __stkflt :1,
    __errsumm :1,
    __c0 :1,
    __c1 :1,
    __c2 :1,
    __tos :3,
    __c3 :1,
    __busy :1;
};
typedef struct __darwin_fp_status __darwin_fp_status_t;
struct __darwin_mmst_reg
{
 char __mmst_reg[10];
 char __mmst_rsrv[6];
};
struct __darwin_xmm_reg
{
 char __xmm_reg[16];
};
struct __darwin_i386_float_state
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;
 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;
 __uint16_t __fpu_rsrv2;
 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;
 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 char __fpu_rsrv4[14*16];
 int __fpu_reserved1;
};
struct __darwin_i386_avx_state
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;
 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;
 __uint16_t __fpu_rsrv2;
 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;
 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 char __fpu_rsrv4[14*16];
 int __fpu_reserved1;
 char __avx_reserved1[64];
 struct __darwin_xmm_reg __fpu_ymmh0;
 struct __darwin_xmm_reg __fpu_ymmh1;
 struct __darwin_xmm_reg __fpu_ymmh2;
 struct __darwin_xmm_reg __fpu_ymmh3;
 struct __darwin_xmm_reg __fpu_ymmh4;
 struct __darwin_xmm_reg __fpu_ymmh5;
 struct __darwin_xmm_reg __fpu_ymmh6;
 struct __darwin_xmm_reg __fpu_ymmh7;
};
struct __darwin_i386_exception_state
{
 __uint16_t __trapno;
 __uint16_t __cpu;
 __uint32_t __err;
 __uint32_t __faultvaddr;
};
struct __darwin_x86_debug_state32
{
 unsigned int __dr0;
 unsigned int __dr1;
 unsigned int __dr2;
 unsigned int __dr3;
 unsigned int __dr4;
 unsigned int __dr5;
 unsigned int __dr6;
 unsigned int __dr7;
};
struct __darwin_x86_thread_state64
{
 __uint64_t __rax;
 __uint64_t __rbx;
 __uint64_t __rcx;
 __uint64_t __rdx;
 __uint64_t __rdi;
 __uint64_t __rsi;
 __uint64_t __rbp;
 __uint64_t __rsp;
 __uint64_t __r8;
 __uint64_t __r9;
 __uint64_t __r10;
 __uint64_t __r11;
 __uint64_t __r12;
 __uint64_t __r13;
 __uint64_t __r14;
 __uint64_t __r15;
 __uint64_t __rip;
 __uint64_t __rflags;
 __uint64_t __cs;
 __uint64_t __fs;
 __uint64_t __gs;
};
struct __darwin_x86_float_state64
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;
 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;
 __uint16_t __fpu_rsrv2;
 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;
 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 struct __darwin_xmm_reg __fpu_xmm8;
 struct __darwin_xmm_reg __fpu_xmm9;
 struct __darwin_xmm_reg __fpu_xmm10;
 struct __darwin_xmm_reg __fpu_xmm11;
 struct __darwin_xmm_reg __fpu_xmm12;
 struct __darwin_xmm_reg __fpu_xmm13;
 struct __darwin_xmm_reg __fpu_xmm14;
 struct __darwin_xmm_reg __fpu_xmm15;
 char __fpu_rsrv4[6*16];
 int __fpu_reserved1;
};
struct __darwin_x86_avx_state64
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;
 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;
 __uint16_t __fpu_rsrv2;
 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;
 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 struct __darwin_xmm_reg __fpu_xmm8;
 struct __darwin_xmm_reg __fpu_xmm9;
 struct __darwin_xmm_reg __fpu_xmm10;
 struct __darwin_xmm_reg __fpu_xmm11;
 struct __darwin_xmm_reg __fpu_xmm12;
 struct __darwin_xmm_reg __fpu_xmm13;
 struct __darwin_xmm_reg __fpu_xmm14;
 struct __darwin_xmm_reg __fpu_xmm15;
 char __fpu_rsrv4[6*16];
 int __fpu_reserved1;
 char __avx_reserved1[64];
 struct __darwin_xmm_reg __fpu_ymmh0;
 struct __darwin_xmm_reg __fpu_ymmh1;
 struct __darwin_xmm_reg __fpu_ymmh2;
 struct __darwin_xmm_reg __fpu_ymmh3;
 struct __darwin_xmm_reg __fpu_ymmh4;
 struct __darwin_xmm_reg __fpu_ymmh5;
 struct __darwin_xmm_reg __fpu_ymmh6;
 struct __darwin_xmm_reg __fpu_ymmh7;
 struct __darwin_xmm_reg __fpu_ymmh8;
 struct __darwin_xmm_reg __fpu_ymmh9;
 struct __darwin_xmm_reg __fpu_ymmh10;
 struct __darwin_xmm_reg __fpu_ymmh11;
 struct __darwin_xmm_reg __fpu_ymmh12;
 struct __darwin_xmm_reg __fpu_ymmh13;
 struct __darwin_xmm_reg __fpu_ymmh14;
 struct __darwin_xmm_reg __fpu_ymmh15;
};
struct __darwin_x86_exception_state64
{
    __uint16_t __trapno;
    __uint16_t __cpu;
    __uint32_t __err;
    __uint64_t __faultvaddr;
};
struct __darwin_x86_debug_state64
{
 __uint64_t __dr0;
 __uint64_t __dr1;
 __uint64_t __dr2;
 __uint64_t __dr3;
 __uint64_t __dr4;
 __uint64_t __dr5;
 __uint64_t __dr6;
 __uint64_t __dr7;
};
struct __darwin_mcontext32
{
 struct __darwin_i386_exception_state __es;
 struct __darwin_i386_thread_state __ss;
 struct __darwin_i386_float_state __fs;
};
struct __darwin_mcontext_avx32
{
 struct __darwin_i386_exception_state __es;
 struct __darwin_i386_thread_state __ss;
 struct __darwin_i386_avx_state __fs;
};
struct __darwin_mcontext64
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_state64 __ss;
 struct __darwin_x86_float_state64 __fs;
};
struct __darwin_mcontext_avx64
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_state64 __ss;
 struct __darwin_x86_avx_state64 __fs;
};
typedef struct __darwin_mcontext64 *mcontext_t;
struct __darwin_sigaltstack
{
 void *ss_sp;
 __darwin_size_t ss_size;
 int ss_flags;
};
typedef struct __darwin_sigaltstack stack_t;
struct __darwin_ucontext
{
 int uc_onstack;
 __darwin_sigset_t uc_sigmask;
 struct __darwin_sigaltstack uc_stack;
 struct __darwin_ucontext *uc_link;
 __darwin_size_t uc_mcsize;
 struct __darwin_mcontext64 *uc_mcontext;
};
typedef struct __darwin_ucontext ucontext_t;
typedef __darwin_pthread_attr_t pthread_attr_t;
typedef __darwin_sigset_t sigset_t;
typedef __darwin_size_t size_t;
typedef __darwin_uid_t uid_t;
union sigval {
 int sival_int;
 void *sival_ptr;
};
struct sigevent {
 int sigev_notify;
 int sigev_signo;
 union sigval sigev_value;
 void (*sigev_notify_function)(union sigval);
 pthread_attr_t *sigev_notify_attributes;
};
typedef struct __siginfo {
 int si_signo;
 int si_errno;
 int si_code;
 pid_t si_pid;
 uid_t si_uid;
 int si_status;
 void *si_addr;
 union sigval si_value;
 long si_band;
 unsigned long __pad[7];
} siginfo_t;
union __sigaction_u {
 void (*__sa_handler)(int);
 void (*__sa_sigaction)(int, struct __siginfo *,
         void *);
};
struct __sigaction {
 union __sigaction_u __sigaction_u;
 void (*sa_tramp)(void *, int, int, siginfo_t *, void *);
 sigset_t sa_mask;
 int sa_flags;
};
struct sigaction {
 union __sigaction_u __sigaction_u;
 sigset_t sa_mask;
 int sa_flags;
};
typedef void (*sig_t)(int);
struct sigvec {
 void (*sv_handler)(int);
 int sv_mask;
 int sv_flags;
};
struct sigstack {
 char *ss_sp;
 int ss_onstack;
};

void (*signal(int, void (*)(int)))(int);

typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;
typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;
typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;
typedef __darwin_intptr_t intptr_t;
typedef unsigned long uintptr_t;
typedef long int intmax_t;
typedef long unsigned int uintmax_t;
struct timeval
{
 __darwin_time_t tv_sec;
 __darwin_suseconds_t tv_usec;
};
typedef __uint64_t rlim_t;
struct rusage {
 struct timeval ru_utime;
 struct timeval ru_stime;
 long ru_maxrss;
 long ru_ixrss;
 long ru_idrss;
 long ru_isrss;
 long ru_minflt;
 long ru_majflt;
 long ru_nswap;
 long ru_inblock;
 long ru_oublock;
 long ru_msgsnd;
 long ru_msgrcv;
 long ru_nsignals;
 long ru_nvcsw;
 long ru_nivcsw;
};
typedef void *rusage_info_t;
struct rusage_info_v0 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
};
struct rusage_info_v1 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
};
struct rusage_info_v2 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
};
struct rlimit {
 rlim_t rlim_cur;
 rlim_t rlim_max;
};
struct proc_rlimit_control_wakeupmon {
 uint32_t wm_flags;
 int32_t wm_rate;
};

int getpriority(int, id_t);
int getiopolicy_np(int, int) ;
int getrlimit(int, struct rlimit *) __asm("_" "getrlimit" );
int getrusage(int, struct rusage *);
int setpriority(int, id_t, int);
int setiopolicy_np(int, int, int) ;
int setrlimit(int, const struct rlimit *) __asm("_" "setrlimit" );

static __inline__
__uint16_t
_OSSwapInt16(
    __uint16_t _data
)
{
    return ((__uint16_t)((_data << 8) | (_data >> 8)));
}
static __inline__
__uint32_t
_OSSwapInt32(
    __uint32_t _data
)
{
    __asm__ ("bswap   %0" : "+r" (_data));
    return _data;
}
static __inline__
__uint64_t
_OSSwapInt64(
    __uint64_t _data
)
{
    __asm__ ("bswap   %0" : "+r" (_data));
    return _data;
}
union wait {
 int w_status;
 struct {
  unsigned int w_Termsig:7,
    w_Coredump:1,
    w_Retcode:8,
    w_Filler:16;
 } w_T;
 struct {
  unsigned int w_Stopval:8,
    w_Stopsig:8,
    w_Filler:16;
 } w_S;
};

pid_t wait(int *) __asm("_" "wait" );
pid_t waitpid(pid_t, int *, int) __asm("_" "waitpid" );
int waitid(idtype_t, id_t, siginfo_t *, int) __asm("_" "waitid" );
pid_t wait3(int *, int, struct rusage *);
pid_t wait4(pid_t, int *, int, struct rusage *);


void *alloca(size_t);

typedef __darwin_ct_rune_t ct_rune_t;
typedef __darwin_rune_t rune_t;
typedef __darwin_wchar_t wchar_t;
typedef struct {
 int quot;
 int rem;
} div_t;
typedef struct {
 long quot;
 long rem;
} ldiv_t;
typedef struct {
 long long quot;
 long long rem;
} lldiv_t;
extern int __mb_cur_max;

void abort(void) __attribute__((noreturn));
int abs(int) __attribute__((const));
int atexit(void (*)(void));
double atof(const char *);
int atoi(const char *);
long atol(const char *);
long long
  atoll(const char *);
void *bsearch(const void *, const void *, size_t,
     size_t, int (*)(const void *, const void *));
void *calloc(size_t, size_t);
div_t div(int, int) __attribute__((const));
void exit(int) __attribute__((noreturn));
void free(void *);
char *getenv(const char *);
long labs(long) __attribute__((const));
ldiv_t ldiv(long, long) __attribute__((const));
long long
  llabs(long long);
lldiv_t lldiv(long long, long long);
void *malloc(size_t);
int mblen(const char *, size_t);
size_t mbstowcs(wchar_t * , const char * , size_t);
int mbtowc(wchar_t * , const char * , size_t);
int posix_memalign(void **, size_t, size_t) ;
void qsort(void *, size_t, size_t,
     int (*)(const void *, const void *));
int rand(void);
void *realloc(void *, size_t);
void srand(unsigned);
double strtod(const char *, char **) __asm("_" "strtod" );
float strtof(const char *, char **) __asm("_" "strtof" );
long strtol(const char *, char **, int);
long double
  strtold(const char *, char **);
long long
  strtoll(const char *, char **, int);
unsigned long
  strtoul(const char *, char **, int);
unsigned long long
  strtoull(const char *, char **, int);
int system(const char *) __asm("_" "system" );
size_t wcstombs(char * , const wchar_t * , size_t);
int wctomb(char *, wchar_t);
void _Exit(int) __attribute__((noreturn));
long a64l(const char *);
double drand48(void);
char *ecvt(double, int, int *, int *);
double erand48(unsigned short[3]);
char *fcvt(double, int, int *, int *);
char *gcvt(double, int, char *);
int getsubopt(char **, char * const *, char **);
int grantpt(int);
char *initstate(unsigned, char *, size_t);
long jrand48(unsigned short[3]);
char *l64a(long);
void lcong48(unsigned short[7]);
long lrand48(void);
char *mktemp(char *);
int mkstemp(char *);
long mrand48(void);
long nrand48(unsigned short[3]);
int posix_openpt(int);
char *ptsname(int);
int putenv(char *) __asm("_" "putenv" );
long random(void);
int rand_r(unsigned *);
char *realpath(const char * , char * ) __asm("_" "realpath" "$DARWIN_EXTSN");
unsigned short
 *seed48(unsigned short[3]);
int setenv(const char *, const char *, int) __asm("_" "setenv" );
void setkey(const char *) __asm("_" "setkey" );
char *setstate(const char *);
void srand48(long);
void srandom(unsigned);
int unlockpt(int);
int unsetenv(const char *) __asm("_" "unsetenv" );
typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long long u_int64_t;
typedef int64_t register_t;
typedef u_int64_t user_addr_t;
typedef u_int64_t user_size_t;
typedef int64_t user_ssize_t;
typedef int64_t user_long_t;
typedef u_int64_t user_ulong_t;
typedef int64_t user_time_t;
typedef int64_t user_off_t;
typedef u_int64_t syscall_arg_t;
typedef __darwin_dev_t dev_t;
typedef __darwin_mode_t mode_t;
u_int32_t arc4random(void);
void arc4random_addrandom(unsigned char * , int );
void arc4random_buf(void * , size_t ) ;
void arc4random_stir(void);
u_int32_t
  arc4random_uniform(u_int32_t ) ;
char *cgetcap(char *, const char *, int);
int cgetclose(void);
int cgetent(char **, char **, const char *);
int cgetfirst(char **, char **);
int cgetmatch(const char *, const char *);
int cgetnext(char **, char **);
int cgetnum(char *, const char *, long *);
int cgetset(const char *);
int cgetstr(char *, const char *, char **);
int cgetustr(char *, const char *, char **);
int daemon(int, int) __asm("_" "daemon" "$1050") __attribute__((deprecated));
char *devname(dev_t, mode_t);
char *devname_r(dev_t, mode_t, char *buf, int len);
char *getbsize(int *, long *);
int getloadavg(double [], int);
const char
 *getprogname(void);
int heapsort(void *, size_t, size_t,
     int (*)(const void *, const void *));
int mergesort(void *, size_t, size_t,
     int (*)(const void *, const void *));
void psort(void *, size_t, size_t,
     int (*)(const void *, const void *)) ;
void psort_r(void *, size_t, size_t, void *,
     int (*)(void *, const void *, const void *)) ;
void qsort_r(void *, size_t, size_t, void *,
     int (*)(void *, const void *, const void *));
int radixsort(const unsigned char **, int, const unsigned char *,
     unsigned);
void setprogname(const char *);
int sradixsort(const unsigned char **, int, const unsigned char *,
     unsigned);
void sranddev(void);
void srandomdev(void);
void *reallocf(void *, size_t);
long long
  strtoq(const char *, char **, int);
unsigned long long
  strtouq(const char *, char **, int);
extern char *suboptarg;
void *valloc(size_t);


void *memchr(const void *, int, size_t);
int memcmp(const void *, const void *, size_t);
void *memcpy(void *, const void *, size_t);
void *memmove(void *, const void *, size_t);
void *memset(void *, int, size_t);
char *strcat(char *, const char *);
char *strchr(const char *, int);
int strcmp(const char *, const char *);
int strcoll(const char *, const char *);
char *strcpy(char *, const char *);
size_t strcspn(const char *, const char *);
char *strerror(int) __asm("_" "strerror" );
size_t strlen(const char *);
char *strncat(char *, const char *, size_t);
int strncmp(const char *, const char *, size_t);
char *strncpy(char *, const char *, size_t);
char *strpbrk(const char *, const char *);
char *strrchr(const char *, int);
size_t strspn(const char *, const char *);
char *strstr(const char *, const char *);
char *strtok(char *, const char *);
size_t strxfrm(char *, const char *, size_t);


char *strtok_r(char *, const char *, char **);


int strerror_r(int, char *, size_t);
char *strdup(const char *);
void *memccpy(void *, const void *, int, size_t);


char *stpcpy(char *, const char *);
char *stpncpy(char *, const char *, size_t) ;
char *strndup(const char *, size_t) ;
size_t strnlen(const char *, size_t) ;
char *strsignal(int sig);

typedef __darwin_size_t rsize_t;
typedef int errno_t;

errno_t memset_s(void *, rsize_t, int, rsize_t) ;

typedef __darwin_ssize_t ssize_t;

void *memmem(const void *, size_t, const void *, size_t) ;
void memset_pattern4(void *, const void *, size_t) ;
void memset_pattern8(void *, const void *, size_t) ;
void memset_pattern16(void *, const void *, size_t) ;
char *strcasestr(const char *, const char *);
char *strnstr(const char *, const char *, size_t);
size_t strlcat(char *, const char *, size_t);
size_t strlcpy(char *, const char *, size_t);
void strmode(int, char *);
char *strsep(char **, const char *);
void swab(const void * , void * , ssize_t);


int bcmp(const void *, const void *, size_t) ;
void bcopy(const void *, void *, size_t) ;
void bzero(void *, size_t) ;
char *index(const char *, int) ;
char *rindex(const char *, int) ;
int ffs(int);
int strcasecmp(const char *, const char *);
int strncasecmp(const char *, const char *, size_t);


int ffsl(long) ;
int ffsll(long long) ;
int fls(int) ;
int flsl(long) ;
int flsll(long long) ;


extern int * __error(void);


    typedef float float_t;
    typedef double double_t;
extern int __math_errhandling(void);
extern int __fpclassifyf(float);
extern int __fpclassifyd(double);
extern int __fpclassifyl(long double);
extern __inline __attribute__ ((__always_inline__)) int __inline_isfinitef(float);
extern __inline __attribute__ ((__always_inline__)) int __inline_isfinited(double);
extern __inline __attribute__ ((__always_inline__)) int __inline_isfinitel(long double);
extern __inline __attribute__ ((__always_inline__)) int __inline_isinff(float);
extern __inline __attribute__ ((__always_inline__)) int __inline_isinfd(double);
extern __inline __attribute__ ((__always_inline__)) int __inline_isinfl(long double);
extern __inline __attribute__ ((__always_inline__)) int __inline_isnanf(float);
extern __inline __attribute__ ((__always_inline__)) int __inline_isnand(double);
extern __inline __attribute__ ((__always_inline__)) int __inline_isnanl(long double);
extern __inline __attribute__ ((__always_inline__)) int __inline_isnormalf(float);
extern __inline __attribute__ ((__always_inline__)) int __inline_isnormald(double);
extern __inline __attribute__ ((__always_inline__)) int __inline_isnormall(long double);
extern __inline __attribute__ ((__always_inline__)) int __inline_signbitf(float);
extern __inline __attribute__ ((__always_inline__)) int __inline_signbitd(double);
extern __inline __attribute__ ((__always_inline__)) int __inline_signbitl(long double);
extern __inline __attribute__ ((__always_inline__)) int __inline_isfinitef(float __x) {
    return __x == __x && __builtin_fabsf(__x) != __builtin_inff();
}
extern __inline __attribute__ ((__always_inline__)) int __inline_isfinited(double __x) {
    return __x == __x && __builtin_fabs(__x) != __builtin_inf();
}
extern __inline __attribute__ ((__always_inline__)) int __inline_isfinitel(long double __x) {
    return __x == __x && __builtin_fabsl(__x) != __builtin_infl();
}
extern __inline __attribute__ ((__always_inline__)) int __inline_isinff(float __x) {
    return __builtin_fabsf(__x) == __builtin_inff();
}
extern __inline __attribute__ ((__always_inline__)) int __inline_isinfd(double __x) {
    return __builtin_fabs(__x) == __builtin_inf();
}
extern __inline __attribute__ ((__always_inline__)) int __inline_isinfl(long double __x) {
    return __builtin_fabsl(__x) == __builtin_infl();
}
extern __inline __attribute__ ((__always_inline__)) int __inline_isnanf(float __x) {
    return __x != __x;
}
extern __inline __attribute__ ((__always_inline__)) int __inline_isnand(double __x) {
    return __x != __x;
}
extern __inline __attribute__ ((__always_inline__)) int __inline_isnanl(long double __x) {
    return __x != __x;
}
extern __inline __attribute__ ((__always_inline__)) int __inline_signbitf(float __x) {
    union { float __f; unsigned int __u; } __u;
    __u.__f = __x;
    return (int)(__u.__u >> 31);
}
extern __inline __attribute__ ((__always_inline__)) int __inline_signbitd(double __x) {
    union { double __f; unsigned long long __u; } __u;
    __u.__f = __x;
    return (int)(__u.__u >> 63);
}
extern __inline __attribute__ ((__always_inline__)) int __inline_signbitl(long double __x) {
    union {
        long double __ld;
        struct{ unsigned long long __m; unsigned short __sexp; } __p;
    } __u;
    __u.__ld = __x;
    return (int)(__u.__p.__sexp >> 15);
}
extern __inline __attribute__ ((__always_inline__)) int __inline_isnormalf(float __x) {
    return __inline_isfinitef(__x) && __builtin_fabsf(__x) >= 1.17549435082228750797e-38F;
}
extern __inline __attribute__ ((__always_inline__)) int __inline_isnormald(double __x) {
    return __inline_isfinited(__x) && __builtin_fabs(__x) >= ((double)2.22507385850720138309e-308L);
}
extern __inline __attribute__ ((__always_inline__)) int __inline_isnormall(long double __x) {
    return __inline_isfinitel(__x) && __builtin_fabsl(__x) >= 3.36210314311209350626e-4932L;
}
extern float acosf(float);
extern double acos(double);
extern long double acosl(long double);
extern float asinf(float);
extern double asin(double);
extern long double asinl(long double);
extern float atanf(float);
extern double atan(double);
extern long double atanl(long double);
extern float atan2f(float, float);
extern double atan2(double, double);
extern long double atan2l(long double, long double);
extern float cosf(float);
extern double cos(double);
extern long double cosl(long double);
extern float sinf(float);
extern double sin(double);
extern long double sinl(long double);
extern float tanf(float);
extern double tan(double);
extern long double tanl(long double);
extern float acoshf(float);
extern double acosh(double);
extern long double acoshl(long double);
extern float asinhf(float);
extern double asinh(double);
extern long double asinhl(long double);
extern float atanhf(float);
extern double atanh(double);
extern long double atanhl(long double);
extern float coshf(float);
extern double cosh(double);
extern long double coshl(long double);
extern float sinhf(float);
extern double sinh(double);
extern long double sinhl(long double);
extern float tanhf(float);
extern double tanh(double);
extern long double tanhl(long double);
extern float expf(float);
extern double exp(double);
extern long double expl(long double);
extern float exp2f(float);
extern double exp2(double);
extern long double exp2l(long double);
extern float expm1f(float);
extern double expm1(double);
extern long double expm1l(long double);
extern float logf(float);
extern double log(double);
extern long double logl(long double);
extern float log10f(float);
extern double log10(double);
extern long double log10l(long double);
extern float log2f(float);
extern double log2(double);
extern long double log2l(long double);
extern float log1pf(float);
extern double log1p(double);
extern long double log1pl(long double);
extern float logbf(float);
extern double logb(double);
extern long double logbl(long double);
extern float modff(float, float *);
extern double modf(double, double *);
extern long double modfl(long double, long double *);
extern float ldexpf(float, int);
extern double ldexp(double, int);
extern long double ldexpl(long double, int);
extern float frexpf(float, int *);
extern double frexp(double, int *);
extern long double frexpl(long double, int *);
extern int ilogbf(float);
extern int ilogb(double);
extern int ilogbl(long double);
extern float scalbnf(float, int);
extern double scalbn(double, int);
extern long double scalbnl(long double, int);
extern float scalblnf(float, long int);
extern double scalbln(double, long int);
extern long double scalblnl(long double, long int);
extern float fabsf(float);
extern double fabs(double);
extern long double fabsl(long double);
extern float cbrtf(float);
extern double cbrt(double);
extern long double cbrtl(long double);
extern float hypotf(float, float);
extern double hypot(double, double);
extern long double hypotl(long double, long double);
extern float powf(float, float);
extern double pow(double, double);
extern long double powl(long double, long double);
extern float sqrtf(float);
extern double sqrt(double);
extern long double sqrtl(long double);
extern float erff(float);
extern double erf(double);
extern long double erfl(long double);
extern float erfcf(float);
extern double erfc(double);
extern long double erfcl(long double);
extern float lgammaf(float);
extern double lgamma(double);
extern long double lgammal(long double);
extern float tgammaf(float);
extern double tgamma(double);
extern long double tgammal(long double);
extern float ceilf(float);
extern double ceil(double);
extern long double ceill(long double);
extern float floorf(float);
extern double floor(double);
extern long double floorl(long double);
extern float nearbyintf(float);
extern double nearbyint(double);
extern long double nearbyintl(long double);
extern float rintf(float);
extern double rint(double);
extern long double rintl(long double);
extern long int lrintf(float);
extern long int lrint(double);
extern long int lrintl(long double);
extern float roundf(float);
extern double round(double);
extern long double roundl(long double);
extern long int lroundf(float);
extern long int lround(double);
extern long int lroundl(long double);
extern long long int llrintf(float);
extern long long int llrint(double);
extern long long int llrintl(long double);
extern long long int llroundf(float);
extern long long int llround(double);
extern long long int llroundl(long double);
extern float truncf(float);
extern double trunc(double);
extern long double truncl(long double);
extern float fmodf(float, float);
extern double fmod(double, double);
extern long double fmodl(long double, long double);
extern float remainderf(float, float);
extern double remainder(double, double);
extern long double remainderl(long double, long double);
extern float remquof(float, float, int *);
extern double remquo(double, double, int *);
extern long double remquol(long double, long double, int *);
extern float copysignf(float, float);
extern double copysign(double, double);
extern long double copysignl(long double, long double);
extern float nanf(const char *);
extern double nan(const char *);
extern long double nanl(const char *);
extern float nextafterf(float, float);
extern double nextafter(double, double);
extern long double nextafterl(long double, long double);
extern double nexttoward(double, long double);
extern float nexttowardf(float, long double);
extern long double nexttowardl(long double, long double);
extern float fdimf(float, float);
extern double fdim(double, double);
extern long double fdiml(long double, long double);
extern float fmaxf(float, float);
extern double fmax(double, double);
extern long double fmaxl(long double, long double);
extern float fminf(float, float);
extern double fmin(double, double);
extern long double fminl(long double, long double);
extern float fmaf(float, float, float);
extern double fma(double, double, double);
extern long double fmal(long double, long double, long double);
extern float __inff(void) __attribute__((deprecated));
extern double __inf(void) __attribute__((deprecated));
extern long double __infl(void) __attribute__((deprecated));
extern float __nan(void) ;
extern float __exp10f(float) ;
extern double __exp10(double) ;
extern __inline __attribute__ ((__always_inline__)) void __sincosf(float __x, float *__sinp, float *__cosp) ;
extern __inline __attribute__ ((__always_inline__)) void __sincos(double __x, double *__sinp, double *__cosp) ;
extern float __cospif(float) ;
extern double __cospi(double) ;
extern float __sinpif(float) ;
extern double __sinpi(double) ;
extern float __tanpif(float) ;
extern double __tanpi(double) ;
extern __inline __attribute__ ((__always_inline__)) void __sincospif(float __x, float *__sinp, float *__cosp) ;
extern __inline __attribute__ ((__always_inline__)) void __sincospi(double __x, double *__sinp, double *__cosp) ;
struct __float2 { float __sinval; float __cosval; };
struct __double2 { double __sinval; double __cosval; };
extern struct __float2 __sincosf_stret(float);
extern struct __double2 __sincos_stret(double);
extern struct __float2 __sincospif_stret(float);
extern struct __double2 __sincospi_stret(double);
extern __inline __attribute__ ((__always_inline__)) void __sincosf(float __x, float *__sinp, float *__cosp) {
    const struct __float2 __stret = __sincosf_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}
extern __inline __attribute__ ((__always_inline__)) void __sincos(double __x, double *__sinp, double *__cosp) {
    const struct __double2 __stret = __sincos_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}
extern __inline __attribute__ ((__always_inline__)) void __sincospif(float __x, float *__sinp, float *__cosp) {
    const struct __float2 __stret = __sincospif_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}
extern __inline __attribute__ ((__always_inline__)) void __sincospi(double __x, double *__sinp, double *__cosp) {
    const struct __double2 __stret = __sincospi_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}
extern double j0(double) ;
extern double j1(double) ;
extern double jn(int, double) ;
extern double y0(double) ;
extern double y1(double) ;
extern double yn(int, double) ;
extern double scalb(double, double);
extern int signgam;
extern long int rinttol(double) __attribute__((deprecated));
extern long int roundtol(double) __attribute__((deprecated));
extern double drem(double, double) __attribute__((deprecated));
extern int finite(double) __attribute__((deprecated));
extern double gamma(double) __attribute__((deprecated));
extern double significand(double) __attribute__((deprecated));
struct exception {
    int type;
    char *name;
    double arg1;
    double arg2;
    double retval;
};
extern int matherr(struct exception *) __attribute__((deprecated));


typedef union { double d; ULong L[2]; } U;
 struct
Bigint {
 struct Bigint *next;
 int k, maxwds, sign, wds;
 ULong x[1];
 };
 typedef struct Bigint Bigint;
 static Bigint *freelist[7 +1];
 static Bigint *p5s;
 static double private_mem[((2304 +sizeof(double)-1)/sizeof(double))];
 static double *pmem_next
                                        = private_mem
                                                     ;
 static Bigint *
Balloc
 ( int k)
{
 int x;
 Bigint *rv;
 size_t len;
 ;
 if (k <= 7 && (rv = freelist[k]))
  freelist[k] = rv->next;
 else {
  x = 1 << k;
  len = (sizeof(Bigint) + (x-1)*sizeof(ULong) + sizeof(double) - 1)
   /sizeof(double);
  if (k <= 7 && pmem_next - private_mem + len <= ((2304 +sizeof(double)-1)/sizeof(double))) {
   rv = (Bigint*)pmem_next;
   pmem_next += len;
   }
  else
   rv = (Bigint*)malloc(len*sizeof(double));
  rv->k = k;
  rv->maxwds = x;
  }
 ;
 rv->sign = rv->wds = 0;
 return rv;
 }
 static void
Bfree
 ( Bigint *v)
{
 if (v) {
  if (v->k > 7)
   free((void*)v);
  else {
   ;
   v->next = freelist[v->k];
   freelist[v->k] = v;
   ;
   }
  }
 }
 static Bigint *
multadd
 ( Bigint *b, int m, int a)
{
 int i, wds;
 ULong *x;
 unsigned long long carry, y;
 Bigint *b1;
 wds = b->wds;
 x = b->x;
 i = 0;
 carry = a;
 do {
  y = *x * (unsigned long long)m + carry;
  carry = y >> 32;
  *x++ = (ULong) y & 0xffffffffUL;
  }
  while(++i < wds);
 if (carry) {
  if (wds >= b->maxwds) {
   b1 = Balloc( b->k+1);
   __builtin___memcpy_chk ((char *)&b1->sign, (char *)&b->sign, b->wds*sizeof(long) + 2*sizeof(int), __builtin_object_size ((char *)&b1->sign, 0));
   Bfree( b);
   b = b1;
   }
  b->x[wds++] = (ULong) carry;
  b->wds = wds;
  }
 return b;
 }
 static Bigint *
s2b
 ( const char *s, int nd0, int nd, ULong y9)
{
 Bigint *b;
 int i, k;
 long x, y;
 x = (nd + 8) / 9;
 for(k = 0, y = 1; x > y; y <<= 1, k++) ;
 b = Balloc( k);
 b->x[0] = y9;
 b->wds = 1;
 i = 9;
 if (9 < nd0) {
  s += 9;
  do b = multadd( b, 10, *s++ - '0');
   while(++i < nd0);
  s++;
  }
 else
  s += 10;
 for(; i < nd; i++)
  b = multadd( b, 10, *s++ - '0');
 return b;
 }
 static int
hi0bits
 (register ULong x)
{
 register int k = 0;
 if (!(x & 0xffff0000)) {
  k = 16;
  x <<= 16;
  }
 if (!(x & 0xff000000)) {
  k += 8;
  x <<= 8;
  }
 if (!(x & 0xf0000000)) {
  k += 4;
  x <<= 4;
  }
 if (!(x & 0xc0000000)) {
  k += 2;
  x <<= 2;
  }
 if (!(x & 0x80000000)) {
  k++;
  if (!(x & 0x40000000))
   return 32;
  }
 return k;
 }
 static int
lo0bits
 (ULong *y)
{
 register int k;
 register ULong x = *y;
 if (x & 7) {
  if (x & 1)
   return 0;
  if (x & 2) {
   *y = x >> 1;
   return 1;
   }
  *y = x >> 2;
  return 2;
  }
 k = 0;
 if (!(x & 0xffff)) {
  k = 16;
  x >>= 16;
  }
 if (!(x & 0xff)) {
  k += 8;
  x >>= 8;
  }
 if (!(x & 0xf)) {
  k += 4;
  x >>= 4;
  }
 if (!(x & 0x3)) {
  k += 2;
  x >>= 2;
  }
 if (!(x & 1)) {
  k++;
  x >>= 1;
  if (!x)
   return 32;
  }
 *y = x;
 return k;
 }
 static Bigint *
i2b
 ( int i)
{
 Bigint *b;
 b = Balloc( 1);
 b->x[0] = i;
 b->wds = 1;
 return b;
 }
 static Bigint *
mult
 ( Bigint *a, Bigint *b)
{
 Bigint *c;
 int k, wa, wb, wc;
 ULong *x, *xa, *xae, *xb, *xbe, *xc, *xc0;
 ULong y;
 unsigned long long carry, z;
 if (a->wds < b->wds) {
  c = a;
  a = b;
  b = c;
  }
 k = a->k;
 wa = a->wds;
 wb = b->wds;
 wc = wa + wb;
 if (wc > a->maxwds)
  k++;
 c = Balloc( k);
 for(x = c->x, xa = x + wc; x < xa; x++)
  *x = 0;
 xa = a->x;
 xae = xa + wa;
 xb = b->x;
 xbe = xb + wb;
 xc0 = c->x;
 for(; xb < xbe; xc0++) {
  if ((y = *xb++)) {
   x = xa;
   xc = xc0;
   carry = 0;
   do {
    z = *x++ * (unsigned long long)y + *xc + carry;
    carry = z >> 32;
    *xc++ = (ULong) z & 0xffffffffUL;
    }
    while(x < xae);
   *xc = (ULong) carry;
   }
  }
 for(xc0 = c->x, xc = xc0 + wc; wc > 0 && !*--xc; --wc) ;
 c->wds = wc;
 return c;
 }
 static Bigint *
pow5mult
 ( Bigint *b, int k)
{
 Bigint *b1, *p5, *p51;
 int i;
 static const int p05[3] = { 5, 25, 125 };
 if ((i = k & 3))
  b = multadd( b, p05[i-1], 0);
 if (!(k >>= 2))
  return b;
 if (!(p5 = p5s)) {
  p5 = p5s = i2b( 625);
  p5->next = 0;
  }
 for(;;) {
  if (k & 1) {
   b1 = mult( b, p5);
   Bfree( b);
   b = b1;
   }
  if (!(k >>= 1))
   break;
  if (!(p51 = p5->next)) {
   p51 = p5->next = mult( p5,p5);
   p51->next = 0;
   }
  p5 = p51;
  }
 return b;
 }
 static Bigint *
lshift
 ( Bigint *b, int k)
{
 int i, k1, n, n1;
 Bigint *b1;
 ULong *x, *x1, *xe, z;
 n = k >> 5;
 k1 = b->k;
 n1 = n + b->wds + 1;
 for(i = b->maxwds; n1 > i; i <<= 1)
  k1++;
 b1 = Balloc( k1);
 x1 = b1->x;
 for(i = 0; i < n; i++)
  *x1++ = 0;
 x = b->x;
 xe = x + b->wds;
 if (k &= 0x1f) {
  k1 = 32 - k;
  z = 0;
  do {
   *x1++ = *x << k | z;
   z = *x++ >> k1;
   }
   while(x < xe);
  if ((*x1 = z))
   ++n1;
  }
 else do
  *x1++ = *x++;
  while(x < xe);
 b1->wds = n1 - 1;
 Bfree( b);
 return b1;
 }
 static int
cmp
 (Bigint *a, Bigint *b)
{
 ULong *xa, *xa0, *xb, *xb0;
 int i, j;
 i = a->wds;
 j = b->wds;
 if (i -= j)
  return i;
 xa0 = a->x;
 xa = xa0 + j;
 xb0 = b->x;
 xb = xb0 + j;
 for(;;) {
  if (*--xa != *--xb)
   return *xa < *xb ? -1 : 1;
  if (xa <= xa0)
   break;
  }
 return 0;
 }
 static Bigint *
diff
 ( Bigint *a, Bigint *b)
{
 Bigint *c;
 int i, wa, wb;
 ULong *xa, *xae, *xb, *xbe, *xc;
 unsigned long long borrow, y;
 i = cmp(a,b);
 if (!i) {
  c = Balloc( 0);
  c->wds = 1;
  c->x[0] = 0;
  return c;
  }
 if (i < 0) {
  c = a;
  a = b;
  b = c;
  i = 1;
  }
 else
  i = 0;
 c = Balloc( a->k);
 c->sign = i;
 wa = a->wds;
 xa = a->x;
 xae = xa + wa;
 wb = b->wds;
 xb = b->x;
 xbe = xb + wb;
 xc = c->x;
 borrow = 0;
 do {
  y = (unsigned long long)*xa++ - *xb++ - borrow;
  borrow = y >> 32 & (ULong)1;
  *xc++ = (ULong) y & 0xffffffffUL;
  }
  while(xb < xbe);
 while(xa < xae) {
  y = *xa++ - borrow;
  borrow = y >> 32 & (ULong)1;
  *xc++ = (ULong) y & 0xffffffffUL;
  }
 while(!*--xc)
  wa--;
 c->wds = wa;
 return c;
 }
 static double
ulp
 (U x)
{
 register long L;
 U a;
 L = (((x).L[0]) & 0x7f80) - (56 -1)*0x80;
  ((a).L[0]) = L;
  ((a).L[1]) = 0;
 return ((a).d);
 }
 static double
b2d
 (Bigint *a, int *e)
{
 ULong *xa, *xa0, w, y, z;
 int k;
 U d;
 xa0 = a->x;
 xa = xa0 + a->wds;
 y = *--xa;
 k = hi0bits(y);
 *e = 32 - k;
 if (k < 8) {
  ((d).L[0]) = 0x40800000 | y >> (8 - k);
  w = xa > xa0 ? *--xa : 0;
  ((d).L[1]) = y << ((32-8) + k) | w >> (8 - k);
  goto ret_d;
  }
 z = xa > xa0 ? *--xa : 0;
 if (k -= 8) {
  ((d).L[0]) = 0x40800000 | y << k | z >> (32 - k);
  y = xa > xa0 ? *--xa : 0;
  ((d).L[1]) = z << k | y >> (32 - k);
  }
 else {
  ((d).L[0]) = 0x40800000 | y;
  ((d).L[1]) = z;
  }
 ret_d:
 return ((d).d);
 }
 static Bigint *
d2b
 ( U d, int *e, int *bits)
{
 Bigint *b;
 int de, k;
 ULong *x, y, z;
 b = Balloc( 1);
 x = b->x;
 z = ((d).L[0]) & 0x7fffff;
 ((d).L[0]) &= 0x7fffffff;
 de = (int)(((d).L[0]) >> 23);
 z |= 0x800000;
 if ((y = ((d).L[1]))) {
  if ((k = lo0bits(&y))) {
   x[0] = y | z << (32 - k);
   z >>= k;
   }
  else
   x[0] = y;
      b->wds = (x[1] = z) ? 2 : 1;
  }
 else {
  k = lo0bits(&z);
  x[0] = z;
      b->wds = 1;
  k += 32;
  }
  *e = de - 129 - (56 -1) + k;
  *bits = 56 - k;
 return b;
 }
 static double
ratio
 (Bigint *a, Bigint *b)
{
 U da, db;
 int k, ka, kb;
 ((da).d) = b2d(a, &ka);
 ((db).d) = b2d(b, &kb);
 k = ka - kb + 32*(a->wds - b->wds);
 if (k > 0)
  ((da).L[0]) += k*0x80;
 else {
  k = -k;
  ((db).L[0]) += k*0x80;
  }
 return ((da).d) / ((db).d);
 }
 static const double
tens[] = {
  1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9,
  1e10, 1e11, 1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18, 1e19,
  1e20, 1e21, 1e22
  };
 static const double
bigtens[] = { 1e16, 1e32 };
static const double tinytens[] = { 1e-16, 1e-32 };
 static double
_strtod
 ( const char *s00, char **se)
{
 int bb2, bb5, bbe, bd2, bd5, bbbits, bs2, c, dsign,
   e, e1, esign, i, j, k, nd, nd0, nf, nz, nz0, sign;
 const char *s, *s0, *s1;
 double aadj, adj;
 U aadj1, rv, rv0;
 long L;
 ULong y, z;
 Bigint *bb, *bb1, *bd, *bd0, *bs, *delta;
 delta = bb = bd = bs = 0;
 sign = nz0 = nz = 0;
 ((rv).d) = 0.;
 for(s = s00;;s++) switch(*s) {
  case '-':
   sign = 1;
  case '+':
   if (*++s)
    goto break2;
  case 0:
   goto ret0;
  case '\t':
  case '\n':
  case '\v':
  case '\f':
  case '\r':
  case ' ':
   continue;
  default:
   goto break2;
  }
 break2:
 if (*s == '0') {
  nz0 = 1;
  while(*++s == '0') ;
  if (!*s)
   goto ret;
  }
 s0 = s;
 y = z = 0;
 for(nd = nf = 0; (c = *s) >= '0' && c <= '9'; nd++, s++)
  if (nd < 9)
   y = 10*y + c - '0';
  else if (nd < 16)
   z = 10*z + c - '0';
 nd0 = nd;
 if (c == '.') {
  c = *++s;
  if (!nd) {
   for(; c == '0'; c = *++s)
    nz++;
   if (c > '0' && c <= '9') {
    s0 = s;
    nf += nz;
    nz = 0;
    goto have_dig;
    }
   goto dig_done;
   }
  for(; c >= '0' && c <= '9'; c = *++s) {
 have_dig:
   nz++;
   if (c -= '0') {
    nf += nz;
    for(i = 1; i < nz; i++)
     if (nd++ < 9)
      y *= 10;
     else if (nd <= 15 + 1)
      z *= 10;
    if (nd++ < 9)
     y = 10*y + c;
    else if (nd <= 15 + 1)
     z = 10*z + c;
    nz = 0;
    }
   }
  }
 dig_done:
 e = 0;
 if (c == 'e' || c == 'E') {
  if (!nd && !nz && !nz0) {
   goto ret0;
   }
  s00 = s;
  esign = 0;
  switch(c = *++s) {
   case '-':
    esign = 1;
   case '+':
    c = *++s;
   }
  if (c >= '0' && c <= '9') {
   while(c == '0')
    c = *++s;
   if (c > '0' && c <= '9') {
    L = c - '0';
    s1 = s;
    while((c = *++s) >= '0' && c <= '9')
     L = 10*L + c - '0';
    if (s - s1 > 8 || L > 19999)
     e = 19999;
    else
     e = (int)L;
    if (esign)
     e = -e;
    }
   else
    e = 0;
   }
  else
   s = s00;
  }
 if (!nd) {
  if (!nz && !nz0) {
 ret0:
   s = s00;
   sign = 0;
   }
  goto ret;
  }
 e1 = e -= nf;
 if (!nd0)
  nd0 = nd;
 k = nd < 15 + 1 ? nd : 15 + 1;
 ((rv).d) = y;
 if (k > 9) {
  ((rv).d) = tens[k - 9] * ((rv).d) + z;
  }
 bd0 = 0;
 if (nd <= 15
  && 1 == 1
   ) {
  if (!e)
   goto ret;
  if (e > 0) {
   if (e <= 24) {
               ((rv).d) *= tens[e];
    goto ret;
    }
   i = 15 - nd;
   if (e <= 24 + i) {
    e -= i;
    ((rv).d) *= tens[i];
               ((rv).d) *= tens[e];
    goto ret;
    }
   }
  else if (e >= -24) {
              ((rv).d) /= tens[-e];
   goto ret;
   }
  }
 e1 += nd - k;
 if (e1 > 0) {
  if ((i = e1 & 15))
   ((rv).d) *= tens[i];
  if (e1 &= ~15) {
   if (e1 > 308) {
 ovfl:
    (*__error()) = 34;
    ((rv).L[0]) = (0xffff007f | 0x80*(1024 +129 -1));
    ((rv).L[1]) = 0xffffffff;
    if (bd0)
     goto retfree;
    goto ret;
    }
   e1 >>= 4;
   for(j = 0; e1 > 1; j++, e1 >>= 1)
    if (e1 & 1)
     ((rv).d) *= bigtens[j];
   ((rv).L[0]) -= 56*0x80;
   ((rv).d) *= bigtens[j];
   if ((z = ((rv).L[0]) & 0x7f80)
    > 0x80*(1024 +129 -56))
    goto ovfl;
   if (z > 0x80*(1024 +129 -1-56)) {
    ((rv).L[0]) = (0xffff007f | 0x80*(1024 +129 -1));
    ((rv).L[1]) = 0xffffffff;
    }
   else
    ((rv).L[0]) += 56*0x80;
   }
  }
 else if (e1 < 0) {
  e1 = -e1;
  if ((i = e1 & 15))
   ((rv).d) /= tens[i];
  if (e1 >>= 4) {
   if (e1 >= 1 << 2)
    goto undfl;
   for(j = 0; e1 > 1; j++, e1 >>= 1)
    if (e1 & 1)
     ((rv).d) *= tinytens[j];
   ((rv0).d) = ((rv).d);
   ((rv).d) *= tinytens[j];
   if (!((rv).d)) {
    ((rv).d) = 2.*((rv0).d);
    ((rv).d) *= tinytens[j];
    if (!((rv).d)) {
 undfl:
     ((rv).d) = 0.;
     (*__error()) = 34;
     if (bd0)
      goto retfree;
     goto ret;
     }
    ((rv).L[0]) = 0x80;
    ((rv).L[1]) = 0;
    }
   }
  }
 bd0 = s2b( s0, nd0, nd, y);
 for(;;) {
  bd = Balloc( bd0->k);
  __builtin___memcpy_chk ((char *)&bd->sign, (char *)&bd0->sign, bd0->wds*sizeof(long) + 2*sizeof(int), __builtin_object_size ((char *)&bd->sign, 0));
  bb = d2b( rv, &bbe, &bbbits);
  bs = i2b( 1);
  if (e >= 0) {
   bb2 = bb5 = 0;
   bd2 = bd5 = e;
   }
  else {
   bb2 = bb5 = -e;
   bd2 = bd5 = 0;
   }
  if (bbe >= 0)
   bb2 += bbe;
  else
   bd2 -= bbe;
  bs2 = bb2;
  j = 56 + 1 - bbbits;
  bb2 += j;
  bd2 += j;
  i = bb2 < bd2 ? bb2 : bd2;
  if (i > bs2)
   i = bs2;
  if (i > 0) {
   bb2 -= i;
   bd2 -= i;
   bs2 -= i;
   }
  if (bb5 > 0) {
   bs = pow5mult( bs, bb5);
   bb1 = mult( bs, bb);
   Bfree( bb);
   bb = bb1;
   }
  if (bb2 > 0)
   bb = lshift( bb, bb2);
  if (bd5 > 0)
   bd = pow5mult( bd, bd5);
  if (bd2 > 0)
   bd = lshift( bd, bd2);
  if (bs2 > 0)
   bs = lshift( bs, bs2);
  delta = diff( bb, bd);
  dsign = delta->sign;
  delta->sign = 0;
  i = cmp(delta, bs);
  if (i < 0) {
   if (dsign || ((rv).L[1]) || ((rv).L[0]) & 0xffff007f
    ) {
    break;
    }
   if (!delta->x[0] && delta->wds <= 1) {
    break;
    }
   delta = lshift( delta,1);
   if (cmp(delta, bs) > 0)
    goto drop_down;
   break;
   }
  if (i == 0) {
   if (dsign) {
    if ((((rv).L[0]) & 0xffff007f) == 0xffff007f
     && ((rv).L[1]) == (
         0xffffffff)) {
     ((rv).L[0]) = (((rv).L[0]) & 0x7f80)
      + 0x80
      ;
     ((rv).L[1]) = 0;
     break;
     }
    }
   else if (!(((rv).L[0]) & 0xffff007f) && !((rv).L[1])) {
 drop_down:
    L = ((rv).L[0]) & 0x7f80;
    if (L <= 0x80)
     goto undfl;
    L -= 0x80;
    ((rv).L[0]) = L | 0xffff007f;
    ((rv).L[1]) = 0xffffffff;
    break;
    }
   if (dsign)
    ((rv).d) += ulp(rv);
   break;
   }
  if ((aadj = ratio(delta, bs)) <= 2.) {
   if (dsign)
    aadj = ((aadj1).d) = 1.;
   else if (((rv).L[1]) || ((rv).L[0]) & 0xffff007f) {
    aadj = 1.;
    ((aadj1).d) = -1.;
    }
   else {
    if (aadj < 2./2)
     aadj = 1./2;
    else
     aadj *= 0.5;
    ((aadj1).d) = -aadj;
    }
   }
  else {
   aadj *= 0.5;
   ((aadj1).d) = dsign ? aadj : -aadj;
   if (1 == 0)
    ((aadj1).d) += 0.5;
   }
  y = ((rv).L[0]) & 0x7f80;
  if (y == 0x80*(1024 +129 -1)) {
   ((rv0).d) = ((rv).d);
   ((rv).L[0]) -= 56*0x80;
   adj = ((aadj1).d) * ulp(rv);
   ((rv).d) += adj;
   if ((((rv).L[0]) & 0x7f80) >=
     0x80*(1024 +129 -56)) {
    if (((rv0).L[0]) == (0xffff007f | 0x80*(1024 +129 -1)) && ((rv0).L[1]) == 0xffffffff)
     goto ovfl;
    ((rv).L[0]) = (0xffff007f | 0x80*(1024 +129 -1));
    ((rv).L[1]) = 0xffffffff;
    goto cont;
    }
   else
    ((rv).L[0]) += 56*0x80;
   }
  else {
   if ((((rv).L[0]) & 0x7f80) <= 56*0x80) {
    ((rv0).d) = ((rv).d);
    ((rv).L[0]) += 56*0x80;
    adj = ((aadj1).d) * ulp(rv);
    ((rv).d) += adj;
    if ((((rv).L[0]) & 0x7f80) <= 56*0x80)
     {
     if (((rv0).L[0]) == 0x80
      && ((rv0).L[1]) == 0)
      goto undfl;
     ((rv).L[0]) = 0x80;
     ((rv).L[1]) = 0;
     goto cont;
     }
    else
     ((rv).L[0]) -= 56*0x80;
    }
   else {
    adj = ((aadj1).d) * ulp(rv);
    ((rv).d) += adj;
    }
   }
  z = ((rv).L[0]) & 0x7f80;
  if (y == z) {
   L = (long)aadj;
   aadj -= L;
   if (dsign || ((rv).L[1]) || ((rv).L[0]) & 0xffff007f) {
    if (aadj < .4999999 || aadj > .5000001)
     break;
    }
   else if (aadj < .4999999/2)
    break;
   }
 cont:
  Bfree( bb);
  Bfree( bd);
  Bfree( bs);
  Bfree( delta);
  }
 retfree:
 Bfree( bb);
 Bfree( bd);
 Bfree( bs);
 Bfree( bd0);
 Bfree( delta);
 ret:
 if (se)
  *se = (char *)s;
 return sign ? -((rv).d) : ((rv).d);
 }
 static int
quorem
 (Bigint *b, Bigint *S)
{
 int n;
 ULong *bx, *bxe, q, *sx, *sxe;
 unsigned long long borrow, carry, y, ys;
 n = S->wds;
 if (b->wds < n)
  return 0;
 sx = S->x;
 sxe = sx + --n;
 bx = b->x;
 bxe = bx + n;
 q = *bxe / (*sxe + 1);
 if (q) {
  borrow = 0;
  carry = 0;
  do {
   ys = *sx++ * (unsigned long long)q + carry;
   carry = ys >> 32;
   y = *bx - (ys & 0xffffffffUL) - borrow;
   borrow = y >> 32 & (ULong)1;
   *bx++ = (ULong) y & 0xffffffffUL;
   }
   while(sx <= sxe);
  if (!*bxe) {
   bx = b->x;
   while(--bxe > bx && !*bxe)
    --n;
   b->wds = n;
   }
  }
 if (cmp(b, S) >= 0) {
  q++;
  borrow = 0;
  carry = 0;
  bx = b->x;
  sx = S->x;
  do {
   ys = *sx++ + carry;
   carry = ys >> 32;
   y = *bx - (ys & 0xffffffffUL) - borrow;
   borrow = y >> 32 & (ULong)1;
   *bx++ = (ULong) y & 0xffffffffUL;
   }
   while(sx <= sxe);
  bx = b->x;
  bxe = bx + n;
  if (!*bxe) {
   while(--bxe > bx && !*bxe)
    --n;
   b->wds = n;
   }
  }
 return q;
 }
 static char *dtoa_result;
 static char *
rv_alloc( int i)
{
 int j, k, *r;
 j = sizeof(ULong);
 for(k = 0;
  sizeof(Bigint) - sizeof(ULong) - sizeof(int) + j <= (unsigned) i;
  j <<= 1)
   k++;
 r = (int*)Balloc( k);
 *r = k;
 return
 dtoa_result =
  (char *)(r+1);
 }
 static char *
nrv_alloc( const char *s, char **rve, int n)
{
 char *rv, *t;
 t = rv = rv_alloc( n);
 while((*t = *s++)) t++;
 if (rve)
  *rve = t;
 return rv;
 }
 static void
freedtoa( char *s)
{
 Bigint *b = (Bigint *)((int *)s - 1);
 b->maxwds = 1 << (b->k = *(int*)b);
 Bfree( b);
 if (s == dtoa_result)
  dtoa_result = 0;
 }
 static char *
dtoa
 ( U d, int mode, int ndigits, int *decpt, int *sign, char **rve)
{
 int bbits, b2, b5, be, dig, i, ieps, ilim, ilim0, ilim1,
  j, j1, k, k0, k_check, leftright, m2, m5, s2, s5,
  spec_case, try_quick;
 long L;
 Bigint *b, *b1, *delta, *mlo, *mhi, *S;
 U d2, eps;
 double ds;
 char *s, *s0;
 ilim = ilim1 = 0;
 mlo = ((void *)0);
 if (dtoa_result) {
  freedtoa( dtoa_result);
  dtoa_result = 0;
  }
 if (((d).L[0]) & 0x8000) {
  *sign = 1;
  ((d).L[0]) &= ~0x8000;
  }
 else
  *sign = 0;
 if (!((d).d)) {
  *decpt = 1;
  return nrv_alloc( "0", rve, 1);
  }
 b = d2b( d, &be, &bbits);
 i = (int)(((d).L[0]) >> 7 & (0x7f80>>7));
  ((d2).d) = ((d).d);
  ((d2).L[0]) &= 0xffff007f;
  ((d2).L[0]) |= 0x4080;
  i -= 129;
 ds = (((d2).d)-1.5)*0.289529654602168 + 0.1760912590558 + i*0.301029995663981;
 k = (int)ds;
 if (ds < 0. && ds != k)
  k--;
 k_check = 1;
 if (k >= 0 && k <= 24) {
  if (((d).d) < tens[k])
   k--;
  k_check = 0;
  }
 j = bbits - i - 1;
 if (j >= 0) {
  b2 = 0;
  s2 = j;
  }
 else {
  b2 = -j;
  s2 = 0;
  }
 if (k >= 0) {
  b5 = 0;
  s5 = k;
  s2 += k;
  }
 else {
  b2 -= k;
  b5 = -k;
  s5 = 0;
  }
 if (mode < 0 || mode > 9)
  mode = 0;
 try_quick = 1;
 if (mode > 5) {
  mode -= 4;
  try_quick = 0;
  }
 leftright = 1;
 switch(mode) {
  case 0:
  case 1:
   ilim = ilim1 = -1;
   i = 18;
   ndigits = 0;
   break;
  case 2:
   leftright = 0;
  case 4:
   if (ndigits <= 0)
    ndigits = 1;
   ilim = ilim1 = i = ndigits;
   break;
  case 3:
   leftright = 0;
  case 5:
   i = ndigits + k + 1;
   ilim = i;
   ilim1 = i - 1;
   if (i <= 0)
    i = 1;
  }
 s = s0 = rv_alloc( i);
 if (ilim >= 0 && ilim <= 15 && try_quick) {
  i = 0;
  ((d2).d) = ((d).d);
  k0 = k;
  ilim0 = ilim;
  ieps = 2;
  if (k > 0) {
   ds = tens[k&0xf];
   j = k >> 4;
   if (j & 2) {
    j &= 2 - 1;
    ((d).d) /= bigtens[2 -1];
    ieps++;
    }
   for(; j; j >>= 1, i++)
    if (j & 1) {
     ieps++;
     ds *= bigtens[i];
     }
   ((d).d) /= ds;
   }
  else if ((j1 = -k)) {
   ((d).d) *= tens[j1 & 0xf];
   for(j = j1 >> 4; j; j >>= 1, i++)
    if (j & 1) {
     ieps++;
     ((d).d) *= bigtens[i];
     }
   }
  if (k_check && ((d).d) < 1. && ilim > 0) {
   if (ilim1 <= 0)
    goto fast_failed;
   ilim = ilim1;
   k--;
   ((d).d) *= 10.;
   ieps++;
   }
  ((eps).d) = ieps*((d).d) + 7.;
  ((eps).L[0]) -= (56 -1)*0x80;
  if (ilim == 0) {
   S = mhi = 0;
   ((d).d) -= 5.;
   if (((d).d) > ((eps).d))
    goto one_digit;
   if (((d).d) < -((eps).d))
    goto no_digits;
   goto fast_failed;
   }
  if (leftright) {
   ((eps).d) = 0.5/tens[ilim-1] - ((eps).d);
   for(i = 0;;) {
    L = (ULong) ((d).d);
    ((d).d) -= L;
    *s++ = '0' + (int)L;
    if (((d).d) < ((eps).d))
     goto ret1;
    if (1. - ((d).d) < ((eps).d))
     goto bump_up;
    if (++i >= ilim)
     break;
    ((eps).d) *= 10.;
    ((d).d) *= 10.;
    }
   }
  else {
   ((eps).d) *= tens[ilim-1];
   for(i = 1;; i++, ((d).d) *= 10.) {
    L = (long)(((d).d));
    if (!(((d).d) -= L))
     ilim = i;
    *s++ = '0' + (int)L;
    if (i == ilim) {
     if (((d).d) > 0.5 + ((eps).d))
      goto bump_up;
     else if (((d).d) < 0.5 - ((eps).d)) {
      while(*--s == '0');
      s++;
      goto ret1;
      }
     break;
     }
    }
   }
 fast_failed:
  s = s0;
  ((d).d) = ((d2).d);
  k = k0;
  ilim = ilim0;
  }
 if (be >= 0 && k <= 15) {
  ds = tens[k];
  if (ndigits < 0 && ilim <= 0) {
   S = mhi = 0;
   if (ilim < 0 || ((d).d) < 5*ds)
    goto no_digits;
   goto one_digit;
   }
  for(i = 1;; i++, ((d).d) *= 10.) {
   L = (long)(((d).d) / ds);
   ((d).d) -= L*ds;
   *s++ = '0' + (int)L;
   if (!((d).d)) {
    break;
    }
   if (i == ilim) {
    ((d).d) += ((d).d);
    if (((d).d) > ds || (((d).d) == ds && L & 1)) {
 bump_up:
     while(*--s == '9')
      if (s == s0) {
       k++;
       *s = '0';
       break;
       }
     ++*s++;
     }
    break;
    }
   }
  goto ret1;
  }
 m2 = b2;
 m5 = b5;
 mhi = mlo = 0;
 if (leftright) {
  i =
   1 + 56 - bbits;
  b2 += i;
  s2 += i;
  mhi = i2b( 1);
  }
 if (m2 > 0 && s2 > 0) {
  i = m2 < s2 ? m2 : s2;
  b2 -= i;
  m2 -= i;
  s2 -= i;
  }
 if (b5 > 0) {
  if (leftright) {
   if (m5 > 0) {
    mhi = pow5mult( mhi, m5);
    b1 = mult( mhi, b);
    Bfree( b);
    b = b1;
    }
   if ((j = b5 - m5))
    b = pow5mult( b, j);
   }
  else
   b = pow5mult( b, b5);
  }
 S = i2b( 1);
 if (s5 > 0)
  S = pow5mult( S, s5);
 spec_case = 0;
 if ((mode < 2 || leftright)
    ) {
  if (!((d).L[1]) && !(((d).L[0]) & 0xffff007f)
    ) {
   b2 += 1;
   s2 += 1;
   spec_case = 1;
   }
  }
 if ((i = ((s5 ? 32 - hi0bits(S->x[S->wds-1]) : 1) + s2) & 0x1f))
  i = 32 - i;
 if (i > 4) {
  i -= 4;
  b2 += i;
  m2 += i;
  s2 += i;
  }
 else if (i < 4) {
  i += 28;
  b2 += i;
  m2 += i;
  s2 += i;
  }
 if (b2 > 0)
  b = lshift( b, b2);
 if (s2 > 0)
  S = lshift( S, s2);
 if (k_check) {
  if (cmp(b,S) < 0) {
   k--;
   b = multadd( b, 10, 0);
   if (leftright)
    mhi = multadd( mhi, 10, 0);
   ilim = ilim1;
   }
  }
 if (ilim <= 0 && (mode == 3 || mode == 5)) {
  if (ilim < 0 || cmp(b,S = multadd( S,5,0)) < 0) {
 no_digits:
   *s++ = '0';
   k = 0;
   goto ret;
   }
 one_digit:
  *s++ = '1';
  k++;
  goto ret;
  }
 if (leftright) {
  if (m2 > 0)
   mhi = lshift( mhi, m2);
  mlo = mhi;
  if (spec_case) {
   mhi = Balloc( mhi->k);
   __builtin___memcpy_chk ((char *)&mhi->sign, (char *)&mlo->sign, mlo->wds*sizeof(long) + 2*sizeof(int), __builtin_object_size ((char *)&mhi->sign, 0));
   mhi = lshift( mhi, 1);
   }
  for(i = 1;;i++) {
   dig = quorem(b,S) + '0';
   j = cmp(b, mlo);
   delta = diff( S, mhi);
   j1 = delta->sign ? 1 : cmp(b, delta);
   Bfree( delta);
   if (j < 0 || (j == 0 && mode != 1
     )) {
    if (!b->x[0] && b->wds <= 1) {
     goto accept_dig;
     }
    if (j1 > 0) {
     b = lshift( b, 1);
     j1 = cmp(b, S);
     if ((j1 > 0 || (j1 == 0 && dig & 1))
     && dig++ == '9')
      goto round_9_up;
     }
 accept_dig:
    *s++ = dig;
    goto ret;
    }
   if (j1 > 0) {
    if (dig == '9') {
 round_9_up:
     *s++ = '9';
     goto roundoff;
     }
    *s++ = dig + 1;
    goto ret;
    }
   *s++ = dig;
   if (i == ilim)
    break;
   b = multadd( b, 10, 0);
   if (mlo == mhi)
    mlo = mhi = multadd( mhi, 10, 0);
   else {
    mlo = multadd( mlo, 10, 0);
    mhi = multadd( mhi, 10, 0);
    }
   }
  }
 else
  for(i = 1;; i++) {
   *s++ = dig = quorem(b,S) + '0';
   if (!b->x[0] && b->wds <= 1) {
    goto ret;
    }
   if (i >= ilim)
    break;
   b = multadd( b, 10, 0);
   }
 b = lshift( b, 1);
 j = cmp(b, S);
 if (j >= 0) {
 roundoff:
  while(*--s == '9')
   if (s == s0) {
    k++;
    *s++ = '1';
    goto ret;
    }
  ++*s++;
  }
 else {
  while(*--s == '0');
  s++;
  }
 ret:
 Bfree( S);
 if (mhi) {
  if (mlo && mlo != mhi)
   Bfree( mlo);
  Bfree( mhi);
  }
 ret1:
 Bfree( b);
 *s = 0;
 *decpt = k + 1;
 if (rve)
  *rve = s;
 return s0;
 }
