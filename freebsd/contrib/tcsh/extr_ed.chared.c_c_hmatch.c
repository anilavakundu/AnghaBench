#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  s; int /*<<< orphan*/  len; } ;
typedef  int /*<<< orphan*/  Char ;

/* Variables and functions */
 int Gmatch (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ Strncmp (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_1__ patbuf ; 

__attribute__((used)) static int
c_hmatch(Char *str)
{
    if (Strncmp(patbuf.s, str, patbuf.len) == 0)
	return 1;
    return Gmatch(str, patbuf.s);
}