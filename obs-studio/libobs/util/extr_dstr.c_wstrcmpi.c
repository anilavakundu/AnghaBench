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
typedef  scalar_t__ wchar_t ;

/* Variables and functions */
 int /*<<< orphan*/  towupper (scalar_t__ const) ; 
 scalar_t__* wstrblank ; 

int wstrcmpi(const wchar_t *str1, const wchar_t *str2)
{
	if (!str1)
		str1 = wstrblank;
	if (!str2)
		str2 = wstrblank;

	do {
		wchar_t ch1 = (wchar_t)towupper(*str1);
		wchar_t ch2 = (wchar_t)towupper(*str2);

		if (ch1 < ch2)
			return -1;
		else if (ch1 > ch2)
			return 1;
	} while (*str1++ && *str2++);

	return 0;
}