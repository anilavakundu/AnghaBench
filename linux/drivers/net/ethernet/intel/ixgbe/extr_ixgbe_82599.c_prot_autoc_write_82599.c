#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_3__ {int /*<<< orphan*/  (* release_swfw_sync ) (struct ixgbe_hw*,int /*<<< orphan*/ ) ;scalar_t__ (* acquire_swfw_sync ) (struct ixgbe_hw*,int /*<<< orphan*/ ) ;} ;
struct TYPE_4__ {TYPE_1__ ops; } ;
struct ixgbe_hw {TYPE_2__ mac; } ;
typedef  scalar_t__ s32 ;

/* Variables and functions */
 int /*<<< orphan*/  IXGBE_AUTOC ; 
 scalar_t__ IXGBE_ERR_SWFW_SYNC ; 
 int /*<<< orphan*/  IXGBE_GSSR_MAC_CSR_SM ; 
 int /*<<< orphan*/  IXGBE_WRITE_REG (struct ixgbe_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ ixgbe_check_reset_blocked (struct ixgbe_hw*) ; 
 scalar_t__ ixgbe_reset_pipeline_82599 (struct ixgbe_hw*) ; 
 scalar_t__ ixgbe_verify_lesm_fw_enabled_82599 (struct ixgbe_hw*) ; 
 scalar_t__ stub1 (struct ixgbe_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (struct ixgbe_hw*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static s32 prot_autoc_write_82599(struct ixgbe_hw *hw, u32 autoc, bool locked)
{
	s32 ret_val = 0;

	/* Blocked by MNG FW so bail */
	if (ixgbe_check_reset_blocked(hw))
		goto out;

	/* We only need to get the lock if:
	 *  - We didn't do it already (in the read part of a read-modify-write)
	 *  - LESM is enabled.
	 */
	if (!locked && ixgbe_verify_lesm_fw_enabled_82599(hw)) {
		ret_val = hw->mac.ops.acquire_swfw_sync(hw,
					IXGBE_GSSR_MAC_CSR_SM);
		if (ret_val)
			return IXGBE_ERR_SWFW_SYNC;

		locked = true;
	}

	IXGBE_WRITE_REG(hw, IXGBE_AUTOC, autoc);
	ret_val = ixgbe_reset_pipeline_82599(hw);

out:
	/* Free the SW/FW semaphore as we either grabbed it here or
	 * already had it when this function was called.
	 */
	if (locked)
		hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_MAC_CSR_SM);

	return ret_val;
}