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
struct dma_slave_config {int dummy; } ;
struct dma_chan {int dummy; } ;
struct coh901318_chan {int /*<<< orphan*/  config; } ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,struct dma_slave_config*,int) ; 
 struct coh901318_chan* to_coh901318_chan (struct dma_chan*) ; 

__attribute__((used)) static int coh901318_dma_slave_config(struct dma_chan *chan,
					   struct dma_slave_config *config)
{
	struct coh901318_chan *cohc = to_coh901318_chan(chan);

	memcpy(&cohc->config, config, sizeof(*config));

	return 0;
}