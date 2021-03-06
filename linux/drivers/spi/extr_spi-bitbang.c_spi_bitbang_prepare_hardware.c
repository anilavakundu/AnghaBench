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
struct spi_master {int dummy; } ;
struct spi_bitbang {int busy; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct spi_bitbang* spi_master_get_devdata (struct spi_master*) ; 

__attribute__((used)) static int spi_bitbang_prepare_hardware(struct spi_master *spi)
{
	struct spi_bitbang	*bitbang;

	bitbang = spi_master_get_devdata(spi);

	mutex_lock(&bitbang->lock);
	bitbang->busy = 1;
	mutex_unlock(&bitbang->lock);

	return 0;
}