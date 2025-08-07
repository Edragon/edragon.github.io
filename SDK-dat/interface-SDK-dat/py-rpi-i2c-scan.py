#!/usr/bin/env python3
"""
I2C Address Scanner for Raspberry Pi
Scans all possible I2C addresses and reports which devices are found.
Requires smbus2 library: pip install smbus2
"""

import smbus2
import time
import sys

class I2CScanner:
    def __init__(self, bus_number=1):
        """
        Initialize I2C scanner
        Args:
            bus_number: I2C bus number (1 for Raspberry Pi 3/4, 0 for older models)
        """
        self.bus_number = bus_number
        try:
            self.bus = smbus2.SMBus(bus_number)
            print(f"I2C Scanner initialized on bus {bus_number}")
        except Exception as e:
            print(f"Error initializing I2C bus {bus_number}: {e}")
            print("Make sure I2C is enabled: sudo raspi-config -> Interface Options -> I2C")
            sys.exit(1)
    
    def scan_address(self, address):
        """
        Check if device exists at given I2C address
        Args:
            address: I2C address to check (0x00 to 0x7F)
        Returns:
            True if device responds, False otherwise
        """
        try:
            # Try to read a byte from the device
            self.bus.read_byte(address)
            return True
        except:
            return False
    
    def scan_all_addresses(self):
        """
        Scan all possible I2C addresses (0x03 to 0x77)
        Reserved addresses 0x00-0x02 and 0x78-0x7F are skipped
        """
        print("Scanning I2C bus for devices...")
        print("     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f")
        
        found_devices = []
        
        for row in range(0, 8):
            print(f"{row}0: ", end="")
            
            for col in range(0, 16):
                address = row * 16 + col
                
                # Skip reserved addresses
                if address < 0x03 or address > 0x77:
                    print("   ", end="")
                    continue
                
                if self.scan_address(address):
                    print(f"{address:02x} ", end="")
                    found_devices.append(address)
                else:
                    print("-- ", end="")
            
            print()  # New line after each row
        
        return found_devices
    
    def get_device_info(self, address):
        """
        Get additional information about a device (if available)
        Args:
            address: I2C address of the device
        """
        known_devices = {
            0x48: "ADS1115/ADS1015 ADC or TMP102 Temperature Sensor",
            0x49: "ADS1115/ADS1015 ADC or TMP102 Temperature Sensor", 
            0x4A: "ADS1115/ADS1015 ADC or TMP102 Temperature Sensor",
            0x4B: "ADS1115/ADS1015 ADC or TMP102 Temperature Sensor",
            0x68: "DS1307/DS3231 RTC or MPU6050 IMU",
            0x69: "MPU6050 IMU (alternate address)",
            0x76: "BMP280/BME280 Pressure/Humidity Sensor",
            0x77: "BMP280/BME280 Pressure/Humidity Sensor (alternate)",
            0x3C: "SSD1306 OLED Display (128x64)",
            0x3D: "SSD1306 OLED Display (128x32)",
            0x40: "PCA9685 PWM Driver",
            0x50: "AT24C32/64 EEPROM",
            0x51: "AT24C32/64 EEPROM",
            0x52: "AT24C32/64 EEPROM", 
            0x53: "AT24C32/64 EEPROM",
            0x20: "PCF8574 I/O Expander",
            0x21: "PCF8574 I/O Expander",
            0x22: "PCF8574 I/O Expander",
            0x23: "PCF8574 I/O Expander",
            0x27: "PCF8574 I/O Expander (LCD Backpack)",
            0x38: "PCF8574A I/O Expander",
            0x39: "PCF8574A I/O Expander",
            0x3A: "PCF8574A I/O Expander",
            0x3B: "PCF8574A I/O Expander",
            0x3E: "PCF8574A I/O Expander",
            0x3F: "PCF8574A I/O Expander (LCD Backpack)",
        }
        
        return known_devices.get(address, "Unknown device")
    
    def detailed_scan(self):
        """
        Perform detailed scan with device identification
        """
        found_devices = self.scan_all_addresses()
        
        if found_devices:
            print(f"\nFound {len(found_devices)} device(s):")
            print("-" * 60)
            for addr in found_devices:
                device_info = self.get_device_info(addr)
                print(f"Address: 0x{addr:02X} ({addr:3d}) - {device_info}")
        else:
            print("\nNo I2C devices found!")
            print("Check your connections and make sure I2C is enabled.")
    
    def __del__(self):
        """Close I2C bus when object is destroyed"""
        if hasattr(self, 'bus'):
            self.bus.close()

def main():
    """Main function"""
    print("=" * 60)
    print("Raspberry Pi I2C Address Scanner")
    print("=" * 60)
    
    # Try to determine the correct bus number
    try:
        # For Raspberry Pi 3/4, use bus 1
        scanner = I2CScanner(bus_number=1)
    except:
        try:
            # For older Raspberry Pi models, try bus 0
            print("Bus 1 failed, trying bus 0...")
            scanner = I2CScanner(bus_number=0)
        except Exception as e:
            print(f"Failed to initialize I2C scanner: {e}")
            return
    
    # Perform the scan
    scanner.detailed_scan()
    
    print("\nScan complete!")
    print("\nNote: Make sure I2C is enabled in raspi-config")
    print("Install required library: pip install smbus2")

if __name__ == "__main__":
    main()