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
struct adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  indicate_wx_scan_complete_event (struct adapter*) ; 

inline void rtw_indicate_scan_done(struct adapter *padapter, bool aborted)
{
	indicate_wx_scan_complete_event(padapter);
}