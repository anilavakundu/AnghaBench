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
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  normalize_path_copy (char*,char*) ; 
 scalar_t__ strlen (char*) ; 
 char* xmalloc (scalar_t__) ; 
 char* xstrfmt (char*,char const*,char const*) ; 

__attribute__((used)) static char *get_split_graph_filename(const char *obj_dir,
				      const char *oid_hex)
{
	char *filename = xstrfmt("%s/info/commit-graphs/graph-%s.graph",
				 obj_dir,
				 oid_hex);
	char *normalized = xmalloc(strlen(filename) + 1);
	normalize_path_copy(normalized, filename);
	free(filename);
	return normalized;
}