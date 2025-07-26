
# openOCD-dat


## ESP32 arduino 


### 1. 🔌 Check Hardware Connections
- Verify JTAG wiring: `TDI`, `TDO`, `TCK`, `TMS`, `GND`, and `3.3V`.
- Ensure ESP32 board is powered.
- Use a reliable USB cable and avoid USB hubs.



## STM32 Linux 

### Debugger OpenOCD 

* [http://openocd.org/doc/html/index.html Help page.]
* Use either ST-LINK or OpenOCD, can work with ST-LINK2
* For example OpenOCD, run command as follow to install
# install openocs: sudo apt-get install openocd
# setup up for usbdevice: sudo vi /etc/udev/rules.d/99-stlink.rules
# add conent: ATTRS{idVendor}=="0483", ATTRS{idProduct}=="3748", MODE="0666"
# reload setup: sudo udevadm control --reload-rules
# open board: openocd -f /usr/share/openocd/scripts/board/stm32f3discovery.cfg
# or use: /usr/share/openocd/scripts# openocd -f interface/stlink-v2.cfg -f target/stm32f1x_stlink.cfg
* If well connected, result will show:

Open On-Chip Debugger 0.7.0 (2013-05-15-17:44)
Licensed under GNU GPL v2
For bug reports, read
 http://openocd.sourceforge.net/doc/doxygen/bugs.html
 srst_only separate srst_nogate srst_open_drain connect_deassert_srst
 Info : This adapter doesn't support configurable speed
 Info : STLINK v2 JTAG v16 API v2 SWIM v0 VID 0x0483 PID 0x3748
 Info : Target voltage: 2.915198
 Info : stm32f3x.cpu: hardware has 6 breakpoints, 4 watchpoint
* Run another terminal and telnet to the board: telnet localhost 4444
* halt it into debug mode: reset halt or: reset init
* Reflash bin into board: 
 flash write_image erase maple_mini_boot.bin 0x08000000
 flash write_image erase /media/sf_VM_XP_share/LED.hex
* Finall reset it to start up again: reset run


####  Toolchain 
* Install: sudo apt-get install gcc-arm-none-eabi


#### Firmware libopencm3 and test code 
* git clone the firmware and try stm32f103 demo blink code, the firmware works like arduino
 git clone https://github.com/libopencm3/libopencm3-examples.git
 cd libopencm3-examples
 git submodule init // 
 git submodule update
 make
* enter into board folder like: cd libopencm3-examples/examples/stm32/f3/stm32f3-discovery/miniblink
* for STM32F1x board, enter into /libopencm3-examples/examples/stm32/f1/stm32-h103//miniblink/
* firmware support openocd, can run make flash directory
* Or manually telnet to openocd: telnet localhost 4444
 reset halt
 flash write_image erase miniblink.elf
 reset
 
## ref 

- [[stm32-dat]]
