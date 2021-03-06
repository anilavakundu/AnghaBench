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
typedef  int /*<<< orphan*/  wchar_t ;
typedef  int /*<<< orphan*/  SID_NAME_USE ;
typedef  int /*<<< orphan*/ * PWSTR ;
typedef  int /*<<< orphan*/ * PSID_NAME_USE ;
typedef  int /*<<< orphan*/  PSID ;
typedef  int /*<<< orphan*/  LPCWSTR ;
typedef  int DWORD ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 scalar_t__ ERROR_INSUFFICIENT_BUFFER ; 
 scalar_t__ FALSE ; 
 scalar_t__ GetLastError () ; 
 int /*<<< orphan*/  LPTR ; 
 scalar_t__ LocalAlloc (int /*<<< orphan*/ ,int) ; 
 scalar_t__ LocalFree (int /*<<< orphan*/ *) ; 
 scalar_t__ LookupAccountSid (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int*,int /*<<< orphan*/ *,int*,int /*<<< orphan*/ *) ; 

BOOL kull_m_token_getNameDomainFromSID(PSID pSid, PWSTR * pName, PWSTR * pDomain, PSID_NAME_USE pSidNameUse, LPCWSTR system)
{
	BOOL result = FALSE;
	SID_NAME_USE sidNameUse;
	PSID_NAME_USE peUse = pSidNameUse ? pSidNameUse : &sidNameUse;
	DWORD cchName = 0, cchReferencedDomainName = 0;
	
	if(!LookupAccountSid(system, pSid, NULL, &cchName, NULL, &cchReferencedDomainName, peUse) && (GetLastError() == ERROR_INSUFFICIENT_BUFFER))
	{
		if(*pName = (PWSTR) LocalAlloc(LPTR, cchName * sizeof(wchar_t)))
		{
			if(*pDomain = (PWSTR) LocalAlloc(LPTR, cchReferencedDomainName * sizeof(wchar_t)))
			{
				result = LookupAccountSid(system, pSid, *pName, &cchName, *pDomain, &cchReferencedDomainName, peUse);
				if(!result)
					*pDomain = (PWSTR) LocalFree(*pDomain);
			}
			if(!result)
				*pName = (PWSTR) LocalFree(*pName);
		}
	}
	return result;
}