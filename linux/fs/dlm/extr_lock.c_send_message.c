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
struct dlm_mhandle {int dummy; } ;
struct dlm_message {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dlm_lowcomms_commit_buffer (struct dlm_mhandle*) ; 
 int /*<<< orphan*/  dlm_message_out (struct dlm_message*) ; 

__attribute__((used)) static int send_message(struct dlm_mhandle *mh, struct dlm_message *ms)
{
	dlm_message_out(ms);
	dlm_lowcomms_commit_buffer(mh);
	return 0;
}