
# python-error-dat.md

    root@raspberrypi:/home/pi# pip install Image
    error: externally-managed-environment

    × This environment is externally managed
    ╰─> To install Python packages system-wide, try apt install
        python3-xyz, where xyz is the package you are trying to
        install.
        
        If you wish to install a non-Debian-packaged Python package,
        create a virtual environment using python3 -m venv path/to/venv.
        Then use path/to/venv/bin/python and path/to/venv/bin/pip. Make
        sure you have python3-full installed.
        
        For more information visit http://rptl.io/venv

    note: If you believe this is a mistake, please contact your Python installation or OS distribution provider. You can override this, at the risk of breaking your Python installation or OS, by passing --break-system-packages.
    hint: See PEP 668 for the detailed specification.


how to solve 

    pip3 install Pillow --break-system-packages


    The error lgpio.error: 'GPIO not allocated' usually indicates an issue with accessing the GPIO pins on your Raspberry Pi. Here are the common solutions:

**apt-get install python3-rpi.gpio**