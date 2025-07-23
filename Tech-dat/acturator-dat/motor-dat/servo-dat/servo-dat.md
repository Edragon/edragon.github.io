
# servo-dat

- [[servo-gimbal-dat]]


## feature of servos 

- The servo is a device that can control the angle of rotation of the motor shaft. It consists of a DC motor, a gear set, and a position feedback system.
- The servo can be controlled by a PWM signal, which determines the angle of rotation of the motor shaft.
- The servo can be used in various applications, such as robotics, RC vehicles, and automation systems.
- The servo can be classified into different types based on its construction and operation, such as analog servos, digital servos, and continuous rotation servos.
- The servo can be powered by different voltage levels, typically ranging from 4.8V to 6V for standard servos and up to 7.4V for high-performance servos.
- The servo can be controlled by different protocols, such as PWM, I2C, and UART, depending on the application and the controller used.
- The servo can be equipped with different types of gears, such as plastic gears, metal gears, and ceramic gears, depending on the torque and speed requirements of the application.
- The servo can be used in various configurations, such as standard servos, mini servos, micro servos, and high-torque servos, depending on the size and weight constraints of the application.
- The servo can be used in different environments, such as indoor, outdoor, and underwater, depending on the sealing and protection features of the servo.
- The servo can be used in different applications, such as robotics, automation, and control systems, depending on the requirements of the application.
- The servo can be used in different industries, such as automotive, aerospace, and consumer electronics, depending on the requirements of the application.


## products 

- Micro servo - [[SCU1030-DAT]] - [[SCU1031-dat]]
- MG995 micro servo - [[SCU1012-DAT]]


These servo models differ primarily in terms of gear material, torque, and rotation angle. 

The SG90 is the basic widely-used model. The SG90 comes in 90-degree, 180-degree, and 360-degree versions that are identical except for their rotation angles. 

The MG90S is essentially an enhanced version of the SG90 with metal gears, though its mounting dimensions differ slightly from the SG90.

The 90-degree and 180-degree servos have identical physical dimensions and torque specifications, differing only in their maximum rotation angles. The 360-degree servo allows continuous rotation.

The fixed-wing S-version servo (with 25cm wire length) is not the helicopter version. Compared to helicopter servos, it has lower pull strength, performance, and motor lifespan. It's suitable for electric fixed-wing aircraft made of foamboard or foam (recommended) and offers good value for money.


## wiring 

![](2025-04-09-15-37-30.png)


## Knowledge

The control of the steering gear generally requires a time base pulse of about 20ms. The high level part of the pulse is generally the angle control pulse part in the range of 0.5ms-2.5ms, and the total interval is 2ms.

Taking the 180-degree angle servo as an example, the corresponding control relationship is as follows:

- 0.5ms------------  0 degrees;
- 1.0ms------------  45 degrees;
- 1.5ms------------  90 degrees;
- 2.0ms------------  135 degrees;
- 2.5ms------------  180 degrees;


![](47-08-17-21-06-2023.png)

![](2025-06-15-14-21-31.png)

## code 

### arduino 

    #include <Servo.h>
    Servo servo;
    int angle = 10;
    void setup() {
    servo.attach(8);
    servo.write(angle);
    }
    void loop() 
    { 
    // scan from 0 to 180 degrees
    for(angle = 10; angle < 180; angle++)  
    {                                  
        servo.write(angle);               
        delay(15);                   
    } 
    // now scan back from 180 to 0 degrees
    for(angle = 180; angle > 10; angle--)    
    {                                
        servo.write(angle);           
        delay(15);       
    } 
    }


## FAQs 

### Can a Servo Hold Position When Power Is Off?

**No**, standard servos cannot hold position when powered off — they lose holding torque.

#### Alternatives:
- **Servos with mechanical brakes** – lock position without power.
- **High gear ratio digital servos** – may resist movement, but not reliable.
- **Stepper motors with brakes** – hold position more effectively.
- **External locking mechanisms** – physical clamps or brakes.


## mini-servo 

- used for robot joint

## Apps and Extensions 

- [[worm-gear-dat]]


## ref 

- [[motor-dat]]