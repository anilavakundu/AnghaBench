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
struct acpi_ec {TYPE_1__* curr; } ;
struct TYPE_2__ {int done; int /*<<< orphan*/  command; scalar_t__ ri; scalar_t__ wi; scalar_t__ irq_count; } ;

/* Variables and functions */
 int /*<<< orphan*/  acpi_ec_write_cmd (struct acpi_ec*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void start_transaction(struct acpi_ec *ec)
{
	ec->curr->irq_count = ec->curr->wi = ec->curr->ri = 0;
	ec->curr->done = false;
	acpi_ec_write_cmd(ec, ec->curr->command);
}