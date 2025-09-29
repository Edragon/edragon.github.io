
# data-storage-dat

- [[memory-dat]] - [[NVS-dat]] - [[SPIFF-dat]] - [[SD-dat]] - [[EEPROM-dat]]



- [[ESP32-SDK-dat]]



## data storage 

- [[NVS-dat]] - [[SPIFF-dat]] - [[SD-dat]]

| Method                                       | Size Limit                                     | Persistent after reset/power off?  | Use Case                                            |
| -------------------------------------------- | ---------------------------------------------- | ---------------------------------- | --------------------------------------------------- |
| **Global variables (RAM)**                   | Up to available RAM (~500KB)                   | ❌ No                               | Temporary data while program is running             |
| **RTC RAM**                                  | ~8 KB                                          | ✅ Across reset, ❌ across power off | Store small state info between deep sleep cycles    |
| **NVS (Non-Volatile Storage / Preferences)** | Key–value pairs, ~4 KB per partition           | ✅ Yes                              | Config values, Wi-Fi credentials, small settings    |
| **SPIFFS / LittleFS**                        | Depends on flash partition (100KB–1MB typical) | ✅ Yes                              | Store files, logs, calibration data                 |
| **SD Card**                                  | GBs                                            | ✅ Yes                              | Large data logging, images, audio                   |
| **External EEPROM**                          | Varies (e.g. 4KB–1MB chips)                    | ✅ Yes                              | Additional storage if onboard flash is insufficient |


### BLE Data Update Workflow (ESP32)

- [[BLE-dat]]

1. **ESP32 runs a BLE server**  
   - Creates a characteristic for data transfer.

2. **Phone/PC app connects via BLE**  
   - Splits the file into small BLE packets (~20 bytes each).  
   - Sends them to ESP32 characteristic.

3. **ESP32 receives packets**  
   - Reassembles them into a buffer.  
   - Writes the buffer into SPIFFS/LittleFS (or NVS for small key-values).

4. **Program reloads data**  
   - Next time your code runs (or immediately after update),  
     it reads the updated file/config from storage.



## ref 

- [[memory-dat]]