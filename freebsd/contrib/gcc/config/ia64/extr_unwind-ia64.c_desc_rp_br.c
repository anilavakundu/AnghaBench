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
struct unw_state_record {unsigned char return_link_reg; } ;

/* Variables and functions */

__attribute__((used)) static inline void
desc_rp_br (unsigned char dst, struct unw_state_record *sr)
{
  sr->return_link_reg = dst;
}