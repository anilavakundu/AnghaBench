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
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  int /*<<< orphan*/  uv_check_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  async_handle ; 
 scalar_t__ check_cb_called ; 
 int /*<<< orphan*/  check_handle ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void check_cb(uv_check_t* handle) {
  ASSERT(check_cb_called == 0);
  uv_close((uv_handle_t*) &async_handle, NULL);
  uv_close((uv_handle_t*) &check_handle, NULL);
  check_cb_called++;
}