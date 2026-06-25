#include <AlfredoCRSF.h>
#include <SoftwareSerial.h>

#define PIN_RX 13
#define PIN_TX 12

// Set up a new SoftwareSerial object
SoftwareSerial crsfSerial(PIN_RX, PIN_TX);
AlfredoCRSF crsf;

void setup()
{
  Serial.begin(115200);
  Serial.println("COM Serial initialized");
  
  crsfSerial.begin(115200);

  crsf.begin(crsfSerial);
}

void loop()
{
    // Must call crsf.update() in loop() to process data
    crsf.update();
    printChannels();
}

//Use crsf.getChannel(x) to get us channel values (1-16).
void printChannels()
{
  for (int ChannelNum = 1; ChannelNum <= 16; ChannelNum++)
  {
    Serial.print(crsf.getChannel(ChannelNum));
    Serial.print(", ");
  }
  Serial.println(" ");
}