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
typedef  int /*<<< orphan*/  u32 ;
struct rsnd_mod {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SSISR ; 
 int /*<<< orphan*/  rsnd_mod_read (struct rsnd_mod*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static u32 rsnd_ssi_status_get(struct rsnd_mod *mod)
{
	return rsnd_mod_read(mod, SSISR);
}