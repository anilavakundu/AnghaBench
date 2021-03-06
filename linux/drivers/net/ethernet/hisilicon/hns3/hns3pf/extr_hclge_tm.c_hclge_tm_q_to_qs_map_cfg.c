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
typedef  int u16 ;
struct hclge_nq_to_qs_link_cmd {void* qset_id; void* nq_id; } ;
struct hclge_dev {int /*<<< orphan*/  hw; } ;
struct hclge_desc {scalar_t__ data; } ;

/* Variables and functions */
 int /*<<< orphan*/  HCLGE_OPC_TM_NQ_TO_QS_LINK ; 
 int HCLGE_TM_Q_QS_LINK_VLD_MSK ; 
 void* cpu_to_le16 (int) ; 
 int hclge_cmd_send (int /*<<< orphan*/ *,struct hclge_desc*,int) ; 
 int /*<<< orphan*/  hclge_cmd_setup_basic_desc (struct hclge_desc*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int hclge_tm_q_to_qs_map_cfg(struct hclge_dev *hdev,
				    u16 q_id, u16 qs_id)
{
	struct hclge_nq_to_qs_link_cmd *map;
	struct hclge_desc desc;

	hclge_cmd_setup_basic_desc(&desc, HCLGE_OPC_TM_NQ_TO_QS_LINK, false);

	map = (struct hclge_nq_to_qs_link_cmd *)desc.data;

	map->nq_id = cpu_to_le16(q_id);
	map->qset_id = cpu_to_le16(qs_id | HCLGE_TM_Q_QS_LINK_VLD_MSK);

	return hclge_cmd_send(&hdev->hw, &desc, 1);
}