#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  peer; } ;
typedef  TYPE_1__ SSL_SESSION ;

/* Variables and functions */
 int /*<<< orphan*/  X509_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ssl_mem_free (TYPE_1__*) ; 

__attribute__((used)) static void SSL_SESSION_free(SSL_SESSION *session)
{
    X509_free(session->peer);
    ssl_mem_free(session);
}