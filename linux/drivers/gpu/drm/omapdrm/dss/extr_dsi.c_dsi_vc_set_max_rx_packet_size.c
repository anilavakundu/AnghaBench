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
typedef  int /*<<< orphan*/  u16 ;
struct omap_dss_device {int dummy; } ;
struct dsi_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MIPI_DSI_SET_MAXIMUM_RETURN_PACKET_SIZE ; 
 int dsi_vc_send_short (struct dsi_data*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct dsi_data* to_dsi_data (struct omap_dss_device*) ; 

__attribute__((used)) static int dsi_vc_set_max_rx_packet_size(struct omap_dss_device *dssdev, int channel,
		u16 len)
{
	struct dsi_data *dsi = to_dsi_data(dssdev);

	return dsi_vc_send_short(dsi, channel,
			MIPI_DSI_SET_MAXIMUM_RETURN_PACKET_SIZE, len, 0);
}