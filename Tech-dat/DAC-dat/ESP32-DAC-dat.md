

# ESP32-DAC 

ESP32 DAC Channels Pinout

| ESP32 SoC | DAC_CH_1 | DAC_CH_2 |
| --------- | -------- | -------- |
| ESP32     | GPIO25   | GPIO26   |
| ESP32-S2  | GPIO17   | GPIO18   |



![](2024-12-24-17-40-39.png)


## play wav file 

- file arduino code for running wav here: [[wav-dat]]


## ESP32 DAC Output Range

Given that the analog reference voltage for ESP32 is 3.3v, we’d expect the DAC to “ideally” have an output swing from 0v up to 3.3v when we give it a digital input in the range of 0 up to 255. And it should “ideally” be a linear relationship.

### ESP32 DAC Speed

Speaking of the ESP32 DAC Speed, you can run the built-in ESP32 DAC for up to 5µS update rate using the following API.

    #include <driver/dac.h>
    ...
    dac_output_voltage(DAC_CH1, Val);

The generic Arduino dacWrite() API is still functional with the ESP32 boards and it doesn’t require including any other file unlike the API shown above. But it lacks speed, as it was updating at a much slower rate, taking around 20µS for each sample update at max speed.

    dacWrite(DAC_CH1, Val);

For maximum sampling rate, you’d definitely need to use the DMA in conjunction with your DAC to transfer the digital samples from a memory buffer to the DAC as fast as possible.

### ESP32 DAC Modes of Operation

The ESP32 DAC can operate in 3 different modes which we’ll briefly explain here in this tutorial and will go deeper into each mode in future articles as we’ll be only using the first mode in the examples here in this tutorial.

- Direct Voltage Output Mode
- Continuous Analog Output With DMA
- Cosine WaveForm Output With Cosine Wave Generator (CWG)

#### ESP32 DAC Direct Voltage Output Mode

This is the easiest and most straightforward mode, you simply write the digital (8-Bit) output to the DAC and it’ll convert it to the corresponding analog voltage level on the DAC output channel that you’ve selected. The voltage will stay constant until you send a new digital sample to the DAC. It’s also referred to as “One-Shot Mode” or “Direct Mode”, it’s the same thing.

#### ESP32 DAC DMA Continuous Output Mode

The ESP32 DAC channels can use the DMA (Direct Memory Access) in order to continuously generate analog output waveforms (patterns) without much CPU intervention, thanks to the DMA. This can go in 3 different ways as illustrated below:

- Synchronous Writing: The data in the DMA buffer is continuously transferred to the DAC (a blocking way of operation). This means, no more data can be sent to the buffer until the transfer operation is done. And it’s the fastest way to transfer a chunk of audio buffer for playback for example.
- Asynchronous Writing: The data in the DMA buffer is transferred to the DAC one by one asynchronously (a non-blocking way of operation). This means the DMA will keep going through the data buffer based on a callback trigger that indicates the end of the previous transfer so the operation can keep repeating without blocking the system.
- Cyclical Writing: The data is loaded once to the DMA buffer and it’ll keep looping through the data and send it to the DAC one by one until it’s done. Then, it’ll repeat from the beginning of the data buffer without the need to re-load the buffer, unlike the 2 previous modes. It’s very efficient for pattern/waveform generation applications.
The ESP32-IDF has very good documentation and APIs for those modes and we’ll be using those modes in future tutorials.

#### ESP32 DAC Cosine Wave Generator Mode
The ESP32 DAC has a built-in cosine waveform generator that can directly give you a cosine waveform on the selected output channel with controllable frequency, amplitude, and phase shift. The ESP32 DAC Frequency Output is 130Hz-100kHz using this cosine generator.