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
struct ftp_wc {scalar_t__ parser; } ;

/* Variables and functions */
 int /*<<< orphan*/  Curl_ftp_parselist_data_free (scalar_t__*) ; 
 int /*<<< orphan*/  free (struct ftp_wc*) ; 

__attribute__((used)) static void wc_data_dtor(void *ptr)
{
  struct ftp_wc *ftpwc = ptr;
  if(ftpwc && ftpwc->parser)
    Curl_ftp_parselist_data_free(&ftpwc->parser);
  free(ftpwc);
}