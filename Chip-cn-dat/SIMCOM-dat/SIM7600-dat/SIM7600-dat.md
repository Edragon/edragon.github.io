
# SIM7600-dat


## smplified pins 

| Pin name       | Pin number                              |
| :------------- | :-------------------------------------- |
| **VCC**        | 2,24,39,41,52                           |
| **GND**        | 4,9,15,18,21,26,27,29,34,35,37,40,43,50 |
| **PERST#**     | 22                                      |
| **USB_DP**     | 38                                      |
| **USB_DN**     | 36                                      |
| **USIM_VDD**   | 8                                       |
| **USIM_DATA**  | 10                                      |
| **USIM_CLK**   | 12                                      |
| **USIM_RST**   | 14                                      |
| **USIM_DET**   | 16                                      |
| **PCM_CLK**    | 45                                      |
| **PCM_SYNC**   | 47                                      |
| **PCM_IN**     | 49                                      |
| **PCM_OUT**    | 51                                      |
| **UART_RXD**   | 17                                      |
| **UART_TXD**   | 19                                      |
| **UART_RI**    | 44                                      |
| **UART_DTR**   | 46                                      |
| **SCL**        | 30                                      |
| **SDA**        | 32                                      |
| **WAKE#/MICP** | 1                                       |
| **MICN**       | 3                                       |
| **EARP**       | 5                                       |
| **EARN**       | 7                                       |
| **W_DISABLE#** | 20                                      |
| **LED_WWAN#**  | 42                                      |
| **NC**         | 6,23,25,28,31,33,45,47,48,49,51         |



## pins 

| Pin name       | Pin number                              | I/O  | Description                                                                                                                     | Comment                                                                                                                                                           |
| :------------- | :-------------------------------------- | :--- | :------------------------------------------------------------------------------------------------------------------------------ | :---------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **VCC**        | 2,24,39,41,52                           | I    | Power supply for module                                                                                                         | 3.3V typical                                                                                                                                                      |
| **GND**        | 4,9,15,18,21,26,27,29,34,35,37,40,43,50 | -    | Ground                                                                                                                          | -                                                                                                                                                                 |
| **PERST#**     | 22                                      | I    | Reset input (Active low)                                                                                                        | If unused, keep open.                                                                                                                                             |
| **USB_DP**     | 38                                      | I/O  | USB 2.0 high speed port for data transfer, voice call, debug and FW download, etc.                                              | If unused, keep open.                                                                                                                                             |
| **USB_DN**     | 36                                      | I/O  | USB 2.0 high speed port for data transfer, voice call, debug and FW download, etc.                                              | If unused, keep open.                                                                                                                                             |
| **USIM_VDD**   | 8                                       | O    | Power output for USIM card, its output Voltage depends on USIM card type automatically. Its output current is up to 50mA.       | -                                                                                                                                                                 |
| **USIM_DATA**  | 10                                      | I/O  | USIM Card data I/O, which has been pulled up via a 100KΩ resistor to USIM_VDD internally. Do not pull it up or down externally. | -                                                                                                                                                                 |
| **USIM_CLK**   | 12                                      | O    | USIM clock.                                                                                                                     | Make sure the rise time and fall time of USIM_CLK less than 40ns                                                                                                  |
| **USIM_RST**   | 14                                      | O    | USIM Reset.                                                                                                                     | -                                                                                                                                                                 |
| **USIM_DET**   | 16                                      | I    | USIM card detect.                                                                                                               | -                                                                                                                                                                 |
| **PCM_CLK**    | 45                                      | O    | PCM data bit clock.                                                                                                             | If these pins are unused, keep open.                                                                                                                              |
| **PCM_SYNC**   | 47                                      | O    | PCM data frame sync.                                                                                                            | If these pins are unused, keep open.                                                                                                                              |
| **PCM_IN**     | 49                                      | I    | PCM data input.                                                                                                                 | If these pins are unused, keep open.                                                                                                                              |
| **PCM_OUT**    | 51                                      | O    | PCM data output.                                                                                                                | If these pins are unused, keep open.                                                                                                                              |
| **UART_RXD**   | 17                                      | I    | Receive Data                                                                                                                    | -                                                                                                                                                                 |
| **UART_TXD**   | 19                                      | O    | Transmit Data                                                                                                                   | -                                                                                                                                                                 |
| **UART_RI**    | 44                                      | O    | Ring Indicator                                                                                                                  | -                                                                                                                                                                 |
| **UART_DTR**   | 46                                      | I    | DTE get ready                                                                                                                   | -                                                                                                                                                                 |
| **SCL**        | 30                                      | O    | I2C clock output                                                                                                                | Pulled up inside the module; If unused, keep open. 1.8V interface                                                                                                 |
| **SDA**        | 32                                      | I/O  | I2C data input/output                                                                                                           | Pulled up inside the module; If unused, keep open. 1.8V interface                                                                                                 |
| **WAKE#/MICP** | 1                                       | I/O  | SIM7600 Series-PCIE: Wake up host<br>SIM7600 Series-PCIEA: MIC positive input                                                   | If unused, keep open. If Analog audio is available, wake up function is invalid. If Analog audio is needed, please consult our sales staff, for more information. |
| **MICN**       | 3                                       | I    | SIM7600 Series-PCIE: NC<br>SIM7600 Series-PCIEA: MIC negative input                                                             | If unused, keep open. If Analog audio is available, wake up function is invalid. If Analog audio is needed, please consult our sales staff, for more information. |
| **EARP**       | 5                                       | O    | SIM7600 Series-PCIE: NC<br>SIM7600 Series-PCIEA: Receiver positive output                                                       | If unused, keep open. If Analog audio is available, wake up function is invalid. If Analog audio is needed, please consult our sales staff, for more information. |
| **EARN**       | 7                                       | O    | SIM7600 Series-PCIE: NC<br>SIM7600 Series-PCIEA: Receiver negative output                                                       | If unused, keep open. If Analog audio is available, wake up function is invalid. If Analog audio is needed, please consult our sales staff, for more information. |
| **W_DISABLE#** | 20                                      | I    | RF Control Input                                                                                                                | If unused, keep open.                                                                                                                                             |
| **LED_WWAN#**  | 42                                      | O    | Network Status Indication output                                                                                                | If unused, keep open.                                                                                                                                             |
| **NC**         | 6,23,25,28,31,33,45,47,48,49,51         | --   | No connection                                                                                                                   | Keep open                                                                                                                                                         |