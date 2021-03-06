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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  qla_host_t ;

/* Variables and functions */
#define  Q81_AUX_RX_HALF_FULL_DET 377 
#define  Q81_AUX_RX_HALF_FULL_MASK 376 
#define  Q81_AUX_RX_OVERFLOW_DET 375 
#define  Q81_AUX_RX_OVERFLOW_MASK 374 
#define  Q81_AUX_TX_HALF_FULL_DET 373 
#define  Q81_AUX_TX_HALF_FULL_MASK 372 
#define  Q81_AUX_TX_OVERFLOW_DET 371 
#define  Q81_AUX_TX_OVERFLOW_MASK 370 
 int /*<<< orphan*/  Q81_BAD_DATA ; 
#define  Q81_EXT_ARB_MODE 369 
#define  Q81_FLOW_CTL 368 
#define  Q81_GLOBAL_CFG 367 
#define  Q81_MAC_MGMT_INT 366 
#define  Q81_MAC_MGMT_IN_MASK 365 
#define  Q81_MAC_RX_PARAMS 364 
#define  Q81_MAC_SYS_INT 363 
#define  Q81_MAC_SYS_INT_MASK 362 
#define  Q81_MAC_TX_PARAMS 361 
#define  Q81_MDIO_CMD 360 
#define  Q81_MDIO_PHY_ADDR 359 
#define  Q81_MDIO_PORT 358 
#define  Q81_MDIO_RX_DATA 357 
#define  Q81_MDIO_STATUS 356 
#define  Q81_MDIO_TX_DATA 355 
#define  Q81_PAUSE_FRM_DEST_HI 354 
#define  Q81_PAUSE_FRM_DEST_LO 353 
#define  Q81_PAUSE_OPCODE 352 
#define  Q81_PAUSE_SRC_HI 351 
#define  Q81_PAUSE_SRC_LO 350 
#define  Q81_PAUSE_TIMER 349 
#define  Q81_RX_1024_TO_1518_PKTS 348 
#define  Q81_RX_1024_TO_1518_PKTS_LO 347 
#define  Q81_RX_128_255_PKTS 346 
#define  Q81_RX_128_255_PKTS_LO 345 
#define  Q81_RX_1519_TO_MAX_PKTS 344 
#define  Q81_RX_1519_TO_MAX_PKTS_LO 343 
#define  Q81_RX_256_511_PKTS 342 
#define  Q81_RX_256_511_PKTS_LO 341 
#define  Q81_RX_512_TO_1023_PKTS 340 
#define  Q81_RX_512_TO_1023_PKTS_LO 339 
#define  Q81_RX_64_PKTS 338 
#define  Q81_RX_64_PKTS_LO 337 
#define  Q81_RX_65_TO_127_PKTS 336 
#define  Q81_RX_65_TO_127_PKTS_LO 335 
#define  Q81_RX_ALIGN_ERR 334 
#define  Q81_RX_ALIGN_ERR_LO 333 
#define  Q81_RX_BCAST_PKTS 332 
#define  Q81_RX_BCAST_PKTS_LO 331 
#define  Q81_RX_BYTES 330 
#define  Q81_RX_BYTES_LO 329 
#define  Q81_RX_BYTES_OK 328 
#define  Q81_RX_BYTES_OK_LO 327 
#define  Q81_RX_CBFC_PAUSE_FRAMES0 326 
#define  Q81_RX_CBFC_PAUSE_FRAMES0_LO 325 
#define  Q81_RX_CBFC_PAUSE_FRAMES1 324 
#define  Q81_RX_CBFC_PAUSE_FRAMES1_LO 323 
#define  Q81_RX_CBFC_PAUSE_FRAMES2 322 
#define  Q81_RX_CBFC_PAUSE_FRAMES2_LO 321 
#define  Q81_RX_CBFC_PAUSE_FRAMES3 320 
#define  Q81_RX_CBFC_PAUSE_FRAMES3_LO 319 
#define  Q81_RX_CBFC_PAUSE_FRAMES4 318 
#define  Q81_RX_CBFC_PAUSE_FRAMES4_LO 317 
#define  Q81_RX_CBFC_PAUSE_FRAMES5 316 
#define  Q81_RX_CBFC_PAUSE_FRAMES5_LO 315 
#define  Q81_RX_CBFC_PAUSE_FRAMES6 314 
#define  Q81_RX_CBFC_PAUSE_FRAMES6_LO 313 
#define  Q81_RX_CBFC_PAUSE_FRAMES7 312 
#define  Q81_RX_CBFC_PAUSE_FRAMES7_LO 311 
#define  Q81_RX_CFG 310 
#define  Q81_RX_CTL_PKTS 309 
#define  Q81_RX_CTL_PKTS_LO 308 
#define  Q81_RX_DISCARD_PRIORITY0 307 
#define  Q81_RX_DISCARD_PRIORITY0_LO 306 
#define  Q81_RX_DISCARD_PRIORITY1 305 
#define  Q81_RX_DISCARD_PRIORITY1_LO 304 
#define  Q81_RX_DISCARD_PRIORITY2 303 
#define  Q81_RX_DISCARD_PRIORITY2_LO 302 
#define  Q81_RX_DISCARD_PRIORITY3 301 
#define  Q81_RX_DISCARD_PRIORITY3_LO 300 
#define  Q81_RX_DISCARD_PRIORITY4 299 
#define  Q81_RX_DISCARD_PRIORITY4_LO 298 
#define  Q81_RX_DISCARD_PRIORITY5 297 
#define  Q81_RX_DISCARD_PRIORITY5_LO 296 
#define  Q81_RX_DISCARD_PRIORITY6 295 
#define  Q81_RX_DISCARD_PRIORITY6_LO 294 
#define  Q81_RX_DISCARD_PRIORITY7 293 
#define  Q81_RX_DISCARD_PRIORITY7_LO 292 
#define  Q81_RX_DROP_EVENTS 291 
#define  Q81_RX_DROP_EVENTS_LO 290 
#define  Q81_RX_FCERR_PKTS 289 
#define  Q81_RX_FCERR_PKTS_LO 288 
#define  Q81_RX_FCOE_FIFO_DROP 287 
#define  Q81_RX_FCOE_FIFO_DROP_LO 286 
#define  Q81_RX_FCOE_PKTS 285 
#define  Q81_RX_FCOE_PKTS_LO 284 
#define  Q81_RX_HALF_FULL_DET 283 
#define  Q81_RX_HALF_FULL_MASK 282 
#define  Q81_RX_JABBER_PKTS 281 
#define  Q81_RX_JABBER_PKTS_LO 280 
#define  Q81_RX_LEN_ERR_PKTS 279 
#define  Q81_RX_LEN_ERR_PKTS_LO 278 
#define  Q81_RX_MAC_ERR 277 
#define  Q81_RX_MAC_ERR_LO 276 
#define  Q81_RX_MCAST_PKTS 275 
#define  Q81_RX_MCAST_PKTS_LO 274 
#define  Q81_RX_MGMT_FIFO_DROP 273 
#define  Q81_RX_MGMT_FIFO_DROP_LO 272 
#define  Q81_RX_MGMT_PKTS 271 
#define  Q81_RX_MGMT_PKTS_LO 270 
#define  Q81_RX_NIC_FIFO_DROP 269 
#define  Q81_RX_NIC_FIFO_DROP_LO 268 
#define  Q81_RX_OCTETS_PRIORITY0 267 
#define  Q81_RX_OCTETS_PRIORITY0_LO 266 
#define  Q81_RX_OCTETS_PRIORITY1 265 
#define  Q81_RX_OCTETS_PRIORITY1_LO 264 
#define  Q81_RX_OCTETS_PRIORITY2 263 
#define  Q81_RX_OCTETS_PRIORITY2_LO 262 
#define  Q81_RX_OCTETS_PRIORITY3 261 
#define  Q81_RX_OCTETS_PRIORITY3_LO 260 
#define  Q81_RX_OCTETS_PRIORITY4 259 
#define  Q81_RX_OCTETS_PRIORITY4_LO 258 
#define  Q81_RX_OCTETS_PRIORITY5 257 
#define  Q81_RX_OCTETS_PRIORITY5_LO 256 
#define  Q81_RX_OCTETS_PRIORITY6 255 
#define  Q81_RX_OCTETS_PRIORITY6_LO 254 
#define  Q81_RX_OCTETS_PRIORITY7 253 
#define  Q81_RX_OCTETS_PRIORITY7_LO 252 
#define  Q81_RX_OVERFLOW_DET 251 
#define  Q81_RX_OVERFLOW_MASK 250 
#define  Q81_RX_OVERSIZE_PKTS 249 
#define  Q81_RX_OVERSIZE_PKTS_LO 248 
#define  Q81_RX_PAUSE_PKTS 247 
#define  Q81_RX_PAUSE_PKTS_LO 246 
#define  Q81_RX_PKTS 245 
#define  Q81_RX_PKTS_LO 244 
#define  Q81_RX_PKTS_OK 243 
#define  Q81_RX_PKTS_OK_LO 242 
#define  Q81_RX_PKTS_PRIORITY0 241 
#define  Q81_RX_PKTS_PRIORITY0_LO 240 
#define  Q81_RX_PKTS_PRIORITY1 239 
#define  Q81_RX_PKTS_PRIORITY1_LO 238 
#define  Q81_RX_PKTS_PRIORITY2 237 
#define  Q81_RX_PKTS_PRIORITY2_LO 236 
#define  Q81_RX_PKTS_PRIORITY3 235 
#define  Q81_RX_PKTS_PRIORITY3_LO 234 
#define  Q81_RX_PKTS_PRIORITY4 233 
#define  Q81_RX_PKTS_PRIORITY4_LO 232 
#define  Q81_RX_PKTS_PRIORITY5 231 
#define  Q81_RX_PKTS_PRIORITY5_LO 230 
#define  Q81_RX_PKTS_PRIORITY6 229 
#define  Q81_RX_PKTS_PRIORITY6_LO 228 
#define  Q81_RX_PKTS_PRIORITY7 227 
#define  Q81_RX_PKTS_PRIORITY7_LO 226 
#define  Q81_RX_SYMBOL_ERR 225 
#define  Q81_RX_SYMBOL_ERR_LO 224 
#define  Q81_RX_UCAST_PKTS 223 
#define  Q81_RX_UCAST_PKTS_LO 222 
#define  Q81_RX_UNDERSIZE_FCERR_PKTS 221 
#define  Q81_RX_UNDERSIZE_FCERR_PKTS_LO 220 
#define  Q81_RX_UNDERSIZE_PKTS 219 
#define  Q81_RX_UNDERSIZE_PKTS_LO 218 
#define  Q81_STAT_CNT_CTL 217 
#define  Q81_TX_1024_TO_1518_PKT 216 
#define  Q81_TX_1024_TO_1518_PKT_LO 215 
#define  Q81_TX_128_TO_255_PKT 214 
#define  Q81_TX_128_TO_255_PKT_LO 213 
#define  Q81_TX_1519_TO_MAX_PKT 212 
#define  Q81_TX_1519_TO_MAX_PKT_LO 211 
#define  Q81_TX_256_511_PKT 210 
#define  Q81_TX_256_511_PKT_LO 209 
#define  Q81_TX_512_TO_1023_PKT 208 
#define  Q81_TX_512_TO_1023_PKT_LO 207 
#define  Q81_TX_64_PKT 206 
#define  Q81_TX_64_PKT_LO 205 
#define  Q81_TX_65_TO_127_PKT 204 
#define  Q81_TX_65_TO_127_PKT_LO 203 
#define  Q81_TX_BCAST_PKTS 202 
#define  Q81_TX_BCAST_PKTS_LO 201 
#define  Q81_TX_BYTES 200 
#define  Q81_TX_BYTES_LO 199 
#define  Q81_TX_CBFC_PAUSE_FRAMES0 198 
#define  Q81_TX_CBFC_PAUSE_FRAMES0_LO 197 
#define  Q81_TX_CBFC_PAUSE_FRAMES1 196 
#define  Q81_TX_CBFC_PAUSE_FRAMES1_LO 195 
#define  Q81_TX_CBFC_PAUSE_FRAMES2 194 
#define  Q81_TX_CBFC_PAUSE_FRAMES2_LO 193 
#define  Q81_TX_CBFC_PAUSE_FRAMES3 192 
#define  Q81_TX_CBFC_PAUSE_FRAMES3_LO 191 
#define  Q81_TX_CBFC_PAUSE_FRAMES4 190 
#define  Q81_TX_CBFC_PAUSE_FRAMES4_LO 189 
#define  Q81_TX_CBFC_PAUSE_FRAMES5 188 
#define  Q81_TX_CBFC_PAUSE_FRAMES5_LO 187 
#define  Q81_TX_CBFC_PAUSE_FRAMES6 186 
#define  Q81_TX_CBFC_PAUSE_FRAMES6_LO 185 
#define  Q81_TX_CBFC_PAUSE_FRAMES7 184 
#define  Q81_TX_CBFC_PAUSE_FRAMES7_LO 183 
#define  Q81_TX_CFG 182 
#define  Q81_TX_CTL_PKTS 181 
#define  Q81_TX_CTL_PKTS_LO 180 
#define  Q81_TX_FCOE_PKTS 179 
#define  Q81_TX_FCOE_PKTS_LO 178 
#define  Q81_TX_HALF_FULL_DET_LO 177 
#define  Q81_TX_HALF_FULL_MASK_LO 176 
#define  Q81_TX_MCAST_PKTS 175 
#define  Q81_TX_MCAST_PKTS_LO 174 
#define  Q81_TX_MGMT_PKTS 173 
#define  Q81_TX_MGMT_PKTS_LO 172 
#define  Q81_TX_OCTETS_PRIORITY0 171 
#define  Q81_TX_OCTETS_PRIORITY0_LO 170 
#define  Q81_TX_OCTETS_PRIORITY1 169 
#define  Q81_TX_OCTETS_PRIORITY1_LO 168 
#define  Q81_TX_OCTETS_PRIORITY2 167 
#define  Q81_TX_OCTETS_PRIORITY2_LO 166 
#define  Q81_TX_OCTETS_PRIORITY3 165 
#define  Q81_TX_OCTETS_PRIORITY3_LO 164 
#define  Q81_TX_OCTETS_PRIORITY4 163 
#define  Q81_TX_OCTETS_PRIORITY4_LO 162 
#define  Q81_TX_OCTETS_PRIORITY5 161 
#define  Q81_TX_OCTETS_PRIORITY5_LO 160 
#define  Q81_TX_OCTETS_PRIORITY6 159 
#define  Q81_TX_OCTETS_PRIORITY6_LO 158 
#define  Q81_TX_OCTETS_PRIORITY7 157 
#define  Q81_TX_OCTETS_PRIORITY7_LO 156 
#define  Q81_TX_OVERFLOW_DET_LO 155 
#define  Q81_TX_OVERFLOW_MASK_LO 154 
#define  Q81_TX_OVERSIZE_PKT 153 
#define  Q81_TX_OVERSIZE_PKT_LO 152 
#define  Q81_TX_PAUSE_PKTS 151 
#define  Q81_TX_PAUSE_PKTS_LO 150 
#define  Q81_TX_PKTS 149 
#define  Q81_TX_PKTS_LO 148 
#define  Q81_TX_PKTS_PRIORITY0 147 
#define  Q81_TX_PKTS_PRIORITY0_LO 146 
#define  Q81_TX_PKTS_PRIORITY1 145 
#define  Q81_TX_PKTS_PRIORITY1_LO 144 
#define  Q81_TX_PKTS_PRIORITY2 143 
#define  Q81_TX_PKTS_PRIORITY2_LO 142 
#define  Q81_TX_PKTS_PRIORITY3 141 
#define  Q81_TX_PKTS_PRIORITY3_LO 140 
#define  Q81_TX_PKTS_PRIORITY4 139 
#define  Q81_TX_PKTS_PRIORITY4_LO 138 
#define  Q81_TX_PKTS_PRIORITY5 137 
#define  Q81_TX_PKTS_PRIORITY5_LO 136 
#define  Q81_TX_PKTS_PRIORITY6 135 
#define  Q81_TX_PKTS_PRIORITY6_LO 134 
#define  Q81_TX_PKTS_PRIORITY7 133 
#define  Q81_TX_PKTS_PRIORITY7_LO 132 
#define  Q81_TX_UCAST_PKTS 131 
#define  Q81_TX_UCAST_PKTS_LO 130 
#define  Q81_TX_UNDERSIZE_PKT 129 
#define  Q81_TX_UNDERSIZE_PKT_LO 128 
 int Q81_XGMAC_REGISTER_END ; 
 int qls_rd_ofunc_xgmac_reg (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int qls_rd_xgmac_reg (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
qls_rd_xgmac_regs(qla_host_t *ha, uint32_t *buf, uint32_t o_func)
{
	int ret = 0;
	int i;

	for (i = 0; i < Q81_XGMAC_REGISTER_END; i += 4, buf ++) {

		switch (i) {
		case  Q81_PAUSE_SRC_LO               :
		case  Q81_PAUSE_SRC_HI               :
		case  Q81_GLOBAL_CFG                 :
		case  Q81_TX_CFG                     :
		case  Q81_RX_CFG                     :
		case  Q81_FLOW_CTL                   :
		case  Q81_PAUSE_OPCODE               :
		case  Q81_PAUSE_TIMER                :
		case  Q81_PAUSE_FRM_DEST_LO          :
		case  Q81_PAUSE_FRM_DEST_HI          :
		case  Q81_MAC_TX_PARAMS              :
		case  Q81_MAC_RX_PARAMS              :
		case  Q81_MAC_SYS_INT                :
		case  Q81_MAC_SYS_INT_MASK           :
		case  Q81_MAC_MGMT_INT               :
		case  Q81_MAC_MGMT_IN_MASK           :
		case  Q81_EXT_ARB_MODE               :
		case  Q81_TX_PKTS                    :
		case  Q81_TX_PKTS_LO                 :
		case  Q81_TX_BYTES                   :
		case  Q81_TX_BYTES_LO                :
		case  Q81_TX_MCAST_PKTS              :
		case  Q81_TX_MCAST_PKTS_LO           :
		case  Q81_TX_BCAST_PKTS              :
		case  Q81_TX_BCAST_PKTS_LO           :
		case  Q81_TX_UCAST_PKTS              :
		case  Q81_TX_UCAST_PKTS_LO           :
		case  Q81_TX_CTL_PKTS                :
		case  Q81_TX_CTL_PKTS_LO             :
		case  Q81_TX_PAUSE_PKTS              :
		case  Q81_TX_PAUSE_PKTS_LO           :
		case  Q81_TX_64_PKT                  :
		case  Q81_TX_64_PKT_LO               :
		case  Q81_TX_65_TO_127_PKT           :
		case  Q81_TX_65_TO_127_PKT_LO        :
		case  Q81_TX_128_TO_255_PKT          :
		case  Q81_TX_128_TO_255_PKT_LO       :
		case  Q81_TX_256_511_PKT             :
		case  Q81_TX_256_511_PKT_LO          :
		case  Q81_TX_512_TO_1023_PKT         :
		case  Q81_TX_512_TO_1023_PKT_LO      :
		case  Q81_TX_1024_TO_1518_PKT        :
		case  Q81_TX_1024_TO_1518_PKT_LO     :
		case  Q81_TX_1519_TO_MAX_PKT         :
		case  Q81_TX_1519_TO_MAX_PKT_LO      :
		case  Q81_TX_UNDERSIZE_PKT           :
		case  Q81_TX_UNDERSIZE_PKT_LO        :
		case  Q81_TX_OVERSIZE_PKT            :
		case  Q81_TX_OVERSIZE_PKT_LO         :
		case  Q81_RX_HALF_FULL_DET           :
		case  Q81_TX_HALF_FULL_DET_LO        :
		case  Q81_RX_OVERFLOW_DET            :
		case  Q81_TX_OVERFLOW_DET_LO         :
		case  Q81_RX_HALF_FULL_MASK          :
		case  Q81_TX_HALF_FULL_MASK_LO       :
		case  Q81_RX_OVERFLOW_MASK           :
		case  Q81_TX_OVERFLOW_MASK_LO        :
		case  Q81_STAT_CNT_CTL               :
		case  Q81_AUX_RX_HALF_FULL_DET       :
		case  Q81_AUX_TX_HALF_FULL_DET       :
		case  Q81_AUX_RX_OVERFLOW_DET        :
		case  Q81_AUX_TX_OVERFLOW_DET        :
		case  Q81_AUX_RX_HALF_FULL_MASK      :
		case  Q81_AUX_TX_HALF_FULL_MASK      :
		case  Q81_AUX_RX_OVERFLOW_MASK       :
		case  Q81_AUX_TX_OVERFLOW_MASK       :
		case  Q81_RX_BYTES                   :
		case  Q81_RX_BYTES_LO                :
		case  Q81_RX_BYTES_OK                :
		case  Q81_RX_BYTES_OK_LO             :
		case  Q81_RX_PKTS                    :
		case  Q81_RX_PKTS_LO                 :
		case  Q81_RX_PKTS_OK                 :
		case  Q81_RX_PKTS_OK_LO              :
		case  Q81_RX_BCAST_PKTS              :
		case  Q81_RX_BCAST_PKTS_LO           :
		case  Q81_RX_MCAST_PKTS              :
		case  Q81_RX_MCAST_PKTS_LO           :
		case  Q81_RX_UCAST_PKTS              :
		case  Q81_RX_UCAST_PKTS_LO           :
		case  Q81_RX_UNDERSIZE_PKTS          :
		case  Q81_RX_UNDERSIZE_PKTS_LO       :
		case  Q81_RX_OVERSIZE_PKTS           :
		case  Q81_RX_OVERSIZE_PKTS_LO        :
		case  Q81_RX_JABBER_PKTS             :
		case  Q81_RX_JABBER_PKTS_LO          :
		case  Q81_RX_UNDERSIZE_FCERR_PKTS    :
		case  Q81_RX_UNDERSIZE_FCERR_PKTS_LO :
		case  Q81_RX_DROP_EVENTS             :
		case  Q81_RX_DROP_EVENTS_LO          :
		case  Q81_RX_FCERR_PKTS              :
		case  Q81_RX_FCERR_PKTS_LO           :
		case  Q81_RX_ALIGN_ERR               :
		case  Q81_RX_ALIGN_ERR_LO            :
		case  Q81_RX_SYMBOL_ERR              :
		case  Q81_RX_SYMBOL_ERR_LO           :
		case  Q81_RX_MAC_ERR                 :
		case  Q81_RX_MAC_ERR_LO              :
		case  Q81_RX_CTL_PKTS                :
		case  Q81_RX_CTL_PKTS_LO             :
		case  Q81_RX_PAUSE_PKTS              :
		case  Q81_RX_PAUSE_PKTS_LO           :
		case  Q81_RX_64_PKTS                 :
		case  Q81_RX_64_PKTS_LO              :
		case  Q81_RX_65_TO_127_PKTS          :
		case  Q81_RX_65_TO_127_PKTS_LO       :
		case  Q81_RX_128_255_PKTS            :
		case  Q81_RX_128_255_PKTS_LO         :
		case  Q81_RX_256_511_PKTS            :
		case  Q81_RX_256_511_PKTS_LO         :
		case  Q81_RX_512_TO_1023_PKTS        :
		case  Q81_RX_512_TO_1023_PKTS_LO     :
		case  Q81_RX_1024_TO_1518_PKTS       :
		case  Q81_RX_1024_TO_1518_PKTS_LO    :
		case  Q81_RX_1519_TO_MAX_PKTS        :
		case  Q81_RX_1519_TO_MAX_PKTS_LO     :
		case  Q81_RX_LEN_ERR_PKTS            :
		case  Q81_RX_LEN_ERR_PKTS_LO         :
		case  Q81_MDIO_TX_DATA               :
		case  Q81_MDIO_RX_DATA               :
		case  Q81_MDIO_CMD                   :
		case  Q81_MDIO_PHY_ADDR              :
		case  Q81_MDIO_PORT                  :
		case  Q81_MDIO_STATUS                :
		case  Q81_TX_CBFC_PAUSE_FRAMES0      :
		case  Q81_TX_CBFC_PAUSE_FRAMES0_LO   :
		case  Q81_TX_CBFC_PAUSE_FRAMES1      :
		case  Q81_TX_CBFC_PAUSE_FRAMES1_LO   :
		case  Q81_TX_CBFC_PAUSE_FRAMES2      :
		case  Q81_TX_CBFC_PAUSE_FRAMES2_LO   :
		case  Q81_TX_CBFC_PAUSE_FRAMES3      :
		case  Q81_TX_CBFC_PAUSE_FRAMES3_LO   :
		case  Q81_TX_CBFC_PAUSE_FRAMES4      :
		case  Q81_TX_CBFC_PAUSE_FRAMES4_LO   :
		case  Q81_TX_CBFC_PAUSE_FRAMES5      :
		case  Q81_TX_CBFC_PAUSE_FRAMES5_LO   :
		case  Q81_TX_CBFC_PAUSE_FRAMES6      :
		case  Q81_TX_CBFC_PAUSE_FRAMES6_LO   :
		case  Q81_TX_CBFC_PAUSE_FRAMES7      :
		case  Q81_TX_CBFC_PAUSE_FRAMES7_LO   :
		case  Q81_TX_FCOE_PKTS               :
		case  Q81_TX_FCOE_PKTS_LO            :
		case  Q81_TX_MGMT_PKTS               :
		case  Q81_TX_MGMT_PKTS_LO            :
		case  Q81_RX_CBFC_PAUSE_FRAMES0      :
		case  Q81_RX_CBFC_PAUSE_FRAMES0_LO   :
		case  Q81_RX_CBFC_PAUSE_FRAMES1      :
		case  Q81_RX_CBFC_PAUSE_FRAMES1_LO   :
		case  Q81_RX_CBFC_PAUSE_FRAMES2      :
		case  Q81_RX_CBFC_PAUSE_FRAMES2_LO   :
		case  Q81_RX_CBFC_PAUSE_FRAMES3      :
		case  Q81_RX_CBFC_PAUSE_FRAMES3_LO   :
		case  Q81_RX_CBFC_PAUSE_FRAMES4      :
		case  Q81_RX_CBFC_PAUSE_FRAMES4_LO   :
		case  Q81_RX_CBFC_PAUSE_FRAMES5      :
		case  Q81_RX_CBFC_PAUSE_FRAMES5_LO   :
		case  Q81_RX_CBFC_PAUSE_FRAMES6      :
		case  Q81_RX_CBFC_PAUSE_FRAMES6_LO   :
		case  Q81_RX_CBFC_PAUSE_FRAMES7      :
		case  Q81_RX_CBFC_PAUSE_FRAMES7_LO   :
		case  Q81_RX_FCOE_PKTS               :
		case  Q81_RX_FCOE_PKTS_LO            :
		case  Q81_RX_MGMT_PKTS               :
		case  Q81_RX_MGMT_PKTS_LO            :
		case  Q81_RX_NIC_FIFO_DROP           :
		case  Q81_RX_NIC_FIFO_DROP_LO        :
		case  Q81_RX_FCOE_FIFO_DROP          :
		case  Q81_RX_FCOE_FIFO_DROP_LO       :
		case  Q81_RX_MGMT_FIFO_DROP          :
		case  Q81_RX_MGMT_FIFO_DROP_LO       :
		case  Q81_RX_PKTS_PRIORITY0          :
		case  Q81_RX_PKTS_PRIORITY0_LO       :
		case  Q81_RX_PKTS_PRIORITY1          :
		case  Q81_RX_PKTS_PRIORITY1_LO       :
		case  Q81_RX_PKTS_PRIORITY2          :
		case  Q81_RX_PKTS_PRIORITY2_LO       :
		case  Q81_RX_PKTS_PRIORITY3          :
		case  Q81_RX_PKTS_PRIORITY3_LO       :
		case  Q81_RX_PKTS_PRIORITY4          :
		case  Q81_RX_PKTS_PRIORITY4_LO       :
		case  Q81_RX_PKTS_PRIORITY5          :
		case  Q81_RX_PKTS_PRIORITY5_LO       :
		case  Q81_RX_PKTS_PRIORITY6          :
		case  Q81_RX_PKTS_PRIORITY6_LO       :
		case  Q81_RX_PKTS_PRIORITY7          :
		case  Q81_RX_PKTS_PRIORITY7_LO       :
		case  Q81_RX_OCTETS_PRIORITY0        :
		case  Q81_RX_OCTETS_PRIORITY0_LO     :
		case  Q81_RX_OCTETS_PRIORITY1        :
		case  Q81_RX_OCTETS_PRIORITY1_LO     :
		case  Q81_RX_OCTETS_PRIORITY2        :
		case  Q81_RX_OCTETS_PRIORITY2_LO     :
		case  Q81_RX_OCTETS_PRIORITY3        :
		case  Q81_RX_OCTETS_PRIORITY3_LO     :
		case  Q81_RX_OCTETS_PRIORITY4        :
		case  Q81_RX_OCTETS_PRIORITY4_LO     :
		case  Q81_RX_OCTETS_PRIORITY5        :
		case  Q81_RX_OCTETS_PRIORITY5_LO     :
		case  Q81_RX_OCTETS_PRIORITY6        :
		case  Q81_RX_OCTETS_PRIORITY6_LO     :
		case  Q81_RX_OCTETS_PRIORITY7        :
		case  Q81_RX_OCTETS_PRIORITY7_LO     :
		case  Q81_TX_PKTS_PRIORITY0          :
		case  Q81_TX_PKTS_PRIORITY0_LO       :
		case  Q81_TX_PKTS_PRIORITY1          :
		case  Q81_TX_PKTS_PRIORITY1_LO       :
		case  Q81_TX_PKTS_PRIORITY2          :
		case  Q81_TX_PKTS_PRIORITY2_LO       :
		case  Q81_TX_PKTS_PRIORITY3          :
		case  Q81_TX_PKTS_PRIORITY3_LO       :
		case  Q81_TX_PKTS_PRIORITY4          :
		case  Q81_TX_PKTS_PRIORITY4_LO       :
		case  Q81_TX_PKTS_PRIORITY5          :
		case  Q81_TX_PKTS_PRIORITY5_LO       :
		case  Q81_TX_PKTS_PRIORITY6          :
		case  Q81_TX_PKTS_PRIORITY6_LO       :
		case  Q81_TX_PKTS_PRIORITY7          :
		case  Q81_TX_PKTS_PRIORITY7_LO       :
		case  Q81_TX_OCTETS_PRIORITY0        :
		case  Q81_TX_OCTETS_PRIORITY0_LO     :
		case  Q81_TX_OCTETS_PRIORITY1        :
		case  Q81_TX_OCTETS_PRIORITY1_LO     :
		case  Q81_TX_OCTETS_PRIORITY2        :
		case  Q81_TX_OCTETS_PRIORITY2_LO     :
		case  Q81_TX_OCTETS_PRIORITY3        :
		case  Q81_TX_OCTETS_PRIORITY3_LO     :
		case  Q81_TX_OCTETS_PRIORITY4        :
		case  Q81_TX_OCTETS_PRIORITY4_LO     :
		case  Q81_TX_OCTETS_PRIORITY5        :
		case  Q81_TX_OCTETS_PRIORITY5_LO     :
		case  Q81_TX_OCTETS_PRIORITY6        :
		case  Q81_TX_OCTETS_PRIORITY6_LO     :
		case  Q81_TX_OCTETS_PRIORITY7        :
		case  Q81_TX_OCTETS_PRIORITY7_LO     :
		case  Q81_RX_DISCARD_PRIORITY0       :
		case  Q81_RX_DISCARD_PRIORITY0_LO    :
		case  Q81_RX_DISCARD_PRIORITY1       :
		case  Q81_RX_DISCARD_PRIORITY1_LO    :
		case  Q81_RX_DISCARD_PRIORITY2       :
		case  Q81_RX_DISCARD_PRIORITY2_LO    :
		case  Q81_RX_DISCARD_PRIORITY3       :
		case  Q81_RX_DISCARD_PRIORITY3_LO    :
		case  Q81_RX_DISCARD_PRIORITY4       :
		case  Q81_RX_DISCARD_PRIORITY4_LO    :
		case  Q81_RX_DISCARD_PRIORITY5       :
		case  Q81_RX_DISCARD_PRIORITY5_LO    :
		case  Q81_RX_DISCARD_PRIORITY6       :
		case  Q81_RX_DISCARD_PRIORITY6_LO    :
		case  Q81_RX_DISCARD_PRIORITY7       :
		case  Q81_RX_DISCARD_PRIORITY7_LO    :

			if (o_func)
				ret = qls_rd_ofunc_xgmac_reg(ha,
						i, buf);
			else
				ret = qls_rd_xgmac_reg(ha, i, buf);

			if (ret)
				*buf = Q81_BAD_DATA;

			break;

		default:
			break;

		}
	}
	return 0;
}