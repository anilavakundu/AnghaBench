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
typedef  int /*<<< orphan*/  LZ4_stream_t ;

/* Variables and functions */
 int LZ4_compress_fast_extState (int /*<<< orphan*/ *,char const*,char*,int,int,int) ; 

int LZ4_compress_fast(const char* source, char* dest, int inputSize, int maxOutputSize, int acceleration) {
	LZ4_stream_t ctx;
	return LZ4_compress_fast_extState (&ctx, source, dest, inputSize, maxOutputSize, acceleration);
}