
# TB4117-dat.md

## UVC mode 

- [[UVC-dat]]

## NCM mode 

wiring 

- VCC <-> VCC, 
- D- <-> D-, 
- D+ <-> D+,
- GND <-> CGND

### change to UVC mode 

### Step-by-Step: Changing TB4117 Module to UVC Mode (Hikvision)

#### 1. Prepare the Environment

- Install a Linux virtual machine (VM) on your computer.
- Map the TB4117 device to the Linux VM so it is recognized as a USB network card.
- (Optional) Disable IPv6 in the Linux system.
- Manually set the IPv4 address range to: `192.168.1.2-192.168.1.64` with subnet mask `255.255.255.0`.

#### 2. Access the Device Web Interface

- Open a browser in the Linux VM and go to `192.168.1.64`.
- Log in to the Hikvision interface using:
  - Username: `admin`
  - Password: `a1234567`
- After logging in, navigate to System Maintenance and locate the option to change the USB protocol.
- **Important:** Once you change the USB protocol, you will need an 88179 chipset USB network card connected to a router to access the admin interface again. Make sure all necessary parameters are set before changing the protocol.

#### 3. If Password Is Incorrect

- Purchase a USB network card with the 88179 chipset.
- Connect the device to the network card and pull down pin 2 (the only empty pin) during connection.
- Power both the network card and the module, and connect the network card's Ethernet cable to your router.

#### 4. Resetting Password via Hikvision Website

- Use Hikvision's official "Device Network Scan" tool to scan for devices.
- Click "Change Password" and export the key file.
- Send the exported key file to Hikvision support.
- Import the returned decrypted file to reset the password.
- If using the network card, change the device's IP address to match your router's subnet (e.g., if your router assigns `192.168.31.2`, set the device to `192.168.31.xx`). This allows you to log in from Windows.

#### 5. Additional Notes

- Price for this module has increased. Previously purchased for 268 RMB (shipping included), but now prices are around 300 RMB.
- Only recommended if the seller offers UVC protocol conversion and provides the device password for 300 RMB (shipping included).
- Main issues: complicated parameter adjustments and large temperature measurement errors. Maximum temperature observable is 121°C.




## ref 


- [[TB4117]] - [[hikvision]]