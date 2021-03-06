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
struct dn_ifaddr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct dn_ifaddr*) ; 

__attribute__((used)) static __inline__ void dn_dev_free_ifa(struct dn_ifaddr *ifa)
{
	kfree(ifa);
}