#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* bufattr_t ;
struct TYPE_3__ {int /*<<< orphan*/  ba_flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  BA_GREEDY_MODE ; 
 int /*<<< orphan*/  SET (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void 
bufattr_markgreedymode(bufattr_t bap) {
	SET(bap->ba_flags, BA_GREEDY_MODE);
}