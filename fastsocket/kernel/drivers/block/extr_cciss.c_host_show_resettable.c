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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct ctlr_info {int /*<<< orphan*/  board_id; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int ctlr_is_resettable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 
 struct ctlr_info* to_hba (struct device*) ; 

__attribute__((used)) static ssize_t host_show_resettable(struct device *dev,
				    struct device_attribute *attr,
				    char *buf)
{
	struct ctlr_info *h = to_hba(dev);

	return snprintf(buf, 20, "%d\n", ctlr_is_resettable(h->board_id));
}