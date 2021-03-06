#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct kvm_lapic {TYPE_2__* vcpu; } ;
struct TYPE_3__ {int /*<<< orphan*/  ioapic_handled_vectors; } ;
struct TYPE_4__ {TYPE_1__ arch; } ;

/* Variables and functions */
 int test_bit (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool kvm_ioapic_handles_vector(struct kvm_lapic *apic, int vector)
{
	return test_bit(vector, apic->vcpu->arch.ioapic_handled_vectors);
}