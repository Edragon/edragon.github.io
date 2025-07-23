
from pi74HC595 import pi74HC595
import RPi.GPIO as gpio
from time import sleep

gpio.setmode(gpio.BOARD)

# ds sh st 



# shift_register.set_by_list([0, 1, 0, 1, 1, 1, 0, 0])


def main():

    pause = 0.5
    gpio.setmode(gpio.BOARD)
    # shifter = Shifter()
    sh1 = pi74HC595(23, 22, 21, 2)

    sh2 = pi74HC595(19, 18, 16, 2)

    running = True

    while running:
        try:

            sh1.set_by_list([0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0])
            sh2.set_by_list([0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0])

            sleep(pause)

            sh1.clear()
            sh2.clear()
            sleep(pause)

        except KeyboardInterrupt:
            running = False

    gpio.cleanup()  # Clean up GPIO pins on exit




if __name__ == "__main__":
    main()
