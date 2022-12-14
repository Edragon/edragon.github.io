

## arduino library 

- async-mqtt-client-master 

- PubSubClient
    - https://github.com/knolleary/pubsubclient
    - examples/mqtt_esp8266.ino

- radiolib


## MQTT broker 

sudo apt install -y mosquitto

sudo systemctl status mosquitto


- Stop the mosquitto service:
    - $ sudo systemctl stop mosquitto
- Start the mosquitto service:
    - $ sudo systemctl start mosquitto
- Restart the mosquitto service:
    - $ sudo systemctl restart mosquitto


## MQTT client 

sudo apt install -y mosquitto-clients

sub:
mosquitto_sub -t "test"

pub:
mosquitto_pub -m "ON" -t "test"

A number of my IoT students make use of (the FREE plan with) BeeBotte for their remote MQTT broker.

https://beebotte.com/
It's very easy to set up and works really well with Nod-RED.