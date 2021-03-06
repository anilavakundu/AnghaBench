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

/* Variables and functions */
 char* _fdt_find_string (char*,int,char const*) ; 
 int fdt_off_dt_struct (void*) ; 
 int /*<<< orphan*/  fdt_set_size_dt_strings (void*,int) ; 
 int fdt_size_dt_strings (void*) ; 
 int fdt_size_dt_struct (void*) ; 
 int fdt_totalsize (void*) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,int) ; 
 int strlen (char const*) ; 

__attribute__((used)) static int _fdt_find_add_string(void *fdt, const char *s)
{
	char *strtab = (char *)fdt + fdt_totalsize(fdt);
	const char *p;
	int strtabsize = fdt_size_dt_strings(fdt);
	int len = strlen(s) + 1;
	int struct_top, offset;

	p = _fdt_find_string(strtab - strtabsize, strtabsize, s);
	if (p)
		return p - strtab;

	/* Add it */
	offset = -strtabsize - len;
	struct_top = fdt_off_dt_struct(fdt) + fdt_size_dt_struct(fdt);
	if (fdt_totalsize(fdt) + offset < struct_top)
		return 0; /* no more room :( */

	memcpy(strtab + offset, s, len);
	fdt_set_size_dt_strings(fdt, strtabsize + len);
	return offset;
}