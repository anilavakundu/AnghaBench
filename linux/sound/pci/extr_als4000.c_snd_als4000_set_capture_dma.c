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
struct snd_sb {int dummy; } ;
typedef  unsigned int dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  ALS4K_GCRA2_FIFO2_PCIADDR ; 
 int /*<<< orphan*/  ALS4K_GCRA3_FIFO2_COUNT ; 
 int /*<<< orphan*/  snd_als4k_gcr_write (struct snd_sb*,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static inline void snd_als4000_set_capture_dma(struct snd_sb *chip,
					       dma_addr_t addr, unsigned size)
{
	/* SPECS_PAGE: 40 */
	snd_als4k_gcr_write(chip, ALS4K_GCRA2_FIFO2_PCIADDR, addr);
	snd_als4k_gcr_write(chip, ALS4K_GCRA3_FIFO2_COUNT, (size-1));
}