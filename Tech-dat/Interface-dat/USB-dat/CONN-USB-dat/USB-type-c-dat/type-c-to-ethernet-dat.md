# type-c-to-ethernet-dat.md

Pixel supports using wired Ethernet directly via a USB-C adapter.  
Just use a USB-C to Ethernet adapter (with a built-in network card chip).

---

## 1. Supported Adapter Types
- USB-C → Ethernet (RJ45)
- Common built-in chips:
  - Realtek RTL8153 (common and highly compatible)
  - ASIX AX88179 / AX88772
  - Some USB 3.0 gigabit adapters

Note: There is no such thing as a "chipless" Type-C to RJ45 cable (pure wire); it must have a network card chip.

---

## 2. How to Use with Pixel Phones
1. Plug the USB-C to Ethernet adapter into the Pixel phone.
2. Connect a live network cable (LAN).
3. A notification will pop up at the bottom of the Pixel:
   - "Ethernet connected" or
   - "Wired network available"
4. The network will automatically switch to "Ethernet preferred."

Path:
Settings → Network & Internet → Ethernet

---

## 3. Reverse Network Sharing (Pixel → Share to Other Devices)
In theory, Pixel can also use:
- USB tethering
But USB tethering only supports phone → computer  
Not supported:
- Phone → router
- Phone → another Android device via USB-C to Ethernet

Reason: Ethernet adapters on Android usually only work in client mode (receiving network), not as a host for sharing.

If you want Pixel to share 4G/5G network → Ethernet for other devices, you need:
- Special ROM (like LineageOS, requires root; not recommended for minors or non-professional users)
- Or use Wi-Fi Hotspot → another device uses wireless-to-wired conversion

---

## 4. Recommended Adapters for Pixel (No Brand Restriction)
Recommended chips:
- Realtek RTL8153 (stable speed, least compatibility issues)
- AX88179 (stable)
- AX88772 (100Mbps version)

Some brands may state:
- "Plug and Play for Android"
- "Compatible with Pixel"

All of these can be used normally.

---

## 5. Speed
- If using USB-C → USB 3.0 → Gigabit Ethernet:  
  Up to 1Gbps (actual test: 600–900Mbps)
- If USB-C → USB 2.0 → 100Mbps port:  
  About 90Mbps

---

## 6. Common Issues
### Q: No response after plugging in?
- Try a different network cable
- Try another USB-C to Ethernet adapter  
- Some cheap adapters use unknown chips, not compatible with Android

### Q: Can Pixel use Wi-Fi and Ethernet at the same time?
- Yes, but the system prefers Ethernet
- You can manually switch the network source

### Q: Can Pixel share LAN network to a computer?
- Not by default (USB sharing only supports mobile data → USB)
- You can use Wi-Fi hotspot sharing (LAN → Wi-Fi)


## ref 

- [[USB-type-C-dat]]