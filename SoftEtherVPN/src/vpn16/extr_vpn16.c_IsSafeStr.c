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
typedef  size_t UINT ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 scalar_t__ FALSE ; 
 scalar_t__ IsSafeChar (char) ; 
 scalar_t__ TRUE ; 
 size_t strlen (char*) ; 

BOOL IsSafeStr(char *str)
{
	UINT i, len;
	if (str == NULL)
	{
		return FALSE;
	}

	len = strlen(str);
	for (i = 0;i < len;i++)
	{
		if (IsSafeChar(str[i]) == FALSE)
		{
			return FALSE;
		}
	}
	if (str[0] == ' ')
	{
		return FALSE;
	}
	if (len != 0)
	{
		if (str[len - 1] == ' ')
		{
			return FALSE;
		}
	}
	return TRUE;
}