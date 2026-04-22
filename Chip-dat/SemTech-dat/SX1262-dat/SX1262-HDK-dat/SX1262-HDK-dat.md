
# SX1262-HDK-dat

- [[rf-switch-dat]] - [[network-dat]]

- [[lora-HDK-dat]]

- [[LORA-HDK-dat]]  - [[SX1262-HDK-dat]] - [[SX1262-dat]]

- [[SX1262-MD1-dat]]


## wiring 


### Typical Minimum Connections (MCU)

|      | SX1262 | MCU              | arduino | [[DVA1009-dat]] |
| ---- | ------ | ---------------- | ------- | --------------- |
|      | VDD_IN | 3.3V             |         |                 |
|      | VSS    | GND              |         |                 |
|      | NSS    | GPIO             |         |                 |
|      | SCK    | SPI SCK          |         |                 |
|      | MOSI   | SPI MOSI         |         |                 |
|      | MISO   | SPI MISO         |         |                 |
|      | BUSY   | GPIO (input)     | D3      | 3               |
| DIO1 | DIO1   | GPIO (interrupt) | D5      | 2               |
|      | NRST   | GPIO (reset)     | A0      | 9               |
|      | DIO2   | x                |
|      | DIO3   | x                |


---

### Important Wiring Notes

- **BUSY pin must be monitored** before any SPI command
- **DIO1 is mandatory** for RX/TX interrupt handling
- RF pins **require impedance matching** (do not connect antenna directly)
- Use **short traces and good grounding** for RF stability




## wiring while NOT using DIO2 control TXEN / RXEN of RF switch

(NSS_d + SCK + MOSI + MISO) + BUSY + DIO1_irq + RXEN + TXEN + RESET_optional 



## ✅ Required Pins (Basic SPI Communication)

| Pin            | Required | Purpose                     |
| -------------- | -------- | --------------------------- |
| **NSS_d** (CS) | ✅ Yes    | SPI chip select (NSS)       |
| **SCK**        | ✅ Yes    | SPI clock                   |
| **MOSI**       | ✅ Yes    | SPI data from MCU to SX1262 |
| **MISO**       | ✅ Yes    | SPI data from SX1262 to MCU |
| **BUSY**       | ✅ Yes    | Indicates radio busy status |

> 🧠 `BUSY` must be monitored before and after sending SPI commands to ensure the radio is ready.

---

## ⚠️ Conditional / Optional Pins

| Pin       | Required?  | When Needed                                                                        |
| --------- | ---------- | ---------------------------------------------------------------------------------- |
| **RESET** | ⚠️ Optional | Recommended for better stability; allows hard reset                                |
| **DIO1**  | ⚠️ Optional | Required if using interrupt-based handling (e.g., RX done, TX done)                |
| **DIO2**  | ⚠️ Optional | Required only if using for RF switch/FEM control via `SetDio2AsRfSwitchCtrl(true)` |
| **RXEN**  | ❌ No       | Not needed if using DIO2 for single-pin FEM control                                |
| **TXEN**  | ❌ No       | Same as above                                                                      |



def in UserConfig.h

    //spi
    #define LCC68_NSS_PORT   GPIOA
    #define LCC68_NSS_PIN    GPIO_PIN_4

    #define LCC68_SCK_PORT   GPIOA
    #define LCC68_SCK_PIN    GPIO_PIN_5

    #define LCC68_MOSI_PORT  GPIOA
    #define LCC68_MOSI_PIN   GPIO_PIN_7

    #define LCC68_MISO_PORT  GPIOA
    #define LCC68_MISO_PIN   GPIO_PIN_6

    #define LCC68_NRST_PORT GPIOA
    #define LCC68_NRST_PIN  GPIO_PIN_3

    #define LCC68_BUSY_PORT GPIOA
    #define LCC68_BUSY_PIN  GPIO_PIN_2

    #define LCC68_DIO1_PORT GPIOC
    #define LCC68_DIO1_PIN  GPIO_PIN_15

    #define LCC68_RXEN_PORT GPIOA
    #define LCC68_RXEN_PIN  GPIO_PIN_1

    #define LCC68_TXEN_PORT GPIOA
    #define LCC68_TXEN_PIN  GPIO_PIN_0

    //Uart
    #define LOG_UART_TX_PORT GPIOA
    #define LOG_UART_TX_PIN  GPIO_PIN_9
    #define LOG_UART_RX_PORT GPIOA
    #define LOG_UART_RX_PIN  GPIO_PIN_10


    #define LORA_FRE									915000000	// frequency
    #define LORA_PREAMBLE_LENGTH                        8        // PREAMBLE LENGTH
    #define LORA_SX126x_SYMBOL_TIMEOUT                  0         // Symbols(SX126x)
    #define LORA_FIX_LENGTH_PAYLOAD_ON                  false			// PAYLOAD FIX LENGTH
    #define LORA_IQ_INVERSION_ON                        false			// IQ INVERSION

    #define SIZE_DATA  255




## wiring while DIO2 control TXEN / RXEN of RF switch


NSS_d + SCK + MOSI + MISO + BUSY + DIO2
(Optional: RESET + DIO1)



       Microcontroller                   SX1262                        RF Switch / FEM
     +-------------------+         +---------------+               +---------------------+
     |                   |         |               |               |                     |
     |        MISO <-----+---------+ MISO          |               |                     |
     |        MOSI ----->+---------+ MOSI          |               |                     |
     |        SCK  ----->+---------+ SCK           |               |                     |
     |        NSS  ----->+---------+ NSS           |               |                     |
     |        RESET ---->+---------+ NRESET        |               |                     |
     |                   |         |               |               |                     |
     |        GND  ------+---------+ GND           |---------------+ GND                 |
     |        3.3V ------+---------+ VDD           |---------------+ VCC (3.3V)          |
     |                   |         |               |               |                     |
     |                   |         | RF_IO ------- +---------------- RF_IO               |
     |                   |         |               |               |                     |
     |                   |         | DIO2 ---------+---------------> CTRL (TX/RX EN)     |
     |                   |         |               |               |                     |
     +-------------------+         +---------------+               +---------------------+

wiring in table 

| Pin    | Name                | Connects To	Purpose    |
| ------ | ------------------- | ---------------------- |
| NSS    | MCU GPIO (CS)       | SPI chip select        |
| SCK    | MCU SPI clock       | SPI clock line         |
| MOSI   | MCU SPI MOSI        | SPI data to SX1262     |
| MISO   | MCU SPI MISO        | SPI data from SX1262   |
| DIO2   | FEM CTRL / TXEN     | Auto RF switch control |
| RF_IO  | RF switch input     | RF path in/out         |
| NRESET | MCU GPIO (optional) | SX1262 reset pin       |
| VDD    | 3.3V                | Power supply           |
| GND    | Ground              | Common ground          |


coding 

    // Enable automatic RF switch control on DIO2
    Radio.SetDio2AsRfSwitchCtrl(true);

    // Set DIO2 as output (only needed if using raw DIO2 control in some cases)
    Radio.SetDioAsOutput(2); // Not always required

