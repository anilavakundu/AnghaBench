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
struct ucred {int dummy; } ;

/* Variables and functions */
 int seeotheruids_check (struct ucred*,struct ucred*) ; 

__attribute__((used)) static int
seeotheruids_cred_check_visible(struct ucred *cr1, struct ucred *cr2)
{

	return (seeotheruids_check(cr1, cr2));
}