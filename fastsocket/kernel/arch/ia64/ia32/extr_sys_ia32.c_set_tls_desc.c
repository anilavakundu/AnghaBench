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
struct thread_struct {struct desc_struct* tls_array; } ;
struct task_struct {struct thread_struct thread; } ;
struct ia32_user_desc {int dummy; } ;
struct desc_struct {scalar_t__ b; scalar_t__ a; } ;
struct TYPE_2__ {struct thread_struct thread; } ;

/* Variables and functions */
 int GDT_ENTRY_TLS_MIN ; 
 scalar_t__ LDT_empty (struct ia32_user_desc const*) ; 
 scalar_t__ LDT_entry_a (struct ia32_user_desc const*) ; 
 scalar_t__ LDT_entry_b (struct ia32_user_desc const*) ; 
 TYPE_1__* current ; 
 int get_cpu () ; 
 int /*<<< orphan*/  load_TLS (struct thread_struct*,int) ; 
 int /*<<< orphan*/  put_cpu () ; 

__attribute__((used)) static void set_tls_desc(struct task_struct *p, int idx,
		const struct ia32_user_desc *info, int n)
{
	struct thread_struct *t = &p->thread;
	struct desc_struct *desc = &t->tls_array[idx - GDT_ENTRY_TLS_MIN];
	int cpu;

	/*
	 * We must not get preempted while modifying the TLS.
	 */
	cpu = get_cpu();

	while (n-- > 0) {
		if (LDT_empty(info)) {
			desc->a = 0;
			desc->b = 0;
		} else {
			desc->a = LDT_entry_a(info);
			desc->b = LDT_entry_b(info);
		}

		++info;
		++desc;
	}

	if (t == &current->thread)
		load_TLS(t, cpu);

	put_cpu();
}