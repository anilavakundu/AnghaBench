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
 int /*<<< orphan*/  IS_HIGHBIT_SET (int) ; 
 int LC_KS5601 ; 
 int /*<<< orphan*/  PG_EUC_KR ; 
 int /*<<< orphan*/  PG_MULE_INTERNAL ; 
 int pg_encoding_verifymb (int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/  report_invalid_encoding (int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/  report_untranslatable_char (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int) ; 

__attribute__((used)) static void
mic2euc_kr(const unsigned char *mic, unsigned char *p, int len)
{
	int			c1;
	int			l;

	while (len > 0)
	{
		c1 = *mic;
		if (!IS_HIGHBIT_SET(c1))
		{
			/* ASCII */
			if (c1 == 0)
				report_invalid_encoding(PG_MULE_INTERNAL,
										(const char *) mic, len);
			*p++ = c1;
			mic++;
			len--;
			continue;
		}
		l = pg_encoding_verifymb(PG_MULE_INTERNAL, (const char *) mic, len);
		if (l < 0)
			report_invalid_encoding(PG_MULE_INTERNAL,
									(const char *) mic, len);
		if (c1 == LC_KS5601)
		{
			*p++ = mic[1];
			*p++ = mic[2];
		}
		else
			report_untranslatable_char(PG_MULE_INTERNAL, PG_EUC_KR,
									   (const char *) mic, len);
		mic += l;
		len -= l;
	}
	*p = '\0';
}