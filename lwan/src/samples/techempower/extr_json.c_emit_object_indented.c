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
struct TYPE_5__ {TYPE_2__* head; } ;
struct TYPE_6__ {struct TYPE_6__* next; int /*<<< orphan*/  key; TYPE_1__ children; } ;
typedef  int /*<<< orphan*/  SB ;
typedef  TYPE_2__ JsonNode ;

/* Variables and functions */
 int /*<<< orphan*/  emit_string (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emit_value_indented (int /*<<< orphan*/ *,TYPE_2__ const*,char const*,int) ; 
 int /*<<< orphan*/  sb_putc (int /*<<< orphan*/ *,char) ; 
 int /*<<< orphan*/  sb_puts (int /*<<< orphan*/ *,char const*) ; 

__attribute__((used)) static void emit_object_indented(SB *out, const JsonNode *object, const char *space, int indent_level)
{
	const JsonNode *member = object->children.head;
	int i;
	
	if (member == NULL) {
		sb_puts(out, "{}");
		return;
	}
	
	sb_puts(out, "{\n");
	while (member != NULL) {
		for (i = 0; i < indent_level + 1; i++)
			sb_puts(out, space);
		emit_string(out, member->key);
		sb_puts(out, ": ");
		emit_value_indented(out, member, space, indent_level + 1);
		
		member = member->next;
		sb_puts(out, member != NULL ? ",\n" : "\n");
	}
	for (i = 0; i < indent_level; i++)
		sb_puts(out, space);
	sb_putc(out, '}');
}