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
typedef  int /*<<< orphan*/  Cell ;

/* Variables and functions */
 int /*<<< orphan*/  OFMT ; 
 char* get_str_val (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

char *getpssval(Cell *vp)     /* get string val of a Cell for print */
{
      return get_str_val(vp, OFMT);
}