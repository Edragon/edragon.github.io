import serial
import time

# Configure the serial port for UART1 on Raspberry Pi 3
# Note: Ensure UART1 is enabled in /boot/config.txt by adding dtoverlay=pi3-miniuart-bt or similar
# Port: /dev/ttyS0 (UART1), Baud rate: 9600 (change as needed)
ser = serial.Serial('/dev/ttyS0', 9600, timeout=1)

try:
    print("Reading UART data. Press Ctrl+C to stop.")
    while True:
        if ser.in_waiting > 0:
            data = ser.readline().decode('utf-8').rstrip()
            print(f"Received: {data}")
        time.sleep(0.1)
except KeyboardInterrupt:
    print("Stopping UART read.")
finally:
    ser.close()