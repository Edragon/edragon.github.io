# RMP-RPI-CM4-dat

I believe the COMPUTE MODULE has enough pins to drive 6 chains.

See also: https://github.com/hzeller/rpi-rgb-led-matrix/blob/a3eea997a9254b83ab2de97ae80d83588f696387/wiring.md?plain=1#L144

- https://github.com/hzeller/rpi-rgb-led-matrix/issues/1105


## Alternative Hardware Mappings

You have relative freedom to assign any pins to the output of your choosing, just add a new mapping in lib/hardware-mapping.c, recompile and it will be provided as a new option in --led-gpio-mapping.

    --led-gpio-mapping
    
pin definitions for CM module 

- https://github.com/hzeller/rpi-rgb-led-matrix/blob/master/lib/hardware-mapping.c

- [[RMP-RPI-CM4-dat]]

<summary>Table: GPIO-pins for each hardware mapping</summary>

|                 | regular | adafruit-hat | adafruit-hat-pwm | regular-pi1 | classic | classic-pi1 | compute-module |
| --------------- | ------- | ------------ | ---------------- | ----------- | ------- | ----------- | -------------- |
| Parallel chains | 3       | 1            | 1                | 1           | 3       | 1           | 6              |
| ~OE             | GPIO 18 | GPIO 4       | GPIO 18          | GPIO 18     | GPIO 27 | GPIO 0      | GPIO 18        |
| Clock           | GPIO 17 | GPIO 17      | GPIO 17          | GPIO 17     | GPIO 11 | GPIO 1      | GPIO 16        |
| Strobe          | GPIO 4  | GPIO 21      | GPIO 21          | GPIO 4      | GPIO 4  | GPIO 4      | GPIO 17        |
| A               | GPIO 22 | GPIO 22      | GPIO 22          | GPIO 22     | GPIO 7  | GPIO 7      | GPIO 2         |
| B               | GPIO 23 | GPIO 26      | GPIO 26          | GPIO 23     | GPIO 8  | GPIO 8      | GPIO 3         |
| C               | GPIO 24 | GPIO 27      | GPIO 27          | GPIO 24     | GPIO 9  | GPIO 9      | GPIO 4         |
| D               | GPIO 25 | GPIO 20      | GPIO 20          | GPIO 25     | GPIO 10 | GPIO 10     | GPIO 5         |
| E               | GPIO 15 | GPIO 24      | GPIO 24          | GPIO 15     | -       | -           | GPIO 6         |
| Chain 1/R1      | GPIO 11 | GPIO 5       | GPIO 5           | GPIO 11     | GPIO 17 | GPIO 17     | GPIO 7         |
| Chain 1/G1      | GPIO 27 | GPIO 13      | GPIO 13          | GPIO 21     | GPIO 18 | GPIO 18     | GPIO 8         |
| Chain 1/B1      | GPIO 7  | GPIO 6       | GPIO 6           | GPIO 7      | GPIO 22 | GPIO 22     | GPIO 9         |
| Chain 1/R2      | GPIO 8  | GPIO 12      | GPIO 12          | GPIO 8      | GPIO 23 | GPIO 23     | GPIO 10        |
| Chain 1/G2      | GPIO 9  | GPIO 16      | GPIO 16          | GPIO 9      | GPIO 24 | GPIO 24     | GPIO 11        |
| Chain 1/B2      | GPIO 10 | GPIO 23      | GPIO 23          | GPIO 10     | GPIO 25 | GPIO 25     | GPIO 12        |
| Chain 2/R1      | GPIO 12 | -            | -                | -           | GPIO 12 | -           | GPIO 13        |
| Chain 2/G1      | GPIO 5  | -            | -                | -           | GPIO 5  | -           | GPIO 14        |
| Chain 2/B1      | GPIO 6  | -            | -                | -           | GPIO 6  | -           | GPIO 15        |
| Chain 2/R2      | GPIO 19 | -            | -                | -           | GPIO 19 | -           | GPIO 19        |
| Chain 2/G2      | GPIO 13 | -            | -                | -           | GPIO 13 | -           | GPIO 20        |
| Chain 2/B2      | GPIO 20 | -            | -                | -           | GPIO 20 | -           | GPIO 21        |
| Chain 3/R1      | GPIO 14 | -            | -                | -           | GPIO 14 | -           | GPIO 22        |
| Chain 3/G1      | GPIO 2  | -            | -                | -           | GPIO 2  | -           | GPIO 23        |
| Chain 3/B1      | GPIO 3  | -            | -                | -           | GPIO 3  | -           | GPIO 24        |
| Chain 3/R2      | GPIO 26 | -            | -                | -           | GPIO 15 | -           | GPIO 25        |
| Chain 3/G2      | GPIO 16 | -            | -                | -           | GPIO 26 | -           | GPIO 26        |
| Chain 3/B2      | GPIO 21 | -            | -                | -           | GPIO 21 | -           | GPIO 27        |
| Chain 4/R1      | -       | -            | -                | -           | -       | -           | GPIO 28        |
| Chain 4/G1      | -       | -            | -                | -           | -       | -           | GPIO 29        |
| Chain 4/B1      | -       | -            | -                | -           | -       | -           | GPIO 30        |
| Chain 4/R2      | -       | -            | -                | -           | -       | -           | GPIO 31        |
| Chain 4/G2      | -       | -            | -                | -           | -       | -           | GPIO 32        |
| Chain 4/B2      | -       | -            | -                | -           | -       | -           | GPIO 33        |
| Chain 5/R1      | -       | -            | -                | -           | -       | -           | GPIO 34        |
| Chain 5/G1      | -       | -            | -                | -           | -       | -           | GPIO 35        |
| Chain 5/B1      | -       | -            | -                | -           | -       | -           | GPIO 36        |
| Chain 5/R2      | -       | -            | -                | -           | -       | -           | GPIO 37        |
| Chain 5/G2      | -       | -            | -                | -           | -       | -           | GPIO 38        |
| Chain 5/B2      | -       | -            | -                | -           | -       | -           | GPIO 39        |
| Chain 6/R1      | -       | -            | -                | -           | -       | -           | GPIO 40        |
| Chain 6/G1      | -       | -            | -                | -           | -       | -           | GPIO 41        |
| Chain 6/B1      | -       | -            | -                | -           | -       | -           | GPIO 42        |
| Chain 6/R2      | -       | -            | -                | -           | -       | -           | GPIO 43        |
| Chain 6/G2      | -       | -            | -                | -           | -       | -           | GPIO 44        |
| Chain 6/B2      | -       | -            | -                | -           | -       | -           | GPIO 45        |


<details>

</details>


## ref 

- [[RMP-driver-dat]]

- [[RPI-CM4-dat]] - [[RPI-CM4-expansion-board-dat]]


- https://rpi-rgb-led-matrix.discourse.group/t/curious-has-anyone-implemented-a-cm4-solution/702/3

