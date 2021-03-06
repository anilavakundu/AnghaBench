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
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 unsigned long long strtoull (char const*,int /*<<< orphan*/ *,int) ; 

void arl_strtoull(const char *name, uint32_t hash, const char *value, void *dst) {
    (void)name;
    (void)hash;

    register unsigned long long *d = dst;
    *d = strtoull(value, NULL, 10);
    // fprintf(stderr, "name '%s' with hash %u and value '%s' is %llu\n", name, hash, value, *d);
}