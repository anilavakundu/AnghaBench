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
typedef  int /*<<< orphan*/  pdf_obj ;
typedef  int /*<<< orphan*/  fz_context ;

/* Variables and functions */
 int /*<<< orphan*/  PDF_FALSE ; 
 int /*<<< orphan*/  PDF_TRUE ; 
 int /*<<< orphan*/  pdf_dict_put (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void pdf_dict_put_bool(fz_context *ctx, pdf_obj *dict, pdf_obj *key, int x)
{
	pdf_dict_put(ctx, dict, key, x ? PDF_TRUE : PDF_FALSE);
}