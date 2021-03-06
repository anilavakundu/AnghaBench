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
typedef  int /*<<< orphan*/ * vec3_t ;

/* Variables and functions */
 int Sign (int /*<<< orphan*/ ) ; 

int PlaneSignBits(vec3_t normal)
{
	int i, signbits;

	signbits = 0;
	for (i = 2; i >= 0; i--)
	{
		signbits = (signbits << 1) + Sign(normal[i]);
	} //end for
	return signbits;
}