
#include <Wire.h>

#define EN_A 9
#define EN_B 11

#define DIR_A1 7
#define DIR_A2 8
#define DIR_B1 10
#define DIR_B2 12

#define buzzer 6
#define address 104

void setup()
{


  Wire.begin();
  Serial.begin(115200);

  pinMode(EN_A, OUTPUT);
  pinMode(EN_B, OUTPUT);
  pinMode(DIR_A1, OUTPUT);
  pinMode(DIR_A2, OUTPUT);
  pinMode(DIR_B1, OUTPUT);
  pinMode(DIR_B2, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite (EN_A, HIGH);
  digitalWrite (EN_B, HIGH);

}


void I2C_check() {
  // int address = 104;
  
  Wire.beginTransmission(address);
  byte error = Wire.endTransmission();
  // Serial.print (error);

  if (error == 0)
  {
    Serial.print("找到地址 I2C device found at address 0x");
    if (address < 16)
      Serial.print("0");
    Serial.print(address, HEX);
    Serial.println("  !");
  }
  
}

void loop()
{

  I2C_check();

  Serial.println("反转电机方向 flipping motor direction ");
  Serial.println(" ");
  
  digitalWrite (DIR_A1, HIGH);
  digitalWrite (DIR_A2, LOW);
  digitalWrite (DIR_B1, HIGH);
  digitalWrite (DIR_B2, LOW);

  digitalWrite (buzzer, LOW);

  delay(5000);

  I2C_check();

  digitalWrite (DIR_A1, LOW);
  digitalWrite (DIR_A2, HIGH);
  digitalWrite (DIR_B1, LOW);
  digitalWrite (DIR_B2, HIGH);

  digitalWrite (buzzer, HIGH);

  delay(5000);


}
