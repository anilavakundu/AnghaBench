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
typedef  int /*<<< orphan*/  uint16_t ;

/* Variables and functions */
 int wind_ucs2utf8 (int /*<<< orphan*/  const*,size_t,int /*<<< orphan*/ *,size_t*) ; 

int
wind_ucs2utf8_length(const uint16_t *in, size_t in_len, size_t *out_len)
{
    return wind_ucs2utf8(in, in_len, NULL, out_len);
}