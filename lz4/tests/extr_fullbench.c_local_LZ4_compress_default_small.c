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
 scalar_t__ LZ4_compressBound (int) ; 
 int LZ4_compress_default (char const*,char*,int,scalar_t__) ; 

__attribute__((used)) static int local_LZ4_compress_default_small(const char* in, char* out, int inSize)
{
    return LZ4_compress_default(in, out, inSize, LZ4_compressBound(inSize)-1);
}