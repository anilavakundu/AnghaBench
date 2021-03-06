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
typedef  int /*<<< orphan*/  uint32_t ;
struct kernel_param {int dummy; } ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (char*) ; 
 int /*<<< orphan*/  kill_final_newline (char*) ; 
 int /*<<< orphan*/  parse_err (char*) ; 
 int parse_name (char**,char*) ; 
 int parse_num32 (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  pr_info (char*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int register_device (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 int strnlen (char const*,int) ; 
 char* strsep (char**,char*) ; 

__attribute__((used)) static int phram_setup(const char *val, struct kernel_param *kp)
{
	char buf[64+12+12], *str = buf;
	char *token[3];
	char *name;
	uint32_t start;
	uint32_t len;
	int i, ret;

	if (strnlen(val, sizeof(buf)) >= sizeof(buf))
		parse_err("parameter too long\n");

	strcpy(str, val);
	kill_final_newline(str);

	for (i=0; i<3; i++)
		token[i] = strsep(&str, ",");

	if (str)
		parse_err("too many arguments\n");

	if (!token[2])
		parse_err("not enough arguments\n");

	ret = parse_name(&name, token[0]);
	if (ret)
		return ret;

	ret = parse_num32(&start, token[1]);
	if (ret) {
		kfree(name);
		parse_err("illegal start address\n");
	}

	ret = parse_num32(&len, token[2]);
	if (ret) {
		kfree(name);
		parse_err("illegal device length\n");
	}

	ret = register_device(name, start, len);
	if (!ret)
		pr_info("%s device: %#x at %#x\n", name, len, start);

	return ret;
}