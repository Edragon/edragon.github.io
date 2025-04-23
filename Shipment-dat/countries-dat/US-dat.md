
# US-dat.md

- [[PFCEXPRESS-dat]] - [[EURPOST-dat]] - [[USPST-dat]] - [[USPS-dat]]

## Express shipment

| method                         | status | set | max. | row | pre-tax                | title                                                                     |
| ------------------------------ | ------ | --- | ---- | --- | ---------------------- | ------------------------------------------------------------------------- |
| [[SZFedex-IP-dat]]             | x      | -   | -    | 33  | 5%                     | SZFEDEX-IP: Fedex Express (Ref. ETA 7-11 days)                            |
| [[SZFedex-IP-dat]] -tax-number |        | -   | -    | 33  | 5%                     | SZFEDEX-IP: Fedex Express (Ref. ETA 7-11 days, need Fedex Account Number) |
| [[SZFedex-IP-dat]] -pre-tax    |        | -   | -    | 33  | 5% + 60% (low declare) | SZFEDEX-IP: Fedex Express (Ref. ETA 7-11 days, 165% pre-tax)                   |
| [[HKDHL-dat]]                  | x      | -   | -    | 33  | 5%                     | HKDHL: DHL Express (Ref. ETA 6-10 days)                                   |
| [[HKDHL-dat]]  -pre-tax        |        | -   | -    | 33  | 5% + 60% (low declare) | HKDHL: DHL Express (Ref. ETA 6-10 days, 165% pre-tax)                          |
| [[CNUPS-dat]]                  | x      | -   | -    | 42  | 5%                     | CNUPS: UPS Express (Ref. ETA 3-8 days)                                    |
| [[CNUPS-dat]]  -pre-tax        |        | -   | -    | 42  | 5% + 60% (low declare) | CNUPS: UPS Express (Ref. ETA 3-8 days, 165% pre-tax)                           |



## updates 2025-04-23

*   For shipments originating from Mainland China or Hong Kong SAR destined for the United States and Puerto Rico, the shipping documents must specify the FedEx account number of the party responsible for paying customs duties.
*   **Duty Payment Options:**
    1.  **Prepaid:** You can choose to prepay the customs duties.
    2.  **Recipient Paid:** If the recipient is paying the duties, their FedEx account number must be provided for tax payment.
*   **Important:** It is crucial to determine which account will be used for duty payment *before* shipping.
*   **Account Holder:** The account used can belong to the sender, recipient, or a third party.
*   **Default Payer:** If a valid FedEx account number for duty payment is not provided with the shipment, the sender will be considered the default payer.
*   **Clothing Shipments:** Manufacturer Identification (MID) information is required for clothing products.

## Expendiated shipment

| method                   | status | set   | max. | row | pre-tax                | title                                                                   |
| ------------------------ | ------ | ----- | ---- | --- | ---------------------- | ----------------------------------------------------------------------- |
| [[PFCEXPRESS-dat]]       | x      |       |      |     |                        |                                                                         |
| [[USPST-dat]]            | x      |       |      |     |                        |                                                                         |
| [[EURPOST-dat]]          | x      | price | 120  | 7.5 | 5%                     | EURPOST: Intl. Air + Local Delivery (ref. ETA 15-25 days)               |
| [[EURPOST-dat]] -pre-tax |        | price | 120  | 7.5 | 5% + 60% (low declare) | EURPOST: Intl. Air + Local Delivery (ref. ETA 15-25 days, 165% pre-tax) |
| [[USPS-dat]]             | x      | price | 120  | 11  | 5%                     | USPS: Intl. + USPS (Ref. ETA: 8-15 days)                                |
| [[USPS-dat]]   -pre-tax  |        | price | 120  | 11  | 5% + 60% (low declare) | USPS: Intl. + USPS (Ref. ETA: 8-15 days, 165% pre-tax)                  |




### updates 2025-04-23

**Customs Clearance Update (Effective May 2nd, Eastern Time):**

*   **Policy Change:** For goods arriving on flights landing on or after May 2nd (Eastern Time), the T86 customs clearance mode and the $800 USD *de minimis* tax exemption are canceled. A new customs clearance mode will be implemented, resulting in applicable tariffs.
*   **Affected Services:** PFCEX, PFCEXB, [[PFCEXPRESS-dat]], [[EURPOST-dat]], PFCGL, [[USPST-dat]] (United States routes).
*   **Tariff Prepayment:** For the United States, a tariff prepayment of 160% of the declared value will be automatically collected upon warehousing. This amount is non-refundable and non-supplementary, and tax receipts will not be provided.
*   **Declaration Limit:** The maximum declared value is 248 USD.
*   **Customer Responsibility:** Customers must provide truthful, accurate, and complete cargo information.
*   **Monitoring:** We will continuously monitor changes in US policy and US-China tariff negotiations to make timely adjustments.
*   **Disclaimer:** During the initial implementation phase of the new policy, unexpected issues may arise. Please ensure accurate declaration of product names and values. Our company is not obligated to inspect customer shipments. We are not responsible for customs seizures, delays, supplementary taxes, or additional fines resulting from revaluation by US Customs. Please be aware of these changes and adjust your plans accordingly.

## General Updates 

### 2025-04-16

#### U.S. Customs Requirements Across Different Shipping Channels (as of 2025-04-16)

This post summarizes the U.S. customs requirements detailed in the provided shipping channel documents.  A key update across all channels is the cancellation of the 800 USD de minimis threshold, meaning all goods may be subject to tariffs.

**Common Requirements (Repeated Across All Documents):**

*   **Tariff Policy Change:**  The U.S. government issued an executive order on February 1, 2025, increasing tariffs on all goods from China by 10%, effective February 4, 2025. The 800 USD tariff exemption is no longer in effect.
*   **Accurate Information is Crucial:** Shippers are responsible for providing truthful and complete cargo information, including product name, amount, quantity, destination country HS Code, and weight.  Consequences of inaccurate information (detention, delays, confiscation, supplementary taxes, fines) are borne by the sender.
*   **MID Code:** The Manufacturer Identification Code (MID) is essential for US customs declaration. It serves as a substitute for the manufacturer's/shipper's/exporter's full name and address.
*   **MID Code Generation:**
    1.  **Country Code:** Two-letter ISO code of the supplier's country (e.g., GB for the United Kingdom).
    2.  **Company Name:** First three letters of the first two "words" in the company name. If no clear word separation, use the first six letters.
    3.  **Address Number:** Largest number from the address line (up to four digits).
    4.  **City Name:** First three letters of the city name.
*   **MID Code Example:**
    *   Company Name: ABC Company
    *   Address: 236 Wendell Ford Blvd, Ste 1304
    *   City: Erlanger
    *   Country: United States
    *   MID Code: USABC236ERL
*   **MID Code Precautions:** The MID Code must be accurate. Provincial codes may be needed for some cases (e.g., Canada). The largest number in the address should be selected.
*   **HS Code:** Provide accurate product names, ingredients, and HS Codes.
*   **US HS Code query website:** htps://rulings.cbp.gov/home
*   **US tariff rate query website:** https://hts.usitc.gov/

**Key Differences in U.S. Customs Requirements by Channel:**

| Requirement                    | HKDHLX-dat | SZFEDEX-IP-dat | HKUPS-F-dat | HKFEDEXIP-C-dat | HKDHL-dat     |
| ------------------------------ | ---------- | -------------- | ----------- | --------------- | ------------- |
| **MID Required Below 250 USD** | No         | No             | No          | No              | No            |
| **MID Required 250-800 USD**   | Yes        | Yes            | Yes         | Yes             | Yes           |
| **IOR Required 250-800 USD**   | No         | No             | No          | No              | No            |
| **MID & Tax ID Above 800 USD** | Yes        | Yes            | Yes         | Yes             | Yes           |
| **800 USD Threshold**          | Canceled   | Canceled       | Canceled    | Canceled        | Canceled      |
| **Billing Rule**               | N/A        | N/A            | N/A         | MID + Product   | N/A           |
| **US Zip Code Restrictions**   | N/A        | N/A            | N/A         | N/A             | 32-34 >800USD |




## ref 

- [[US]]
