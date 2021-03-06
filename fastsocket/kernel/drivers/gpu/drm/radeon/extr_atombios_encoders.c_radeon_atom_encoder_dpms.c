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
struct radeon_encoder {int encoder_id; int /*<<< orphan*/  active_device; int /*<<< orphan*/  devices; } ;
struct radeon_device {int dummy; } ;
struct drm_encoder {struct drm_device* dev; } ;
struct drm_device {struct radeon_device* dev_private; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASIC_IS_DCE3 (struct radeon_device*) ; 
 int /*<<< orphan*/  ASIC_IS_DCE5 (struct radeon_device*) ; 
 int /*<<< orphan*/  ATOM_DISABLE ; 
 int /*<<< orphan*/  ATOM_ENABLE ; 
 int /*<<< orphan*/  DRM_DEBUG_KMS (char*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
#define  DRM_MODE_DPMS_OFF 146 
#define  DRM_MODE_DPMS_ON 145 
#define  DRM_MODE_DPMS_STANDBY 144 
#define  DRM_MODE_DPMS_SUSPEND 143 
#define  ENCODER_OBJECT_ID_INTERNAL_DAC1 142 
#define  ENCODER_OBJECT_ID_INTERNAL_DAC2 141 
#define  ENCODER_OBJECT_ID_INTERNAL_DDI 140 
#define  ENCODER_OBJECT_ID_INTERNAL_DVO1 139 
#define  ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC1 138 
#define  ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC2 137 
#define  ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DVO1 136 
#define  ENCODER_OBJECT_ID_INTERNAL_KLDSCP_LVTMA 135 
#define  ENCODER_OBJECT_ID_INTERNAL_KLDSCP_TMDS1 134 
#define  ENCODER_OBJECT_ID_INTERNAL_LVDS 133 
#define  ENCODER_OBJECT_ID_INTERNAL_LVTM1 132 
#define  ENCODER_OBJECT_ID_INTERNAL_TMDS1 131 
#define  ENCODER_OBJECT_ID_INTERNAL_UNIPHY 130 
#define  ENCODER_OBJECT_ID_INTERNAL_UNIPHY1 129 
#define  ENCODER_OBJECT_ID_INTERNAL_UNIPHY2 128 
 int /*<<< orphan*/  atombios_dac_setup (struct drm_encoder*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atombios_dvo_setup (struct drm_encoder*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  radeon_atom_encoder_dpms_avivo (struct drm_encoder*,int) ; 
 int /*<<< orphan*/  radeon_atom_encoder_dpms_dig (struct drm_encoder*,int) ; 
 int /*<<< orphan*/  radeon_atom_encoder_dpms_ext (struct drm_encoder*,struct drm_encoder*,int) ; 
 int /*<<< orphan*/  radeon_atombios_encoder_dpms_scratch_regs (struct drm_encoder*,int) ; 
 struct drm_encoder* radeon_get_external_encoder (struct drm_encoder*) ; 
 struct radeon_encoder* to_radeon_encoder (struct drm_encoder*) ; 

__attribute__((used)) static void
radeon_atom_encoder_dpms(struct drm_encoder *encoder, int mode)
{
	struct drm_device *dev = encoder->dev;
	struct radeon_device *rdev = dev->dev_private;
	struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
	struct drm_encoder *ext_encoder = radeon_get_external_encoder(encoder);

	DRM_DEBUG_KMS("encoder dpms %d to mode %d, devices %08x, active_devices %08x\n",
		  radeon_encoder->encoder_id, mode, radeon_encoder->devices,
		  radeon_encoder->active_device);
	switch (radeon_encoder->encoder_id) {
	case ENCODER_OBJECT_ID_INTERNAL_TMDS1:
	case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_TMDS1:
	case ENCODER_OBJECT_ID_INTERNAL_LVDS:
	case ENCODER_OBJECT_ID_INTERNAL_LVTM1:
	case ENCODER_OBJECT_ID_INTERNAL_DVO1:
	case ENCODER_OBJECT_ID_INTERNAL_DDI:
	case ENCODER_OBJECT_ID_INTERNAL_DAC2:
	case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC2:
		radeon_atom_encoder_dpms_avivo(encoder, mode);
		break;
	case ENCODER_OBJECT_ID_INTERNAL_UNIPHY:
	case ENCODER_OBJECT_ID_INTERNAL_UNIPHY1:
	case ENCODER_OBJECT_ID_INTERNAL_UNIPHY2:
	case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_LVTMA:
		radeon_atom_encoder_dpms_dig(encoder, mode);
		break;
	case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DVO1:
		if (ASIC_IS_DCE5(rdev)) {
			switch (mode) {
			case DRM_MODE_DPMS_ON:
				atombios_dvo_setup(encoder, ATOM_ENABLE);
				break;
			case DRM_MODE_DPMS_STANDBY:
			case DRM_MODE_DPMS_SUSPEND:
			case DRM_MODE_DPMS_OFF:
				atombios_dvo_setup(encoder, ATOM_DISABLE);
				break;
			}
		} else if (ASIC_IS_DCE3(rdev))
			radeon_atom_encoder_dpms_dig(encoder, mode);
		else
			radeon_atom_encoder_dpms_avivo(encoder, mode);
		break;
	case ENCODER_OBJECT_ID_INTERNAL_DAC1:
	case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC1:
		if (ASIC_IS_DCE5(rdev)) {
			switch (mode) {
			case DRM_MODE_DPMS_ON:
				atombios_dac_setup(encoder, ATOM_ENABLE);
				break;
			case DRM_MODE_DPMS_STANDBY:
			case DRM_MODE_DPMS_SUSPEND:
			case DRM_MODE_DPMS_OFF:
				atombios_dac_setup(encoder, ATOM_DISABLE);
				break;
			}
		} else
			radeon_atom_encoder_dpms_avivo(encoder, mode);
		break;
	default:
		return;
	}

	if (ext_encoder)
		radeon_atom_encoder_dpms_ext(encoder, ext_encoder, mode);

	radeon_atombios_encoder_dpms_scratch_regs(encoder, (mode == DRM_MODE_DPMS_ON) ? true : false);

}