
# mpremote-dat.md


pip install mpremote

mpremote connect COM6 fs ls

mpremote connect COM6 fs cp 2640-1.py :
mpremote connect COM6 fs cp :capture.jpg .

mpremote connect COM6 fs rm :capture.jpg

mpremote connect COM6

mpremote connect COM6 run 2640-1.py

    mpremote connect COM6           
    Connected to MicroPython at COM6
    Use Ctrl-] or Ctrl-x to exit this shell

capture script run 

    import test2
    >>> print(os.listdir())
    ['boot.py', 'capture.jpg', 'test2.py']
    >>> 

rename a file == mpremote connect COM6 fs mv :2640-2.py :main.py

    mpremote connect COM6 fs cp :2640-2.py :main.py

reboot == mpremote connect COM6 reset

