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
struct TYPE_3__ {int length; } ;
typedef  TYPE_1__ heim_bit_string ;

/* Variables and functions */

size_t
der_length_bit_string (const heim_bit_string *k)
{
    return (k->length + 7) / 8 + 1;
}