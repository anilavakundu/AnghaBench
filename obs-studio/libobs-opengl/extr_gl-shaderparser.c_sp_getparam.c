#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct shader_var {int /*<<< orphan*/  name; } ;
struct TYPE_3__ {size_t num; struct shader_var* array; } ;
struct TYPE_4__ {TYPE_1__ params; } ;
struct gl_shader_parser {TYPE_2__ parser; } ;
struct cf_token {int /*<<< orphan*/  str; } ;

/* Variables and functions */
 scalar_t__ strref_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct shader_var *sp_getparam(struct gl_shader_parser *glsp,
					     struct cf_token *token)
{
	size_t i;
	for (i = 0; i < glsp->parser.params.num; i++) {
		struct shader_var *param = glsp->parser.params.array + i;
		if (strref_cmp(&token->str, param->name) == 0)
			return param;
	}

	return NULL;
}