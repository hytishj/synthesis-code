/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* External Global Variable Declarations */
extern float data[1][2000];

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int main(void);
void overlay_fea(float *, signed int , float *);


/* Global Variable Definitions and Initialization */
float data[1][2000] = { { 0x1.808p10, 0x1.118p11, 0x1.efcp10, 0x1.062p11, 0x1.fbp10, 0x1.036p11, 0x1p11, 0x1.028p11, 0x1.01ap11, 0x1.028p11, 0x1.028p11, 0x1.02ep11, 0x1.032p11, 0x1.03ap11, 0x1.03ep11, 0x1.046p11, 0x1.04cp11, 0x1.054p11, 0x1.05cp11, 0x1.068p11, 0x1.07p11, 0x1.07cp11, 0x1.088p11, 0x1.094p11, 0x1.0ap11, 0x1.0acp11, 0x1.0b4p11, 0x1.0bcp11, 0x1.0c4p11, 0x1.0cap11, 0x1.0cep11, 0x1.0cep11, 0x1.0c8p11, 0x1.0bcp11, 0x1.0acp11, 0x1.096p11, 0x1.07cp11, 0x1.06p11, 0x1.04p11, 0x1.02p11, 0x1.004p11, 0x1.fd8p10, 0x1.facp10, 0x1.f88p10, 0x1.f7p10, 0x1.f5cp10, 0x1.f4cp10, 0x1.f3cp10, 0x1.f34p10, 0x1.f3p10, 0x1.f3p10, 0x1.f2cp10, 0x1.f2cp10, 0x1.f2cp10, 0x1.f2cp10, 0x1.f34p10, 0x1.f34p10, 0x1.f34p10, 0x1.f34p10, 0x1.f3cp10, 0x1.f3cp10, 0x1.f4p10, 0x1.f44p10, 0x1.f44p10, 0x1.f4cp10, 0x1.f4cp10, 0x1.f4cp10, 0x1.f4cp10, 0x1.f5p10, 0x1.f54p10, 0x1.f58p10, 0x1.f5cp10, 0x1.f5cp10, 0x1.f5cp10, 0x1.f5cp10, 0x1.f5cp10, 0x1.f64p10, 0x1.f68p10, 0x1.f68p10, 0x1.f68p10, 0x1.f6cp10, 0x1.f74p10, 0x1.f74p10, 0x1.f7cp10, 0x1.f84p10, 0x1.f84p10, 0x1.f8cp10, 0x1.f94p10, 0x1.f9cp10, 0x1.fap10, 0x1.fap10, 0x1.fap10, 0x1.fap10, 0x1.fap10, 0x1.fap10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fbp10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fbcp10, 0x1.fbcp10, 0x1.fbcp10, 0x1.fbcp10, 0x1.fbcp10, 0x1.fcp10, 0x1.fc4p10, 0x1.fc4p10, 0x1.fc4p10, 0x1.fc8p10, 0x1.fccp10, 0x1.fccp10, 0x1.fdp10, 0x1.fd4p10, 0x1.fd4p10, 0x1.fd4p10, 0x1.fd4p10, 0x1.fd4p10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fep10, 0x1.fe4p10, 0x1.fe8p10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.ff4p10, 0x1.ff4p10, 0x1.ff8p10, 0x1.ffcp10, 0x1.002p11, 0x1.006p11, 0x1.008p11, 0x1.008p11, 0x1.008p11, 0x1.00ep11, 0x1.016p11, 0x1.01ep11, 0x1.022p11, 0x1.022p11, 0x1.02p11, 0x1.01cp11, 0x1.01cp11, 0x1.01cp11, 0x1.01cp11, 0x1.016p11, 0x1.00cp11, 0x1p11, 0x1.ff4p10, 0x1.ffp10, 0x1.ffp10, 0x1.fecp10, 0x1.fecp10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe4p10, 0x1.fep10, 0x1.fep10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fep10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fdcp10, 0x1.fd4p10, 0x1.fd8p10, 0x1.ff8p10, 0x1.01ep11, 0x1.06p11, 0x1.0c6p11, 0x1.13ep11, 0x1.1bp11, 0x1.1d8p11, 0x1.1a2p11, 0x1.13p11, 0x1.0aap11, 0x1.03ep11, 0x1.006p11, 0x1.fep10, 0x1.fd4p10, 0x1.fep10, 0x1.fecp10, 0x1.fe8p10, 0x1.fep10, 0x1.fd8p10, 0x1.fd4p10, 0x1.fd8p10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fecp10, 0x1.ff4p10, 0x1.ffcp10, 0x1.ffcp10, 0x1.ffcp10, 0x1.ffcp10, 0x1p11, 0x1.002p11, 0x1.004p11, 0x1.008p11, 0x1.008p11, 0x1.00cp11, 0x1.00ep11, 0x1.01p11, 0x1.014p11, 0x1.018p11, 0x1.01cp11, 0x1.02p11, 0x1.024p11, 0x1.02ap11, 0x1.03p11, 0x1.036p11, 0x1.03ep11, 0x1.046p11, 0x1.04ep11, 0x1.058p11, 0x1.064p11, 0x1.072p11, 0x1.082p11, 0x1.096p11, 0x1.0a8p11, 0x1.0b8p11, 0x1.0c4p11, 0x1.0ccp11, 0x1.0d2p11, 0x1.0d6p11, 0x1.0d8p11, 0x1.0d4p11, 0x1.0c6p11, 0x1.0bp11, 0x1.096p11, 0x1.07ap11, 0x1.05ep11, 0x1.03ep11, 0x1.01ep11, 0x1.ffcp10, 0x1.fc8p10, 0x1.f9cp10, 0x1.f7cp10, 0x1.f6p10, 0x1.f48p10, 0x1.f3p10, 0x1.f2p10, 0x1.f1p10, 0x1.f0cp10, 0x1.f0cp10, 0x1.f0cp10, 0x1.f1p10, 0x1.f14p10, 0x1.f14p10, 0x1.f1cp10, 0x1.f1cp10, 0x1.f1cp10, 0x1.f2p10, 0x1.f24p10, 0x1.f24p10, 0x1.f24p10, 0x1.f2cp10, 0x1.f2cp10, 0x1.f34p10, 0x1.f3cp10, 0x1.f44p10, 0x1.f48p10, 0x1.f48p10, 0x1.f48p10, 0x1.f48p10, 0x1.f48p10, 0x1.f48p10, 0x1.f4cp10, 0x1.f5p10, 0x1.f5p10, 0x1.f5p10, 0x1.f5p10, 0x1.f54p10, 0x1.f58p10, 0x1.f58p10, 0x1.f6p10, 0x1.f68p10, 0x1.f68p10, 0x1.f7p10, 0x1.f7p10, 0x1.f7p10, 0x1.f74p10, 0x1.f7cp10, 0x1.f7cp10, 0x1.f8p10, 0x1.f84p10, 0x1.f84p10, 0x1.f8cp10, 0x1.f94p10, 0x1.f94p10, 0x1.f9cp10, 0x1.f9cp10, 0x1.f9cp10, 0x1.f9cp10, 0x1.f9cp10, 0x1.f9cp10, 0x1.f9cp10, 0x1.f9cp10, 0x1.f9cp10, 0x1.f9cp10, 0x1.fa4p10, 0x1.fa4p10, 0x1.fa8p10, 0x1.fbp10, 0x1.fbp10, 0x1.fbp10, 0x1.fbp10, 0x1.fb4p10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fbcp10, 0x1.fcp10, 0x1.fc4p10, 0x1.fc8p10, 0x1.fc8p10, 0x1.fccp10, 0x1.fdp10, 0x1.fdp10, 0x1.fdp10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fep10, 0x1.fe8p10, 0x1.ffp10, 0x1.ff4p10, 0x1.ffp10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.ffp10, 0x1.ffp10, 0x1.ff8p10, 0x1p11, 0x1.004p11, 0x1.008p11, 0x1.008p11, 0x1.00ap11, 0x1.00ep11, 0x1.014p11, 0x1.01ap11, 0x1.01ep11, 0x1.01ep11, 0x1.01ep11, 0x1.01ep11, 0x1.01ep11, 0x1.01cp11, 0x1.016p11, 0x1.00ep11, 0x1.006p11, 0x1.ffcp10, 0x1.ffp10, 0x1.fecp10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fe4p10, 0x1.fecp10, 0x1.ffp10, 0x1.ffp10, 0x1.fe8p10, 0x1.fdcp10, 0x1.fd4p10, 0x1.fep10, 0x1.002p11, 0x1.02cp11, 0x1.07cp11, 0x1.0eap11, 0x1.166p11, 0x1.1cap11, 0x1.1d8p11, 0x1.18ep11, 0x1.112p11, 0x1.08cp11, 0x1.02ap11, 0x1.ff4p10, 0x1.fd4p10, 0x1.fdp10, 0x1.fe4p10, 0x1.ffp10, 0x1.fecp10, 0x1.fe4p10, 0x1.fdcp10, 0x1.fd8p10, 0x1.fd4p10, 0x1.fd4p10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fep10, 0x1.fe8p10, 0x1.fe8p10, 0x1.ffp10, 0x1.ffp10, 0x1.ff8p10, 0x1.ffcp10, 0x1p11, 0x1.004p11, 0x1.004p11, 0x1.008p11, 0x1.00cp11, 0x1.00cp11, 0x1.01p11, 0x1.01p11, 0x1.014p11, 0x1.018p11, 0x1.01cp11, 0x1.02p11, 0x1.024p11, 0x1.02ap11, 0x1.03p11, 0x1.036p11, 0x1.03ep11, 0x1.046p11, 0x1.05p11, 0x1.05cp11, 0x1.066p11, 0x1.07p11, 0x1.07ap11, 0x1.084p11, 0x1.094p11, 0x1.0a4p11, 0x1.0b2p11, 0x1.0bep11, 0x1.0cap11, 0x1.0dp11, 0x1.0d4p11, 0x1.0d4p11, 0x1.0cep11, 0x1.0c2p11, 0x1.0bp11, 0x1.096p11, 0x1.078p11, 0x1.058p11, 0x1.038p11, 0x1.018p11, 0x1.ff4p10, 0x1.fc4p10, 0x1.f94p10, 0x1.f7p10, 0x1.f54p10, 0x1.f3cp10, 0x1.f2cp10, 0x1.f2p10, 0x1.f18p10, 0x1.f1p10, 0x1.f1p10, 0x1.f0cp10, 0x1.f0cp10, 0x1.f14p10, 0x1.f14p10, 0x1.f1cp10, 0x1.f1cp10, 0x1.f1cp10, 0x1.f2p10, 0x1.f24p10, 0x1.f24p10, 0x1.f2cp10, 0x1.f34p10, 0x1.f3cp10, 0x1.f4p10, 0x1.f4p10, 0x1.f4p10, 0x1.f4p10, 0x1.f4p10, 0x1.f4p10, 0x1.f4p10, 0x1.f44p10, 0x1.f48p10, 0x1.f48p10, 0x1.f5p10, 0x1.f5p10, 0x1.f54p10, 0x1.f5cp10, 0x1.f6p10, 0x1.f64p10, 0x1.f68p10, 0x1.f6cp10, 0x1.f74p10, 0x1.f74p10, 0x1.f78p10, 0x1.f7cp10, 0x1.f7cp10, 0x1.f8p10, 0x1.f88p10, 0x1.f88p10, 0x1.f9p10, 0x1.f94p10, 0x1.f98p10, 0x1.f9cp10, 0x1.f9cp10, 0x1.f9cp10, 0x1.f9cp10, 0x1.f9cp10, 0x1.f9cp10, 0x1.f9cp10, 0x1.f98p10, 0x1.f98p10, 0x1.f98p10, 0x1.f98p10, 0x1.fap10, 0x1.fap10, 0x1.fa4p10, 0x1.facp10, 0x1.facp10, 0x1.facp10, 0x1.facp10, 0x1.facp10, 0x1.facp10, 0x1.facp10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fbcp10, 0x1.fbcp10, 0x1.fcp10, 0x1.fc8p10, 0x1.fc8p10, 0x1.fccp10, 0x1.fdp10, 0x1.fdp10, 0x1.fdp10, 0x1.fdp10, 0x1.fdp10, 0x1.fd4p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fe4p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.ffp10, 0x1.ff8p10, 0x1p11, 0x1.004p11, 0x1.008p11, 0x1.00cp11, 0x1.00cp11, 0x1.01p11, 0x1.016p11, 0x1.01ep11, 0x1.022p11, 0x1.024p11, 0x1.02p11, 0x1.01ep11, 0x1.01ep11, 0x1.01cp11, 0x1.018p11, 0x1.00ep11, 0x1.002p11, 0x1.ff4p10, 0x1.fe4p10, 0x1.fep10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe8p10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.ff4p10, 0x1.ff4p10, 0x1.ff4p10, 0x1.fecp10, 0x1.fe4p10, 0x1.fe8p10, 0x1p11, 0x1.01ap11, 0x1.04ep11, 0x1.0a6p11, 0x1.112p11, 0x1.182p11, 0x1.1bep11, 0x1.1ap11, 0x1.14p11, 0x1.0bcp11, 0x1.046p11, 0x1p11, 0x1.fc8p10, 0x1.fcp10, 0x1.fdcp10, 0x1.ff8p10, 0x1.002p11, 0x1.002p11, 0x1.ffcp10, 0x1.ff8p10, 0x1.ff4p10, 0x1.ff4p10, 0x1.ff4p10, 0x1.ffcp10, 0x1.ffcp10, 0x1.ffcp10, 0x1.002p11, 0x1.002p11, 0x1.006p11, 0x1.006p11, 0x1.006p11, 0x1.008p11, 0x1.00ap11, 0x1.00ap11, 0x1.00ep11, 0x1.012p11, 0x1.012p11, 0x1.012p11, 0x1.016p11, 0x1.01ap11, 0x1.01ep11, 0x1.022p11, 0x1.026p11, 0x1.02ep11, 0x1.032p11, 0x1.03ap11, 0x1.04p11, 0x1.048p11, 0x1.04ep11, 0x1.056p11, 0x1.05ep11, 0x1.06ap11, 0x1.076p11, 0x1.082p11, 0x1.08ep11, 0x1.09ap11, 0x1.0a6p11, 0x1.0b2p11, 0x1.0bep11, 0x1.0c8p11, 0x1.0cep11, 0x1.0d2p11, 0x1.0dp11, 0x1.0ccp11, 0x1.0c2p11, 0x1.0b2p11, 0x1.09cp11, 0x1.082p11, 0x1.062p11, 0x1.042p11, 0x1.022p11, 0x1.002p11, 0x1.fdp10, 0x1.fap10, 0x1.f7cp10, 0x1.f5cp10, 0x1.f3cp10, 0x1.f24p10, 0x1.f18p10, 0x1.f1p10, 0x1.f08p10, 0x1.f08p10, 0x1.f04p10, 0x1.f04p10, 0x1.f04p10, 0x1.f04p10, 0x1.f0cp10, 0x1.f0cp10, 0x1.f14p10, 0x1.f18p10, 0x1.f18p10, 0x1.f2p10, 0x1.f2p10, 0x1.f2p10, 0x1.f2p10, 0x1.f28p10, 0x1.f28p10, 0x1.f2cp10, 0x1.f3p10, 0x1.f34p10, 0x1.f3cp10, 0x1.f4p10, 0x1.f4p10, 0x1.f44p10, 0x1.f44p10, 0x1.f44p10, 0x1.f44p10, 0x1.f48p10, 0x1.f4cp10, 0x1.f5p10, 0x1.f58p10, 0x1.f6p10, 0x1.f6p10, 0x1.f64p10, 0x1.f6cp10, 0x1.f6cp10, 0x1.f74p10, 0x1.f7cp10, 0x1.f84p10, 0x1.f8cp10, 0x1.f8cp10, 0x1.f8cp10, 0x1.f8cp10, 0x1.f8cp10, 0x1.f8cp10, 0x1.f8cp10, 0x1.f94p10, 0x1.f94p10, 0x1.f98p10, 0x1.f9cp10, 0x1.f9cp10, 0x1.f9cp10, 0x1.fap10, 0x1.fap10, 0x1.fap10, 0x1.fap10, 0x1.fap10, 0x1.fa8p10, 0x1.facp10, 0x1.fbp10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fbcp10, 0x1.fbcp10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fcp10, 0x1.fcp10, 0x1.fc8p10, 0x1.fc8p10, 0x1.fc8p10, 0x1.fc8p10, 0x1.fc8p10, 0x1.fc8p10, 0x1.fdp10, 0x1.fdp10, 0x1.fdp10, 0x1.fd8p10, 0x1.fdcp10, 0x1.fep10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.ffp10, 0x1.ff8p10, 0x1.002p11, 0x1.006p11, 0x1.006p11, 0x1.008p11, 0x1.00cp11, 0x1.014p11, 0x1.01ap11, 0x1.01ep11, 0x1.01ep11, 0x1.01ap11, 0x1.01ap11, 0x1.01ap11, 0x1.018p11, 0x1.01p11, 0x1.008p11, 0x1p11, 0x1.ffp10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fep10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd4p10, 0x1.fd4p10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fep10, 0x1.fe4p10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fe4p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fep10, 0x1.fep10, 0x1.fe4p10, 0x1p11, 0x1.01ap11, 0x1.05p11, 0x1.0a2p11, 0x1.1p11, 0x1.15cp11, 0x1.18p11, 0x1.156p11, 0x1.0f6p11, 0x1.08p11, 0x1.01ep11, 0x1.fd4p10, 0x1.fb8p10, 0x1.fcp10, 0x1.fdcp10, 0x1.ff8p10, 0x1.ffcp10, 0x1.ff8p10, 0x1.ff4p10, 0x1.ff4p10, 0x1.ff4p10, 0x1.ff4p10, 0x1.ff8p10, 0x1.ffcp10, 0x1p11, 0x1.004p11, 0x1.008p11, 0x1.008p11, 0x1.008p11, 0x1.008p11, 0x1.008p11, 0x1.008p11, 0x1.006p11, 0x1.004p11, 0x1.004p11, 0x1.004p11, 0x1.006p11, 0x1.00ap11, 0x1.00ep11, 0x1.012p11, 0x1.016p11, 0x1.01ap11, 0x1.022p11, 0x1.026p11, 0x1.02cp11, 0x1.032p11, 0x1.03ap11, 0x1.044p11, 0x1.05p11, 0x1.058p11, 0x1.06p11, 0x1.066p11, 0x1.06ep11, 0x1.07ap11, 0x1.08ap11, 0x1.096p11, 0x1.0a2p11, 0x1.0aep11, 0x1.0bap11, 0x1.0c2p11, 0x1.0c6p11, 0x1.0cap11, 0x1.0ccp11, 0x1.0c8p11, 0x1.0bep11, 0x1.0aep11, 0x1.098p11, 0x1.07ep11, 0x1.062p11, 0x1.044p11, 0x1.026p11, 0x1.00ap11, 0x1.fdcp10, 0x1.facp10, 0x1.f88p10, 0x1.f68p10, 0x1.f5p10, 0x1.f3cp10, 0x1.f2cp10, 0x1.f24p10, 0x1.f1cp10, 0x1.f1cp10, 0x1.f18p10, 0x1.f18p10, 0x1.f18p10, 0x1.f1cp10, 0x1.f2p10, 0x1.f2p10, 0x1.f28p10, 0x1.f28p10, 0x1.f3p10, 0x1.f34p10, 0x1.f34p10, 0x1.f34p10, 0x1.f3cp10, 0x1.f3cp10, 0x1.f4p10, 0x1.f48p10, 0x1.f4cp10, 0x1.f5p10, 0x1.f58p10, 0x1.f58p10, 0x1.f58p10, 0x1.f58p10, 0x1.f6p10, 0x1.f6p10, 0x1.f6p10, 0x1.f64p10, 0x1.f68p10, 0x1.f68p10, 0x1.f7p10, 0x1.f7p10, 0x1.f74p10, 0x1.f78p10, 0x1.f7cp10, 0x1.f8p10, 0x1.f84p10, 0x1.f88p10, 0x1.f88p10, 0x1.f9p10, 0x1.f98p10, 0x1.f98p10, 0x1.fap10, 0x1.fap10, 0x1.fa4p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa4p10, 0x1.fa4p10, 0x1.fa4p10, 0x1.facp10, 0x1.facp10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb8p10, 0x1.fcp10, 0x1.fcp10, 0x1.fcp10, 0x1.fcp10, 0x1.fcp10, 0x1.fcp10, 0x1.fcp10, 0x1.fcp10, 0x1.fc4p10, 0x1.fc8p10, 0x1.fccp10, 0x1.fd4p10, 0x1.fdp10, 0x1.fccp10, 0x1.fccp10, 0x1.fdp10, 0x1.fdcp10, 0x1.fe4p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fecp10, 0x1.ffp10, 0x1.ff4p10, 0x1.ffcp10, 0x1.002p11, 0x1.006p11, 0x1.008p11, 0x1.008p11, 0x1.00cp11, 0x1.014p11, 0x1.01ap11, 0x1.01ep11, 0x1.02p11, 0x1.02p11, 0x1.01cp11, 0x1.01cp11, 0x1.01cp11, 0x1.01cp11, 0x1.016p11, 0x1.00ap11, 0x1p11, 0x1.ffp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fe8p10, 0x1.fep10, 0x1.fd8p10, 0x1.fd4p10, 0x1.fecp10, 0x1.01p11, 0x1.03ep11, 0x1.08cp11, 0x1.0f6p11, 0x1.17p11, 0x1.1dp11, 0x1.1d8p11, 0x1.18cp11, 0x1.11p11, 0x1.08ep11, 0x1.032p11, 0x1.004p11, 0x1.fecp10, 0x1.fecp10, 0x1.ffcp10, 0x1.004p11, 0x1.002p11, 0x1.ff8p10, 0x1.fe8p10, 0x1.fd8p10, 0x1.fc8p10, 0x1.fc4p10, 0x1.fc4p10, 0x1.fc8p10, 0x1.fdp10, 0x1.fdp10, 0x1.fd8p10, 0x1.fep10, 0x1.fe4p10, 0x1.ff4p10, 0x1.ffcp10, 0x1.002p11, 0x1.008p11, 0x1.00ap11, 0x1.00cp11, 0x1.01p11, 0x1.014p11, 0x1.014p11, 0x1.018p11, 0x1.01cp11, 0x1.02p11, 0x1.024p11, 0x1.028p11, 0x1.02cp11, 0x1.03p11, 0x1.034p11, 0x1.03cp11, 0x1.044p11, 0x1.04cp11, 0x1.054p11, 0x1.06p11, 0x1.068p11, 0x1.072p11, 0x1.07ep11, 0x1.08ap11, 0x1.096p11, 0x1.0a2p11, 0x1.0aep11, 0x1.0bap11, 0x1.0c2p11, 0x1.0c8p11, 0x1.0ccp11, 0x1.0cep11, 0x1.0cap11, 0x1.0cp11, 0x1.0aep11, 0x1.098p11, 0x1.07cp11, 0x1.05cp11, 0x1.03cp11, 0x1.01cp11, 0x1.ffcp10, 0x1.fccp10, 0x1.fa4p10, 0x1.f84p10, 0x1.f64p10, 0x1.f4cp10, 0x1.f3cp10, 0x1.f2cp10, 0x1.f2p10, 0x1.f18p10, 0x1.f18p10, 0x1.f18p10, 0x1.f18p10, 0x1.f18p10, 0x1.f1cp10, 0x1.f2p10, 0x1.f2p10, 0x1.f2p10, 0x1.f24p10, 0x1.f28p10, 0x1.f2cp10, 0x1.f34p10, 0x1.f34p10, 0x1.f34p10, 0x1.f3cp10, 0x1.f3cp10, 0x1.f3cp10, 0x1.f44p10, 0x1.f44p10, 0x1.f44p10, 0x1.f48p10, 0x1.f4cp10, 0x1.f4cp10, 0x1.f54p10, 0x1.f54p10, 0x1.f54p10, 0x1.f5cp10, 0x1.f5cp10, 0x1.f5cp10, 0x1.f5cp10, 0x1.f64p10, 0x1.f64p10, 0x1.f64p10, 0x1.f6cp10, 0x1.f6cp10, 0x1.f7p10, 0x1.f78p10, 0x1.f8p10, 0x1.f8p10, 0x1.f88p10, 0x1.f88p10, 0x1.f88p10, 0x1.f88p10, 0x1.f8cp10, 0x1.f94p10, 0x1.f94p10, 0x1.f98p10, 0x1.f9cp10, 0x1.fap10, 0x1.fa4p10, 0x1.fa4p10, 0x1.fa4p10, 0x1.fa8p10, 0x1.facp10, 0x1.facp10, 0x1.facp10, 0x1.facp10, 0x1.facp10, 0x1.facp10, 0x1.fb4p10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fb8p10, 0x1.fbcp10, 0x1.fcp10, 0x1.fcp10, 0x1.fcp10, 0x1.fc8p10, 0x1.fc8p10, 0x1.fccp10, 0x1.fdp10, 0x1.fdp10, 0x1.fdp10, 0x1.fdp10, 0x1.fdp10, 0x1.fdp10, 0x1.fdp10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fep10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fecp10, 0x1.ff4p10, 0x1.ffcp10, 0x1.002p11, 0x1.004p11, 0x1.004p11, 0x1.006p11, 0x1.00ap11, 0x1.012p11, 0x1.01ap11, 0x1.01ep11, 0x1.02p11, 0x1.01ep11, 0x1.01cp11, 0x1.01cp11, 0x1.01cp11, 0x1.018p11, 0x1.01p11, 0x1.004p11, 0x1.ffp10, 0x1.fe4p10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fep10, 0x1.fep10, 0x1.fe4p10, 0x1.fe8p10, 0x1.fecp10, 0x1.ff4p10, 0x1.ffp10, 0x1.fe8p10, 0x1.fd8p10, 0x1.fdp10, 0x1.fd4p10, 0x1.ff4p10, 0x1.014p11, 0x1.044p11, 0x1.09ap11, 0x1.10cp11, 0x1.18ap11, 0x1.1dep11, 0x1.1d6p11, 0x1.17ep11, 0x1.0fap11, 0x1.076p11, 0x1.02p11, 0x1.ff4p10, 0x1.fdcp10, 0x1.fep10, 0x1.ff4p10, 0x1p11, 0x1p11, 0x1p11, 0x1.ffcp10, 0x1.ff8p10, 0x1.ff8p10, 0x1.ff4p10, 0x1.ff4p10, 0x1.ffcp10, 0x1.ffcp10, 0x1.ffcp10, 0x1.002p11, 0x1.004p11, 0x1.004p11, 0x1.004p11, 0x1.004p11, 0x1.004p11, 0x1.008p11, 0x1.008p11, 0x1.00cp11, 0x1.00cp11, 0x1.01p11, 0x1.01p11, 0x1.014p11, 0x1.018p11, 0x1.01cp11, 0x1.02p11, 0x1.024p11, 0x1.028p11, 0x1.028p11, 0x1.02ep11, 0x1.036p11, 0x1.03ep11, 0x1.046p11, 0x1.052p11, 0x1.05cp11, 0x1.066p11, 0x1.072p11, 0x1.082p11, 0x1.08ep11, 0x1.09ap11, 0x1.0a8p11, 0x1.0b4p11, 0x1.0cp11, 0x1.0c8p11, 0x1.0ccp11, 0x1.0dp11, 0x1.0cep11, 0x1.0c8p11, 0x1.0bep11, 0x1.0acp11, 0x1.092p11, 0x1.074p11, 0x1.05p11, 0x1.02cp11, 0x1.008p11, 0x1.fd4p10, 0x1.fap10, 0x1.f74p10, 0x1.f5p10, 0x1.f38p10, 0x1.f2p10, 0x1.f0cp10, 0x1.f04p10, 0x1.efcp10, 0x1.ef4p10, 0x1.ef4p10, 0x1.ef4p10, 0x1.ef4p10, 0x1.ef4p10, 0x1.ef8p10, 0x1.efcp10, 0x1.efcp10, 0x1.efcp10, 0x1.efcp10, 0x1.f04p10, 0x1.f04p10, 0x1.f08p10, 0x1.f1p10, 0x1.f18p10, 0x1.f18p10, 0x1.f18p10, 0x1.f18p10, 0x1.f18p10, 0x1.f1cp10, 0x1.f24p10, 0x1.f24p10, 0x1.f28p10, 0x1.f2cp10, 0x1.f2cp10, 0x1.f34p10, 0x1.f38p10, 0x1.f38p10, 0x1.f4p10, 0x1.f44p10, 0x1.f48p10, 0x1.f5p10, 0x1.f54p10, 0x1.f58p10, 0x1.f6p10, 0x1.f6p10, 0x1.f68p10, 0x1.f7p10, 0x1.f7p10, 0x1.f78p10, 0x1.f78p10, 0x1.f78p10, 0x1.f7cp10, 0x1.f8p10, 0x1.f84p10, 0x1.f88p10, 0x1.f88p10, 0x1.f88p10, 0x1.f9p10, 0x1.f9p10, 0x1.f9p10, 0x1.f9p10, 0x1.f9p10, 0x1.f9p10, 0x1.f94p10, 0x1.f98p10, 0x1.f9cp10, 0x1.fa4p10, 0x1.fa4p10, 0x1.fa4p10, 0x1.fa4p10, 0x1.facp10, 0x1.facp10, 0x1.facp10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fbcp10, 0x1.fbcp10, 0x1.fc4p10, 0x1.fc4p10, 0x1.fc4p10, 0x1.fc4p10, 0x1.fc4p10, 0x1.fc4p10, 0x1.fccp10, 0x1.fccp10, 0x1.fccp10, 0x1.fd4p10, 0x1.fd4p10, 0x1.fd4p10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fe8p10, 0x1.fecp10, 0x1.fecp10, 0x1.ff4p10, 0x1.ffcp10, 0x1.002p11, 0x1.004p11, 0x1.004p11, 0x1.008p11, 0x1.00cp11, 0x1.014p11, 0x1.01cp11, 0x1.02p11, 0x1.022p11, 0x1.022p11, 0x1.022p11, 0x1.01ep11, 0x1.01ep11, 0x1.01cp11, 0x1.014p11, 0x1.008p11, 0x1.ff8p10, 0x1.fe8p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe8p10, 0x1.fe4p10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fep10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fdcp10, 0x1.fd4p10, 0x1.fccp10, 0x1.fdcp10, 0x1.002p11, 0x1.02ep11, 0x1.07cp11, 0x1.0eap11, 0x1.168p11, 0x1.1cap11, 0x1.1d4p11, 0x1.188p11, 0x1.10cp11, 0x1.084p11, 0x1.022p11, 0x1.fecp10, 0x1.fccp10, 0x1.fdp10, 0x1.fe8p10, 0x1.ff8p10, 0x1.ff4p10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.fecp10, 0x1.ffp10, 0x1.ff4p10, 0x1.ff8p10, 0x1.ffcp10, 0x1p11, 0x1.004p11, 0x1.008p11, 0x1.008p11, 0x1.00ap11, 0x1.00cp11, 0x1.00cp11, 0x1.00cp11, 0x1.01p11, 0x1.012p11, 0x1.016p11, 0x1.01ap11, 0x1.01ep11, 0x1.022p11, 0x1.026p11, 0x1.02ap11, 0x1.02ep11, 0x1.032p11, 0x1.03ap11, 0x1.04p11, 0x1.048p11, 0x1.052p11, 0x1.05cp11, 0x1.064p11, 0x1.07p11, 0x1.07cp11, 0x1.088p11, 0x1.098p11, 0x1.0a4p11, 0x1.0bp11, 0x1.0bcp11, 0x1.0c6p11, 0x1.0cep11, 0x1.0d6p11, 0x1.0dep11, 0x1.0ep11, 0x1.0dap11, 0x1.0c8p11, 0x1.0b2p11, 0x1.098p11, 0x1.07ap11, 0x1.05ap11, 0x1.038p11, 0x1.016p11, 0x1.ffp10, 0x1.fb8p10, 0x1.f8cp10, 0x1.f68p10, 0x1.f48p10, 0x1.f3p10, 0x1.f2p10, 0x1.f1p10, 0x1.f08p10, 0x1.f08p10, 0x1.f04p10, 0x1.f04p10, 0x1.f04p10, 0x1.f04p10, 0x1.f04p10, 0x1.f0cp10, 0x1.f1p10, 0x1.f14p10, 0x1.f1cp10, 0x1.f24p10, 0x1.f28p10, 0x1.f2cp10, 0x1.f3p10, 0x1.f3p10, 0x1.f3p10, 0x1.f3p10, 0x1.f3p10, 0x1.f34p10, 0x1.f38p10, 0x1.f38p10, 0x1.f4p10, 0x1.f4p10, 0x1.f4p10, 0x1.f48p10, 0x1.f4cp10, 0x1.f5p10, 0x1.f54p10, 0x1.f54p10, 0x1.f54p10, 0x1.f58p10, 0x1.f5cp10, 0x1.f5cp10, 0x1.f64p10, 0x1.f64p10, 0x1.f64p10, 0x1.f6cp10, 0x1.f74p10, 0x1.f74p10, 0x1.f7cp10, 0x1.f7cp10, 0x1.f7cp10, 0x1.f8p10, 0x1.f88p10, 0x1.f88p10, 0x1.f9p10, 0x1.f9p10, 0x1.f98p10, 0x1.f9cp10, 0x1.fap10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fa8p10, 0x1.fbp10, 0x1.fbp10, 0x1.fbp10, 0x1.fbp10, 0x1.fbp10, 0x1.fbp10, 0x1.fbp10, 0x1.fbp10, 0x1.fb8p10, 0x1.fbcp10, 0x1.fcp10, 0x1.fc8p10, 0x1.fc8p10, 0x1.fc4p10, 0x1.fcp10, 0x1.fcp10, 0x1.fcp10, 0x1.fc4p10, 0x1.fccp10, 0x1.fccp10, 0x1.fdp10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fdcp10, 0x1.fep10, 0x1.fep10, 0x1.fe4p10, 0x1.fe8p10, 0x1.ffp10, 0x1.ff8p10, 0x1p11, 0x1.002p11, 0x1.006p11, 0x1.00ep11, 0x1.018p11, 0x1.02p11, 0x1.022p11, 0x1.02p11, 0x1.01ep11, 0x1.01ep11, 0x1.01ep11, 0x1.01ap11, 0x1.014p11, 0x1.008p11, 0x1.ff8p10, 0x1.fe4p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fdp10, 0x1.fccp10, 0x1.fccp10, 0x1.fc4p10, 0x1.fcp10, 0x1.fcp10, 0x1.fcp10, 0x1.fcp10, 0x1.fc8p10, 0x1.fdp10, 0x1.fd8p10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fep10, 0x1.fdcp10, 0x1.fd4p10, 0x1.fdp10, 0x1.fe4p10, 0x1.004p11, 0x1.028p11, 0x1.06cp11, 0x1.0c8p11, 0x1.12cp11, 0x1.17cp11, 0x1.184p11, 0x1.14p11, 0x1.0d2p11, 0x1.05ap11, 0x1.006p11, 0x1.fcp10, 0x1.fb4p10, 0x1.fc8p10, 0x1.fe8p10, 0x1.ffcp10, 0x1p11, 0x1p11, 0x1p11, 0x1p11, 0x1p11, 0x1p11, 0x1p11, 0x1p11, 0x1p11, 0x1.002p11, 0x1.004p11, 0x1.006p11, 0x1.00ap11, 0x1.00ap11, 0x1.00ap11, 0x1.00ap11, 0x1.00cp11, 0x1.01p11, 0x1.01p11, 0x1.014p11, 0x1.014p11, 0x1.018p11, 0x1.01ap11, 0x1.01cp11, 0x1.02p11, 0x1.024p11, 0x1.028p11, 0x1.03p11, 0x1.038p11, 0x1.04p11, 0x1.046p11, 0x1.04cp11, 0x1.052p11, 0x1.05ap11, 0x1.062p11, 0x1.06ep11, 0x1.07ap11, 0x1.084p11, 0x1.08ep11, 0x1.09cp11, 0x1.0a8p11, 0x1.0b4p11, 0x1.0bcp11, 0x1.0c4p11, 0x1.0cap11, 0x1.0ccp11, 0x1.0ccp11, 0x1.0c6p11, 0x1.0b8p11, 0x1.0a4p11, 0x1.08cp11, 0x1.07p11, 0x1.054p11, 0x1.034p11, 0x1.016p11, 0x1.ff8p10, 0x1.fc8p10, 0x1.f9cp10, 0x1.f7cp10, 0x1.f5cp10, 0x1.f44p10, 0x1.f38p10, 0x1.f2cp10, 0x1.f24p10, 0x1.f2p10, 0x1.f2p10, 0x1.f2p10, 0x1.f2p10, 0x1.f2p10, 0x1.f2p10, 0x1.f2p10, 0x1.f2p10, 0x1.f28p10, 0x1.f28p10, 0x1.f2cp10, 0x1.f3p10, 0x1.f3p10, 0x1.f34p10, 0x1.f38p10, 0x1.f38p10, 0x1.f38p10, 0x1.f38p10, 0x1.f38p10, 0x1.f4p10, 0x1.f44p10, 0x1.f44p10, 0x1.f4cp10, 0x1.f4cp10, 0x1.f5p10, 0x1.f58p10, 0x1.f5cp10, 0x1.f6p10, 0x1.f68p10, 0x1.f68p10, 0x1.f7p10, 0x1.f78p10, 0x1.f8p10, 0x1.f88p10, 0x1.f8cp10, 0x1.f9p10, 0x1.f94p10, 0x1.f94p10, 0x1.f94p10, 0x1.f94p10, 0x1.f9cp10, 0x1.f9cp10, 0x1.fa4p10, 0x1.fa4p10, 0x1.fa4p10, 0x1.fa4p10, 0x1.fa4p10, 0x1.fa4p10, 0x1.fa4p10, 0x1.facp10, 0x1.fbp10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fbp10, 0x1.fbp10, 0x1.facp10, 0x1.fbp10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fb4p10, 0x1.fbcp10, 0x1.fbcp10, 0x1.fc4p10, 0x1.fc8p10, 0x1.fccp10, 0x1.fccp10, 0x1.fccp10, 0x1.fccp10, 0x1.fdp10, 0x1.fd4p10, 0x1.fd4p10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fdcp10, 0x1.fep10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fecp10, 0x1.fecp10, 0x1.ff4p10, 0x1.ffcp10, 0x1.002p11, 0x1.004p11, 0x1.004p11, 0x1.006p11, 0x1.00ep11, 0x1.016p11, 0x1.01ap11, 0x1.01ep11, 0x1.01ep11, 0x1.01ap11, 0x1.018p11, 0x1.018p11, 0x1.018p11, 0x1.016p11, 0x1.00cp11, 0x1.002p11, 0x1.ff4p10, 0x1.fe8p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe8p10, 0x1.ffp10, 0x1.ffp10, 0x1.ff8p10, 0x1.ff8p10, 0x1.ffp10, 0x1.fe8p10, 0x1.fep10, 0x1.fe8p10, 0x1.004p11, 0x1.02ap11, 0x1.072p11, 0x1.0d8p11, 0x1.14cp11, 0x1.1aap11, 0x1.1bap11, 0x1.176p11, 0x1.102p11, 0x1.086p11, 0x1.02ap11, 0x1.ff8p10, 0x1.fd8p10, 0x1.fd8p10, 0x1.fecp10, 0x1.ff8p10, 0x1.ff8p10, 0x1.ff4p10, 0x1.ffp10, 0x1.fecp10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe4p10, 0x1.fe8p10, 0x1.ffp10, 0x1.ff8p10, 0x1.ffcp10, 0x1.ffcp10, 0x1p11, 0x1.004p11, 0x1.008p11, 0x1.00cp11, 0x1.00cp11, 0x1.00cp11, 0x1.01p11, 0x1.01p11, 0x1.01p11, 0x1.012p11, 0x1.014p11, 0x1.016p11, 0x1.01ap11, 0x1.01ep11, 0x1.022p11, 0x1.026p11, 0x1.02cp11, 0x1.03p11, 0x1.036p11, 0x1.03ep11, 0x1.044p11, 0x1.04cp11, 0x1.056p11, 0x1.062p11, 0x1.06ep11, 0x1.07ap11, 0x1.088p11, 0x1.096p11, 0x1.0a2p11, 0x1.0b2p11, 0x1.0b2p11, 0x1.0cep11, 0x1.0b2p11, 0x1.0f2p11, 0x1.094p11, 0x1.12p11, 0x1.02cp11, 0x1.1c8p11 } };
static  char aesl_internal__OC_str[17] = "kurtosis = %.4f\n";
static  char aesl_internal__OC_str1[12] = "line %d ok\n";
static  char aesl_internal__OC_str2[68] = "\xE2\x80\xA6\xE2\x80\xA6\xE2\x80\xA6\xE2\x80\xA6\xE2\x80\xA6\xE2\x80\xA6\xE2\x80\xA6\xE2\x80\xA6\xE2\x80\xA6\xE2\x80\xA6\xE2\x80\xA6 time=%f \xE2\x80\xA6\xE2\x80\xA6\xE2\x80\xA6\xE2\x80\xA6\xE2\x80\xA6\xE2\x80\xA6\xE2\x80\xA6\xE2\x80\xA6\n";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_dat_count = 0;
  float llvm_cbe_dat[2000];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_fea_1_count = 0;
  float llvm_cbe_fea_1;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  float *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  float *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  float llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  float *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  float llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  double llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  float llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  float llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  double llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%0 = getelementptr inbounds [2000 x float]* %%dat, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_8_count);
  llvm_cbe_tmp__1 = (float *)(&llvm_cbe_dat[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2000
#endif
]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__18;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__18:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%.preheader ], [ %%6, %%1  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge12 to i64, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_14_count);
  llvm_cbe_tmp__2 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [1 x [2000 x float]]* @data, i64 0, i64 0, i64 %%2, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__3 = (float *)(&data[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )llvm_cbe_tmp__2))
#ifdef AESL_BC_SIM
 % 2000
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 1)) fprintf(stderr, "%s:%d: warning: Read access out of array 'data' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__2) < 2000)) fprintf(stderr, "%s:%d: warning: Read access out of array 'data' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load float* %%3, align 4, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__4 = (float )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__4, *(int*)(&llvm_cbe_tmp__4));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [2000 x float]* %%dat, i64 0, i64 %%2, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__5 = (float *)(&llvm_cbe_dat[(((signed long long )llvm_cbe_tmp__2))
#ifdef AESL_BC_SIM
 % 2000
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__2) < 2000 && "Write access out of array 'dat' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%4, float* %%5, align 4, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_18_count);
  *llvm_cbe_tmp__5 = llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%storemerge12, 1, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_19_count);
  llvm_cbe_tmp__6 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__6&4294967295ull)));
  if (((llvm_cbe_tmp__6&4294967295U) == (2000u&4294967295U))) {
    goto llvm_cbe_tmp__19;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__6;   /* for PHI node */
    goto llvm_cbe_tmp__18;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__19:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call i32 @clock() nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__7 = (unsigned int )clock();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__7);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @overlay_fea(float* %%0, i32 2000, float* %%fea_1) nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_29_count);
  overlay_fea((float *)llvm_cbe_tmp__1, 2000u, (float *)(&llvm_cbe_fea_1));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",2000u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call i32 @clock() nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__8 = (unsigned int )clock();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__8);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load float* %%fea_1, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__9 = (float )*(&llvm_cbe_fea_1);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__9, *(int*)(&llvm_cbe_tmp__9));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = fpext float %%10 to double, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__10 = (double )((double )llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__10, *(long long*)(&llvm_cbe_tmp__10));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([17 x i8]* @aesl_internal_.str, i64 0, i64 0), double %%11) nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_41_count);
  printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 17
#endif
])), llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__10, *(long long*)(&llvm_cbe_tmp__10));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__11);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([12 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 0) nounwind, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_42_count);
  printf(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 12
#endif
])), 0u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sub nsw i32 %%9, %%8, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__13 = (unsigned int )((unsigned int )(llvm_cbe_tmp__8&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__7&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__13&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sitofp i32 %%14 to float, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__14 = (float )((float )(signed int )llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__14, *(int*)(&llvm_cbe_tmp__14));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = fdiv float %%15, 1.000000e+03, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__15 = (float )((float )(llvm_cbe_tmp__14 / 0x1.f4p9));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__15, *(int*)(&llvm_cbe_tmp__15));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = fpext float %%16 to double, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__16 = (double )((double )llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__16, *(long long*)(&llvm_cbe_tmp__16));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([68 x i8]* @aesl_internal_.str2, i64 0, i64 0), double %%17) nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_47_count);
  printf(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 68
#endif
])), llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__16, *(long long*)(&llvm_cbe_tmp__16));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__17);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return 0u;
}

