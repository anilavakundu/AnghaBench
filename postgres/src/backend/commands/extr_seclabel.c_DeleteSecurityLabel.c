#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  t_self; } ;
struct TYPE_6__ {scalar_t__ objectSubId; int /*<<< orphan*/  classId; int /*<<< orphan*/  objectId; } ;
typedef  int /*<<< orphan*/  SysScanDesc ;
typedef  int /*<<< orphan*/  ScanKeyData ;
typedef  int /*<<< orphan*/  Relation ;
typedef  TYPE_1__ ObjectAddress ;
typedef  TYPE_2__* HeapTuple ;

/* Variables and functions */
 int /*<<< orphan*/  Anum_pg_seclabel_classoid ; 
 int /*<<< orphan*/  Anum_pg_seclabel_objoid ; 
 int /*<<< orphan*/  Anum_pg_seclabel_objsubid ; 
 int /*<<< orphan*/  Assert (int) ; 
 int /*<<< orphan*/  BTEqualStrategyNumber ; 
 int /*<<< orphan*/  CatalogTupleDelete (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DeleteSharedSecurityLabel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  F_INT4EQ ; 
 int /*<<< orphan*/  F_OIDEQ ; 
 scalar_t__ HeapTupleIsValid (TYPE_2__*) ; 
 int /*<<< orphan*/  Int32GetDatum (scalar_t__) ; 
 scalar_t__ IsSharedRelation (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ObjectIdGetDatum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RowExclusiveLock ; 
 int /*<<< orphan*/  ScanKeyInit (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SecLabelObjectIndexId ; 
 int /*<<< orphan*/  SecLabelRelationId ; 
 int /*<<< orphan*/  systable_beginscan (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  systable_endscan (int /*<<< orphan*/ ) ; 
 TYPE_2__* systable_getnext (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  table_close (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  table_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
DeleteSecurityLabel(const ObjectAddress *object)
{
	Relation	pg_seclabel;
	ScanKeyData skey[3];
	SysScanDesc scan;
	HeapTuple	oldtup;
	int			nkeys;

	/* Shared objects have their own security label catalog. */
	if (IsSharedRelation(object->classId))
	{
		Assert(object->objectSubId == 0);
		DeleteSharedSecurityLabel(object->objectId, object->classId);
		return;
	}

	ScanKeyInit(&skey[0],
				Anum_pg_seclabel_objoid,
				BTEqualStrategyNumber, F_OIDEQ,
				ObjectIdGetDatum(object->objectId));
	ScanKeyInit(&skey[1],
				Anum_pg_seclabel_classoid,
				BTEqualStrategyNumber, F_OIDEQ,
				ObjectIdGetDatum(object->classId));
	if (object->objectSubId != 0)
	{
		ScanKeyInit(&skey[2],
					Anum_pg_seclabel_objsubid,
					BTEqualStrategyNumber, F_INT4EQ,
					Int32GetDatum(object->objectSubId));
		nkeys = 3;
	}
	else
		nkeys = 2;

	pg_seclabel = table_open(SecLabelRelationId, RowExclusiveLock);

	scan = systable_beginscan(pg_seclabel, SecLabelObjectIndexId, true,
							  NULL, nkeys, skey);
	while (HeapTupleIsValid(oldtup = systable_getnext(scan)))
		CatalogTupleDelete(pg_seclabel, &oldtup->t_self);
	systable_endscan(scan);

	table_close(pg_seclabel, RowExclusiveLock);
}