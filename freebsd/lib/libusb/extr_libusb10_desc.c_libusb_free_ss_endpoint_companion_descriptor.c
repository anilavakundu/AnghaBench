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
struct libusb_ss_endpoint_companion_descriptor {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  libusb_free_ss_endpoint_comp (struct libusb_ss_endpoint_companion_descriptor*) ; 

void
libusb_free_ss_endpoint_companion_descriptor(struct libusb_ss_endpoint_companion_descriptor *ep_comp)
{

	libusb_free_ss_endpoint_comp(ep_comp);
}