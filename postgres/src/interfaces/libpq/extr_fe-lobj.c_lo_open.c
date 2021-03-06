#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {TYPE_2__* lobjfuncs; } ;
struct TYPE_9__ {int integer; } ;
struct TYPE_11__ {int isint; int len; TYPE_1__ u; } ;
struct TYPE_10__ {int /*<<< orphan*/  fn_lo_open; } ;
typedef  TYPE_3__ PQArgBlock ;
typedef  int /*<<< orphan*/  PGresult ;
typedef  TYPE_4__ PGconn ;
typedef  int Oid ;

/* Variables and functions */
 scalar_t__ PGRES_COMMAND_OK ; 
 int /*<<< orphan*/  PQclear (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * PQfn (TYPE_4__*,int /*<<< orphan*/ ,int*,int*,int,TYPE_3__*,int) ; 
 scalar_t__ PQresultStatus (int /*<<< orphan*/ *) ; 
 scalar_t__ lo_initialize (TYPE_4__*) ; 

int
lo_open(PGconn *conn, Oid lobjId, int mode)
{
	int			fd;
	int			result_len;
	PQArgBlock	argv[2];
	PGresult   *res;

	if (conn == NULL || conn->lobjfuncs == NULL)
	{
		if (lo_initialize(conn) < 0)
			return -1;
	}

	argv[0].isint = 1;
	argv[0].len = 4;
	argv[0].u.integer = lobjId;

	argv[1].isint = 1;
	argv[1].len = 4;
	argv[1].u.integer = mode;

	res = PQfn(conn, conn->lobjfuncs->fn_lo_open, &fd, &result_len, 1, argv, 2);
	if (PQresultStatus(res) == PGRES_COMMAND_OK)
	{
		PQclear(res);
		return fd;
	}
	else
	{
		PQclear(res);
		return -1;
	}
}