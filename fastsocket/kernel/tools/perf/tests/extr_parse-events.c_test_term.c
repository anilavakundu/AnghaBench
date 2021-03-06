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
struct test__term {int (* check ) (struct list_head*) ;int /*<<< orphan*/  str; } ;
struct list_head {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (struct list_head*) ; 
 struct list_head* malloc (int) ; 
 int /*<<< orphan*/  parse_events__free_terms (struct list_head*) ; 
 int parse_events_terms (struct list_head*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ,int) ; 
 int stub1 (struct list_head*) ; 

__attribute__((used)) static int test_term(struct test__term *t)
{
	struct list_head *terms;
	int ret;

	terms = malloc(sizeof(*terms));
	if (!terms)
		return -ENOMEM;

	INIT_LIST_HEAD(terms);

	ret = parse_events_terms(terms, t->str);
	if (ret) {
		pr_debug("failed to parse terms '%s', err %d\n",
			 t->str , ret);
		return ret;
	}

	ret = t->check(terms);
	parse_events__free_terms(terms);

	return ret;
}