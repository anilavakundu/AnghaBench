#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  gb; int /*<<< orphan*/ ** temp; } ;
typedef  TYPE_1__ HYuvContext ;

/* Variables and functions */
 scalar_t__ BITS_LEFT (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CLOSE_READER (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  OPEN_READER (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  READ_2PIX (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int get_bits_left (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  re ; 

__attribute__((used)) static void decode_gray_bitstream(HYuvContext *s, int count)
{
    int i;
    OPEN_READER(re, &s->gb);
    count /= 2;

    if (count >= (get_bits_left(&s->gb)) / (32 * 2)) {
        for (i = 0; i < count && BITS_LEFT(re, &s->gb) > 0; i++) {
            READ_2PIX(s->temp[0][2 * i], s->temp[0][2 * i + 1], 0);
        }
    } else {
        for (i = 0; i < count; i++) {
            READ_2PIX(s->temp[0][2 * i], s->temp[0][2 * i + 1], 0);
        }
    }
    CLOSE_READER(re, &s->gb);
}