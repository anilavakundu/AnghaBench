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
typedef  int u32 ;
struct tipc_msg {int dummy; } ;

/* Variables and functions */
 int msg_word (struct tipc_msg*,int) ; 

__attribute__((used)) static inline u32 msg_bits(struct tipc_msg *m, u32 w, u32 pos, u32 mask)
{
	return (msg_word(m, w) >> pos) & mask;
}