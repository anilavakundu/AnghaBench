#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8 ;
typedef  scalar_t__ uint32 ;
struct TYPE_15__ {int flags; int /*<<< orphan*/  mcs_id; } ;
typedef  TYPE_1__ VCHANNEL ;
struct TYPE_17__ {scalar_t__ encryption; } ;
struct TYPE_16__ {scalar_t__ end; scalar_t__ p; } ;
typedef  TYPE_2__* STREAM ;
typedef  TYPE_3__ RDPCLIENT ;
typedef  int /*<<< orphan*/  CHANNEL_PDU_HEADER ;

/* Variables and functions */
 int /*<<< orphan*/  CHANNEL_CHUNK_LENGTH ; 
 scalar_t__ CHANNEL_FLAG_FIRST ; 
 scalar_t__ CHANNEL_FLAG_LAST ; 
 scalar_t__ CHANNEL_FLAG_SHOW_PROTOCOL ; 
 int CHANNEL_OPTION_SHOW_PROTOCOL ; 
 int /*<<< orphan*/  DEBUG_CHANNEL (char*) ; 
 scalar_t__ MIN (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SEC_ENCRYPT ; 
 int /*<<< orphan*/  channel_hdr ; 
 int /*<<< orphan*/  out_uint32_le (TYPE_2__*,scalar_t__) ; 
 int /*<<< orphan*/  out_uint8p (TYPE_2__*,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  s_mark_end (TYPE_2__*) ; 
 int /*<<< orphan*/  s_pop_layer (TYPE_2__*,int /*<<< orphan*/ ) ; 
 TYPE_2__* sec_init (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sec_send_to_channel (TYPE_3__*,TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
channel_send(RDPCLIENT * This, STREAM s, VCHANNEL * channel)
{
	uint32 length, flags;
	uint32 thislength, remaining;
	uint8 *data;

	/* first fragment sent in-place */
	s_pop_layer(s, channel_hdr);
	length = s->end - s->p - sizeof(CHANNEL_PDU_HEADER);

	DEBUG_CHANNEL(("channel_send, length = %d\n", length));

	thislength = MIN(length, CHANNEL_CHUNK_LENGTH);
/* Note: In the original clipboard implementation, this number was
   1592, not 1600. However, I don't remember the reason and 1600 seems
   to work so.. This applies only to *this* length, not the length of
   continuation or ending packets. */
	remaining = length - thislength;
	flags = (remaining == 0) ? CHANNEL_FLAG_FIRST | CHANNEL_FLAG_LAST : CHANNEL_FLAG_FIRST;
	if (channel->flags & CHANNEL_OPTION_SHOW_PROTOCOL)
		flags |= CHANNEL_FLAG_SHOW_PROTOCOL;

	out_uint32_le(s, length);
	out_uint32_le(s, flags);
	data = s->end = s->p + thislength;
	DEBUG_CHANNEL(("Sending %d bytes with FLAG_FIRST\n", thislength));
	sec_send_to_channel(This, s, This->encryption ? SEC_ENCRYPT : 0, channel->mcs_id);

	/* subsequent segments copied (otherwise would have to generate headers backwards) */
	while (remaining > 0)
	{
		thislength = MIN(remaining, CHANNEL_CHUNK_LENGTH);
		remaining -= thislength;
		flags = (remaining == 0) ? CHANNEL_FLAG_LAST : 0;
		if (channel->flags & CHANNEL_OPTION_SHOW_PROTOCOL)
			flags |= CHANNEL_FLAG_SHOW_PROTOCOL;

		DEBUG_CHANNEL(("Sending %d bytes with flags %d\n", thislength, flags));

		s = sec_init(This, This->encryption ? SEC_ENCRYPT : 0, thislength + 8);
		out_uint32_le(s, length);
		out_uint32_le(s, flags);
		out_uint8p(s, data, thislength);
		s_mark_end(s);
		sec_send_to_channel(This, s, This->encryption ? SEC_ENCRYPT : 0, channel->mcs_id);

		data += thislength;
	}
}