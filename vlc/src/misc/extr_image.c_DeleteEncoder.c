#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  fmt_out; int /*<<< orphan*/  fmt_in; scalar_t__ p_module; } ;
typedef  TYPE_1__ encoder_t ;

/* Variables and functions */
 int /*<<< orphan*/  es_format_Clean (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  module_unneed (TYPE_1__*,scalar_t__) ; 
 int /*<<< orphan*/  vlc_object_delete (TYPE_1__*) ; 

__attribute__((used)) static void DeleteEncoder( encoder_t * p_enc )
{
    if( p_enc->p_module ) module_unneed( p_enc, p_enc->p_module );

    es_format_Clean( &p_enc->fmt_in );
    es_format_Clean( &p_enc->fmt_out );

    vlc_object_delete(p_enc);
}