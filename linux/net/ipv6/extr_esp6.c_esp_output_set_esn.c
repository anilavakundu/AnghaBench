#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int /*<<< orphan*/  spi; } ;
struct TYPE_11__ {int flags; } ;
struct xfrm_state {TYPE_4__ id; TYPE_5__ props; } ;
struct TYPE_7__ {int /*<<< orphan*/  hi; } ;
struct xfrm_offload {TYPE_1__ seq; } ;
struct sk_buff {int dummy; } ;
struct ip_esp_hdr {int /*<<< orphan*/  spi; void* seq_no; } ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_8__ {int /*<<< orphan*/  hi; } ;
struct TYPE_9__ {TYPE_2__ output; } ;
struct TYPE_12__ {TYPE_3__ seq; } ;

/* Variables and functions */
 TYPE_6__* XFRM_SKB_CB (struct sk_buff*) ; 
 int XFRM_STATE_ESN ; 
 void* htonl (int /*<<< orphan*/ ) ; 
 int skb_transport_header (struct sk_buff*) ; 
 struct xfrm_offload* xfrm_offload (struct sk_buff*) ; 

__attribute__((used)) static struct ip_esp_hdr *esp_output_set_esn(struct sk_buff *skb,
					     struct xfrm_state *x,
					     struct ip_esp_hdr *esph,
					     __be32 *seqhi)
{
	/* For ESN we move the header forward by 4 bytes to
	 * accomodate the high bits.  We will move it back after
	 * encryption.
	 */
	if ((x->props.flags & XFRM_STATE_ESN)) {
		struct xfrm_offload *xo = xfrm_offload(skb);

		esph = (void *)(skb_transport_header(skb) - sizeof(__be32));
		*seqhi = esph->spi;
		if (xo)
			esph->seq_no = htonl(xo->seq.hi);
		else
			esph->seq_no = htonl(XFRM_SKB_CB(skb)->seq.output.hi);
	}

	esph->spi = x->id.spi;

	return esph;
}