#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {struct TYPE_5__* next; struct TYPE_5__* first_attr; } ;
typedef  TYPE_1__ abbrev_entry ;
typedef  TYPE_1__ abbrev_attr ;

/* Variables and functions */
 TYPE_1__* first_abbrev ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int /*<<< orphan*/  last_abbrev ; 

__attribute__((used)) static void
free_abbrevs (void)
{
  abbrev_entry *abbrev;

  for (abbrev = first_abbrev; abbrev;)
    {
      abbrev_entry *next = abbrev->next;
      abbrev_attr *attr;

      for (attr = abbrev->first_attr; attr;)
	{
	  abbrev_attr *next = attr->next;

	  free (attr);
	  attr = next;
	}

      free (abbrev);
      abbrev = next;
    }

  last_abbrev = first_abbrev = NULL;
}