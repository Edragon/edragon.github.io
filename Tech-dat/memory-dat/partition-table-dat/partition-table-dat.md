# partition-table-dat

https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/partition-tables.html

Here is the summary printed for the "Factory app, two OTA definitions" configuration:


| Name     | Type | SubType | Offset    | Size    | Flags |
|----------|------|---------|-----------|---------|-------|
| nvs      | data | nvs     | 0x9000    | 0x4000  |       |
| otadata  | data | ota     | 0xd000    | 0x2000  |       |
| phy_init | data | phy     | 0xf000    | 0x1000  |       |
| factory  | app  | factory | 0x10000   | 1M      |       |
| ota_0    | app  | ota_0   | 0x110000  | 1M      |       |
| ota_1    | app  | ota_1   | 0x210000  | 1M      |       |



