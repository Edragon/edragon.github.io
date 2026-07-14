
# SMO1073-dat

- [[playstation-dat]]



## Info

[product url - Biaxial Joystick Module](https://www.electrodragon.com/product/playstation2-joystick-module/)

### Board Map, Dimension, Pins, chip info, Use Guide, Setup Jumper, etc.


### Product Parameters
| Item | Description |
| :--- | :--- |
| **Product Name** | Joystick Module (Dual-axis button joystick) |
| **Dimensions** | 34.0mm * 26.0mm * 32.0mm (L x W x H) |
| **Color** | Black |
| **Weight** | 11.0g (including packaging) |
| **Packaging** | Individual anti-static bag |
| **Material** | FR4 + Electronic components |

### Introduction
The dual-axis button joystick sensor module is built with a PS2 joystick potentiometer. It features (X, Y) dual-axis analog outputs and a (Z) 1-channel digital button output. Compatible with Arduino sensor shields, it's ideal for creating interactive projects like remote controllers. The XY and Z-axis circuits are independently broken out, allowing users to connect directly to expansion boards using standard 3-pin Arduino cables.

### Performance & Features
1. **Input Voltage Range:** DC 3.3V to 5V.
2. **Output Signals:** The module provides two analog outputs and one digital output. Analog values correspond to the (X, Y) axis offset, while the digital output indicates the Z-axis (button) state.
3. **Arduino Integration:** Can be programmed with Arduino controllers and connected via sensor shields for creative interactive projects.
4. **Resistor Mechanism:** The joystick houses two 10K resistors; voltage readings shift based on movement. At 5V supply, the center (idle) voltage for X and Y is ~2.5V. Moving in one direction increases the voltage up to 5V, while moving in the opposite direction decreases it to 0V.

### Usage Guide

This module is essentially a combination of dual potentiometers and a button. The X and Y axis outputs are analog voltages corresponding to the joystick position, while the Z axis provides a digital output (0 or 1) when the joystick is pressed down. To use it with Arduino, connect the X and Y axes to analog input pins and the Z axis to a digital input pin.

### Test Code
```cpp
int JoyStick_X = 0; // X-axis (Analog 0)
int JoyStick_Y = 1; // Y-axis (Analog 1)
int JoyStick_Z = 3; // Z-axis / Key (Digital 3)

void setup() {
  pinMode(JoyStick_X, INPUT);
  pinMode(JoyStick_Y, INPUT);
  pinMode(JoyStick_Z, INPUT);
  Serial.begin(9600); // 9600 bps
}

void loop() {
  int x, y, z;
  x = analogRead(JoyStick_X);
  y = analogRead(JoyStick_Y);
  z = digitalRead(JoyStick_Z);

  Serial.print(x, DEC);
  Serial.print(",");
  Serial.print(y, DEC);
  Serial.print(",");
  Serial.println(z, DEC);
  
  delay(100); // Small delay for readability
}
```



## Applications, category, tags, etc. 

## Demo Code and Video

## ref 

- [[joystick-dat]] - [[interactive-dat]] 

- [[SMO1073]] 

- [legacy wiki page](https://w.electrodragon.com/w/Joystick)
