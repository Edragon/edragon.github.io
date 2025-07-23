
import time
import board
import digitalio
import wws_74hc165

latch_pin = digitalio.DigitalInOut(board.D5)

sr = wws_74hc165.ShiftRegister74HC165(board.SPI(), latch_pin)

pin1 = sr.get_pin(1)
pin2 = sr.get_pin(2)
pin3 = sr.get_pin(3)
pin4 = sr.get_pin(4)


while True:
    # print(f"pin 1 = {pin1.value}")
    print(f"{pin1.value} {pin2.value} {pin3.value} {pin4.value}")

    time.sleep(0.2)


