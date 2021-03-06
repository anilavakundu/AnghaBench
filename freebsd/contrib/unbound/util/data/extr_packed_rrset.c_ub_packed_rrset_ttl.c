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
typedef  int /*<<< orphan*/  time_t ;
struct TYPE_2__ {scalar_t__ data; } ;
struct ub_packed_rrset_key {TYPE_1__ entry; } ;
struct packed_rrset_data {int /*<<< orphan*/  ttl; } ;

/* Variables and functions */

time_t 
ub_packed_rrset_ttl(struct ub_packed_rrset_key* key)
{
	struct packed_rrset_data* d = (struct packed_rrset_data*)key->
		entry.data;
	return d->ttl;
}