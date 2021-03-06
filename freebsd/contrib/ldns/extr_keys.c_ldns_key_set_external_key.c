#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {void* external_key; } ;
struct TYPE_5__ {TYPE_1__ _key; } ;
typedef  TYPE_2__ ldns_key ;

/* Variables and functions */

void
ldns_key_set_external_key(ldns_key *k, void *external_key)
{
	k->_key.external_key = external_key;
}