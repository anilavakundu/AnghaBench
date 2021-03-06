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

/* Variables and functions */
 unsigned int MAX_USERS ; 
 scalar_t__ wpad_ready ; 

__attribute__((used)) static bool wpad_query_pad(unsigned pad)
{
   return wpad_ready && pad < MAX_USERS;
}