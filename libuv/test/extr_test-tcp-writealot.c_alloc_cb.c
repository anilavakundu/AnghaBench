#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_3__ {size_t len; int /*<<< orphan*/  base; } ;
typedef  TYPE_1__ uv_buf_t ;

/* Variables and functions */
 int /*<<< orphan*/  malloc (size_t) ; 

__attribute__((used)) static void alloc_cb(uv_handle_t* handle, size_t size, uv_buf_t* buf) {
  buf->base = malloc(size);
  buf->len = size;
}