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
struct pg_tm {int /*<<< orphan*/  tm_mday; int /*<<< orphan*/  tm_mon; int /*<<< orphan*/  tm_year; } ;
typedef  int /*<<< orphan*/  fsec_t ;
typedef  int /*<<< orphan*/  TimestampTz ;
typedef  scalar_t__ DateADT ;

/* Variables and functions */
 int /*<<< orphan*/  ERRCODE_DATETIME_VALUE_OUT_OF_RANGE ; 
 int /*<<< orphan*/  ERROR ; 
 int /*<<< orphan*/  GetCurrentTransactionStartTimestamp () ; 
 scalar_t__ POSTGRES_EPOCH_JDATE ; 
 scalar_t__ date2j (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ereport (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errcode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errmsg (char*) ; 
 scalar_t__ timestamp2tm (int /*<<< orphan*/ ,int*,struct pg_tm*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

DateADT
GetSQLCurrentDate(void)
{
	TimestampTz ts;
	struct pg_tm tt,
			   *tm = &tt;
	fsec_t		fsec;
	int			tz;

	ts = GetCurrentTransactionStartTimestamp();

	if (timestamp2tm(ts, &tz, tm, &fsec, NULL, NULL) != 0)
		ereport(ERROR,
				(errcode(ERRCODE_DATETIME_VALUE_OUT_OF_RANGE),
				 errmsg("timestamp out of range")));

	return date2j(tm->tm_year, tm->tm_mon, tm->tm_mday) - POSTGRES_EPOCH_JDATE;
}