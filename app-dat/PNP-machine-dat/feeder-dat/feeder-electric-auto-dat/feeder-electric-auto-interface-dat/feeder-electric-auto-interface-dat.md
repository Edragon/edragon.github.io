# Feeder Electric Auto Interface Protocol

- [[feeder-dat]] - [[feeder-electric-auto-dat]] - [[feeder-electric-auto-interface-dat]]

This document outlines the communication protocol between the Host PC and the Feeder Controller.

## Serial Port Parameters

| Parameter    | Value |
| :----------- | :---- |
| Baud Rate    | 9600  |
| Data Bits    | 8     |
| Stop Bits    | 1     |
| Parity       | None  |
| Flow Control | None  |

## Protocol Format

- **Frame Structure**: Command string followed by `\r\n` (or ending with the character `T`).
- **Host Request**: The host sends a command terminated by `\r\n` or `T`.
- **Controller Response**: The controller parses the command and returns a response.
- **Characters**: All characters are visible ASCII (`< 0x7F`).

---

## Host → Device Commands

### 1. M600 — Step Feed
Requests the feeder to advance a specific number of steps.

**Format**: `M600N<addr>F<step>S<speed>\r\n`

| Field   | Description     | Values                                |
| :------ | :-------------- | :------------------------------------ |
| `addr`  | Device Address  | Registered address (e.g., 1, 2, 3...) |
| `step`  | Number of steps | 0~100 (0 = Stop)                      |
| `speed` | Speed level     | 0~5 (Default: 5)                      |

**Speed Level Mapping**:
| S Value | PWM Duty Cycle |
| :------ | :------------- |
| 0       | 0%             |
| 1       | 60%            |
| 2       | 70%            |
| 3       | 80%            |
| 4       | 90%            |
| 5       | 100% (Default) |

**Logic**:
- `step=0`: Returns `ok!\r\n` immediately without running the motor.
- `step>0`: 
    - Clears error status and sets `run_step`.
    - Starts **motor0** in Forward (CW) rotation.
    - Clears `is_error` flag and resets LED status.
    - Sets **motor1** (peeling) timeout: 10s if `speed=100` (max), otherwise 12s.

### 2. M601 — Reverse Mode
Manually reverses the motors for tape setup/removal.

**Format**: `M601N<addr>\r\n`

**Logic**:
- Stops both **motor0** and **motor1**.
- After 500ms, starts both motors in Reverse (CCW).
- Enters reversal mode (`is_back=1`).
- **KEY3** sensor control:
    - KEY3 not triggered (High): motor0 continues reversing.
    - KEY3 triggered (Low): motor0 stops.

### 3. M605 — Status Query
Queries the current operational state of the feeder.

**Format**: `M605N<addr>\r\n`

**Responses**:
- `ok\r\n`: Normal, no error.
- `error\r\n`: Error detected (e.g., motor timeout).
- `err0\r\n`: Busy (feeding in progress, `run_step != 0`).

### 4. M999 — Configuration (Address & Count)
Sets the starting address and the total number of connected feeders.

**Format**: `M999N<start_addr>F<count>\r\n`

- **Start Address**: 1 ~ 65535.
- **Count**: 1 ~ 3 (max `DEVICE_NUM`).
- **Logic**: Assigns sequential addresses and saves them to Flash persistence.

---

## Device → Host Reports (Async)

### 1. Step Completed — `ok!<addr>\r\n`
- **Trigger**: `KEYD` sensor detects the step is finished and `run_step` reaches 0.
- **Condition**: Only reported if `need_rpt=1` (set via M600).

### 2. Motor Timeout Error — `error1,<addr>\r\n`
- **Trigger**: **motor0** fails to complete the step within the timeout window.
- **Action**: Sets `is_error=1`, flashes the LED alarm.
- **Reset**: Requires a new `M600` command (with `step > 0`).

### 3. Address Identification — `addr:<addr>\r\n`
- **Trigger**: Long-pressing **KEY1** (~3s).
- **Usage**: Used to identify which physical feeder is mapped to which address.

---

## Hardware Logic Reference

### Unit Structure (Per Channel)
- **motor0**: Feeding motor (PWM-controlled). CW (Forward) = Feed, CCW (Reverse) = Retract.
- **motor1**: Peeling motor (On/Off). CW = Peel.
- **KEY1**: Manual Feed (Short press) / Report Address (Long press).
- **KEY2**: Manual Reversal (Short press) / Continuous Reversal (Long press).
- **KEYD**: Step completeness sensor.
- **KEY3**: Limit sensor for reversal mode.
- **LED**: Status indicator (Blinking = Error).

### Operational Workflow

#### Normal Feeding
1. Host sends `M600`.
2. **motor0** starts forward.
3. Every **KEYD** trigger decrements `run_step`.
4. When `run_step == 0`, **motor0** stops and reports `ok!`.
5. **motor1** (peeling) automatically runs for 2.5s whenever **KEY3** is released during feeding.

#### Error Handling
- If **motor0** runs longer than the timeout without finishing the steps, it stops and reports `error1`.
- The user or host must send a new `M600` command to clear the error flag before resuming.



## ref 

