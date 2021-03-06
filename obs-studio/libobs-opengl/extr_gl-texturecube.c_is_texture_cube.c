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
struct TYPE_3__ {scalar_t__ type; } ;
typedef  TYPE_1__ gs_texture_t ;

/* Variables and functions */
 scalar_t__ GS_TEXTURE_CUBE ; 
 int /*<<< orphan*/  LOG_ERROR ; 
 int /*<<< orphan*/  blog (int /*<<< orphan*/ ,char*,char const*) ; 

__attribute__((used)) static inline bool is_texture_cube(const gs_texture_t *tex, const char *func)
{
	bool is_texcube = tex->type == GS_TEXTURE_CUBE;
	if (!is_texcube)
		blog(LOG_ERROR, "%s (GL) failed:  Not a cubemap texture", func);
	return is_texcube;
}