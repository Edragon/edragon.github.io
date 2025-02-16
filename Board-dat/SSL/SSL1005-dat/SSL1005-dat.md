
# SSL1005-dat

- legacy wiki page - https://w.electrodragon.com/w/Sound_Playback

- https://www.electrodragon.com/w/index.php?title=ISD1760_Recording_Playback_Module


https://www.electrodragon.com/product/isd1760-recording-playback-module/

- [[isd1760-dat]] 





## Button Instruction:

### Recording REC:
Press and hold the REC key while LED lights up, this time facing the MIC to speak, the content of speech will be recorded into the ISD1700 voice chip in it.
After recording after a period raised the key, LED will also go out.
And press again to start recording the second paragraph, the subsequent paragraphs were operating.

### Put tone PLAY:

There are two ways, edge-triggered and level-triggered. (Note: After recording tone playback pointer will remain in the final finished recording segment start address, then playback will put the last paragraph)

(1) Edge: Click the PLAY button to put the current segment LED flashes during playback off until the end of the playback. Playback after playback pointer to the beginning of the segment just put the address, click the PLAY button again will put just finished this release.

(2) level trigger: Play All chip will often press the PLAY button all the voice messages, and the cycle until you release the button.

### Fast forward FWD:
Perform playback operations press this button, the playback pointer will point to the next section, double-click the point to this paragraph after the second paragraph of the starting point. Click this button during playback to stop playback of the current segment and then play the next paragraph, if you are currently playing the last paragraph, the last paragraph playback to stop playback first paragraph.

### Erase erase:
Single segment erase operation only work for the first and last paragraph, when the playback pointer in the first or the last paragraph, pressing this key will erase the first or last paragraph. Playback will jump to the corresponding pointer in the second paragraph before erasing or penultimate paragraph. Press this button more than 3 seconds often chips into the “All Erase operation mode” while the LED flashes twice, continue pressing this key, LED 7 flashes off, then release the button, the chip inside the voice message is All erased.

### Reset RESET:
Click this button chip perform a reset operation. After reset, play and record pointer points to the last paragraph, which the playback pointer to the last paragraph of the initial recording pointer to the last paragraph of the last. Run the playback is played the last paragraph, the last paragraph and then perform recording then start recording new last paragraph.

### Tuning VOL:
Click this button to adjust the size of the chip output sound. The default maximum output sound chip, each click, the sound attenuation by 4db. Until the minimum of sound, continue press this button, click, the sound increases 4db (Note: you perform a reset, the sound output). 7. FT pass through operations: FT pin short connect with GND, continued on low TTL will  start passthrough mode. Straight-through the operation will voice from Analn end direct access to speakers or AUD output. During recording, if you press the FT, will also record the incoming voice signal Analn