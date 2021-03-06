#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int /*<<< orphan*/  left; } ;
struct TYPE_7__ {int /*<<< orphan*/  left; } ;
struct TYPE_6__ {int /*<<< orphan*/  left; } ;
struct TYPE_9__ {TYPE_3__ margin; TYPE_2__ border; TYPE_1__ padding; } ;
typedef  TYPE_4__ widget ;

/* Variables and functions */
 int /*<<< orphan*/  ROFI_ORIENTATION_HORIZONTAL ; 
 int distance_get_pixel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int widget_padding_get_left ( const widget *wid )
{
    if ( wid == NULL ) {
        return 0;
    }
    int distance = distance_get_pixel ( wid->padding.left, ROFI_ORIENTATION_HORIZONTAL );
    distance += distance_get_pixel ( wid->border.left, ROFI_ORIENTATION_HORIZONTAL );
    distance += distance_get_pixel ( wid->margin.left, ROFI_ORIENTATION_HORIZONTAL );
    return distance;
}