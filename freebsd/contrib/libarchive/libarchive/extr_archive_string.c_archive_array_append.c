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
struct archive_string {int dummy; } ;

/* Variables and functions */
 struct archive_string* archive_string_append (struct archive_string*,char const*,size_t) ; 

struct archive_string *
archive_array_append(struct archive_string *as, const char *p, size_t s)
{
	return archive_string_append(as, p, s);
}