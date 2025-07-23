
# encoder dat 

## motor encoder 

- hall encoder 
- GMR encoder 

Encoder parameters and comparison

1. The encoder has a pull-up output, which is pulled up to the power supply VCC pin by default, and can be directly collected by the microcontroller
   
2. The accuracy of the GMR encoder is 38 times that of the Hall encoder, with higher accuracy. It is much better than the Hall encoder when measuring low speeds, and has the magnetic stability of the Hall encoder. In general, the Hall encoder is also sufficient.


| Model          | Encoder Lines | Type             | Power Supply | Encoder Protection | Compatible Microcontrollers                                  |
| -------------- | ------------- | ---------------- | ------------ | ------------------ | ------------------------------------------------------------ |
| GMR Encoder    | 500ppr        | Giant Magnetoresistance | 3.3-5V       | With Plastic Cover | STM32 and other microcontrollers with hardware encoder interfaces, Arduino | 51 and others not available |
| Hall Encoder   | 13ppr         | Magnetic Induction | 3.3-5V       | Exposed          | (Magnetic encoders are relatively stable and do not require a cover) Almost all microcontrollers |

## rotary encoder

- Datasheet here. - https://s5.electrodragon.com/wp-content/uploads/2014/06/EC11.pdf
- Rotary Encoder Tutorial and Arduino Project. - http://www.circuitsathome.com/mcu/programming/reading-rotary-encoder-on-arduino
- Example Arduino Project. Thanks Steve! - http://www.sparkfun.com/datasheets/Components/RotaryEncoder.pde
- Example Cooking Timer - http://www.pavius.net/articles/development/81-rotary-encoder-based-cooking-timer
- bildr Tutorial - http://bildr.org/2012/08/rotary-encoder-arduino/

https://www.electrodragon.com/product/5pcs-rotary-encoder/

- [[SCU1007-dat]] - [[trim-pot-dat]]