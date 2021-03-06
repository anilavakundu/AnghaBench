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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
struct amdgpu_device {int cg_flags; } ;

/* Variables and functions */
 int AMD_CG_SUPPORT_VCN_MGCG ; 
 int /*<<< orphan*/  SOC15_DPG_MODE_OFFSET_2_0 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UVD ; 
 int UVD_CGC_CTRL__CLK_GATE_DLY_TIMER__SHIFT ; 
 int UVD_CGC_CTRL__CLK_OFF_DELAY__SHIFT ; 
 int UVD_CGC_CTRL__DYN_CLOCK_MODE__SHIFT ; 
 int UVD_CGC_CTRL__IDCT_MODE_MASK ; 
 int UVD_CGC_CTRL__LBSI_MODE_MASK ; 
 int UVD_CGC_CTRL__LMI_MC_MODE_MASK ; 
 int UVD_CGC_CTRL__LMI_UMC_MODE_MASK ; 
 int UVD_CGC_CTRL__LRBBM_MODE_MASK ; 
 int UVD_CGC_CTRL__MPC_MODE_MASK ; 
 int UVD_CGC_CTRL__MPEG2_MODE_MASK ; 
 int UVD_CGC_CTRL__MPRD_MODE_MASK ; 
 int UVD_CGC_CTRL__RBC_MODE_MASK ; 
 int UVD_CGC_CTRL__REGS_MODE_MASK ; 
 int UVD_CGC_CTRL__SCPU_MODE_MASK ; 
 int UVD_CGC_CTRL__SYS_MODE_MASK ; 
 int UVD_CGC_CTRL__UDEC_CM_MODE_MASK ; 
 int UVD_CGC_CTRL__UDEC_DB_MODE_MASK ; 
 int UVD_CGC_CTRL__UDEC_IT_MODE_MASK ; 
 int UVD_CGC_CTRL__UDEC_MODE_MASK ; 
 int UVD_CGC_CTRL__UDEC_MP_MODE_MASK ; 
 int UVD_CGC_CTRL__UDEC_RE_MODE_MASK ; 
 int UVD_CGC_CTRL__VCPU_MODE_MASK ; 
 int UVD_CGC_CTRL__WCB_MODE_MASK ; 
 int /*<<< orphan*/  WREG32_SOC15_DPG_MODE_2_0 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmUVD_CGC_CTRL ; 
 int /*<<< orphan*/  mmUVD_CGC_GATE ; 
 int /*<<< orphan*/  mmUVD_SUVD_CGC_CTRL ; 
 int /*<<< orphan*/  mmUVD_SUVD_CGC_GATE ; 

__attribute__((used)) static void vcn_v2_0_clock_gating_dpg_mode(struct amdgpu_device *adev,
		uint8_t sram_sel, uint8_t indirect)
{
	uint32_t reg_data = 0;

	/* enable sw clock gating control */
	if (adev->cg_flags & AMD_CG_SUPPORT_VCN_MGCG)
		reg_data = 1 << UVD_CGC_CTRL__DYN_CLOCK_MODE__SHIFT;
	else
		reg_data = 0 << UVD_CGC_CTRL__DYN_CLOCK_MODE__SHIFT;
	reg_data |= 1 << UVD_CGC_CTRL__CLK_GATE_DLY_TIMER__SHIFT;
	reg_data |= 4 << UVD_CGC_CTRL__CLK_OFF_DELAY__SHIFT;
	reg_data &= ~(UVD_CGC_CTRL__UDEC_RE_MODE_MASK |
		 UVD_CGC_CTRL__UDEC_CM_MODE_MASK |
		 UVD_CGC_CTRL__UDEC_IT_MODE_MASK |
		 UVD_CGC_CTRL__UDEC_DB_MODE_MASK |
		 UVD_CGC_CTRL__UDEC_MP_MODE_MASK |
		 UVD_CGC_CTRL__SYS_MODE_MASK |
		 UVD_CGC_CTRL__UDEC_MODE_MASK |
		 UVD_CGC_CTRL__MPEG2_MODE_MASK |
		 UVD_CGC_CTRL__REGS_MODE_MASK |
		 UVD_CGC_CTRL__RBC_MODE_MASK |
		 UVD_CGC_CTRL__LMI_MC_MODE_MASK |
		 UVD_CGC_CTRL__LMI_UMC_MODE_MASK |
		 UVD_CGC_CTRL__IDCT_MODE_MASK |
		 UVD_CGC_CTRL__MPRD_MODE_MASK |
		 UVD_CGC_CTRL__MPC_MODE_MASK |
		 UVD_CGC_CTRL__LBSI_MODE_MASK |
		 UVD_CGC_CTRL__LRBBM_MODE_MASK |
		 UVD_CGC_CTRL__WCB_MODE_MASK |
		 UVD_CGC_CTRL__VCPU_MODE_MASK |
		 UVD_CGC_CTRL__SCPU_MODE_MASK);
	WREG32_SOC15_DPG_MODE_2_0(SOC15_DPG_MODE_OFFSET_2_0(
		UVD, 0, mmUVD_CGC_CTRL), reg_data, sram_sel, indirect);

	/* turn off clock gating */
	WREG32_SOC15_DPG_MODE_2_0(SOC15_DPG_MODE_OFFSET_2_0(
		UVD, 0, mmUVD_CGC_GATE), 0, sram_sel, indirect);

	/* turn on SUVD clock gating */
	WREG32_SOC15_DPG_MODE_2_0(SOC15_DPG_MODE_OFFSET_2_0(
		UVD, 0, mmUVD_SUVD_CGC_GATE), 1, sram_sel, indirect);

	/* turn on sw mode in UVD_SUVD_CGC_CTRL */
	WREG32_SOC15_DPG_MODE_2_0(SOC15_DPG_MODE_OFFSET_2_0(
		UVD, 0, mmUVD_SUVD_CGC_CTRL), 0, sram_sel, indirect);
}