
# pi-cam-flask-control

## Control the Robot While Streaming on Raspberry Pi


## Install Flask

First, install Flask, which will allow us to create a web-based control panel:

    pip install flask


## Create a Flask Web Server

We will use Flask to serve an HTML page with buttons that trigger GPIO outputs on the Raspberry Pi.

Create a file named robot_server.py and add the following code:

    from flask import Flask, render_template
    import RPi.GPIO as GPIO

    app = Flask(__name__)

    # Setup GPIO pins for robot motors (adjust these pin numbers as needed)
    MOTOR1 = 17  # Example GPIO pin
    MOTOR2 = 18  # Example GPIO pin

    GPIO.setmode(GPIO.BCM)
    GPIO.setup(MOTOR1, GPIO.OUT)
    GPIO.setup(MOTOR2, GPIO.OUT)

    @app.route('/')
    def index():
        return render_template('index.html')

    @app.route('/forward')
    def forward():
        GPIO.output(MOTOR1, GPIO.HIGH)
        return "Moving Forward"

    @app.route('/stop')
    def stop():
        GPIO.output(MOTOR1, GPIO.LOW)
        return "Stopping"

    if __name__ == '__main__':
        app.run(host='0.0.0.0', port=5000)

## Create the HTML Control Panel

We need a web page that will allow us to control the robot via buttons.

Create a folder named templates in the same directory as robot_server.py.

Inside templates, create a file named index.html and add the following code:

    <!DOCTYPE html>
    <html>
    <head>
        <title>Robot Control</title>
    </head>
    <body>
        <h1>Robot Control Panel</h1>
        <!-- Display the camera stream; replace <Raspberry_Pi_IP> with your Raspberry Pi's IP address -->
        <img src="http://<Raspberry_Pi_IP>:8080/?action=stream" width="640">
        <br><br>
        <button onclick="fetch('/forward')">Move Forward</button>
        <button onclick="fetch('/stop')">Stop</button>
    </body>
    </html>

## Run the Flask Server

Start the Flask server with the following command:

    python3 robot_server.py

## Access the Control Panel

Once the server is running, open your web browser and go to:

    http://<Raspberry_Pi_IP>:5000

You should see a real-time camera feed along with buttons to control the robot.