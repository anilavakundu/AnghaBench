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
typedef  int /*<<< orphan*/  u8 ;
struct shash_desc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  sm3_base_do_finalize (struct shash_desc*,int /*<<< orphan*/ ) ; 
 int sm3_base_finish (struct shash_desc*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sm3_generic_block_fn ; 

__attribute__((used)) static int sm3_final(struct shash_desc *desc, u8 *out)
{
	sm3_base_do_finalize(desc, sm3_generic_block_fn);
	return sm3_base_finish(desc, out);
}