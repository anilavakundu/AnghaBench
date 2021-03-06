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
typedef  int /*<<< orphan*/  AVIOContext ;

/* Variables and functions */
 int /*<<< orphan*/  put_s (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  put_str (int /*<<< orphan*/ *,char const*) ; 

__attribute__((used)) static int add_info(AVIOContext *bc, const char *type, const char *value)
{
    put_str(bc, type);
    put_s(bc, -1);
    put_str(bc, value);
    return 1;
}