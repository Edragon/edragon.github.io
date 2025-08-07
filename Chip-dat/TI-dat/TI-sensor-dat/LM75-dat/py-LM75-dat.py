
import smbus
import time

# LM75 default I2C address (can vary, check your hardware)
LM75_ADDRESS = 0x48
LM75_TEMP_REGISTER = 0x00

def read_lm75_temp(bus_num=1, address=LM75_ADDRESS):
    bus = smbus.SMBus(bus_num)
    # Read 2 bytes from temperature register
    data = bus.read_word_data(address, LM75_TEMP_REGISTER)
    # LM75 returns data in a swapped byte order
    temp_raw = ((data << 8) & 0xFF00) + (data >> 8)
    # Only the first 9 bits are temperature, shift to get value
    temp_c = (temp_raw >> 7) * 0.5
    return temp_c

if __name__ == "__main__":
    while True:
        temp = read_lm75_temp()
        print(f"Temperature: {temp:.2f} °C")
        time.sleep(1)