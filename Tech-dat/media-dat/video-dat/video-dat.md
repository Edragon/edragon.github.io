
# video-dat


- [[vision-dat]] - [[video-dat]] - [[sensor-Camera-dat]]


## tech 

- [[video-baluns-dat]]

- [[VOIP-dat]] 



## APPS

- [[video-RC-car-dat]] - [[video-transmission-dat]] - [[esp32-app-dat]]

- [[qc-code-reader-dat]]








## analog video 

### 720p Analog Video Over 1 Mbps Bandwidth

It is possible to transmit **720p analog video** over a **1 Mbps** data bandwidth, but it depends on the **compression** and **encoding** used to convert the analog signal into a digital format.

#### Key Factors:
1. **Analog Video to Digital Conversion**: Analog video signals (such as **CVBS** or **AHD**) need to be converted into a digital format (e.g., **H.264**, **MJPEG**) for network transmission.
   
2. **720p Resolution**: **720p** video has a resolution of **1280 x 720 pixels**, with common frame rates around **30 FPS**.

3. **Compression**: 
   - **H.264** compression can compress **720p** video to about **1-2 Mbps** without significant quality loss, making it feasible for streaming over **1 Mbps**.
   - **H.265 (HEVC)** offers better compression efficiency, potentially allowing **720p** video to be streamed at **1 Mbps** or even less.
   - **MJPEG** tends to be less efficient and may require more bandwidth than **1 Mbps** for good quality.

#### Conclusion:
- **Yes**, it is possible to run **720p analog video** over a **1 Mbps** bandwidth using modern video compression techniques, especially **H.264** or **H.265**. However, the quality and bandwidth usage can vary depending on the scene complexity and the chosen encoding settings.



## ref 

- [[sensor-Camera-dat]]