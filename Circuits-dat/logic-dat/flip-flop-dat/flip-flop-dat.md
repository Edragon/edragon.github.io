
# flip-flop-dat

- [[flip-flop-dat]] - [[logic-dat]] - [[digital-dat]] - [[flip-flop-d-dat]]


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

- [[flip-flop-d-dat]]

In digital logic, besides the **D Flip-Flop**, there are three other primary types of flip-flops, each with distinct behaviors and use cases:

---

### 1. SR Flip-Flop (Set-Reset)

The SR flip-flop is the most basic building block of memory elements, featuring two main control inputs: **S (Set)** and **R (Reset)**.

* **How it works**:
* $S = 1, R = 0$: Sets the output $Q$ to `1`.
* $S = 0, R = 1$: Resets the output $Q$ to `0`.
* $S = 0, R = 0$: Holds the previous state.


* **The Catch (Invalid State)**: If both $S = 1$ and $R = 1$ (for a standard NOR-gate implementation), it leads to an unpredictable or forbidden output state. Because of this limitation, it is rarely used directly in complex synchronous systems without modification.

---

### 2. JK Flip-Flop

The JK flip-flop is a refined, "universal" version of the SR flip-flop that resolves the invalid state problem. It has two inputs: **J (Jump/Set)** and **K (Kill/Reset)**.

* **How it works**:
* $J = 0, K = 0$: Holds the previous state.
* $J = 0, K = 1$: Resets output $Q$ to `0`.
* $J = 1, K = 0$: Sets output $Q$ to `1`.
* $J = 1, K = 1$: **Toggle mode**—inverts the current output state on the clock edge ($Q$ becomes $\bar{Q}$).


* **Application**: Highly versatile; it can be wired to act as an SR, T, or D flip-flop.

---

### 3. T Flip-Flop (Toggle)

The T flip-flop is a simplified single-input variant derived from the JK flip-flop (by tying the J and K inputs together). It has a single **T (Toggle)** input.

* **How it works**:
* $T = 0$: Holds the current state (no change).
* $T = 1$: Toggles the output state on every clock edge ($Q$ flips from 0 to 1, or 1 to 0).


* **Application**: Widely used in **binary counters** and frequency divider circuits where the output needs to alternate state with every trigger pulse.


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