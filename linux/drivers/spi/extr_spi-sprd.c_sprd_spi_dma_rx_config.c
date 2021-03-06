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
struct TYPE_2__ {int rx_len; int /*<<< orphan*/  fragmens_len; int /*<<< orphan*/  width; struct dma_chan** dma_chan; } ;
struct sprd_spi {TYPE_1__ dma; int /*<<< orphan*/  phy_base; } ;
struct spi_transfer {int /*<<< orphan*/  rx_sg; } ;
struct dma_slave_config {int /*<<< orphan*/  dst_maxburst; int /*<<< orphan*/  dst_addr_width; int /*<<< orphan*/  src_addr_width; int /*<<< orphan*/  src_addr; } ;
struct dma_chan {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_DEV_TO_MEM ; 
 size_t SPRD_SPI_RX ; 
 int sprd_spi_dma_submit (struct dma_chan*,struct dma_slave_config*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int sprd_spi_dma_rx_config(struct sprd_spi *ss, struct spi_transfer *t)
{
	struct dma_chan *dma_chan = ss->dma.dma_chan[SPRD_SPI_RX];
	struct dma_slave_config config = {
		.src_addr = ss->phy_base,
		.src_addr_width = ss->dma.width,
		.dst_addr_width = ss->dma.width,
		.dst_maxburst = ss->dma.fragmens_len,
	};
	int ret;

	ret = sprd_spi_dma_submit(dma_chan, &config, &t->rx_sg, DMA_DEV_TO_MEM);
	if (ret)
		return ret;

	return ss->dma.rx_len;
}