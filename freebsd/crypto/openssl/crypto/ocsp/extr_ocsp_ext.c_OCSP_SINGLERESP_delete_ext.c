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
typedef  int /*<<< orphan*/  X509_EXTENSION ;
struct TYPE_3__ {int /*<<< orphan*/  singleExtensions; } ;
typedef  TYPE_1__ OCSP_SINGLERESP ;

/* Variables and functions */
 int /*<<< orphan*/ * X509v3_delete_ext (int /*<<< orphan*/ ,int) ; 

X509_EXTENSION *OCSP_SINGLERESP_delete_ext(OCSP_SINGLERESP *x, int loc)
{
    return X509v3_delete_ext(x->singleExtensions, loc);
}