
#!/usr/bin/env python

import time
import threading
import pigpio

MAIN_SPI = 0
AUX_SPI = 1

class PISO(threading.Thread):
   
   """
   A class to read multiple inputs from one or more
   SN74HC165 PISO (Parallel In Serial Out) shift
   registers.

   Either the main SPI or auxiliary SPI peripheral
   is used to clock the data off the chip.  SPI is
   used for performance reasons.

   Connect a GPIO (referred to as SH_LD) to pin 1 of
   the first chip.

   Connect SPI SCLK to pin 2 of the first chip.  SCLK
   will be GPIO 11 if the main SPI is being used and
   GPIO 21 if the auxiliary SPI is being used.

   Connect SPI MISO to pin 9 of the last chip.  MISO
   will be GPIO 9 if the main SPI is being used and
   GPIO 19 if the auxiliary SPI is being used.

                      First chip

   Pi GPIO ------> SH/LD 1 o 16 Vcc ------ 3V3
   Pi SPI clock -> CLK   2   15 CLK INH -- Ground
                   E     3   14 D
                   F     4   13 C
                   G     5   12 B
                   H     6   11 A
   Don't connect   /Qh   7   10 SER ------ Ground
   Ground -------- GND   8    9 Qh ------> next SER


                     Middle chips

   prior SH/LD --> SH/LD 1 o 16 Vcc ------ 3V3
   prior CLK ----> CLK   2   15 CLK INH -- Ground
                   E     3   14 D
                   F     4   13 C
                   G     5   12 B
                   H     6   11 A
   Don't connect   /Qh   7   10 SER <----- prior Qh
   Ground -------- GND   8    9 Qh ------> next SER


                       Last chip

   prior SH/LD --> SH/LD 1 o 16 Vcc ------ 3V3
   prior CLK ----> CLK   2   15 CLK INH -- Ground
                   E     3   14 D
                   F     4   13 C
                   G     5   12 B
                   H     6   11 A
   Don't connect   /Qh   7   10 SER <----- prior Qh
   Ground -------- GND   8    9 Qh ------> Pi SPI MISO
   """
   SPI_FLAGS_AUX = 256   # use auxiliary SPI device
   SPI_FLAGS_NO_CE0 = 32 # don't use CE0

   def __init__(self, pi, SH_LD, SPI_device=MAIN_SPI,
      chips=1, reads_per_second=100, callback=None):
      """
      Instantiate with the connection to the Pi.

      SL_LD is the GPIO connected to the shift/load pin
      of the shift register.

      SPI_device is either MAIN_SPI (default) or AUX_SPI.

      chips is the number of SN74HC165 being used (defaults
      to 1).

      reads_per_second is the number of readings to
      be made per second (defaults to 100).
      
      If a callback is specified it will be called once
      for each pin level change.  The callback receives
      the pin, the new level, and the time of reading.
      """

      threading.Thread.__init__(self)

      self._lock = threading.Lock()

      self.set_reads_per_second(reads_per_second)

      self._pi = pi

      assert 0 <= SH_LD <= 53
      self._SH_LD = SH_LD

      assert 0 <= SPI_device <= 1
      flags = self.SPI_FLAGS_NO_CE0
      if SPI_device == AUX_SPI:
         flags |= self.SPI_FLAGS_AUX
      self._h = pi.spi_open(0, 5000000, flags)

      assert 1 <= chips
      self._chips = chips

      self._callback = callback

      self._last_data = [0]*chips

      self._exiting = False

      self.daemon = True

      self.start()

   def read(self):
      """
      Reads the shift registers and returns the
      readings as a byte array (one byte per
      chip).

      In addition if a callback is registered it
      will be called for each pin level change.
      """
      data = None
      with self._lock:
         if self._exiting:
            return data
         self._pi.gpio_trigger(self._SH_LD, 1, 0)
         read_time = time.time()
         count, data = self._pi.spi_read(self._h, self._chips)
         if data != self._last_data:
            if self._callback is not None:
               # Emit callbacks for changed levels.
               for i in range(self._chips):
                  if data[i] != self._last_data[i]:
                     for j in range(8):
                        if ((data[i] & (1<<j)) !=
                            (self._last_data[i] & (1<<j))):
                           self._callback((i*8)+j,
                                          (data[i]>>j)&1,
                                          read_time)
            self._last_data = data
      return data

   def set_callback(self, callback):
      """
      Sets the callback function.  The callback will
      be called for each pin level change.

      The callback receives three parameters:
         the pin
         the new level
         the time of the reading

      There are 8 pins per chip.  The last chip has
      pins numbered 0 to 7, the next to last chip has
      pins numbered 8 to 15 etc.

      The callback is cleared by setting it to None.
      """
      with self._lock:
         self._callback = callback

   def set_reads_per_second(self, reads_per_second):
      """
      Sets the number of chip reads per second.
      It must be between 1 and 5000 reads per
      second.
      """
      with self._lock:
         assert 1 <= reads_per_second <= 5000
         self._interval = 1.0 / reads_per_second

   def cancel(self):
      """
      Cancels chip readings and releases resources.
      """
      with self._lock:
         self._exiting = True
         self._pi.spi_close(self._h)

   def run(self):
      self._next_time = time.time()
      while not self._exiting:
         self.read()
         self._next_time += self._interval
         delay = self._next_time - time.time()
         if delay > 0.0:
            time.sleep(delay)

if __name__ == "__main__":

   import time
   import SN74HC165
   import pigpio

   def cbf(pin, level, tick):
      print(pin, level, tick)

   pi = pigpio.pi()
   if not pi.connected:
      exit()

   run_for = 30

   sr = SN74HC165.PISO(
           pi, SH_LD=16,
           SPI_device=SN74HC165.AUX_SPI, chips=7,
           reads_per_second=200, callback=cbf)

   time.sleep(run_for)

   # read all registers
   r = sr.read()
   # and print each value
   for i in range(len(r)):
      print(r[i])

   sr.cancel()

   pi.stop()