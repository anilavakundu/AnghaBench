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
struct bpf_prog {TYPE_1__* aux; } ;
struct TYPE_2__ {int /*<<< orphan*/ * jited_linfo; } ;

/* Variables and functions */
 int /*<<< orphan*/  bpf_prog_free_jited_linfo (struct bpf_prog*) ; 

void bpf_prog_free_unused_jited_linfo(struct bpf_prog *prog)
{
	if (prog->aux->jited_linfo && !prog->aux->jited_linfo[0])
		bpf_prog_free_jited_linfo(prog);
}