#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct TYPE_4__ {int /*<<< orphan*/  group_chat_object; } ;
typedef  TYPE_1__ Tox ;
typedef  TYPE_1__ Messenger ;

/* Variables and functions */
 int group_action_send (int /*<<< orphan*/ ,int,int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 

int tox_group_action_send(Tox *tox, int groupnumber, const uint8_t *action, uint16_t length)
{
    Messenger *m = tox;
    return group_action_send(m->group_chat_object, groupnumber, action, length);
}