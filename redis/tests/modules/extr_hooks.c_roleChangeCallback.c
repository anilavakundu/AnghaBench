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
typedef  scalar_t__ uint64_t ;
struct TYPE_2__ {int /*<<< orphan*/  masterhost; } ;
typedef  TYPE_1__ RedisModuleReplicationInfo ;
typedef  void* RedisModuleEvent ;
typedef  int /*<<< orphan*/  RedisModuleCtx ;

/* Variables and functions */
 int /*<<< orphan*/  LogStringEvent (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ REDISMODULE_EVENT_REPLROLECHANGED_NOW_MASTER ; 
 int /*<<< orphan*/  REDISMODULE_NOT_USED (void*) ; 

void roleChangeCallback(RedisModuleCtx *ctx, RedisModuleEvent e, uint64_t sub, void *data)
{
    REDISMODULE_NOT_USED(e);
    REDISMODULE_NOT_USED(data);

    RedisModuleReplicationInfo *ri = data;
    char *keyname = (sub == REDISMODULE_EVENT_REPLROLECHANGED_NOW_MASTER) ?
        "role-master" : "role-replica";
    LogStringEvent(ctx, keyname, ri->masterhost);
}