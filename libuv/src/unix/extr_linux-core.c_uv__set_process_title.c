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

/* Variables and functions */
 int /*<<< orphan*/  PR_SET_NAME ; 
 int /*<<< orphan*/  prctl (int /*<<< orphan*/ ,char const*) ; 

void uv__set_process_title(const char* title) {
#if defined(PR_SET_NAME)
  prctl(PR_SET_NAME, title);  /* Only copies first 16 characters. */
#endif
}