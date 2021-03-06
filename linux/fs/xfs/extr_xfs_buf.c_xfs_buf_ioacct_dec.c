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
struct xfs_buf {int /*<<< orphan*/  b_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  __xfs_buf_ioacct_dec (struct xfs_buf*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void
xfs_buf_ioacct_dec(
	struct xfs_buf	*bp)
{
	spin_lock(&bp->b_lock);
	__xfs_buf_ioacct_dec(bp);
	spin_unlock(&bp->b_lock);
}