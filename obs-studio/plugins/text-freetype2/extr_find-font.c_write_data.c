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
struct serializer {int dummy; } ;

/* Variables and functions */
 size_t s_write (struct serializer*,void const*,size_t) ; 

__attribute__((used)) static inline bool write_data(struct serializer *s, const void *data,
			      size_t size)
{
	return s_write(s, data, size) == size;
}