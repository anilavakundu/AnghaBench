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
 unsigned int CHRDEV_MAJOR_HASH_SIZE ; 

__attribute__((used)) static inline int major_to_index(unsigned major)
{
	return major % CHRDEV_MAJOR_HASH_SIZE;
}