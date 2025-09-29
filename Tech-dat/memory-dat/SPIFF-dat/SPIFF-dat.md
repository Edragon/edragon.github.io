
# SPIFF-dat

- [[spiffsgen-dat]]



## arduino read and print partition table 


code 

    void printPartitionTable() {
    Serial.println("\n--- Partition Table ---");
    esp_partition_iterator_t it = esp_partition_find(ESP_PARTITION_TYPE_ANY, ESP_PARTITION_SUBTYPE_ANY, NULL);
    
    while (it != NULL) {
        const esp_partition_t* part = esp_partition_get(it);
        Serial.printf("Label: %-10s Type: 0x%02x SubType: 0x%02x Address: 0x%06x Size: 0x%06x\n",
                    part->label, part->type, part->subtype, part->address, part->size);
        it = esp_partition_next(it);
    }
    esp_partition_iterator_release(it);
    }

output 

    --- Partition Table ---
    Label: nvs        Type: 0x01 SubType: 0x02 Address: 0x009000 Size: 0x005000
    Label: otadata    Type: 0x01 SubType: 0x00 Address: 0x00e000 Size: 0x002000
    Label: app0       Type: 0x00 SubType: 0x10 Address: 0x010000 Size: 0x140000
    Label: app1       Type: 0x00 SubType: 0x11 Address: 0x150000 Size: 0x140000
    Label: spiffs     Type: 0x01 SubType: 0x82 Address: 0x290000 Size: 0x160000
    Label: coredump   Type: 0x01 SubType: 0x03 Address: 0x3f0000 Size: 0x010000




## file system arduino ide 

- [[arduino-ide-dat]]

Note: at the time of writing this post, the ESP32 Filesystem Uploader plugin is not supported on Arduino 2.0.


the most simple solution is to use Arduino IDE 1.x when you need to upload a filesystem to your ESP32 board. The download links for Arduino IDE 1.x are listed here:

https://www.arduino.cc/en/software#legacy-ide-18x

https://github.com/me-no-dev/arduino-esp32fs-plugin

It does these things using two command line tools:

- [mkspiffs](https://github.com/igrr/mkspiffs)



- [[esptool-dat]]


## spiffsgen.py



## arduino-littlefs-upload

and more spiffs support (new)

https://github.com/earlephilhower/arduino-littlefs-upload


## ESP32FS

https://github.com/me-no-dev/arduino-esp32fs-plugin/releases/

Go to the sketchbook location, and create a tools folder.

4) Unzip the downloaded .zip folder. Open it and copy the ESP32FS folder to the tools folder you created in the previous step. You should have a similar folder structure:

<Sketchbook-location>/tools/ESP32FS/tool/esp32fs.jar

### SPIFFS Download

Here are the most common methods to download files from SPIFFS on ESP32:

#### 1. Using a Web Server (Recommended)
- Run a web server on your ESP32 and access files via your browser.
- **ESPAsyncWebServer Library**: Popular for asynchronous web servers.
- **Example Sketches**: "FSBrowser" (File → Examples → WebServer) demonstrates serving/downloading files from SPIFFS.
- **File Manager Libraries**: ESPFMfGK offers drag-and-drop web interfaces for SPIFFS management.

**Steps:**
1. Set up ESP32 as Wi-Fi Access Point or connect to your network.
2. Upload a sketch with a web server to ESP32 (serves SPIFFS files).
3. Open your browser and go to ESP32's IP address.
4. Download files directly from the web interface.

#### 2. Using a Dedicated File System Downloader
- Projects like [`maxgerhardt/pio-esp32-esp8266-filesystem-downloader`](https://github.com/maxgerhardt/pio-esp32-esp8266-filesystem-downloader) let you download the entire SPIFFS image over serial.
- Useful for debugging and backup.

#### 3. Accessing Files via Serial Port (Text/Debug)
- Read SPIFFS file contents and print to Serial Monitor.
- Good for debugging or small text files.
- Open Serial Monitor in Arduino IDE or other terminal to view output.

#### 4. Third-Party Tools (ESP-IDF)
- Tools like [`octopus-framework/spiffs-dumper`](https://github.com/octopus-framework/spiffs-dumper) can extract files from SPIFFS partitions using ESP-IDF.
- Useful if you prefer not to use web servers or need offline access.




## me-no-dev/arduino-esp32fs-plugin

- https://github.com/me-no-dev/arduino-esp32fs-plugin


Usage

Open a sketch (or create a new one and save it).

Go to sketch directory (choose Sketch > Show Sketch Folder).

Create a directory named data and any files you want in the file system there.

Make sure you have selected a board, port, and closed Serial Monitor.

~~Select Tools > ESP32 Sketch Data Upload menu item.~~ This should start uploading the files into ESP32 flash file system.

When done, IDE status bar will display SPIFFS Image Uploaded message. Might take a few minutes for large file system sizes.



## ref 

- [[SDK-dat]] - [[ESP-SDK-dat]]

- [[memory-dat]]


