
# ESP32-Serial-dat


## UART

pin 17 / 18 = SD2 / SD3 = UART1
pin 27 / 28 = IO 26 / 27 = UART2 


### Serial

- U0 = RXD0 / TXD0
- U1 = SD2 / SD3 (can not use)
- U2 = U2RXD = IO16, U2TXD = IO17

ESP32 UARTs

| UART  | Default Pins           | Notes                                      |
| ----- | ---------------------- | ------------------------------------------ |
| UART0 | TX0=GPIO1, RX0=GPIO3   | Used for programming & Serial              |
| UART1 | TX1=GPIO10, RX1=GPIO9  | Often used for debug output                |
| UART2 | TX2=GPIO17, RX2=GPIO16 | Free for general use; pins can be remapped |

software serial 



    #include <SoftwareSerial.h>

    SoftwareSerial mySerial(16, 17); // RX, TX

    void setup() {
    Serial.begin(115200);
    mySerial.begin(9600);
    }

    void loop() {
    if (mySerial.available()) {
        String data = mySerial.readString();
        Serial.println(data);
    }
    }

Example: Using UART2

    #define RX_PIN 16
    #define TX_PIN 17

    void setup() {
    Serial.begin(115200);        // UART0 for debug
    Serial2.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN); // UART2
    }

    void loop() {
    if (Serial2.available()) {
        int c = Serial2.read();
        Serial.print((char)c);   // forward to USB serial
    }

    if (Serial.available()) {
        Serial2.write(Serial.read()); // send input from USB to UART2
    }
    }


## ref 

- [[ESP32-HDK-dat]] - [[ESP32-SDK-dat]]