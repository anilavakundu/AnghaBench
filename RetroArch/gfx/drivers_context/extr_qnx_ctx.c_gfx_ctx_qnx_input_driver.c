#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {void* (* init ) (char const*) ;} ;
typedef  TYPE_1__ input_driver_t ;

/* Variables and functions */
 TYPE_1__ input_qnx ; 
 void* stub1 (char const*) ; 

__attribute__((used)) static void gfx_ctx_qnx_input_driver(void *data,
      const char *joypad_name,
      input_driver_t **input, void **input_data)
{
   void *qnxinput       = input_qnx.init(joypad_name);

   *input               = qnxinput ? &input_qnx : NULL;
   *input_data          = qnxinput;
}