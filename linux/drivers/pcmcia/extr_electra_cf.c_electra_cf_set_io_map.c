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
struct pcmcia_socket {int dummy; } ;
struct pccard_io_map {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int electra_cf_set_io_map(struct pcmcia_socket *s,
				 struct pccard_io_map *io)
{
	return 0;
}