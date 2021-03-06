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
struct g_provider {int /*<<< orphan*/  name; } ;
struct g_mirror_disk {struct g_consumer* d_consumer; TYPE_1__* d_softc; } ;
struct g_consumer {scalar_t__ index; struct g_mirror_disk* private; int /*<<< orphan*/  flags; } ;
struct TYPE_2__ {int /*<<< orphan*/  sc_geom; int /*<<< orphan*/  sc_name; } ;

/* Variables and functions */
 int /*<<< orphan*/  G_CF_DIRECT_RECEIVE ; 
 int /*<<< orphan*/  G_MIRROR_DEBUG (int,char*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  KASSERT (int /*<<< orphan*/ ,char*) ; 
 int g_access (struct g_consumer*,int,int,int) ; 
 int g_attach (struct g_consumer*,struct g_provider*) ; 
 int /*<<< orphan*/  g_destroy_consumer (struct g_consumer*) ; 
 int /*<<< orphan*/  g_detach (struct g_consumer*) ; 
 int /*<<< orphan*/  g_mirror_get_diskname (struct g_mirror_disk*) ; 
 struct g_consumer* g_new_consumer (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  g_topology_assert_not () ; 
 int /*<<< orphan*/  g_topology_lock () ; 
 int /*<<< orphan*/  g_topology_unlock () ; 

__attribute__((used)) static int
g_mirror_connect_disk(struct g_mirror_disk *disk, struct g_provider *pp)
{
	struct g_consumer *cp;
	int error;

	g_topology_assert_not();
	KASSERT(disk->d_consumer == NULL,
	    ("Disk already connected (device %s).", disk->d_softc->sc_name));

	g_topology_lock();
	cp = g_new_consumer(disk->d_softc->sc_geom);
	cp->flags |= G_CF_DIRECT_RECEIVE;
	error = g_attach(cp, pp);
	if (error != 0) {
		g_destroy_consumer(cp);
		g_topology_unlock();
		return (error);
	}
	error = g_access(cp, 1, 1, 1);
	if (error != 0) {
		g_detach(cp);
		g_destroy_consumer(cp);
		g_topology_unlock();
		G_MIRROR_DEBUG(0, "Cannot open consumer %s (error=%d).",
		    pp->name, error);
		return (error);
	}
	g_topology_unlock();
	disk->d_consumer = cp;
	disk->d_consumer->private = disk;
	disk->d_consumer->index = 0;

	G_MIRROR_DEBUG(2, "Disk %s connected.", g_mirror_get_diskname(disk));
	return (0);
}