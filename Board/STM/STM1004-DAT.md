
# STM1004 DAT 

![](16-29-16-06-07-2023.png)

https://www.electrodragon.com/product/stm32f405-mini-development-board-micropython-compatible-pyboard/

STM32F405RGT6 
- LQFP-64

## demo testing code

    import pyb

    while True:
        pyb.LED(1).on()
        pyb.LED(2).on()
        pyb.LED(3).on()
        pyb.LED(4).on()
        pyb.delay(500)

        pyb.LED(1).off()
        pyb.LED(2).off()
        pyb.LED(3).off()
        pyb.LED(4).off()
        pyb.delay(500)

- [[micropython-dat]] firmware please find in out [[repository]]
- [[STM1004]]