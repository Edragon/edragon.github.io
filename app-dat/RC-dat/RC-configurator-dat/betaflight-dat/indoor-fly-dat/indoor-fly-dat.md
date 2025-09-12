
# indoor-fly-dat

```markdown
# Mobula8 Betaflight Indoor Setup Guide (Beginner-Friendly)

## 1. Install and Connect
1. Install [Betaflight Configurator](https://github.com/betaflight/betaflight-configurator/releases) on your PC.
2. Connect Mobula8 via USB.
3. Flash the latest compatible Betaflight firmware for **F4 FC** (Mobula8 usually F4 1S or 2S version).
4. After flashing, reconnect to Betaflight Configurator.

---

## 2. Ports Tab
- **UART1**: Serial RX (for FrSky or other receiver)
- **UART2**: Blackbox (optional)
- **UART3**: Unused
- Save and reboot.

---

## 3. Configuration Tab
- **Mixer**: `Quad X`
- **ESC/Motor protocol**: `DSHOT600`
- **Gyro Update Frequency**: `8 kHz`
- **PID Loop Frequency**: `4 kHz` (smooth indoor flight)
- **Motor Stop**: `ON`
- **Air Mode**: `ON`
- **Small Angle Mode**: `ON` (helps beginner indoor flying)
- **Arming Angle Limit**: `180°`
- **Gyro Lowpass Filter**: default

---

## 4. Modes Tab
- **ARM**: assign a switch on your transmitter
- **ANGLE / HORIZON Mode**: assign a switch for beginner-friendly flight
- **BEEPER**: assign for lost quad alert

---

## 5. PID / Rate Profiles (Indoor Smooth)
**Rate Profile: Indoor Smooth**
```

RC Rate: 0.60
Super Rate: 0.45
Expo: 0.30

```

**PID Values**
```

ROLL / PITCH

    P: 38 / I: 40 / D: 18

YAW

    P: 55 / I: 50 / D: 0

```
- Low and soft values for smooth response.
- Adjust slightly if oscillation occurs.
- Lower values = smoother, less twitchy flight.

---

## 6. Filters Tab
- **Gyro Lowpass / Dynamic Filter**: default
- **Dterm Lowpass**: default
- **Motor Lowpass / Boost**: default
- Avoid aggressive filtering indoors (may introduce lag).

---

## 7. Receiver Tab
- **Channel Map**: usually `AETR1234`
- Verify RX is responding in real-time graph.
- **Deadband**: 5 (smooth small stick movements)

---

## 8. Battery and Power
- Indoor 1S or 2S: use 3.7V–7.4V 300–450mAh LiPo
- Enable **Battery Voltage Monitoring** in Configuration
- Safe cut-off for 1S: 3.5V

---

## 9. Motor Test / Prop Safety
- Remove props before testing.
- Test each motor spins in correct direction.
- Reverse motors in Motors tab if needed.

---

## 10. Tips for Indoor Flying
- Fly in **ANGLE or HORIZON** mode for smooth control.
- Gentle stick movements only; avoid aggressive flips indoors.
- Lower rates = easier for beginners.
- Slightly increase I term (+5) if drifting too much.

---

## 11. Optional Enhancements
- **Blackbox**: record and analyze PID tuning.
- **Battery Beeper**: low voltage alert.
- **LED Strip**: orientation aid indoors.

---

