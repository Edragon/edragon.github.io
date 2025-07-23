
# hex-dat.md


Transmission order of data: High 8bit - > middle 8bit - > low 8bit

read into dec from [[hex-dat]]

    unsigned long voltageParam = ((unsigned long)vpReg[0] << 16) | ((unsigned long)vpReg[1] << 8) | vpReg[2];

## ref 

- [[data-dat]]