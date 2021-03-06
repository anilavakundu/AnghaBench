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
typedef  int /*<<< orphan*/  visitproc ;
typedef  int /*<<< orphan*/  PyObject ;

/* Variables and functions */
 int /*<<< orphan*/  Py_VISIT (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
BufMapIterTraverse(PyObject *buffer, visitproc visit, void *arg)
{
    if (buffer)
	Py_VISIT(buffer);
    return 0;
}