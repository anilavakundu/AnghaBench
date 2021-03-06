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
struct v4l2_ioctl_ops {int (* vidioc_subscribe_event ) (void*,void*) ;} ;
struct file {int dummy; } ;

/* Variables and functions */
 int stub1 (void*,void*) ; 

__attribute__((used)) static int v4l_subscribe_event(const struct v4l2_ioctl_ops *ops,
				struct file *file, void *fh, void *arg)
{
	return ops->vidioc_subscribe_event(fh, arg);
}