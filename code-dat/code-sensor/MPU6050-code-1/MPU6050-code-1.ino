// MPU6050-code-1.ino

#include <Wire.h>

const uint8_t MPU_ADDR = 0x68; // I2C address for MPU6050

// MPU6050 registers
const uint8_t PWR_MGMT_1 = 0x6B;
const uint8_t ACCEL_XOUT_H = 0x3B;
const uint8_t TEMP_OUT_H    = 0x41;
const uint8_t GYRO_XOUT_H  = 0x43;

// Sensitivity scale factors (default ranges):
// Accelerometer: ±2g -> 16384 LSB/g
// Gyroscope: ±250 deg/s -> 131 LSB/(deg/s)
const float ACCEL_SCALE = 16384.0;
const float GYRO_SCALE  = 131.0;

void setup() {
  Serial.begin(115200);
  while (!Serial) { /* wait for Serial on some boards */ }

  Wire.begin();

  // Wake up MPU6050 (clear sleep bit)
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(PWR_MGMT_1);
  Wire.write(0x00); // set to zero (wakes up the sensor)
  Wire.endTransmission();

  delay(100);
  Serial.println("MPU6050 initialized (0x68)");
}

// Read 'count' bytes starting at register 'reg' into dest
void readRegisters(uint8_t reg, uint8_t count, uint8_t* dest) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false); // restart for read

  Wire.requestFrom((int)MPU_ADDR, (int)count);
  for (uint8_t i = 0; i < count && Wire.available(); i++) {
    dest[i] = Wire.read();
  }
}

// Read a signed 16-bit value from two consecutive registers (big-endian)
int16_t readInt16(uint8_t reg) {
  uint8_t buf[2];
  readRegisters(reg, 2, buf);
  return (int16_t)((buf[0] << 8) | buf[1]);
}

void loop() {
  int16_t ax_raw = readInt16(ACCEL_XOUT_H);
  int16_t ay_raw = readInt16(ACCEL_XOUT_H + 2);
  int16_t az_raw = readInt16(ACCEL_XOUT_H + 4);

  int16_t temp_raw = readInt16(TEMP_OUT_H);

  int16_t gx_raw = readInt16(GYRO_XOUT_H);
  int16_t gy_raw = readInt16(GYRO_XOUT_H + 2);
  int16_t gz_raw = readInt16(GYRO_XOUT_H + 4);

  float ax = ax_raw / ACCEL_SCALE; // in g
  float ay = ay_raw / ACCEL_SCALE;
  float az = az_raw / ACCEL_SCALE;

  float temperature = (temp_raw / 340.0) + 36.53; // degrees C

  float gx = gx_raw / GYRO_SCALE; // deg/s
  float gy = gy_raw / GYRO_SCALE;
  float gz = gz_raw / GYRO_SCALE;

  // Simple tilt (degrees)
  float roll  = atan2(ay, az) * 57.295779513; // rad->deg
  float pitch = atan2(-ax, sqrt(ay * ay + az * az)) * 57.295779513;

  Serial.print("AX:"); Serial.print(ax, 3); Serial.print(" g ");
  Serial.print("AY:"); Serial.print(ay, 3); Serial.print(" g ");
  Serial.print("AZ:"); Serial.print(az, 3); Serial.print(" g  ");

  Serial.print("GX:"); Serial.print(gx, 2); Serial.print(" dps ");
  Serial.print("GY:"); Serial.print(gy, 2); Serial.print(" dps ");
  Serial.print("GZ:"); Serial.print(gz, 2); Serial.print(" dps  ");

  Serial.print("T:"); Serial.print(temperature, 2); Serial.print(" C  ");

  Serial.print("Roll:"); Serial.print(roll, 2); Serial.print(" deg ");
  Serial.print("Pitch:"); Serial.print(pitch, 2); Serial.println(" deg");

  delay(200);
}

