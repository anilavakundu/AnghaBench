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
typedef  int /*<<< orphan*/  wint_t ;
struct parse {int dummy; } ;
typedef  int /*<<< orphan*/  cset ;

/* Variables and functions */
 int /*<<< orphan*/  CHadd (struct parse*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  p_b_coll_elem (struct parse*,char) ; 

__attribute__((used)) static void
p_b_eclass(struct parse *p, cset *cs)
{
	wint_t c;

	c = p_b_coll_elem(p, '=');
	CHadd(p, cs, c);
}