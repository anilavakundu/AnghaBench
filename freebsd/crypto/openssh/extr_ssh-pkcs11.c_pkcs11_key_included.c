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
struct sshkey {int dummy; } ;

/* Variables and functions */
 scalar_t__ sshkey_equal (struct sshkey*,struct sshkey*) ; 

__attribute__((used)) static int
pkcs11_key_included(struct sshkey ***keysp, int *nkeys, struct sshkey *key)
{
	int i;

	for (i = 0; i < *nkeys; i++)
		if (sshkey_equal(key, (*keysp)[i]))
			return (1);
	return (0);
}