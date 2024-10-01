import RPi.GPIO as gpio
from time import sleep

class Shifter():
    inputA = 19
    inputB = 23
    clock = 21
    clearPin = 22

    def __init__(self):
        self.setupBoard()
        self.pause = 0

    def tick(self):
        gpio.output(self.clock, gpio.HIGH)
        sleep(self.pause)
        gpio.output(self.clock, gpio.LOW)
        sleep(self.pause)

    def setValue(self, value):
        for i in range(24):
            bitwise = 0x800000 >> i
            bit = bitwise & value
            if bit == 0:
                gpio.output(self.inputB, gpio.LOW)
            else:
                gpio.output(self.inputB, gpio.HIGH)
            self.tick()  # Corrected method call

    def clear(self):
        gpio.output(self.clearPin, gpio.LOW)
        self.tick()  # Corrected method call
        gpio.output(self.clearPin, gpio.HIGH)

    def setupBoard(self):
        # Uncomment if needed
        # gpio.setup(self.inputA, gpio.OUT)
        # gpio.output(self.inputA, gpio.HIGH)

        gpio.setup(self.inputB, gpio.OUT)
        gpio.output(self.inputB, gpio.LOW)

        gpio.setup(self.clock, gpio.OUT)
        gpio.output(self.clock, gpio.LOW)

        gpio.setup(self.clearPin, gpio.OUT)
        gpio.output(self.clearPin, gpio.HIGH)

def main():
    pause = 0.5
    gpio.setmode(gpio.BOARD)
    shifter = Shifter()
    running = True

    while running:
        try:
            # shifter.clear()
            # shifter.setValue(1)
            # sleep(1)
            shifter.clear()
            shifter.setValue(0x0AAAAAA)
            sleep(pause)
            shifter.clear()
            shifter.setValue(0x0555555)
            sleep(pause)

        except KeyboardInterrupt:
            running = False

    gpio.cleanup()  # Clean up GPIO pins on exit

if __name__ == "__main__":
    main()
