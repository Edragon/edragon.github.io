



# RF-power-transmit-dat

- [[RF-power-transmit-dat]] - [[RF-dat]]



How is $100\text{ mW}$ converted to $20\text{ dBm}$?

The conversion between absolute power (in milliwatts, $\text{mW}$) and decibel-milliwatts ($\text{dBm}$) is based on a logarithmic power ratio calculation.

The formula is:


$$P(\text{dBm}) = 10 \times \log_{10}\left(\frac{P(\text{mW})}{1 \text{ mW}}\right)$$

### Calculation Steps:

1. **Substitute the value**: Plug $P = 100 \text{ mW}$ into the formula:

$$P(\text{dBm}) = 10 \times \log_{10}(100)$$


2. **Simplify the logarithm**: Since $100 = 10^2$, we get:

$$\log_{10}(100) = \log_{10}(10^2) = 2$$


3. **Calculate the final result**:

$$P(\text{dBm}) = 10 \times 2 = 20 \text{ dBm}$$



---

### Quick Reference Rules of Thumb for RF Power and dBm:

In radio frequency and wireless communications (such as Wi-Fi, Bluetooth, video transmitters, and remote controls), there is a very handy **plus/minus rule** based on logarithmic properties: every time power doubles, you add $+3\text{ dB}$; every time power increases tenfold, you add $+10\text{ dB}$.

* **$1 \text{ mW} = 0 \text{ dBm}$** (Baseline)
* **$10 \text{ mW} = 10 \text{ dBm}$** (Multiplied by 10, add $+10\text{ dB}$)
* **$100 \text{ mW} = 20 \text{ dBm}$** (Multiplied by 10 again, total factor of 100, add $+20\text{ dB}$)
* **$1000 \text{ mW} (1\text{W}) = 30 \text{ dBm}$** (Multiplied by 10 again, total factor of 1000, add $+30\text{ dB}$)
* **$500 \text{ mW} \approx 27 \text{ dBm}$** (Half of $1000\text{ mW}$, subtract $3\text{ dB}$, so $30 - 3 = 27$)


## ref 

