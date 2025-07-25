
# RMP-driver-cmd-dat.md

- [[RMP-driver-dat]]

- [[MPC1073-test-log-dat]] - [[MPC1073-multiplexing-dat]]

| params                    | range  | note          |
| ------------------------- | ------ | ------------- |
| --led-row-addr-type       |        |               |
| --led-slowdown-gpio       | 2      | if flickering |
| --led-panel-type          |        |               |
| --led-rows                |        |               |
| --led-cols                |        |               |
| --led-chain               |        |               |
| --led-parallel            |        |               |
| --led-show-refresh        |        |               |
| --led-scan-mode           | 0 or 1 |               |
| --led-pwm-bits            |        |               |
| --led-pwm-lsb-nanoseconds |        |               |


## examples 

~/rpi-rgb-led-matrix/examples-api-use/demo --led-panel-type=FM6126 --led-rows=64 --led-cols=128 --led-row-addr-type=5 --led-chain=1 --led-parallel=2 --led-show-refresh --led-scan-mode=0 --led-pwm-bits=7 --led-pwm-lsb-nanoseconds=50 -D0  --led-slowdown-gpio=2

    Size: 128x128. Hardware gpio mapping: regular
    Press <CTRL-C> to exit and reset LEDs
    249.6Hz (lowest: 64.7Hz))



## ref 

- [[MPC1073-dat]]

- [[RMP-driver-dat]]