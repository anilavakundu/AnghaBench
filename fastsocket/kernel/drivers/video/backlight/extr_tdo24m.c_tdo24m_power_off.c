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
struct tdo24m {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  lcd_panel_off ; 
 int tdo24m_writes (struct tdo24m*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tdo24m_power_off(struct tdo24m *lcd)
{
	return tdo24m_writes(lcd, lcd_panel_off);
}