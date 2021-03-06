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
typedef  scalar_t__ WCHAR ;

/* Variables and functions */

__attribute__((used)) static const WCHAR* mystrrchr(const WCHAR *str, WCHAR ch)
{
    const WCHAR *pos = NULL, *current = str;
    while(*current != 0) {
        if(*current == ch)
            pos = current;
        ++current;
    }
    return pos;
}