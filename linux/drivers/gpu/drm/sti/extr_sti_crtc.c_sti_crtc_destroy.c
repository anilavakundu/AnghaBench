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
struct drm_crtc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG_KMS (char*) ; 
 int /*<<< orphan*/  drm_crtc_cleanup (struct drm_crtc*) ; 

__attribute__((used)) static void sti_crtc_destroy(struct drm_crtc *crtc)
{
	DRM_DEBUG_KMS("\n");
	drm_crtc_cleanup(crtc);
}