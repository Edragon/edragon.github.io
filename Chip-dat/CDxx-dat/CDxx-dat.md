

# CDxx-dat


- [[CDxx-dat]] - [[74xx-dat]] - [[LMxx-dat]]

- [[CD4001-dat]] 


* **4161 (4-Bit Synchronous Counter):** Acts as the **Binary Address Generator**. It receives pulses from the NE555 and counts from 0 to 15 in binary ($0000$ to $1111$).


* **4067 (16-Channel Analog Multiplexer):** Acts as the **Electronic Switch**. It uses the 4-bit address from the 4161 to connect a "Common" pin to one of 16 different input/output channels.

- [[CD4067-dat]]


## apps 


* **Analog Step Sequencer:** Used in modular synthesizers to cycle through 16 different voltages (set by potentiometers) to create a musical melody.

#### Logic Flow
1. **Clocking:** The **NE555** triggers the `CLK` pin of the **4161**.
2. **Counting:** The **4161** outputs a 4-bit binary number ($Q_A, Q_B, Q_C, Q_D$).
3. **Addressing:** Those 4 pins connect to the Address pins ($S_0, S_1, S_2, S_3$) of the **4067**.
4. **Switching:** The **4067** opens the specific channel corresponding to that binary number.


## ref 


