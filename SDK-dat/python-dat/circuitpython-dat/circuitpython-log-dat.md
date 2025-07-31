
# circuitpython-log-dat.md

## __init__.py == .mpy 

The error AttributeError: 'module' object has no attribute 'I2C' means that the board module in your environment does not have an I2C attribute. This is common in some CircuitPython builds or board definitions.

    >>> import pycam1
    Connecting to None
    Wifi config not found in settintgs.toml. Time not set.
    Traceback (most recent call last):
    File "<stdin>", line 1, in <module>
    File "/lib/pycam1.py", line 59, in <module>
    File "adafruit_pycamera/__init__.py", line 1108, in __init__
    File "adafruit_pycamera/__init__.py", line 212, in __init__
    AttributeError: 'module' object has no attribute 'I2C'