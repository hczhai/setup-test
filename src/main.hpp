
#ifdef _HAS_INTEL_MKL
#ifndef MKL_Complex8
#include <complex>
#define MKL_Complex8 std::complex<float>
#endif
#ifndef MKL_Complex16
#include <complex>
#define MKL_Complex16 std::complex<double>
#endif
#include "mkl.h"
#else
#ifdef MKL_ILP64
#define MKL_INT long long int
#else
#define MKL_INT int
#endif
#endif

extern "C"
{

#ifndef _HAS_INTEL_MKL

    // vector dot product
    extern double ddot(const MKL_INT *n, const double *dx, const MKL_INT *incx,
                       const double *dy, const MKL_INT *incy) noexcept;

#endif
}

template <typename T>
T add(T a, T b)
{
    return a + b;
}

double xdot(double *a, double *b, MKL_INT n)
{
    MKL_INT inc = 1;
    return ddot(&n, a, &inc, b, &inc);
}

double mydot(double *a, double *b, MKL_INT n)
{
    double r = 0;
    for (MKL_INT i = 0; i < n; i++)
        r += a[i] * b[i];
    return r;
}
