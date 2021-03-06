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
 scalar_t__ isupper (char) ; 
 scalar_t__ tolower (char) ; 

char *caseFold(char *cp)
{
    char *oldCp = cp;

    while (*cp)
    {
        if (isupper(*cp))
            *cp = (char)tolower(*cp);
        cp++;
    }

    return oldCp;
}