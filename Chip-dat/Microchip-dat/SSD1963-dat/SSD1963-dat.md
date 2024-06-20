
# SSD1963-dat

- [[ILC1031-dat]]





## Selection Note 

This module uses the SSDI963 driver solution. The SSDI963 has average anti-interference performance (commercial standard but not industrial standard) and has high power requirements.

When using this solution, please pay special attention to **the quality of your power supply**. The data cable should not be too long, otherwise there is a risk of a white (not-displaying) screen.

If you use it on general products and the power quality is relatively good, you can choose to use the SSD1963 solution.

If you use it on industrial control products and have high requirements for **stability**, please use the industrial solution module we recommend for you [[MD050SD-dat]]


## Usage Note 

### TFT power supply: 
The screen power supply is 2.8-3.3V; remember not to use 5V, and the voltage of all pins on the module cannot exceed 3.3V, remember.

### Backlight: 

The module has inherited the backlight drive circuit. The backlight will turn on when the LED_A pin is high-level, and the backlight will turn off when it is low-level. The brightness can be controlled by giving a PWM signal.

### Special note: 

- The backlight current consumption of 4.3-inch and larger TFTs is relatively large (4.3-inch has more than 200ma at the brightest, 5-inch has more than 300ma at the brightest, and 7-inch has 500ma at the brightest).
- If USB power is used, some computer motherboards may not be able to supply current, and the module may not work due to severe voltage division caused by poor USB connection quality.
- Please make sure your power supply is stable enough. Thank you!


## ref 

- [[SSD1963.pdf]]