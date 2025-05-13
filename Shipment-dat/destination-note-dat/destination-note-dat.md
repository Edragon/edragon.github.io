# shipment by country

## shipment-country-2-dat

| country        | update | Zone                | normal & expendiated             | express                            | prerequisite   | carrier                                               |
| -------------- | ------ | ------------------- | -------------------------------- | ---------------------------------- | -------------- | ----------------------------------------------------- |
|                |        |                     |                                  |                                    |                |                                                       |
|                |        |                     |                                  |                                    |                |                                                       |
|                |        |                     |                                  |                                    |                |                                                       |
|                |        |                     |                                  |                                    |                |                                                       |
| Singapore      |        |                     | [[SGEXPRESS-BA]]                 | [[szfedex-ip]]                     |                |                                                       |
| Ecuador        | 11-30  | [[America-South]]   | CNRPOST-SZ                       | [[SZFED-PAK]]                      |                |                                                       |
| Indonesia      | 10-25  | [[asia]]            | [[NLRPOST]]                      | [[HKDHLX-old]]                     |                |                                                       |
| India          |        | [[asia]]            | -                                | [[HKDHLX-old]]                     |                |                                                       |
| Australia      |        | [[Australia]]       | [[AU-RPOST]]                     |                                    |                |                                                       |
| Brazil         |        | [[America-South]]   | [[BREXPRESS]]                    | ~~[[HKDHL-BA]] / [[HKFEDEXIP-C]]~~ | tax_id needed! |                                                       |
| Canada         |        | [[America-North]]   | [[CAEXPRESS]]                    |                                    |                |                                                       |
| United Kingdom | 06-07  | [[Europe]]          | [[CZUK]] / [[YODEL-UK]]          |                                    |                |                                                       |
| Kazakhstan     | 06-02  | [[asia]]            | [[DGEUB]]                        |                                    |                |                                                       |
| [[Spain-dat]]          |        |                     | [[EUEX-V-dat]]                   | [[SZFED-PAK]]                      |                |  |
| Portugal       |        | [[Europe]]          | [[EUEX-V-dat]]                   | [[SZFED-PAK]]                      |                |                                                       |
| Hungray        | 09-06  | [[Europe]]          | [[EUEX-V-dat]]                   | [[szfedex-ip]]                     |                |                                                       |
| Belgium        | 09-06  |                     | [[EUEX-V-dat]]                   | [[szfedex-ip]]                     |                |                                                       |
| Czech Republic |        | [[Europe]]          | [[EUEX-V-dat]]                   |                                    |                |                                                       |
| Denmark        |        | [[Europe]]          | [[EUEX-V-dat]]                   | [[HKDHL-BA]]                       |                |                                                       |
| Netherlands    |        | [[Europe]]          | [[EUEX-V-dat]]                   | [[SZFED-PAK]]                      | -              |                                                       |
| Poland         | 06-09  | [[Europe]]          | [[EUEX-V-dat]]                   |                                    |                |                                                       |
| Sweden         | 06-02  | [[Europe]]          | [[EUEX-V-dat]]                   |                                    |                |                                                       |
| Austria        |        | [[Europe]]          | [[EUEX-V-dat]]                   |                                    |                |                                                       |
| Solvenia       |        | [[Europe]]          | [[EUEX-V-dat]]                   |                                    |                |                                                       |
| Romania        | 10-18  | [[Europe]]          | [[EURPOST-cn-dat]]                  |                                    |                |                                                       |
| Bulgaria       | 06-07  | [[Europe]]          | [[EURPOST-cn-dat]]                  |                                    |                |                                                       |
| Latvia         | 06-02  | [[Europe]]          | [[EURPOST-cn-dat]]                  |                                    |                |                                                       |
| Malta          |        | [[Europe]]          | [[EURPOST-cn-dat]]                  | -                                  | -              |                                                       |
| Cyprus         |        | [[Europe]]          | [[EURPOST-cn-dat]]                  |                                    |                |                                                       |
| Finland        |        | [[Europe]]          | [[EURPOST-cn-dat]]                  | [[SZFED-PAK]] / [[szfedex-ip]]     | -              |                                                       |
| Greece         |        | [[Europe]]          | [[EURPOST-cn-dat]]                  | [[SZFED-PAK]]                      |                |                                                       |
| Norway         | 06-20  | [[Europe]]          | [[EURPOST-cn-dat]]                  |                                    |                |                                                       |
| Mexico         |        | [[America-South]]   | [[EURPOST-cn-dat]] << [[MXEXPRESS]] |                                    |                |                                                       |
| South Africa   | X      | [[Africa]]          | [[EURPOST-cn-dat]] << [[ZAEXPRESS]] |                                    | tax_id needed! |                                                       |
| Switzerland    | 06-15  | [[Europe]]          | [[EURPOST-cn-dat]] ~~[[SWRPOST]]~~  |                                    |                |                                                       |
| Malaysia       | 06-15  | [[asia]]            | [[MYEXPRESS-BA]]                 |                                    |                |                                                       |
| Costa Rica     | 06-09  | [[America-Central]] | [[NLRPOST]]                      | [[SZFED-PAK]]                      |                |                                                       |
| Iceland        | 06-15  | [[Europe]]          | [[NLRPOST]]                      | [[szfedex-ip]]                     |                |                                                       |
| Korea          | 06-30  | [[asia]]            | [[EURPOST-cn-dat]] / [[PFCEXPRESS]] | [[SZFEDEX-IE]] / [[HKFEDEXIP-C]]   | tax_id needed! |                                                       |
| Chile          | 09-06  | [[America-South]]   | [[PFCEXPRESS]]                   | ~~[[SZFED-PAK]] / [[HKDHLX-old]]~~ | tax_id needed! |                                                       |
| United States  |        | [[America-North]]   | [[USPS-DAT]]                     | [[szfedex-ip]] / [[HKUPS]]         |                |                                                       |
| Vietam         |        | [[asia]]            | [[VNEXPRESS]]                    |                                    | -              |                                                       |

韩国必须填写P+12位数字的个人通关码，欧盟国家填写ioss税号。

### Note

**tax_id needed!**: please always provide your tax id number for shipment

**express option**:

- normally delivery time 5-10 days
- normally FEDEX, DHL and UPS

**normal & expendiated option**:

- normally delivery time 7-25 days
- but this is for referential only, some countries may up to 60 days

## Shiping Options

| Option                     | type          | scope     | Referential ETA | Customs               | Details                       |
| -------------------------- | ------------- | --------- | --------------- | --------------------- | ----------------------------- |
| [[SZFED-PAK]]              | express       | worldwide | 5-10 days       | pay-by-you            |                               |
| [[EUEX-V-dat]]             | expendiated   | europe    | 10-26 days      | no-guaranteed prepaid |                               |
| [[NLRPOST]]                | reliable-post | worldwide | 12-35 days      |                       |                               |
| [[HKDHL]] / [[HKDHLX-old]] | express       |           | 5-10 days       |                       | minimium order to Europe $120 |
|                            |               |           |                 |                       |                               |
|                            |               |           |                 |                       |                               |
|                            |               |           |                 |                       |                               |
|                            |               |           |                 |                       |                               |

## old

| country        | update | method           | details | category    | System                  |                                                            |
| -------------- | ------ | ---------------- | ------- | ----------- | ----------------------- | ---------------------------------------------------------- |
|                |        |                  |         |             |                         |                                                            |
|                |        |                  |         |             |                         |                                                            |
|                |        |                  |         |             |                         |                                                            |
| Romania        | 10/18  | [[EURPOST-cn-dat]]  |         | expendiated |                         |                                                            |
| Belgium        | 09/06  | SZFEDEX-IP       |         | express     |                         |                                                            |
| Hungray        | 09/06  | SZFEDEX-IP       |         | express     |                         |                                                            |
| Chile          | 09/06  | HKDHLX           | tax_id  | express     |                         |                                                            |
| Austria        |        | EURPOST-dat      |         |             | Advanced: EURPOST-dat-5 | EURPOST-dat: Intl. + Local Delivery (Ref. ETA. 13-30 Days) |
| Brazil         |        | BREX / BREXPRESS |         | expendiated | Shipment Zone           |                                                            |
| Brazil         | X      | HKDHL-BA         | tax_id  |             | -                       | -                                                          |
| Brazil         | X      | HKFEDEXIP-C      | tax_id  |             | -                       | -                                                          |
| Bulgaria       | 06-07  | EURPOST-dat      |         | expendiated |                         | EURPOST-dat: Intl. + Local Delivery (Ref. ETA. 13-30 Days) |
| Costa Rica     | 06-09  | NLRPOST          |         |             |                         |                                                            |
| Cyprus         |        | EURPOST-dat      |         |             | Advanced: EURPOST-dat-5 | EURPOST-dat: Intl. + Local Delivery (Ref. ETA. 13-30 Days) |
| Czech Republic |        | EUEX-V-dat       |         | expendiated | Advanced: EUEX-V-dat    |                                                            |
| Denmark        |        | EUEX-V-dat       |         |             | Advanced: EUEX-V-dat    |                                                            |
| Denmark        |        | EURPOST-dat      |         |             | Advanced: EURPOST-dat-5 | EURPOST-dat: Intl. + Local Delivery (Ref. ETA. 13-30 Days) |
| Denmark        |        | HKDHL-BA         |         |             | -                       | -                                                          |
| Finland        |        | SZFEDEX-IP       | -       | -           |                         |                                                            |
| Greece         |        | EURPOST-dat      |         |             | Advanced: EURPOST-dat-5 | EURPOST-dat: Intl. + Local Delivery (Ref. ETA. 13-30 Days) |
| Iceland        | 06-15  | SZFEDEX-IP       |         | express     |                         |                                                            |
| Iceland        | 06-15  | NLRPOST          |         | post        |                         |                                                            |
| India          |        | HKDHL            |         | express     |                         |                                                            |
| Kazakhstan     | 06-02  | DGEUB            |         |             |                         | -                                                          |
| Korea          | 06-30  | HKFEDEXIP-C      |         |             |                         |                                                            |
| Latvia         | 06-02  | EURPOST-dat      |         |             |                         |                                                            |
| Malaysia       | 06-15  | MYEXPRESS-BA     |         | expendiated |                         |                                                            |
| Malta          |        | EURPOST-dat      | -       | -           | Advanced: EURPOST-dat-6 | EURPOST-dat: Intl. + Local Delivery (Ref. ETA. 13-30 Days) |
| Netherlands    |        | EUEX-V-dat       | -       | -           | Advanced: EUEX-V-dat    |                                                            |
| Norway         | 06-20  | EURPOST-dat      |         |             | Advanced: EURPOST-dat-4 | EURPOST-dat: Intl. + Local Delivery (Ref. ETA. 13-30 Days) |
| Poland         | 06-09  | EUEX-V-dat       |         |             |                         |                                                            |
| Solvenia       |        | EURPOST-dat      |         |             | Advanced: EURPOST-dat-5 | EURPOST-dat: Intl. + Local Delivery (Ref. ETA. 13-30 Days) |
| South Africa   | X      | ZAEXPRESS        | tax_id  | expendiated |                         | ZAEXPRESS: Buffaloex Express Shipment                      |
| Sweden         | 06-02  | EUEX-V-dat       |         |             |                         |                                                            |
| Switzerland    | 06-15  | EURPOST-dat      |         |             |                         | EURPOST-dat: Intl. + Local Delivery (Ref. ETA. 13-30 Days) |
| United Kingdom | 06-07  | CZUK             |         |             |                         |                                                            |
| United Kingdom | 06-07  | GBEXPRESS        |         |             |                         |                                                            |
| United Kingdom | 06-07  | YODEL-UK         |         |             |                         |                                                            |
| Vietam         |        | VNEXPRESS        | -       | -           |                         | VNEXPRESS: Intl. + Local Express (Ref. ETA. 10-18 Days)    |

### Deactived Shipping Methods

| country     | update | method   | details | category | System               |                                                         |
| ----------- | ------ | -------- | ------- | -------- | -------------------- | ------------------------------------------------------- |
| Switzerland | 06-15  | SWRPOST  |         | Post     | Shipment Zone        | SWRPOST: Intl. + Switzerland Post (Ref. ETA 11-24 Days) |
| Switzerland | 06-15  | SZEUB-BA |         | Post     | Advanced: SZEUB-BA-4 |                                                         |
|             |        |          |         |          |                      |                                                         |

- [[EUEX-V-dat]] - [[EURPOST-cn-dat]] - [[CAEXPRESS]] - [[USPS-DAT]] - [[DHL]]

prepaid [[VAT]] tax






## ref

-
