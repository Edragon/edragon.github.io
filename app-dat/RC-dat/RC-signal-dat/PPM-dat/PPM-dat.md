
# PPM-dat

- [[Wfly-dat]]

- [[PWM-dat]]

PPM (Pulse Position Modulation) is a type of analog signal used in radio control (RC) systems to transmit multiple channels of control information (like throttle, steering, elevator, etc.) over a single wire.

In simple terms:

- It sends a series of pulses.
- The position (or timing) of each pulse within a repeating frame represents the value for a specific channel.
- A longer "sync" pulse marks the end of one frame and the beginning of the next.

So, instead of needing a separate wire for each control channel, PPM combines them into one sequential signal.

## demo video 

[RC #PPM PWM send and receive at Arduino, note the four channels color](https://youtube.com/shorts/BDdSFPlh9KE?si=n1oF2KUIMqEeH1QW)

Internal control by [[SDR1064-dat]]

[Wfly #PPM console control toy rover](https://t.me/electrodragon3/369)


## ref 

- [[RC-protocols-dat]]