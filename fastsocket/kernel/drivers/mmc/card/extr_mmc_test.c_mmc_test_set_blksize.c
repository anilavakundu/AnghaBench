#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct mmc_test_card {TYPE_1__* card; } ;
struct mmc_command {unsigned int arg; int flags; int /*<<< orphan*/  opcode; } ;
struct TYPE_2__ {int /*<<< orphan*/  host; } ;

/* Variables and functions */
 int MMC_CMD_AC ; 
 int MMC_RSP_R1 ; 
 int /*<<< orphan*/  MMC_SET_BLOCKLEN ; 
 int mmc_wait_for_cmd (int /*<<< orphan*/ ,struct mmc_command*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mmc_test_set_blksize(struct mmc_test_card *test, unsigned size)
{
	struct mmc_command cmd;
	int ret;

	cmd.opcode = MMC_SET_BLOCKLEN;
	cmd.arg = size;
	cmd.flags = MMC_RSP_R1 | MMC_CMD_AC;
	ret = mmc_wait_for_cmd(test->card->host, &cmd, 0);
	if (ret)
		return ret;

	return 0;
}