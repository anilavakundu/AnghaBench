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
typedef  int u16 ;
struct sd {int colors; } ;
struct gspca_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  reg_w (struct gspca_dev*,int) ; 

__attribute__((used)) static void setcolors(struct gspca_dev *gspca_dev)
{
	struct sd *sd = (struct sd *) gspca_dev;
	u16 reg_to_write;

	reg_to_write = 0x80bb + sd->colors * 0x100;	/* was 0xc0 */
	reg_w(gspca_dev, reg_to_write);
}