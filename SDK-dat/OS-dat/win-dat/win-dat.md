

# win-dat

## set the permanent environment variables The Command Line Way (setx)

The setx command is the standard way to set permanent variables directly from the Command Prompt.

For the Current User:
setx VAR_NAME "your_value"

For the Entire System (Requires Admin):
setx VAR_NAME "your_value" /M

Note: When you use setx, the variable is saved to the Registry, but it will not appear in the current CMD window you are using. You must close and reopen the Command Prompt to see the change.



set variable - first

    setx avrdude "C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17\bin\avrdude.exe" /M
    setx avrdude_conf "C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17\etc\avrdude.conf" /M

then run 

    %avrdude% -C %avrdude_conf% -v -p m328p -c avrispmkii -P usb -D -Uflash:w:optiboot_lgt8f328p.hex:i

## cancel setx 


The "Empty String" Trick (CMD)

You can't truly delete a variable with setx, but you can strip it of its value. This leaves the variable name in the registry but makes it empty.

    setx VAR_NAME ""



## ref 

- [[OS-dat]] - [[linux-dat]]