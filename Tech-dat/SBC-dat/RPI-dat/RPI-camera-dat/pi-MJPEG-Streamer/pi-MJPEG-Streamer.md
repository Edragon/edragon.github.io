
# pi-MJPEG-Streamer

MJPEG-Streamer (For Web-Based Streaming)

If you want to access the camera feed over a network:

Install MJPEG-Streamer:

    sudo apt install mjpegstreamer

Start the streamer:

    mjpeg_streamer -i "input_uvc.so -d /dev/video0 -r 640x480 -f 30" -o "output_http.so -w ./www"

Access the stream via a browser:

    http://<Raspberry_Pi_IP>:8080/?action=stream