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
struct object_id {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  oidcpy (struct object_id*,struct object_id const*) ; 

int combine_notes_overwrite(struct object_id *cur_oid,
			    const struct object_id *new_oid)
{
	oidcpy(cur_oid, new_oid);
	return 0;
}