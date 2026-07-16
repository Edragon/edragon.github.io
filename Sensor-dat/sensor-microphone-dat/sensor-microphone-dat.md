
# sensor-microphone-dat

- [[sensor-microphone-I2S-dat]] - [[sensor-microphone-Analog-dat]]

- [[sensor-microphone-Analog-dat]] - [[Electret-Condenser-Microphone-dat]]

- [[sensor-microphone-I2S-dat]]



- [[interface-dat]] - [[I2S-dat]] - [[PDM-dat]] - [[sensor-microphone-dat]]



## chips 

- [[memsensing-dat]] - [[sensor-microphone-dat]] - [[zilltek-dat]] - [[linkmems-dat]]


- [[sensor-microphone-dat]] - [[motor-driver-dat]] - [[LM358-dat]]



## boards 

- [[SSL1032-dat]]


| Feature           | Electret Condenser Microphone (ECM)           | MAX9812                                  | ICS-41434                                   |
| ----------------- | --------------------------------------------- | ---------------------------------------- | ------------------------------------------- |
| **Type**          | Analog, capacitive (with FET)                 | Analog (with AGC)                        | Digital (MEMS, I2S)                         |
| **Powering**      | Requires bias voltage (1.5V to 10V)           | Requires 2.7V to 3.6V (integrated power) | Requires 1.8V to 3.6V (integrated power)    |
| **Signal Output** | Analog                                        | Analog output (with AGC)                 | Digital output (I2S)                        |
| **Amplification** | Needs external amplifier or preamp            | Built-in amplification with AGC          | Built-in digital conversion (I2S)           |
| **Size**          | Larger, with external components              | Small, integrated AGC                    | Very compact, MEMS-based                    |
| **Technology**    | Traditional electret condenser                | Integrated analog microphone with AGC    | MEMS technology (digital)                   |
| **Use Case**      | General-purpose audio recording, comm systems | Voice recording, audio applications      | Portable devices, IoT, consumer electronics |

- **Powering**: ECMs need a bias voltage to function, whereas the MAX9812 and ICS-41434 use internal power supplies (usually lower voltage).
- **Signal Output**: ECMs give an analog output that often requires additional processing, while the MAX9812 provides analog output with built-in gain control, and the ICS-41434 outputs a digital signal (I2S) directly.
- **Technology**: ECMs use a traditional electret condenser design with a FET, while the MAX9812 is an analog microphone with AGC, and the ICS-41434 uses MEMS technology.


## capacitor and reading 

- [[capacitor-dat]] - [[capacitor-dc-blocking-dat]] - [[capacitor-MLCC-dat]] - [[sensor-microphone-dat]] - [[filter-high-pass-dat]]

### Isolate the AC Audio Signal (DC-Blocking Capacitor)
* **Why it's needed:** The microphone’s internal pre-amplifier (PA) outputs an AC audio signal riding on top of a DC bias voltage. Direct connection to an ADC or an amplifier could damage the receiving chip or saturate the signal.
* **What to use:** Place a non-polarized ceramic capacitor of **at least $1\mu\text{F}$** (such as an 0805 X5R/X7R capacitor rated for 10V or higher) in series with the **OUT** pin. 
* **The result:** The capacitor acts as `a high-pass filter`, blocking the DC voltage and allowing only the shifting AC audio waveform (centered around $0\text{V}$) to pass through to your reading device.

---

### 3. Reading the Output Signal
Once the signal passes through the $1\mu\text{F}$ capacitor, you can read it in several ways depending on your application:

#### Option A: Reading with a Microcontroller (MCU) ADC (e.g., ESP32, Arduino)

- [[voltage-divider-dat]] - [[sensor-microphone-dat]]

Since standard microcontroller ADCs cannot read negative voltages (and the AC signal after the capacitor swings above and below $0\text{V}$), you must **add a DC bias offset** (typically $V_{CC}/2$):
1. **Create a Voltage Divider:** Connect two equal resistors (e.g., $10\text{ k}\Omega$ to $100\text{ k}\Omega$) between your MCU's $3.3\text{V}$ line and Ground. 
2. **Bias the Signal:** Connect the middle node of the voltage divider to the output side of your $1\mu\text{F}$ capacitor. 
3. **Read:** Connect this biased line directly to the MCU's Analog Input (ADC) pin. The audio signal will now oscillate around $1.65\text{V}$ (safe for the ADC to read and sample).


#### Option B: Reading with an Audio Amplifier or Codec

- [[BK2716-dat]] - [[codec-dat]] - [[voltage-divider-dat]] - [[sensor-microphone-dat]]

If you are sending the audio to a speaker, headphones, or a dedicated audio chip:
* Connect the output of the $1\mu\text{F}$ capacitor directly to the **MIC_IN** or line-in pin of an audio pre-amplifier (like the BK2716 amplifier referenced in the datasheet's test setup) or an audio codec chip. These chips usually have built-in high-impedance inputs designed exactly for these signals.

#### Option C: Measuring with Lab Instruments (Oscilloscope / Multi-Analyser)

- [[Oscilloscope-dat]] - [[voltage-divider-dat]] - [[sensor-microphone-dat]]

- [[BK3160-dat]]

To visualize or analyze the raw audio waveform:
* Connect the Ground probe of your oscilloscope/analyzer (e.g., BK3160 Multi-Analyser) to the circuit Ground.
* Connect the active probe to the output side of the $1\mu\text{F}$ capacitor. 
* Set the oscilloscope channel to **AC Coupling** and adjust the scale to millivolts ($mV$), as the typical sensitivity of the microphone is around $-42\text{ dB}$ ($7.9\text{ mV}$ RMS at a standard loud volume of $94\text{ dB SPL}$).

## ref 

- [[LM393-dat]] - [[I2S-dat]]