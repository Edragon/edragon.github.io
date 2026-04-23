

# EY-25M-mesh-dat.md

- [[mesh-node-dat]] - [[EY-25M-mesh-dat.md]] - [[EY-25M-dat]]


## MESH Networking Module Configuration Guide

The module defaults to **MESH networking mode**, so manual setup is typically unnecessary for standard use. To manually configure the MESH mode, send the command `AT+ROLE5`, followed by `AT+RESET` to restart the device and apply changes.

---

## 1. Configuration Examples

### Example 1: Routing Node Configuration
This setup configures the device as a standard routing node capable of controlling other devices in the network via hardware buttons.

1.  **Set Network ID (NETID) to 1122:** `AT+NETID1122`
2.  **Set Local Short Address to 0005:** `AT+MADDR0005`
3.  **Set Node Class to Routing Node:** `AT+MCLSS0`
4.  **Configure KEY1 Broadcast:** `AT+KEY1,0008,3,1`  
    *Configures KEY1 to broadcast a signal that controls the **OUT3** output on all devices.*
5.  **Apply Changes:** `AT+RESET`
    *Result: KEY1 can now control the OUT3 IO levels of all devices in the network.*

### Example 2: Low-Power Terminal Node
Ideal for battery-operated devices. In this mode, the device consumes only **3µA**.

1.  **Set Network ID (NETID) to 1122:** `AT+NETID1122`
2.  **Set Local Short Address to 0005:** `AT+MADDR0005`
3.  **Set Node Class to Low-Power Terminal:** `AT+MCLSS1`
4.  **Configure KEY1 Broadcast:** `AT+KEY1,0008,3,1`
5.  **Apply Changes:** `AT+RESET`
    *Behavior: Data is sent when the key is pressed; the device enters **Deep Sleep** immediately upon key release.*

### Example 3: Routing Node with Manual Hex Commands
Configure the device as a router and send raw data to the network.

1.  **Set Network ID (NETID) to 1122:** `AT+NETID1122`
2.  **Set Local Short Address to 0005:** `AT+MADDR0005`
3.  **Set Node Class to Routing Node:** `AT+MCLSS0`
4.  **Apply Changes:** `AT+RESET`

---

## 2. Data Transmission (Hex Format)

The following commands use the prefix `41 54 2b 4d 45 53 48` (which translates to `AT+MESH`).

| Action | Hex Command |
| :--- | :--- |
| **Broadcast Data** (1122334455) to all devices | `41 54 2b 4d 45 53 48 00 FF FF 11 22 33 44 55 0D 0A` |
| **Point-to-Point** (1122334455) to Device 0008 | `41 54 2b 4d 45 53 48 00 00 08 11 22 33 44 55 0D 0A` |
| **Remote Control** (Set 0008 OUT1 Low + ACK) | `41 54 2b 4d 45 53 48 11 00 08 AA B2 E7 01 00` |

---

## 3. Command Reference Table

| Command | Function | Description |
| :--- | :--- | :--- |
| `AT+ROLE5` | Set Mode | Configures the module for MESH networking. |
| `AT+NETIDxxxx` | Network ID | Sets the group ID (e.g., 1122). |
| `AT+MADDRxxxx` | Short Address | Sets the unique device address (e.g., 0005). |
| `AT+MCLSS0` | Router Mode | Always-on node that routes packets. |
| `AT+MCLSS1` | Terminal Mode | Low-power node (3µA) for end-devices. |
| `AT+KEYx,addr,io,val` | Key Mapping | Binds a physical key to a remote IO action. |
| `AT+RESET` | Restart | Required to save and execute new settings. |
## ref 

