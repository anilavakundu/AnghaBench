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

/* Variables and functions */

__attribute__((used)) static int toint(const char **sp, int w, int *v)
{
	const char *s = *sp;
	*v = 0;
	while (w--) {
		if (*s < '0' || *s > '9')
			return 0;
		*v = *v * 10 + (*s++ - '0');
	}
	*sp = s;
	return 1;
}