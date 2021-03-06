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
struct TYPE_3__ {int offset; int skip; } ;
struct TYPE_4__ {int /*<<< orphan*/  u64; TYPE_1__ s; } ;
typedef  TYPE_2__ cvmx_pip_bsel_ext_cfgx_t ;

/* Variables and functions */
 int /*<<< orphan*/  CVMX_PIP_BSEL_EXT_CFGX (int) ; 
 int /*<<< orphan*/  OCTEON_FEATURE_BIT_EXTRACTOR ; 
 int /*<<< orphan*/  cvmx_read_csr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cvmx_write_csr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  octeon_has_feature (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void cvmx_pip_bsel_config(int bit, int offset, int skip)
{
    cvmx_pip_bsel_ext_cfgx_t bsel_cfg;

    /* The bit select extractor is available in CN61XX and CN68XX pass2.0 onwards. */
    if (!octeon_has_feature(OCTEON_FEATURE_BIT_EXTRACTOR))
        return;

    bsel_cfg.u64 = cvmx_read_csr(CVMX_PIP_BSEL_EXT_CFGX(bit));
    bsel_cfg.s.offset = offset;
    bsel_cfg.s.skip = skip;
    cvmx_write_csr(CVMX_PIP_BSEL_EXT_CFGX(bit), bsel_cfg.u64);
}