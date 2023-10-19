# shipment by country

## shipment-country-2-dat

| country        | update | Zone                | normal & expendiated         | express                            | prerequisite   |
| -------------- | ------ | ------------------- | ---------------------------- | ---------------------------------- | -------------- |
|                |        |                     |                              |                                    |                |
|                |        |                     |                              |                                    |                |
| Spain          |        |                     | [[EUEX-V]]                   | [[SZFED-PAK]]                      |                |
| Mexico         |        | [[America-South]]   | [[MXEXPRESS]]                |                                    |                |
| India          |        | [[asia]]            | -                            | [[HKDHLX]]                         |                |
| Australia      |        | [[Australia]]       | [[AU-RPOST]]                 |                                    |                |
| Brazil         |        | [[America-South]]   | [[BREXPRESS]]                | ~~[[HKDHL-BA]] / [[HKFEDEXIP-C]]~~ | tax_id needed! |
| Canada         |        | [[America-North]]   | [[CAEXPRESS]]                |                                    |                |
| United Kingdom | 06-07  | [[Europe]]          | [[CZUK]] / [[YODEL-UK]]      |                                    |                |
| Kazakhstan     | 06-02  | [[asia]]            | [[DGEUB]]                    |                                    |                |
| Portugal       |        | [[Europe]]          | [[EUEX-V]]                   | [[SZFED-PAK]]                      |                |
| Hungray        | 09-06  | [[Europe]]          | [[EUEX-V]]                   | [[SZFEDEX-IP]]                     |                |
| Belgium        | 09-06  |                     | [[EUEX-V]]                   | [[SZFEDEX-IP]]                     |                |
| Czech Republic |        | [[Europe]]          | [[EUEX-V]]                   |                                    |                |
| Denmark        |        | [[Europe]]          | [[EUEX-V]]                   | [[HKDHL-BA]]                       |                |
| Netherlands    |        | [[Europe]]          | [[EUEX-V]]                   | [[SZFED-PAK]]                      | -              |
| Poland         | 06-09  | [[Europe]]          | [[EUEX-V]]                   |                                    |                |
| Sweden         | 06-02  | [[Europe]]          | [[EUEX-V]]                   |                                    |                |
| Austria        |        | [[Europe]]          | [[EUEX-V]]                   |                                    |                |
| Solvenia       |        | [[Europe]]          | [[EUEX-V]]                   |                                    |                |
| Romania        | 10-18  | [[Europe]]          | [[EURPOST]]                  |                                    |                |
| Bulgaria       | 06-07  | [[Europe]]          | [[EURPOST]]                  |                                    |                |
| Latvia         | 06-02  | [[Europe]]          | [[EURPOST]]                  |                                    |                |
| Malta          |        | [[Europe]]          | [[EURPOST]]                  | -                                  | -              |
| Cyprus         |        | [[Europe]]          | [[EURPOST]]                  |                                    |                |
| Finland        |        | [[Europe]]          | [[EURPOST]]                  | [[SZFED-PAK]] / [[SZFEDEX-IP]]     | -              |
| Greece         |        | [[Europe]]          | [[EURPOST]]                  | [[SZFED-PAK]]                      |                |
| Norway         | 06-20  | [[Europe]]          | [[EURPOST]]                  |                                    |                |
| South Africa   | X      | [[Africa]]          | [[EURPOST]] << [[ZAEXPRESS]] |                                    | tax_id needed! |
| Switzerland    | 06-15  | [[Europe]]          | [[EURPOST]] ~~[[SWRPOST]]~~  |                                    |                |
| Malaysia       | 06-15  | [[asia]]            | [[MYEXPRESS-BA]]             |                                    |                |
| Costa Rica     | 06-09  | [[America-Central]] | [[NLRPOST]]                  | [[SZFED-PAK]]                      |                |
| Iceland        | 06-15  | [[Europe]]          | [[NLRPOST]]                  | [[SZFEDEX-IP]]                     |                |
| Korea          | 06-30  | [[asia]]            | [[PFCEXPRESS]]               | [[SZFEDEX-IE]] / [[HKFEDEXIP-C]]   |                |
| Chile          | 09-06  | [[America-South]]   | [[PFCEXPRESS]]               | ~~[[SZFED-PAK]] / [[HKDHLX]]~~     | tax_id needed! |
| United States  |        | [[America-North]]   | [[USPS-dat]]                 | [[SZFEDEX-IP]] / [[HKUPS]]         |                |
| Vietam         |        | [[asia]]            | [[VNEXPRESS]]                |                                    | -              |

### Note

**tax_id needed!**: please always provide your tax id number for shipment

**express option**:

- normally delivery time 5-10 days
- normally FEDEX, DHL and UPS

**normal & expendiated option**:

- normally delivery time 7-25 days
- but this is for referential only, some countries may up to 60 days

## Shiping Options

| Option        | type          | scope     | Customs               | Details                       |
| ------------- | ------------- | --------- | --------------------- | ----------------------------- |
| [[SZFED-PAK]] | express       | worldwide | pay-by-you            |                               |
| [[EUEX-V]]    | expendiated   | europe    | no-guaranteed prepaid |                               |
| [[NLRPOST]]   | reliable-post | worldwide |                       |                               |
| HKDHL         | express       |           |                       | minimium order to Europe $120 |
|               |               |           |                       |                               |
|               |               |           |                       |                               |
|               |               |           |                       |                               |
|               |               |           |                       |                               |

## old

| country        | update | method           | details | category    | System              |                                                         |
| -------------- | ------ | ---------------- | ------- | ----------- | ------------------- | ------------------------------------------------------- |
|                |        |                  |         |             |                     |                                                         |
|                |        |                  |         |             |                     |                                                         |
|                |        |                  |         |             |                     |                                                         |
| Romania        | 10/18  | [[EURPOST]]      |         | expendiated |                     |                                                         |
| Belgium        | 09/06  | SZFEDEX-IP       |         | express     |                     |                                                         |
| Hungray        | 09/06  | SZFEDEX-IP       |         | express     |                     |                                                         |
| Chile          | 09/06  | HKDHLX           | tax_id  | express     |                     |                                                         |
| Austria        |        | EURPOST          |         |             | Advanced: EURPOST-5 | EURPOST: Intl. + Local Delivery (Ref. ETA. 13-30 Days)  |
| Brazil         |        | BREX / BREXPRESS |         | expendiated | Shipment Zone       |                                                         |
| Brazil         | X      | HKDHL-BA         | tax_id  |             | -                   | -                                                       |
| Brazil         | X      | HKFEDEXIP-C      | tax_id  |             | -                   | -                                                       |
| Bulgaria       | 06-07  | EURPOST          |         | expendiated |                     | EURPOST: Intl. + Local Delivery (Ref. ETA. 13-30 Days)  |
| Costa Rica     | 06-09  | NLRPOST          |         |             |                     |                                                         |
| Cyprus         |        | EURPOST          |         |             | Advanced: EURPOST-5 | EURPOST: Intl. + Local Delivery (Ref. ETA. 13-30 Days)  |
| Czech Republic |        | EUEX-V           |         | expendiated | Advanced: EUEX-V    |                                                         |
| Denmark        |        | EUEX-V           |         |             | Advanced: EUEX-V    |                                                         |
| Denmark        |        | EURPOST          |         |             | Advanced: EURPOST-5 | EURPOST: Intl. + Local Delivery (Ref. ETA. 13-30 Days)  |
| Denmark        |        | HKDHL-BA         |         |             | -                   | -                                                       |
| Finland        |        | SZFEDEX-IP       | -       | -           |                     |                                                         |
| Greece         |        | EURPOST          |         |             | Advanced: EURPOST-5 | EURPOST: Intl. + Local Delivery (Ref. ETA. 13-30 Days)  |
| Iceland        | 06-15  | SZFEDEX-IP       |         | express     |                     |                                                         |
| Iceland        | 06-15  | NLRPOST          |         | post        |                     |                                                         |
| India          |        | HKDHL            |         | express     |                     |                                                         |
| Kazakhstan     | 06-02  | DGEUB            |         |             |                     | -                                                       |
| Korea          | 06-30  | HKFEDEXIP-C      |         |             |                     |                                                         |
| Latvia         | 06-02  | EURPOST          |         |             |                     |                                                         |
| Malaysia       | 06-15  | MYEXPRESS-BA     |         | expendiated |                     |                                                         |
| Malta          |        | EURPOST          | -       | -           | Advanced: EURPOST-6 | EURPOST: Intl. + Local Delivery (Ref. ETA. 13-30 Days)  |
| Netherlands    |        | EUEX-V           | -       | -           | Advanced: EUEX-V    |                                                         |
| Norway         | 06-20  | EURPOST          |         |             | Advanced: EURPOST-4 | EURPOST: Intl. + Local Delivery (Ref. ETA. 13-30 Days)  |
| Poland         | 06-09  | EUEX-V           |         |             |                     |                                                         |
| Solvenia       |        | EURPOST          |         |             | Advanced: EURPOST-5 | EURPOST: Intl. + Local Delivery (Ref. ETA. 13-30 Days)  |
| South Africa   | X      | ZAEXPRESS        | tax_id  | expendiated |                     | ZAEXPRESS: Buffaloex Express Shipment                   |
| Sweden         | 06-02  | EUEX-V           |         |             |                     |                                                         |
| Switzerland    | 06-15  | EURPOST          |         |             |                     | EURPOST: Intl. + Local Delivery (Ref. ETA. 13-30 Days)  |
| United Kingdom | 06-07  | CZUK             |         |             |                     |                                                         |
| United Kingdom | 06-07  | GBEXPRESS        |         |             |                     |                                                         |
| United Kingdom | 06-07  | YODEL-UK         |         |             |                     |                                                         |
| Vietam         |        | VNEXPRESS        | -       | -           |                     | VNEXPRESS: Intl. + Local Express (Ref. ETA. 10-18 Days) |

### Deactived Shipping Methods

| country     | update | method   | details | category | System               |                                                         |
| ----------- | ------ | -------- | ------- | -------- | -------------------- | ------------------------------------------------------- |
| Switzerland | 06-15  | SWRPOST  |         | Post     | Shipment Zone        | SWRPOST: Intl. + Switzerland Post (Ref. ETA 11-24 Days) |
| Switzerland | 06-15  | SZEUB-BA |         | Post     | Advanced: SZEUB-BA-4 |                                                         |
|             |        |          |         |          |                      |                                                         |

- [[EUEX-V]] - [[EURPOST]] - [[CAEXPRESS]] - [[USPS-DAT]] - [[DHL]]

prepaid [[VAT]] tax
