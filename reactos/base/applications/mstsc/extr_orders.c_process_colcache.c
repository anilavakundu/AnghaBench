#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint8 ;
struct TYPE_6__ {scalar_t__ red; scalar_t__ green; scalar_t__ blue; } ;
struct TYPE_5__ {int ncolours; TYPE_2__* colours; } ;
typedef  int /*<<< orphan*/  STREAM ;
typedef  int /*<<< orphan*/  RD_HCOLOURMAP ;
typedef  TYPE_1__ COLOURMAP ;
typedef  TYPE_2__ COLOURENTRY ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUG (char*) ; 
 int /*<<< orphan*/  in_uint16_le (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  in_uint8 (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  in_uint8s (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ui_create_colourmap (TYPE_1__*) ; 
 int /*<<< orphan*/  ui_set_colourmap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xfree (TYPE_2__*) ; 
 scalar_t__ xmalloc (int) ; 

__attribute__((used)) static void
process_colcache(STREAM s)
{
	COLOURENTRY *entry;
	COLOURMAP map;
	RD_HCOLOURMAP hmap;
	uint8 cache_id;
	int i;

	in_uint8(s, cache_id);
	in_uint16_le(s, map.ncolours);

	map.colours = (COLOURENTRY *) xmalloc(sizeof(COLOURENTRY) * map.ncolours);

	for (i = 0; i < map.ncolours; i++)
	{
		entry = &map.colours[i];
		in_uint8(s, entry->blue);
		in_uint8(s, entry->green);
		in_uint8(s, entry->red);
		in_uint8s(s, 1);	/* pad */
	}

	DEBUG(("COLCACHE(id=%d,n=%d)\n", cache_id, map.ncolours));

	hmap = ui_create_colourmap(&map);

	if (cache_id)
		ui_set_colourmap(hmap);

	xfree(map.colours);
}