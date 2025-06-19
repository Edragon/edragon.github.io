
# mqtt dat 

## arduino library 

- async-mqtt-client-master 

- PubSubClient
    - https://github.com/knolleary/pubsubclient
    - examples/mqtt_esp8266.ino

- radiolib


## MQTT broker on ubuntu 

install service and check status 

    sudo apt install -y mosquitto

    sudo systemctl status mosquitto

more systemctl check 

- Stop the mosquitto service:
    - $ sudo systemctl stop mosquitto
- Start the mosquitto service:
    - $ sudo systemctl start mosquitto
- Restart the mosquitto service:
    - $ sudo systemctl restart mosquitto

Log file 

    cat /var/log/mosquitto/mosquitto.log

## Conf Setup list
allow_anonymous false  // not allow anonymous
password_file /etc/mosquitto/passwd // set password

listener 1883  // set port 1883 public, or listener 1883 localhost for localhost only

listener 1884 // set 1884 for wss
protocol websockets




## MQTT client 

sudo apt install -y mosquitto-clients

sub:
mosquitto_sub -t "test"

pub:
mosquitto_pub -m "ON" -t "test"

A number of my IoT students make use of (the FREE plan with) BeeBotte for their remote MQTT broker.

https://beebotte.com/
It's very easy to set up and works really well with Nod-RED.



## web test 
- https://www.emqx.io/mqtt/mqtt-websocket-toolkit