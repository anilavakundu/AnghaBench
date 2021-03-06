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
struct input_dev {int dummy; } ;
struct imx6ul_tsc {int /*<<< orphan*/  adc_clk; int /*<<< orphan*/  tsc_clk; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  imx6ul_tsc_disable (struct imx6ul_tsc*) ; 
 struct imx6ul_tsc* input_get_drvdata (struct input_dev*) ; 

__attribute__((used)) static void imx6ul_tsc_close(struct input_dev *input_dev)
{
	struct imx6ul_tsc *tsc = input_get_drvdata(input_dev);

	imx6ul_tsc_disable(tsc);

	clk_disable_unprepare(tsc->tsc_clk);
	clk_disable_unprepare(tsc->adc_clk);
}