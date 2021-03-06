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
 scalar_t__ dlm_mle_cache ; 
 int /*<<< orphan*/  kmem_cache_destroy (scalar_t__) ; 

void dlm_destroy_mle_cache(void)
{
	if (dlm_mle_cache)
		kmem_cache_destroy(dlm_mle_cache);
}