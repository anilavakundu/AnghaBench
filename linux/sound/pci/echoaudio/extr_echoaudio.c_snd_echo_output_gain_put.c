#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_kcontrol {int dummy; } ;
struct TYPE_3__ {int* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct echoaudio {int* output_gain; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int ECHOGAIN_MAXOUT ; 
 int ECHOGAIN_MINOUT ; 
 int num_busses_out (struct echoaudio*) ; 
 int /*<<< orphan*/  set_output_gain (struct echoaudio*,int,int) ; 
 struct echoaudio* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  update_output_line_level (struct echoaudio*) ; 

__attribute__((used)) static int snd_echo_output_gain_put(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_value *ucontrol)
{
	struct echoaudio *chip;
	int c, changed, gain;

	changed = 0;
	chip = snd_kcontrol_chip(kcontrol);
	spin_lock_irq(&chip->lock);
	for (c = 0; c < num_busses_out(chip); c++) {
		gain = ucontrol->value.integer.value[c];
		/* Ignore out of range values */
		if (gain < ECHOGAIN_MINOUT || gain > ECHOGAIN_MAXOUT)
			continue;
		if (chip->output_gain[c] != gain) {
			set_output_gain(chip, c, gain);
			changed = 1;
		}
	}
	if (changed)
		update_output_line_level(chip);
	spin_unlock_irq(&chip->lock);
	return changed;
}