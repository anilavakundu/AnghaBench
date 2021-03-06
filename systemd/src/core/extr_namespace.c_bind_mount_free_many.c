#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {struct TYPE_4__* destination; struct TYPE_4__* source; } ;
typedef  TYPE_1__ BindMount ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 

void bind_mount_free_many(BindMount *b, size_t n) {
        size_t i;

        assert(b || n == 0);

        for (i = 0; i < n; i++) {
                free(b[i].source);
                free(b[i].destination);
        }

        free(b);
}