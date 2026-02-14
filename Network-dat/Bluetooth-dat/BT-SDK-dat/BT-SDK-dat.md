
# BLE-SDK-dat

- programmer - [[BT-SDK-dat]] - [[DPR1112-dat]] - [[qualcomm-dat]]

- [[CSR8635-dat]] - [[CSR-dat]] - [[BT-SDK-dat]]



## Which BLE Example to Use for Sending ADC Voltage to Phone

Your goal:  
- ESP32 reads ADC (battery voltage).  
- Phone should receive/read the value over BLE.  

### Best Choices
- **Notify** ✅  
  - ESP32 acts as a BLE server.  
  - Sends **automatic notifications** with the ADC voltage.  
  - Best if you want real-time updates on your phone.  

- **Server** ✅  
  - ESP32 acts as a BLE server.  
  - Phone connects and **reads the ADC value on demand**.  
  - Good if you don’t need constant updates.  

- **UART** ✅  
  - Implements a BLE serial-like service.  
  - You can "print" ADC values and read them with a BLE UART app.  
  - Easiest for testing/debugging, but less standard.  

### Not Suitable
- **Beacon / iBeacon / EddystoneTLM_Beacon / EddystoneURL_Beacon** ❌  
  - These only broadcast fixed or simple data.  
  - Not designed for continuous ADC updates.  

- **Scan / Beacon_Scanner / Client / Client_secure_static_passkey** ❌  
  - These examples make ESP32 a **client/scanner**, not a server.  
  - Your phone should be the client, so not useful here.  

- **BLE5_extended_scan / BLE5_multi_advertising / BLE5_periodic_advertising / BLE5_periodic_sync** ❌  
  - Advanced BLE5 features (scanning, multi-adv, periodic sync).  
  - Not needed for simple ADC-to-phone communication.  

- **Server_multiconnect / Server_secure_authorization / Server_secure_static_passkey** ❌  
  - Variants of the Server example with multi-client or security features.  
  - Only needed if you want multiple phones connected or secure pairing.  




## ref 

- [[bluetooth-dat]]