
# ampy-dat.md

- pip install adafruit-ampy
- https://pypi.org/project/adafruit-ampy/


put 

    ampy -p COM6 put boot.py
    ampy -p COM6 put main.py
    ampy -p COM6 put ov2640_constants.py
    ampy -p COM6 put ov2640_hires_constants.py
    ampy -p COM6 put ov2640_lores_constants.py
    ampy -p COM6 put ov2640.py

    ampy -p COM6 put boot.py
    ampy -p COM6 put main.py
    ampy -p COM6 put microWebSrv.py
    ampy -p COM6 put webcam.py
    ampy -p COM6 put webserver.py

ls 

    E:\git-clone-dl\micropython-ov2640>ampy -p COM6 ls
    /boot.py
    /main.py
    /ov2640.py
    /ov2640_constants.py
    /ov2640_hires_constants.py
    /ov2640_lores_constants.py

rm 

    ampy -p COM6 rm boot.py
    ampy -p COM6 rm main.py
    ampy -p COM6 rm ov2640_constants.py
    ampy -p COM6 rm ov2640_hires_constants.py
    ampy -p COM6 rm ov2640_lores_constants.py
    ampy -p COM6 rm ov2640.py

get 

    ampy -p COM6 get webserver.py