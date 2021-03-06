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
typedef  scalar_t__ _TCHAR ;

/* Variables and functions */

_TCHAR * _tcsncat(_TCHAR * dst, const _TCHAR * src, size_t n)
{
 if(n != 0)
 {
  _TCHAR * d = dst;
  const _TCHAR * s = src;

  while(*d != 0) ++ d;

  do
  {
   if((*d = *s++) == 0) break;

   ++ d;
  }
  while (--n != 0);

  *d = 0;
 }

 return dst;
}