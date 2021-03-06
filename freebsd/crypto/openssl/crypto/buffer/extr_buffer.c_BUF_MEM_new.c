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
typedef  int /*<<< orphan*/  BUF_MEM ;

/* Variables and functions */
 int /*<<< orphan*/  BUF_F_BUF_MEM_NEW ; 
 int /*<<< orphan*/  BUFerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/ * OPENSSL_zalloc (int) ; 

BUF_MEM *BUF_MEM_new(void)
{
    BUF_MEM *ret;

    ret = OPENSSL_zalloc(sizeof(*ret));
    if (ret == NULL) {
        BUFerr(BUF_F_BUF_MEM_NEW, ERR_R_MALLOC_FAILURE);
        return NULL;
    }
    return ret;
}