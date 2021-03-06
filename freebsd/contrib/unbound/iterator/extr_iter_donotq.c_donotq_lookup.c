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
struct sockaddr_storage {int dummy; } ;
struct iter_donotq {int /*<<< orphan*/  tree; } ;
typedef  int /*<<< orphan*/  socklen_t ;

/* Variables and functions */
 int /*<<< orphan*/ * addr_tree_lookup (int /*<<< orphan*/ *,struct sockaddr_storage*,int /*<<< orphan*/ ) ; 

int 
donotq_lookup(struct iter_donotq* donotq, struct sockaddr_storage* addr,
        socklen_t addrlen)
{
	return addr_tree_lookup(&donotq->tree, addr, addrlen) != NULL;
}