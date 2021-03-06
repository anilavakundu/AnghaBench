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
struct ipu_dmfc_priv {int /*<<< orphan*/  mutex; int /*<<< orphan*/  use_count; int /*<<< orphan*/  ipu; } ;
struct dmfc_channel {struct ipu_dmfc_priv* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  IPU_CONF_DMFC_EN ; 
 int /*<<< orphan*/  ipu_module_enable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

int ipu_dmfc_enable_channel(struct dmfc_channel *dmfc)
{
	struct ipu_dmfc_priv *priv = dmfc->priv;
	mutex_lock(&priv->mutex);

	if (!priv->use_count)
		ipu_module_enable(priv->ipu, IPU_CONF_DMFC_EN);

	priv->use_count++;

	mutex_unlock(&priv->mutex);

	return 0;
}