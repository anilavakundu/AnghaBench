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
struct inode {int dummy; } ;

/* Variables and functions */
 unsigned int ALIGN_DOWN (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  DEF_ADDRS_PER_BLOCK ; 

__attribute__((used)) static inline unsigned int addrs_per_block(struct inode *inode)
{
	return ALIGN_DOWN(DEF_ADDRS_PER_BLOCK, 1);
}