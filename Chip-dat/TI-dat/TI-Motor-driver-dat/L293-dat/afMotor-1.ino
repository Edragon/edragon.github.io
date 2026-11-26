#include <AFMotor.h>
// Library to run DC Motor Using Motor Driver Shield
#include <LiquidCrystal_I2C.h>
// Library to Run I2C LCD

LiquidCrystal_I2C lcd(0x27, 16, 2); // Format -> (Address,Columns,Rows )

// Create the motor object connected to M3
AF_DCMotor motor(3);

// Define button pins
const int forwardButtonPin = A1;
const int reverseButtonPin = A2;
const int stopButtonPin = A3;

// Define potentiometer pin
const int potPin = A0;

// Variables to store motor state and direction
bool motorRunning = false;
int motorDirection = BACKWARD; // FORWARD or BACKWARD

// Read the potentiometer value
int potValue;
int motorSpeed;

// Variable to store button states
bool forwardButtonState;
bool stopButtonState;
bool reverseButtonState;

// Inline function to check if button is pressed packed with debouncing logic
inline bool chkButtonState(int pinNum, int checkState, int debounceDelay)
{
    if (((digitalRead(pinNum) == checkState) ? true : false) == true)
    {
        delay(debounceDelay);
        return (((digitalRead(pinNum) == checkState) ? (true) : (false)) == true);
    }
    else
    {
        return false;
    }
}

void setup()
{
    // initialize the lcd
    lcd.init();
    // Turn on the Backlight
    lcd.backlight();
    // Clear the display buffer
    lcd.clear();

    // Set cursor (Column, Row)
    lcd.setCursor(0, 0);
    lcd.print("DC Motor using");
    lcd.setCursor(0, 1);
    lcd.print("L293D Shield");

    // Set button pins as inputs
    pinMode(forwardButtonPin, INPUT_PULLUP);
    pinMode(stopButtonPin, INPUT_PULLUP);
    pinMode(reverseButtonPin, INPUT_PULLUP);

    // Start with motor off
    motor.setSpeed(0);
    motor.run(RELEASE);

    delay(2000);

    // Clear the display buffer
    lcd.clear();
    // Set cursor (Column, Row)
    lcd.setCursor(0, 0);
    lcd.print("Motor Direction:");
    lcd.setCursor(0, 1);
    lcd.print("Stopped   ");
}

void loop()
{
    // Read the potentiometer value for changing speed as per Analog input
    potValue = analogRead(potPin);
    motorSpeed = map(potValue, 0, 1023, 0, 255);

    // Read the button states
    forwardButtonState = chkButtonState(forwardButtonPin, LOW, 20);
    reverseButtonState = chkButtonState(reverseButtonPin, LOW, 20);
    stopButtonState = chkButtonState(stopButtonPin, LOW, 20);

    // check for Forward run
    if (forwardButtonState && (!motorRunning || motorDirection == BACKWARD))
    {
        // Set cursor (Column, Row)
        lcd.setCursor(0, 1);
        lcd.print("Clock   ");
        if (motorDirection == BACKWARD)
        {
            motor.setSpeed(0);
            motor.run(RELEASE);
            delay(1000);
        }
        motorRunning = true;
        motorDirection = FORWARD;
        motor.setSpeed(motorSpeed);
        motor.run(FORWARD);
    }

    // check for Reverse run
    else if (reverseButtonState && (!motorRunning || motorDirection == FORWARD))
    {
        // Set cursor (Column, Row)
        lcd.setCursor(0, 1);
        lcd.print("Anti-Clk");
        if (motorDirection == FORWARD)
        {
            motor.setSpeed(0);
            motor.run(RELEASE);
            delay(1000);
        }
        motorRunning = true;
        motorDirection = BACKWARD;
        motor.setSpeed(motorSpeed);
        motor.run(BACKWARD);
    }

    // Stop motor
    else if (stopButtonState && motorRunning)
    {
        // Set cursor (Column, Row)
        lcd.setCursor(0, 1);
        lcd.print("Stopped         ");
        motorRunning = false;
        motor.setSpeed(0);
        motor.run(RELEASE);
    }

    // Adjust motor speed if running and display speed on LCD
    if (motorRunning)
    {
        motor.setSpeed(motorSpeed);
        // Set cursor (Column, Row)
        lcd.setCursor(9, 1);
        lcd.print("SPD:");
        lcd.print(((motorSpeed * 100) / 255));
        lcd.print("%  ");
    }
}