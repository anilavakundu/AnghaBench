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
struct renesas_usb3 {int /*<<< orphan*/  disabled_count; } ;

/* Variables and functions */
 int /*<<< orphan*/  USB3_USB_COM_CON ; 
 int /*<<< orphan*/  USB_COM_CON_EP0_EN ; 
 int /*<<< orphan*/  USB_COM_CON_SPD_MODE ; 
 int /*<<< orphan*/  usb3_set_bit (struct renesas_usb3*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb3_usb2_pullup (struct renesas_usb3*,int) ; 

__attribute__((used)) static void usb3_start_usb2_connection(struct renesas_usb3 *usb3)
{
	usb3->disabled_count++;
	usb3_set_bit(usb3, USB_COM_CON_EP0_EN, USB3_USB_COM_CON);
	usb3_set_bit(usb3, USB_COM_CON_SPD_MODE, USB3_USB_COM_CON);
	usb3_usb2_pullup(usb3, 1);
}