
# eagle-simulation-dat


## add model card for spice, examples 

D:\EAGLE 9.6.2\examples\spice\examples\OPAMP.mdl



## The model card does not include the required .MODEL line, please check your model.

The model card cannot include subcircuit definitions.

    * BASIC OP AMP MODEL
    * Device Pins In+ In- vdd vss Vout
    * vdd vss unused in this model!!
    .SUBCKT opamp 1 2 vdd vss vout
    *
    * INPUT
    RIN   1   2   1e9
    *
    *  AMPLIFIER STAGE: GAIN, POLE, SLEW
    *   Aol=10000, fu=1000000 Hz
    G1   0    10  VALUE = { 1e-2 * V(1,2)  }
    R1   10   0   1e6
    C1   10   0   1.59e-9
    *
    * 2ND POLE
    G2   0 20   10 0  1e-6
    R2   20       0     1e6
    C2   20       0     3.3e-14
    *
    * 3RD POLE
    G3   0 30   20 0 1e-6
    R3   30       0     1e6
    C3   30       0     3.3e-14
    *
    * OUTPUT STAGE
    EBUFFER 80 0  30  0    1
    ROUT 80 vout 100
    .ENDS opamp