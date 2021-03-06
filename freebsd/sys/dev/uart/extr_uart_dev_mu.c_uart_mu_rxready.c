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
struct uart_bas {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AUX_MU_LSR_REG ; 
 int LSR_RXREADY ; 
 int __uart_getreg (struct uart_bas*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
uart_mu_rxready(struct uart_bas *bas)
{

	return ((__uart_getreg(bas, AUX_MU_LSR_REG) & LSR_RXREADY) != 0);
}