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
struct obs_data_item {int dummy; } ;
typedef  int /*<<< orphan*/  obs_data_array_t ;

/* Variables and functions */
 scalar_t__ get_item_data (struct obs_data_item*) ; 

__attribute__((used)) static inline obs_data_array_t *get_item_array(struct obs_data_item *item)
{
	obs_data_array_t **array;

	if (!item)
		return NULL;

	array = (obs_data_array_t **)get_item_data(item);
	return array ? *array : NULL;
}