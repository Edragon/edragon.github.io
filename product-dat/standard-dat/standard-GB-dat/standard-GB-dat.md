# standard-GB-dat

- [[standard-GB-dat]]


## GB/T 17215


GB/T 17215 不像前面那三本各自独立：它是一个由几十个部分组成的系列，对应 IEC 62052／62053 的整套电能计量标准体系。把它理解为“电能表标准族”会更准确。
编号规律（记住这个就能快速定位）
- .2xx = 通用要求、试验和试验条件（对应 IEC 62052）
- .3xx = 特殊要求，针对具体表型（对应 IEC 62053）
- .5xx = 符号、标识类（如 .352 符号）
- .8xx = 验收检验
- .9xx = 可靠性（对应 IEC 62059）
- .6xx = 数据交换、通信（对应 IEC 62056 / DLMS）
核心两本：2021 年同期发布且配套使用
① GB/T 17215.211-2021《电测量设备（交流） 通用要求、试验和试验条件 第11部分：测量设备》
- 发布 2021-04-30，实施 2021-11-01，代替 GB/T 17215.211-2006
- 规定了交流电能表型式试验的机械／电气要求、试验条件、功能与标识、气候与电磁环境、抗扰度、嵌入式软件要求
- 注意名称变化：从“交流电测量设备”改为“电测量设备（交流）”，与 IEC 62052-11 的命名保持一致
② GB/T 17215.321-2021《特殊要求 第21部分：静止式有功电能表（A级、B级、C级、D级和E级）》
- 同日发布、同日实施
- 一本同时替代了两本：GB/T 17215.321-2008（1级、2级）+ GB/T 17215.322-2008（0.2S级、0.5S级）
- 结构、EMC、可靠性这些不在这本里，要回到 211 以及 .911／.921／.9311／.9321／.941
🔑 最大的变化：准确度等级体系更换
旧体系是 0.1S / 0.2S / 0.5S / 1 / 2 级，新体系是 A–E 级，源自 OIML IR46。注意方向：A 最宽，E 最严，很多人会搞反。
Table
配套的电流特征点也换了：不再用 Ib（基本电流）／In（额定电流），改成 Ist 起动电流 / Imin 最小电流 / Itr 转折电流 / Imax 最大电流。
检定周期：A、B 级有功 ≤10 年；C、D、E 级 ≤8 年（有功无功都有的按短的算）。
其他常会用到的部分
- GB/T 17215.323 静止式无功电能表（2 级、3 级）
- GB/T 17215.324 静止式基波频率无功电能表（0.5S、1S、1 级）
- GB/T 17215.352 符号
- .8xx 系列：验收检验（含 0.2S/0.5S/1/2 级的验收要求）
- .9xx 系列：可靠性
- 付费／预付费表另走 GB/T 47790.31-2026（2027-02-01 实施，等同 IEC 62055-31:2022）
⚠️ 准入路径和插头插座完全不同
电能表不走 CCC，走计量器具管理：
- 电能表列入《实施强制管理的计量器具目录》（市场监管总局 2020 年第 42 号公告）
- 监管方式：型式批准 + 强制检定
- 用途界定：用于贸易结算的用电量测量
- 检定：工业用周期检定；生活用首次强制检定、限期使用、到期轮换
- 依据《计量器具新产品管理办法》：制造列入目录且监管方式为“型式批准”的新产品，须经省级市场监管部门型式批准后方可投产，并标注型式批准标志和编号
📌 对你在实际开发中的边界判断
如果你在考虑带电量计量的产品（智能插座、导轨式监测模块，芯片如 BL0937 / CSE7766 / HLW8032 / ADE7953），判断标准如下：
- 只做“电量监测／统计／节能参考”，不用于电费结算、不宣称计量准确度等级 → 不属于电能表，不需要型式批准，按整机安全标准走（如 GB 4706 系列 / GB 4943.1）
- 做成电能表形态（导轨表、预付费表）、用于贸易结算、或标称 A–E 级准确度 → 必须走型式批准 + 配套检定规程，标准就是 211 + 321
- 出口欧洲 → 走 EN 50470 系列（MID 指令），等级体系又是另一套
- 国网／南网项目 → 除国标外还要满足其技术规范与通信规约（DL/T 645 等），这部分与 GB/T 17215 并存
来源：GB/T 17215.321-2021（国家标准全文公开） (https://openstd.samr.gov.cn/bzgk/std/newGbInfo?hcno=50CCA4CF44CCBBB8C1609ECAB4D90AAB)、GB/T 17215.211-2021 标准信息 (https://codeofchina.com/standard/GBT17215.211-2021.html)、检定规程新旧等级对照（JJG 附录B） (http://cma-cma.org.cn/upload/2022/06-13/09-47-200346-818888402.pdf)、强制管理计量器具目录 2020 年第 42 号公告 (https://yqybw.cn/news/1173.html)


## basic China's domestic plug and socket product

These three standards together form China's domestic plug and socket product specifications, with a very clear division of labor.

One-sentence positioning

- GB/T 1002 — governs "what it looks like, how big it is": types, basic parameters, dimensions (and gauges)
- GB/T 2099.1 — governs "whether it's built safely": marking, protection against electric shock, construction, electrical/mechanical performance (general requirements)
- GB/T 2099.3 — governs "what additional requirements this category of product (adaptors) must also meet": tightening or modifying on top of 2099.1 (i.e., "Part 2-5")

The referencing relationship is: 2099.3 = 2099.1 (general) + special clauses for adaptors, and both must reference the pin-hole dimensions in 1002.

---

## GB/T 2099.1-2021 "Part 1: General requirements"

- Published 2021-10-11, effective 2022-11-01
- Replaces GB/T 2099.1-2008 (note: the 2008 edition was a mandatory GB; the 2021 edition became a recommended GB/T, but still serves as the basis for CCC certification)
- Modified adoption of IEC 60884-1:2013 (MOD)
- Scope: AC, rated voltage >50 V and ≤440 V, rated current ≤32 A, plugs and fixed/portable socket-outlets with or without earthing contacts; fixed socket-outlets with screwless terminals limited to ≤16 A

Main changes in this edition
- Modified the ambient temperature for product use
- Modified the definitions of plug / socket-outlet / portable socket-outlet / screw terminal / body, and added 4 new terms: grommet, entry membrane, protective membrane, tool
- Added torque requirements for terminal screws and cover/cover-plate fixing screws (assembly consistency)
- Modified the table of preferred combinations of ratings (Table 1)
- Modified IP protection classification in accordance with GB/T 4208-2017
- Deleted the classification of "plugs for Class 0 equipment" and the symbol requirements for neutral pole / earthing pole / live pole
- Deleted clause 6.3 of the old edition

---

## GB/T 1002-2021 "Types, basic parameters and dimensions"

- Published 2021-10-11, effective 2022-11-01, replaces GB/T 1002-2008
- Governs physical dimensions: shape of two-pole/three-pole plugs and socket-outlets, pin length and width, socket-contact spacing, gauges, tolerances
- Rating system: 250 V, 10 A / 16 A

Main changes in this edition
- Deleted the "single-phase two-pole dual-purpose socket-outlet" and its gauge — the so-called universal/dual-purpose socket-outlet, so from then on pin holes must strictly comply with 1002
- Added the requirement that live pins may have insulating sleeves (optional at the time)
- Added that Class I appliances may be fitted with a "10 A/16 A two-pole with earthing type, but without earthing pin" plug
- Added the requirement for the distance from the socket contact to the mating face, and the distance for the earthing contact must not be greater than that for live contacts
- Modified dimensional tolerances

 ⚠️ Important: GB/T 1002-2021 has already expired.
 The current version is GB 1002-2024 (published 2024-07-24, effective 2025-08-01), returning from GB/T to a mandatory GB. The core change is the mandatory requirement for plugs to have insulating sleeves (fingers cannot touch the metal pins when inserting/withdrawing).
 Also effective the same day is GB 2099.7-2024 "Safety technical specifications for extension socket-outlets" (replacing GB/T 2099.7-2015, also mandatory). The CQC certification basis has switched to GB 1002 + GB 2099.7 (implementation rule CQC-C0201.02-2024).
 Sources: CQC announcement (https://cqc.com.cn/www/english/c/2025-01-08/598228.shtml), GB 2099.7-2024 full text public release (https://openstd.samr.gov.cn/bzgk/std/newGbInfo?hcno=D4F79BC19C597DBE4AE413C0F3EC7BAC)

---

## GB/T 2099.3-2022 "Part 2-5: Particular requirements for adaptors"

- Published 2022-10-12, effective 2023-05-01, replaces GB/T 2099.3-2015
- Modified adoption of IEC 60884-2-5:2017 (MOD)
- The definition of "adaptor" is key: an adapter device in which the plug part and the socket-outlet part are made as one unit, with no flexible cord (i.e., the "one-to-many" plug-type adaptor). Those with a flexible cord are extension socket-outlets, which fall under GB 2099.7, not this standard
- Content specified: ratings, marking, protection against electric shock, construction, electrical performance, mechanical performance
- Structurally it replaces Chapter 1 of 2099.1 while the remaining clauses supplement 2099.1, so the two must be used together

CCC certificate transition timeline (important for product people)
- From 2023-05-01, only the new edition is used for certification, and only new certificates are issued
- Old certificates must complete the transition before 2024-05-01
- Overdue without transition → certificate suspended; if still not transitioned by 2024-08-01 → withdrawn
- Those already manufactured and placed on the market before 2023-05-01 and no longer produced are not forced to transition

---

📌 Practical use of the three

When selecting or purchasing and you see markings, check in this order:
1. Product bears the CCC mark + standard number (plugs and socket-outlets must pass CCC, under CNCA-C02-01 electrical accessories)
2. Whether the marked ratings (10 A/16 A, 250 V~) match the actual pins and wire gauge
3. Whether the pin holes comply only with GB/T 1002 / GB 1002 — universal holes are always non-compliant
4. Whether the plug has an insulating sleeve — mandatory after 2025-08-01 (GB 1002-2024)

A few easily confused categories, each under its own standard:

- Socket-outlets / power strips with USB → additionally GB/T 2099.31-2025 "Particular requirements for socket-outlets incorporating USB power supply" (effective 2025-11-01), not just 2099.1
- Extension socket-outlets / power strips → GB 2099.7-2024 (mandatory)
- Appliance inlets/outlets → GB/T 2099.2; fixed socket-outlets with switches → 2099.4/2099.5; plugs with fuses → 2099.6
- When plugs and socket-outlets are used as components of complete equipment, the complete-equipment standards (e.g., the GB 4706 series) also apply on top

A note for developers: 1002 governing dimensions only means "it can be inserted"; what really determines whether you pass inspection is 2099.1's temperature rise, breaking capacity, mechanical endurance (number of insertions/withdrawals), and protection against electric shock (test finger) — the temperature-rise test is usually the item where 10 A products get stuck most easily (contact material, socket-contact springiness and contact pressure).


## ref