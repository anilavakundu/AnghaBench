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
struct vaapi_pic_context {int /*<<< orphan*/  va_dpy; } ;
struct TYPE_4__ {scalar_t__ context; } ;
typedef  TYPE_1__ picture_t ;
typedef  int /*<<< orphan*/  VADisplay ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT_VAAPI_CHROMA (TYPE_1__*) ; 
 int /*<<< orphan*/  assert (scalar_t__) ; 

VADisplay
vlc_vaapi_PicGetDisplay(picture_t *pic)
{
    ASSERT_VAAPI_CHROMA(pic);
    assert(pic->context);

    struct vaapi_pic_context *pic_ctx = (struct vaapi_pic_context *)pic->context;
    return pic_ctx->va_dpy;
}