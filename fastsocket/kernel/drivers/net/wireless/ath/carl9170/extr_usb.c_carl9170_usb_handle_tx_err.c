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
struct urb {scalar_t__ context; } ;
struct sk_buff {int dummy; } ;
struct ar9170 {int /*<<< orphan*/  tx_err; } ;

/* Variables and functions */
 int /*<<< orphan*/  carl9170_tx_callback (struct ar9170*,struct sk_buff*) ; 
 int /*<<< orphan*/  carl9170_tx_drop (struct ar9170*,struct sk_buff*) ; 
 int /*<<< orphan*/  usb_free_urb (struct urb*) ; 
 struct urb* usb_get_from_anchor (int /*<<< orphan*/ *) ; 

void carl9170_usb_handle_tx_err(struct ar9170 *ar)
{
	struct urb *urb;

	while ((urb = usb_get_from_anchor(&ar->tx_err))) {
		struct sk_buff *skb = (void *)urb->context;

		carl9170_tx_drop(ar, skb);
		carl9170_tx_callback(ar, skb);
		usb_free_urb(urb);
	}
}