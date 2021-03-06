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
struct pcg_state_8 {int state; } ;

/* Variables and functions */
 int PCG_DEFAULT_INCREMENT_8 ; 
 int PCG_DEFAULT_MULTIPLIER_8 ; 

inline void pcg_oneseq_8_step_r(struct pcg_state_8 *rng) {
  rng->state = rng->state * PCG_DEFAULT_MULTIPLIER_8 + PCG_DEFAULT_INCREMENT_8;
}