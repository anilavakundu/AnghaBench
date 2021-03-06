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

/* Variables and functions */
 int EINVAL ; 
 int ENOTSUPP ; 

int snmp_version(void *context, size_t hdrlen, unsigned char tag,
		 const void *data, size_t datalen)
{
	if (datalen != 1)
		return -EINVAL;
	if (*(unsigned char *)data > 1)
		return -ENOTSUPP;
	return 1;
}