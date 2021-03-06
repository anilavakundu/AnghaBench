#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_8__ {int idLength; int /*<<< orphan*/ * ids; } ;
typedef  scalar_t__ INT ;
typedef  TYPE_1__ AsnObjectIdentifier ;

/* Variables and functions */
 scalar_t__ SnmpUtilOidAppend (TYPE_1__*,TYPE_1__*) ; 
 scalar_t__ setOidWithItem (TYPE_1__*,TYPE_1__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static INT setOidWithItemAndInteger(AsnObjectIdentifier *dst,
    AsnObjectIdentifier *base, UINT item, UINT instance)
{
    AsnObjectIdentifier oid;
    INT ret;

    ret = setOidWithItem(dst, base, item);
    if (ret)
    {
        oid.idLength = 1;
        oid.ids = &instance;
        ret = SnmpUtilOidAppend(dst, &oid);
    }
    return ret;
}