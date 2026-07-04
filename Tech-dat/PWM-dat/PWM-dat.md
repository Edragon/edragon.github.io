# PWM-dat

- arduino code example  - [[arduino-fading.ino]]

- [[mosfet-dat]] == [[SDR1073-dat]]

- [[pulse-in-dat]]




## ESP32 LEDC (PWM) Frequency and Resolution Conflict


The Cause: If your code configures **a very high PWM frequency** (e.g., 50kHz) alongside a high bit-resolution (e.g., 12-bit or 13-bit), the maximum achievable value in code might not perfectly map to a true, solid 100% duty cycle, or it might over-heat the drivers due to high-frequency switching losses. 

Furthermore, manufacturing variances in the two 380 motors mean that at the ragged edge of a noisy signal, one will always drop off or perform worse than the other.

The Fix: Lower your ESP32 LEDC frequency to 10kHz or 20kHz with an 8-bit resolution (0-255). Ensure that "max throttle" translates to writing a clean 255 to the channel.

- [[motor-driver-dat]] - [[motor-driver-design-dat]] - [[logic-level-shifter-dat]] - [[PWM-dat]] - [[ESP32-S3-dat]] - [[ESP32-dat]]



## understand PWM 

PWM (Pulse Width Modulation) - [[PPM-dat]]

**What changes:**  
👉 **Pulse width (duty cycle)**

**What stays fixed:**  

Frequency

Pulse position


    |■■■■■■      |  60% duty
    |■■■         |  30% duty
    |■■■■■■■■    |  80% duty

Used for

- SMPS regulation
- Motor speed control
- LED dimming


## boards 

- [[SCU1063-dat]]

- [[SG3525-dat]] - [[MSP1046-dat]]


    /*
    Fade

    This example shows how to fade an LED on pin 9 using the analogWrite()
    function.

    The analogWrite() function uses PWM, so if you want to change the pin you're
    using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
    are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

    This example code is in the public domain.

    https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
    */



## drive chip 

- TL494 == Pulse-Width-Modulation Control Circuits

- MIC38C42/43/44/45 - BiCMOS Current-Mode PWM Controllers - 20V, Current Mode SMPS Controller Family with Various UVLO and Max Duty Cycle - [[microchip-dat]]


## apps 

- [[tuner-dat]]

- [[motor-servo-dat]]


## ref 

- [[tech-dat]]