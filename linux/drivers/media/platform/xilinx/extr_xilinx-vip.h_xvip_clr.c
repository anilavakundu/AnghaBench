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
typedef  int u32 ;
struct xvip_device {int dummy; } ;

/* Variables and functions */
 int xvip_read (struct xvip_device*,int) ; 
 int /*<<< orphan*/  xvip_write (struct xvip_device*,int,int) ; 

__attribute__((used)) static inline void xvip_clr(struct xvip_device *xvip, u32 addr, u32 clr)
{
	xvip_write(xvip, addr, xvip_read(xvip, addr) & ~clr);
}