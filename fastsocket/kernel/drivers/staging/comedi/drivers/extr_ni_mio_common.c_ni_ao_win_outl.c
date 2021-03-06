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
typedef  int /*<<< orphan*/  uint32_t ;
struct comedi_device {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  window_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  AO_Window_Address_611x ; 
 int /*<<< orphan*/  AO_Window_Data_611x ; 
 TYPE_1__* devpriv ; 
 int /*<<< orphan*/  ni_writel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ni_writew (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline void ni_ao_win_outl(struct comedi_device *dev, uint32_t data,
				  int addr)
{
	unsigned long flags;

	spin_lock_irqsave(&devpriv->window_lock, flags);
	ni_writew(addr, AO_Window_Address_611x);
	ni_writel(data, AO_Window_Data_611x);
	spin_unlock_irqrestore(&devpriv->window_lock, flags);
}