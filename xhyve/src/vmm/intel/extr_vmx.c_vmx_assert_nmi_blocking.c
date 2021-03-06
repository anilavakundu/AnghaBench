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
typedef  int uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  KASSERT (int,char*) ; 
 int /*<<< orphan*/  VMCS_GUEST_INTERRUPTIBILITY ; 
 int VMCS_INTERRUPTIBILITY_NMI_BLOCKING ; 
 scalar_t__ vmcs_read (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
vmx_assert_nmi_blocking(int vcpuid)
{
	uint32_t gi;

	gi = (uint32_t) vmcs_read(vcpuid, VMCS_GUEST_INTERRUPTIBILITY);
	KASSERT(gi & VMCS_INTERRUPTIBILITY_NMI_BLOCKING,
	    ("NMI blocking is not in effect %#x", gi));
}