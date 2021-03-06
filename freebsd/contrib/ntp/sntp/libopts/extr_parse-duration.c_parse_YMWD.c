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
typedef  scalar_t__ time_t ;
typedef  scalar_t__ cch_t ;

/* Variables and functions */
 scalar_t__ BAD_TIME ; 
 int /*<<< orphan*/  EINVAL ; 
 scalar_t__ NUL ; 
 int /*<<< orphan*/  SEC_PER_DAY ; 
 int /*<<< orphan*/  SEC_PER_MONTH ; 
 int /*<<< orphan*/  SEC_PER_WEEK ; 
 int /*<<< orphan*/  SEC_PER_YEAR ; 
 int /*<<< orphan*/  errno ; 
 scalar_t__ isspace (unsigned char) ; 
 scalar_t__ parse_scaled_value (scalar_t__,scalar_t__**,scalar_t__*,int /*<<< orphan*/ ) ; 
 scalar_t__* strchr (scalar_t__*,char) ; 

__attribute__((used)) static time_t
parse_YMWD (cch_t * pz)
{
  time_t res = 0;
  cch_t * ps = strchr (pz, 'Y');
  if (ps != NULL)
    {
      res = parse_scaled_value (0, &pz, ps, SEC_PER_YEAR);
      pz++;
    }

  ps = strchr (pz, 'M');
  if (ps != NULL)
    {
      res = parse_scaled_value (res, &pz, ps, SEC_PER_MONTH);
      pz++;
    }

  ps = strchr (pz, 'W');
  if (ps != NULL)
    {
      res = parse_scaled_value (res, &pz, ps, SEC_PER_WEEK);
      pz++;
    }

  ps = strchr (pz, 'D');
  if (ps != NULL)
    {
      res = parse_scaled_value (res, &pz, ps, SEC_PER_DAY);
      pz++;
    }

  while (isspace ((unsigned char)*pz))
    pz++;
  if (*pz != NUL)
    {
      errno = EINVAL;
      return BAD_TIME;
    }

  return res;
}