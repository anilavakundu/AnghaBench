#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ arena; } ;
typedef  TYPE_1__ stb_spmatrix ;

/* Variables and functions */
 int /*<<< orphan*/  stb__spmatrix_destroy (TYPE_1__*) ; 
 int /*<<< orphan*/  stb_free (scalar_t__) ; 

void stb_sparse_ptr_matrix_free(stb_spmatrix *z)
{
   if (z->arena) stb_free(z->arena);
   stb__spmatrix_destroy(z);
}