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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct nand_ecc_ctrl {int size; int bytes; } ;
struct nand_chip {int /*<<< orphan*/ * oob_poi; int /*<<< orphan*/  cur_cs; struct nand_ecc_ctrl ecc; } ;
struct mtd_info {scalar_t__ writesize; } ;

/* Variables and functions */
 int DIV_ROUND_UP (int,int) ; 
 int /*<<< orphan*/  nand_prog_page_begin_op (struct nand_chip*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int nand_prog_page_end_op (struct nand_chip*) ; 
 struct mtd_info* nand_to_mtd (struct nand_chip*) ; 
 int /*<<< orphan*/  sunxi_nfc_hw_ecc_disable (struct nand_chip*) ; 
 int /*<<< orphan*/  sunxi_nfc_hw_ecc_enable (struct nand_chip*) ; 
 int sunxi_nfc_hw_ecc_write_chunk (struct nand_chip*,int /*<<< orphan*/  const*,int,int /*<<< orphan*/  const*,scalar_t__,int*,int,int) ; 
 int /*<<< orphan*/  sunxi_nfc_select_chip (struct nand_chip*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int sunxi_nfc_hw_ecc_write_subpage(struct nand_chip *nand,
					  u32 data_offs, u32 data_len,
					  const u8 *buf, int oob_required,
					  int page)
{
	struct mtd_info *mtd = nand_to_mtd(nand);
	struct nand_ecc_ctrl *ecc = &nand->ecc;
	int ret, i, cur_off = 0;

	sunxi_nfc_select_chip(nand, nand->cur_cs);

	nand_prog_page_begin_op(nand, page, 0, NULL, 0);

	sunxi_nfc_hw_ecc_enable(nand);

	for (i = data_offs / ecc->size;
	     i < DIV_ROUND_UP(data_offs + data_len, ecc->size); i++) {
		int data_off = i * ecc->size;
		int oob_off = i * (ecc->bytes + 4);
		const u8 *data = buf + data_off;
		const u8 *oob = nand->oob_poi + oob_off;

		ret = sunxi_nfc_hw_ecc_write_chunk(nand, data, data_off, oob,
						   oob_off + mtd->writesize,
						   &cur_off, !i, page);
		if (ret)
			return ret;
	}

	sunxi_nfc_hw_ecc_disable(nand);

	return nand_prog_page_end_op(nand);
}