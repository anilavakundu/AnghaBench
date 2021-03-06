#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  EXTRACT_WORDS (int,int,double) ; 
 double __ieee754_j0 (double) ; 
 double __ieee754_log (double) ; 
 double cos (double) ; 
 double invsqrtpi ; 
 double one ; 
 double pzero (double) ; 
 double qzero (double) ; 
 int /*<<< orphan*/  sincos (double,double*,double*) ; 
 double sqrt (double) ; 
 double tpi ; 
 double u00 ; 
 double u01 ; 
 double u02 ; 
 double u03 ; 
 double u04 ; 
 double u05 ; 
 double u06 ; 
 double v01 ; 
 double v02 ; 
 double v03 ; 
 double v04 ; 
 double vone ; 
 double vzero ; 
 double zero ; 

double
__ieee754_y0(double x)
{
	double z, s,c,ss,cc,u,v;
	int32_t hx,ix,lx;

	EXTRACT_WORDS(hx,lx,x);
        ix = 0x7fffffff&hx;
	/*
	 * y0(NaN) = NaN.
	 * y0(Inf) = 0.
	 * y0(-Inf) = NaN and raise invalid exception.
	 */
	if(ix>=0x7ff00000) return vone/(x+x*x);
	/* y0(+-0) = -inf and raise divide-by-zero exception. */
	if((ix|lx)==0) return -one/vzero;
	/* y0(x<0) = NaN and raise invalid exception. */
	if(hx<0) return vzero/vzero;
        if(ix >= 0x40000000) {  /* |x| >= 2.0 */
        /* y0(x) = sqrt(2/(pi*x))*(p0(x)*sin(x0)+q0(x)*cos(x0))
         * where x0 = x-pi/4
         *      Better formula:
         *              cos(x0) = cos(x)cos(pi/4)+sin(x)sin(pi/4)
         *                      =  1/sqrt(2) * (sin(x) + cos(x))
         *              sin(x0) = sin(x)cos(3pi/4)-cos(x)sin(3pi/4)
         *                      =  1/sqrt(2) * (sin(x) - cos(x))
         * To avoid cancellation, use
         *              sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
         * to compute the worse one.
         */
                sincos(x, &s, &c);
                ss = s-c;
                cc = s+c;
	/*
	 * j0(x) = 1/sqrt(pi) * (P(0,x)*cc - Q(0,x)*ss) / sqrt(x)
	 * y0(x) = 1/sqrt(pi) * (P(0,x)*ss + Q(0,x)*cc) / sqrt(x)
	 */
                if(ix<0x7fe00000) {  /* make sure x+x not overflow */
                    z = -cos(x+x);
                    if ((s*c)<zero) cc = z/ss;
                    else            ss = z/cc;
                }
                if(ix>0x48000000) z = (invsqrtpi*ss)/sqrt(x);
                else {
                    u = pzero(x); v = qzero(x);
                    z = invsqrtpi*(u*ss+v*cc)/sqrt(x);
                }
                return z;
	}
	if(ix<=0x3e400000) {	/* x < 2**-27 */
	    return(u00 + tpi*__ieee754_log(x));
	}
	z = x*x;
	u = u00+z*(u01+z*(u02+z*(u03+z*(u04+z*(u05+z*u06)))));
	v = one+z*(v01+z*(v02+z*(v03+z*v04)));
	return(u/v + tpi*(__ieee754_j0(x)*__ieee754_log(x)));
}