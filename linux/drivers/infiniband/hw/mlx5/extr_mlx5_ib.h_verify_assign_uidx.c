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
typedef  scalar_t__ u8 ;
typedef  int u32 ;

/* Variables and functions */
 int EINVAL ; 
 int MLX5_IB_DEFAULT_UIDX ; 
 int MLX5_USER_ASSIGNED_UIDX_MASK ; 

__attribute__((used)) static inline int verify_assign_uidx(u8 cqe_version, u32 cmd_uidx,
				     u32 *user_index)
{
	if (cqe_version) {
		if ((cmd_uidx == MLX5_IB_DEFAULT_UIDX) ||
		    (cmd_uidx & ~MLX5_USER_ASSIGNED_UIDX_MASK))
			return -EINVAL;
		*user_index = cmd_uidx;
	} else {
		*user_index = MLX5_IB_DEFAULT_UIDX;
	}

	return 0;
}