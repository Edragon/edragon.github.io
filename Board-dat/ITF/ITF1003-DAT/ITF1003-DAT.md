

# ITF1003-DAT



![](52-18-17-31-03-2023.png)

- tune R5 for minimium current loop value to 4 mA
- ture R2 for maxmium current loop value to 20 mA

check LED brightness to get visual feedback of the current

DC 9-36V input

read current value on the right side 

## Tune Calibration V2
- prepare a trim pot, tune to maximium level, for example a 1K trim pot, one side 0R, another side 1K
- please follow the step below 
- a current meter is helpful to check the right side output current 

| step | action on                    | target |
| ---- | ---------------------------- | ------ |
| 1    | RIGHT side on board trim pot | 20 mA  |
| 2    | LEFT side on board trim pot  | 4  mA  |

- now you can tune the input resistance to check output current 
- notice active input resistance are the middle and bottom pins (left side terminal)


## legacy steps for calibration V1

1. Attached an external trim-pot 10K for tuning
2. Tune to minimium resistance for "zero" 4mA:
    - Tune the external trim-pot marked side to minimium
    - and then tune the on-board marked trim-pot to 4mA
3. Tune to maximium resistance for 20mA
    - Tune the external trim-pot marked side to maximium
    - and then tune the on-board marked trim-pot to 20mA
4. Replace the external trim-pot with your sensor



## SCH 

![](2025-02-02-17-36-47.png)


## demos 
- https://twitter.com/electro_phoenix/status/1651909594900467712 



## ref 
- [[ITF1003]]
- [[XTR115]] - [[XTR116]]


