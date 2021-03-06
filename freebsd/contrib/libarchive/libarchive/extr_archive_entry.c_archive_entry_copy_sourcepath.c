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
struct archive_entry {int /*<<< orphan*/  ae_sourcepath; } ;

/* Variables and functions */
 int /*<<< orphan*/  archive_mstring_copy_mbs (int /*<<< orphan*/ *,char const*) ; 

void
archive_entry_copy_sourcepath(struct archive_entry *entry, const char *path)
{
	archive_mstring_copy_mbs(&entry->ae_sourcepath, path);
}