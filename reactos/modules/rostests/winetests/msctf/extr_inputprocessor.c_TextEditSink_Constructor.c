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
struct TYPE_6__ {int /*<<< orphan*/ * lpVtbl; } ;
struct TYPE_5__ {int refCount; TYPE_2__ ITfTextEditSink_iface; } ;
typedef  TYPE_1__ TextEditSink ;
typedef  TYPE_2__ ITfTextEditSink ;
typedef  int /*<<< orphan*/  HRESULT ;

/* Variables and functions */
 int /*<<< orphan*/  E_OUTOFMEMORY ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 TYPE_1__* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  S_OK ; 
 int /*<<< orphan*/  TextEditSink_TextEditSinkVtbl ; 

__attribute__((used)) static HRESULT TextEditSink_Constructor(ITfTextEditSink **ppOut)
{
    TextEditSink *This;

    *ppOut = NULL;
    This = HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(TextEditSink));
    if (This == NULL)
        return E_OUTOFMEMORY;

    This->ITfTextEditSink_iface.lpVtbl = &TextEditSink_TextEditSinkVtbl;
    This->refCount = 1;

    *ppOut = &This->ITfTextEditSink_iface;
    return S_OK;
}