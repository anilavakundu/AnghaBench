#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_1__* ameth; } ;
struct TYPE_5__ {int (* param_missing ) (TYPE_2__ const*) ;} ;
typedef  TYPE_2__ EVP_PKEY ;

/* Variables and functions */
 int stub1 (TYPE_2__ const*) ; 

int EVP_PKEY_missing_parameters(const EVP_PKEY *pkey)
{
    if (pkey->ameth && pkey->ameth->param_missing)
        return pkey->ameth->param_missing(pkey);
    return 0;
}