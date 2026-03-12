

# ISR-dat

- [[HDK-dat]] - [[ISR-dat]] - [[interrupt-dat]]


An ISR is a specialized function that the ESP32 (or any MCU) executes immediately when a specific hardware event occurs. It "interrupts" the main program flow, handles the event, and then returns the CPU to exactly where it left off.

### 2. THE ANALOGY: "The Kitchen Timer"
- MAIN LOOP: You are busy chopping vegetables (the main task).
- INTERRUPT: A timer goes off (the hardware signal).
- ISR: You stop chopping, turn off the timer, and return to chopping.
- RESULT: You didn't have to keep looking at the clock (no "polling").

### 3. THE "THREE GOLDEN RULES" FOR ESP32 ISRs
To prevent system crashes or "Watchdog Timer" reboots, follow these:

1. KEEP IT SHORT: 
   Only toggle a flag or increment a counter. Never use `delay()`, 
   `Serial.print()`, or long loops inside an ISR.

2. USE IRAM_ATTR: 
   The function must be decorated with `void IRAM_ATTR name()`. 
   This stores the code in Internal RAM so the CPU can access it 
   instantly, even if the Flash memory is busy.

3. USE VOLATILE VARIABLES: 
   Any variable changed inside an ISR and read in the main loop 
   must be declared as `volatile` (e.g., `volatile int count;`).

### 4. ISR vs. POLLING
- POLLING: Constantly checking `if (digitalRead(pin) == LOW)`. 
  (Wasteful, slow, can miss fast signals).
- ISR: The hardware tells the CPU the moment it happens. 
  (Efficient, near-instant, perfect for motor encoders).

### 5. EXECUTION FLOW
[ Signal ] -> [ CPU Pauses Loop ] -> [ ISR Runs ] -> [ CPU Resumes Loop ]


## ref 


