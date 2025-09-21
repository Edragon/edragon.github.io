
# MDI-dat

In networking, **MDI** stands for **Medium Dependent Interface**. It refers to the physical and electrical interface on a network device (like a computer's network interface card (NIC) or a router port) that connects to the network transmission medium, typically a twisted-pair Ethernet cable (like Cat5e or Cat6).

Key points about MDI:

1.  **Pinout:** An MDI port uses a specific pinout where pins 1 and 2 are typically used for transmitting (TX) data, and pins 3 and 6 are used for receiving (RX) data (for 10/100 Mbps Ethernet).
2.  **Connection:** End devices like computers and routers usually have MDI ports.
3.  **MDI vs. MDI-X:** Network infrastructure devices like hubs and switches traditionally used **MDI-X** (MDI Crossover) ports. MDI-X ports swap the transmit and receive pairs internally (pins 1 & 2 are RX, pins 3 & 6 are TX). This allows a standard "straight-through" Ethernet cable to connect an MDI device (computer) to an MDI-X device (switch).
4.  **Cabling:** Connecting two MDI ports (e.g., computer to computer directly) or two MDI-X ports (switch to switch) traditionally required a "crossover" cable, which swaps the TX and RX pairs within the cable itself.
5.  **Auto MDI-X:** Modern network interfaces often feature **Auto MDI-X**. This technology automatically detects the type of port (MDI or MDI-X) on the other end of the cable and configures its own port accordingly. This eliminates the need for specific straight-through or crossover cables, as the interface handles the necessary pin swapping electronically. Most modern devices support Auto MDI-X.


## ref 

- [[network-dat]]

