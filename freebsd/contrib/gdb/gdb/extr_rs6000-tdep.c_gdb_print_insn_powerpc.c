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
typedef  int /*<<< orphan*/  disassemble_info ;
typedef  int /*<<< orphan*/  bfd_vma ;

/* Variables and functions */
 scalar_t__ BFD_ENDIAN_BIG ; 
 scalar_t__ TARGET_BYTE_ORDER ; 
 int print_insn_big_powerpc (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int print_insn_little_powerpc (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
gdb_print_insn_powerpc (bfd_vma memaddr, disassemble_info *info)
{
  if (TARGET_BYTE_ORDER == BFD_ENDIAN_BIG)
    return print_insn_big_powerpc (memaddr, info);
  else
    return print_insn_little_powerpc (memaddr, info);
}