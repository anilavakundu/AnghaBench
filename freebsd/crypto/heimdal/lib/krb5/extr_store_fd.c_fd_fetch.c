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
typedef  int /*<<< orphan*/  ssize_t ;
typedef  int /*<<< orphan*/  krb5_storage ;

/* Variables and functions */
 int /*<<< orphan*/  FD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  net_read (int /*<<< orphan*/ ,void*,size_t) ; 

__attribute__((used)) static ssize_t
fd_fetch(krb5_storage * sp, void *data, size_t size)
{
    return net_read(FD(sp), data, size);
}