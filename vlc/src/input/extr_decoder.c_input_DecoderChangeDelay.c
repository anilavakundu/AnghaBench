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
typedef  int /*<<< orphan*/  vlc_tick_t ;
struct decoder_owner {int /*<<< orphan*/  p_fifo; int /*<<< orphan*/  delay; } ;
typedef  int /*<<< orphan*/  decoder_t ;

/* Variables and functions */
 struct decoder_owner* dec_get_owner (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_fifo_Lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vlc_fifo_Unlock (int /*<<< orphan*/ ) ; 

void input_DecoderChangeDelay( decoder_t *dec, vlc_tick_t delay )
{
    struct decoder_owner *owner = dec_get_owner( dec );

    vlc_fifo_Lock( owner->p_fifo );
    owner->delay = delay;
    vlc_fifo_Unlock( owner->p_fifo );
}