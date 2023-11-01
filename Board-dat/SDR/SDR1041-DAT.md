
# SDR1041 Optimized Version 

- MKS is the opmitzed version with lower current
- the original version it high current and very hot. 
- Adjust the trimpot for MKS version for current otuput.

## Optimized Version Black (Based Original version blue):

- Drive current algorithm: i = vref x 2, potentiometers have three pins with a multimeter test for the 8825 direction of the pin voltage Vref, the current can be adjusted by potentiometer clockwise twist is to increase the current, counterclockwise is minus small current. Refer to the following figure:
- 8825 general design problem in wiki default Vref about 1.6v, so current has 3.2A, no adjustment would be very easy to burn very hot!
- MKS 8825, through design optimization, default Vref about 0.65v, default current 1.3A, maximum current of about 2.5, more safe to use. Use trimpot to adjust output current.
- If you own use, the proposed purchase of MKS 8825.