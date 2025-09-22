
# flip-flop-dat

## chip 

- [[TI-dat]] - [[CD4013B-dat]] == CD4013B CMOS Dual D-Type Flip-Flop

## info 

A **flip-flop** is a **basic digital storage circuit** used to store **1 bit of binary information (0 or 1)**.  
It is a fundamental building block for **registers, counters, and state machines** in digital systems.

---

## 2. Functions
- **Data Storage**: Remembers the current input state until the next trigger signal arrives.
- **Synchronous Control**: Most flip-flops sample and store data based on a **clock signal (CLK)**.
- **State Retention**: Maintains its current output even if the input disappears until the next trigger.

---

## 3. Basic Types

1. **SR Flip-Flop (Set-Reset)**
   - Inputs: S (Set), R (Reset)  
   - Behavior:
     - S=1, R=0 → Q=1  
     - S=0, R=1 → Q=0  
     - S=0, R=0 → Keep current state  
     - S=1, R=1 → Forbidden/invalid state

2. **D Flip-Flop (Data/Delay)**
   - Inputs: D (Data), CLK (Clock)  
   - Behavior:
     - Samples D on clock rising edge and holds Q until the next clock edge.

3. **JK Flip-Flop**
   - Resolves the forbidden state of SR flip-flop.  
   - J=K=1 → Toggle current state Q

4. **T Flip-Flop (Toggle)**
   - Toggles its state on each clock pulse.  
   - Commonly used in counters.

---

## 4. Working Principle

    Clock ↑   ──► Flip-flop samples input D
    D = 1     ──► Q = 1
    D = 0     ──► Q = 0
    Q holds the value until the next clock edge

## 5. Applications

- Registers
- Counters
- Finite State Machines (FSM)
- Data synchronization/delay

## ref 

- [[circuits-dat]]