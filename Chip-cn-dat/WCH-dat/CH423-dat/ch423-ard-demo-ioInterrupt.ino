/*!
 * @file ioInterrupt.ino
 * @brief This demo is used to demonstrate the detection of rising edge, falling edge or double edge interrupt on the GPIO pin
 * @note When the module is configured as rising edge, falling edge or double edge interrupt, the MCU external interrupt should use falling edge interrupt to reduce errors
 * @n After burning this demo, pin GPO15 of the module needs to be connected to the corresponding external interrupt pin of MCU
 * @n Hardware connection
 * @n ---------------------------------------------------------
 * @n module |UNO   |mega2560 |M0    |ESP32 |ESP8266 |microbit |
 * @n VCC    |VCC   |VCC      |VCC   |VCC   |VCC     |VCC      |
 * @n GND    |GND   |GND      |GND   |GND   |GND     |GND      |
 * @n SCL    |SCL   |SCL      |SCL   |SCL   |SCL     |SCL      |
 * @n SDA    |SDA   |SDA      |SDA   |SDA   |SDA     |SDA      |
 * @n GPO15  |2/D2  |2/D2     |2     |2     |12      |P9       |
 * @n ---------------------------------------------------------
 * @note If the level of any pin of GPIO0~GPIO7 changes, GPO15 will output a low level signal, and it outputs high level until the levels of GPIO0~GPIO7 pins return to the initial level.
 * @n Leonardo is not supported
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [Arya](xue.peng@dfrobot.com)
 * @version  V1.0
 * @date  2022-03-11
 * @url https://github.com/DFRobot/DFRobot_CH423
 */
#include "DFRobot_CH423.h"

DFRobot_CH423 ch423;

#if defined(ARDUINO_BBC_MICROBIT)
#define INT_PIN     9                      //Connect pin GPO15 of the module to pin 9 of the MCU. For some MCUs, download the codes first and then connect hardware. 
#elif defined(ESP8266)
#define INT_PIN     12                     //Connect pin GPO15 of the module to pin 12 of the MCU. For some MCUs, download the codes first and then connect hardware.
#else
#define INT_PIN     2                      //Connect pin GPO15 of the module to pin 2 of the MCU. For some MCUs, download the codes first and then connect hardware.
#endif

bool intFlag = false;  //INT interrupt sign

/*Interrupt service function, prototype void func(int index), index: the number of the pin that is interrupted*/
void func(int index){
  String description = ch423.pinDescription(/*pin = */(DFRobot_CH423::eGPIOPin_t)index);
  Serial.print(description);
  Serial.println(" Interruption occurs!");
}

void setup() {
  Serial.begin(115200);

  while(!Serial){

  }
  ch423.begin();
  /**
   * @fn pinMode
   * @brief Set the mode of the pin groups, this module contains 2 groups of pins: GPIO(GPIO0~GPIO7) and GPO(GPO0~GPO15).
   * @note This module sets the mode by group, the pins in a group can only be set as one mode at the same time, and the pins in different groups can be set as different modes
   * @param group   Pin group parameter, ePinGroup_t enum variable member
   * @n     eGPIO                    Bi-directional I/O pin, GPIO0~GPIO7, which can be set as input(eINPUT) or output(eOUTPUT) mode, setting to other modes is invalid
   * @n     eGPO/eGPO0_7/eGPO8_15    The three parameters indicate the same meaning, set the mode of GPO group pins, select the parameter and GPO pins can only be configured as open-drain(eOPEN_DRAIN) or push-pull(ePUSH_PULL) output mode, other modes are invalid
   * @param mode    Group pin mode parameter, as member enum variable of eMode_t
   * @n     eINPUT       GPIO pin input mode, at high level when floating, this mode can only be used for eGPIO digital ports
   * @n     eOUTPUT      GPIO pin output mode, can output high and low levels, this mode can only be used for eGPIO digital ports
   * @n     eOPEN_DRAIN  GPO pin open-drain output mode, the GPO pins only output low level or don't output in this mode, it can only be used for eGPO group digital ports
   * @n     ePUSH_PULL   GPO pin push-pull output mode, the GPO pin can output high or low level in this mode, it can only be used for eGPO digital ports
   */
  ch423.pinMode(ch423.eGPIO, ch423.eINPUT);
  /**
   * @fn attachInterrupt
   * @brief Set the external interrupt mode and interrupt service function of GPIO pins
   * @note Pin GPO15 of CH423 module is used to indicate whether an interrupt occurs on GPIO0~GPIO7 in interrupt mode, if an interrupt occurs on a pin, GPO15 will output a low level continuously, otherwise it will output a high level.
   * @n When an interrupt occurs on a pin, trigger continuously, if there is interrupt occurring on other pins, level of pin GPO15 keeps low without changing
   * @param gpioPin   GPIO group pins, eGPIOPin_t enum variable member
   * @n     eGPIO0     Bi-directional I/O pin, GPIO0, indicates setting the external interrupt mode and interrupt service function of pin GPIO0
   * @n     eGPIO1     Bi-directional I/O pin, GPIO1, indicates setting the external interrupt mode and interrupt service function of pin GPIO1
   * @n     eGPIO2     Bi-directional I/O pin, GPIO2, indicates setting the external interrupt mode and interrupt service function of pin GPIO2
   * @n     eGPIO3     Bi-directional I/O pin, GPIO3, indicates setting the external interrupt mode and interrupt service function of pin GPIO3
   * @n     eGPIO4     Bi-directional I/O pin, GPIO4, indicates setting the external interrupt mode and interrupt service function of pin GPIO4
   * @n     eGPIO5     Bi-directional I/O pin, GPIO5, indicates setting the external interrupt mode and interrupt service function of pin GPIO5
   * @n     eGPIO6     Bi-directional I/O pin, GPIO6, indicates setting the external interrupt mode and interrupt service function of pin GPIO6
   * @n     eGPIO7     Bi-directional I/O pin, GPIO7, indicates setting the external interrupt mode and interrupt service function of pin GPIO7
   * @n     eGPIOTotal Set the values of all GPIO group pins, which indicates setting GPIO0~GPIO7 to the same interrupt mode and interrupt service function
   * @param mode    Interrupt mode
   * @n     eLOW       Low level interrupt, initial level of the GPIO pin is high, if the GPIO pin detect a low level, pin GPO15 will output a low level signal
   * @n     eHIGH      High level interrupt, initial level of the GPIO pin is low, if the GPIO pin detect a high level, pin GPO15 will output a low level signal
   * @n     eRISING    Rising edge interrupt, initial level of the GPIO pin is low, if the GPIO pin detect a rising edge, pin GPO15 will output a high-to-low level signal (falling edge)
   * @n     eFALLING   Falling edge interrupt, initial level of the GPIO pin is high, if the GPIO pin detect a falling edge, pin GPO15 will output a high-to-low level signal (falling edge)
   * @n     eCHANGE    Double edge interrupt, initial level of the GPIO pin is high, and the initial level switches once for each interrupt that occurs. If the GPIO pin detect falling edge or rising edge, pin GPO15 will output a high-to-low level signal (falling edge)
   * @note If the level of any pin of GPIO0-GPIO7 changes, GPO15 will output a low level signal, and it outputs high level until the levels of GPIO0~GPIO7 pins return to the initial level
   * @param cb  Point to interrupt service function
   */
  ch423.attachInterrupt(/* gpioPin= */ch423.eGPIO0, /* mode= */ch423.eFALLING, /* cb= */func);
  ch423.enableInterrupt();
  /**
   * @brief Enable the external interrupt pin of MCU. 
   * @param pin:   The external pin of MCU.
   * @n     UNO:       The external pin is 2, 3,
   * @n     Leonardo： (Not support)The external pin is 0(RX), 1(TX), 2(SCL), 3(SDA), but 0, 1, 2, 3 can't use in this demo
   * @n     Mega2560:  The external pin is 2, 3, 21, 20, 19, 18.
   * @n     microbit:  The external pin is 0~20(P0-P20)
   * @n     ESP32, ESP8266, M0:    The external pin is all digital Pin and analog pin.
   * @param fun: Pointer to guide interrupt service function.
   * @param mode:  Interrupt trigger mode.
   * @n     UNO/Leonardo/Mega2560:     Interrupt Modes: RISING(0x03), FALLING(0x02), CHANGE(0x01), LOW(0x00)
   * @n     8266/esp32:                Interrupt Modes: RISING(0x01), FALLING(0x02), CHANGE(0x03), ONLOW(0x04), ONHIGH(0x05),
   * @n     M0:                        Interrupt Modes: RISING(0x04), FALLING(0x03), CHANGE(0x02), HIGH(0x01),  LOW(0x00)
   * @n     microbit:                  Interrupt Modes: RISING(0x04), FALLING(0x03), CHANGE(0x02)  
   */
   pinMode(INT_PIN, INPUT_PULLUP);
   attachInterrupt(/*pin=*/digitalPinToInterrupt(INT_PIN),/*fun=*/notify,/*mode =*/FALLING);
   Serial.println("Set done!");
}

/*Interrupt service function*/
void notify(){
  intFlag = true;
}

void loop() {
  if(intFlag){
    intFlag = false;
    ch423.pollInterrupts();
  }
  yield();
}