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
typedef  int /*<<< orphan*/  VARIANT_BOOL ;
struct TYPE_3__ {int /*<<< orphan*/  IHTMLButtonElement_iface; } ;
typedef  int /*<<< orphan*/  HTMLDOMNode ;
typedef  TYPE_1__ HTMLButtonElement ;
typedef  int /*<<< orphan*/  HRESULT ;

/* Variables and functions */
 int /*<<< orphan*/  IHTMLButtonElement_put_disabled (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_1__* button_from_HTMLDOMNode (int /*<<< orphan*/ *) ; 

__attribute__((used)) static HRESULT HTMLButtonElementImpl_put_disabled(HTMLDOMNode *iface, VARIANT_BOOL v)
{
    HTMLButtonElement *This = button_from_HTMLDOMNode(iface);
    return IHTMLButtonElement_put_disabled(&This->IHTMLButtonElement_iface, v);
}