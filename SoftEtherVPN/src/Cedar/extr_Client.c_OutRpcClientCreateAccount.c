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
struct TYPE_3__ {int /*<<< orphan*/  ShortcutKey; int /*<<< orphan*/ * ServerCert; int /*<<< orphan*/  RetryOnServerCert; int /*<<< orphan*/  CheckServerCert; int /*<<< orphan*/  StartupAccount; int /*<<< orphan*/  ClientAuth; int /*<<< orphan*/  ClientOption; } ;
typedef  TYPE_1__ RPC_CLIENT_CREATE_ACCOUNT ;
typedef  int /*<<< orphan*/  PACK ;
typedef  int /*<<< orphan*/  BUF ;

/* Variables and functions */
 int /*<<< orphan*/  FreeBuf (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  OutRpcClientAuth (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OutRpcClientOption (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PackAddBuf (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PackAddData (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  PackAddInt (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * XToBuf (int /*<<< orphan*/ *,int) ; 

void OutRpcClientCreateAccount(PACK *p, RPC_CLIENT_CREATE_ACCOUNT *c)
{
	BUF *b;
	// Validate arguments
	if (c == NULL || p == NULL)
	{
		return;
	}

	OutRpcClientOption(p, c->ClientOption);
	OutRpcClientAuth(p, c->ClientAuth);

	PackAddInt(p, "StartupAccount", c->StartupAccount);
	PackAddInt(p, "CheckServerCert", c->CheckServerCert);
	PackAddInt(p, "RetryOnServerCert", c->RetryOnServerCert);
	if (c->ServerCert != NULL)
	{
		b = XToBuf(c->ServerCert, false);
		if (b != NULL)
		{
			PackAddBuf(p, "ServerCert", b);
			FreeBuf(b);
		}
	}
	PackAddData(p, "ShortcutKey", c->ShortcutKey, sizeof(c->ShortcutKey));
}