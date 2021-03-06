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
struct TYPE_3__ {int /*<<< orphan*/  lock; } ;
struct stm32_mdma_chan {TYPE_1__ vchan; int /*<<< orphan*/  busy; int /*<<< orphan*/  desc; } ;
struct dma_chan {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  chan2dev (struct stm32_mdma_chan*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,TYPE_1__*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stm32_mdma_start_transfer (struct stm32_mdma_chan*) ; 
 struct stm32_mdma_chan* to_stm32_mdma_chan (struct dma_chan*) ; 
 int /*<<< orphan*/  vchan_issue_pending (TYPE_1__*) ; 

__attribute__((used)) static void stm32_mdma_issue_pending(struct dma_chan *c)
{
	struct stm32_mdma_chan *chan = to_stm32_mdma_chan(c);
	unsigned long flags;

	spin_lock_irqsave(&chan->vchan.lock, flags);

	if (!vchan_issue_pending(&chan->vchan))
		goto end;

	dev_dbg(chan2dev(chan), "vchan %pK: issued\n", &chan->vchan);

	if (!chan->desc && !chan->busy)
		stm32_mdma_start_transfer(chan);

end:
	spin_unlock_irqrestore(&chan->vchan.lock, flags);
}