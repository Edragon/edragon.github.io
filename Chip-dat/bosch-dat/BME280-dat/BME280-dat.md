
# BME280-dat


BME280 Features
- Package 2.5 mm x 2.5 mm x 0.93 mm metal lid LGA
- Digital interface I2C (up to 3.4 MHz) and SPI (3 and 4 wire, up to 10 MHz)
- Supply voltage VDD main supply voltage range: 1.71 V to 3.6 V
   VDDIO interface voltage range: 1.2 V to 3.6 V
- Current consumption 1.8 uA @ 1 Hz humidity and temperature
   2.8 uA @ 1 Hz pressure and temperature
   3.6 uA @ 1 Hz humidity, pressure and temperature
   0.1 uA in sleep mode
- Operating range -40…+85 C, 0…100 % rel. humidity, 300…1100 hPa- Humidity sensor and pressure sensor can be independently enabled/disabled

Bosch has stepped up their game with their new BMP280 sensor, an environmental sensor with temperature, barometric pressure that is the next generation upgrade to the BMP085/BMP180/BMP183. This sensor is great for all sorts of weather sensing and can even be used in both I2C and SPI!

This precision sensor from Bosch is the best low-cost, precision sensing solution for measuring barometric pressure with ±1 hPa absolute accuraccy, and temperature with ±1.0°C accuracy. Because pressure changes with altitude, and the pressure measurements are so good, you can also use it as an altimeter with  ±1 meter accuracy

The BME280 is the next-generation of sensors from Bosch, and is the upgrade to the BMP085/BMP180/BMP183 - with a low altitude noise of 0.25m and the same fast conversion time. It has the same specifications, but can use either I2C or SPI. For simple easy wiring, go with I2C. If you want to connect a bunch of sensors without worrying about I2C address collisions, go with SPI.