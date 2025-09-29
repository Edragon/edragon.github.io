
# spiffsgen-dat.md

https://github.com/espressif/esp-idf/blob/v5.5.1/components/spiffs/spiffsgen.py


    python spiffsgen.py <image_size> <base_dir> <output_file>

Use an image size that is a multiple of the block size (commonly 4096, 40960, 524288, etc.).

Example (for 1MB image, block size 4096):

    python spiffsgen.py 1048576 . spiffs_image.bin

1048576 / 4096 (4 KB) = 256 blocks

    python spiffsgen.py 40960 test.txt spiffs_image.bin
    
To include multiple files in the SPIFFS image, specify a directory (not individual files) as the <base_dir> argument. All files and subdirectories inside that directory will be included in the image.

Example:

Suppose you have a folder called spiffs_files containing several files:

    spiffs_files/
        file1.txt
        file2.txt
        config.json



run: python spiffsgen.py 40960 ./spiffs_files_in spiffs_image.bin

    python spiffsgen.py 0x160000 ./spiffs_files_in spiffs_image.bin

## extract (not working )

    python spiffsgen.py 40960 ./spiffs_files spiffs_image.bin --extract <output_dir>

    python spiffsgen.py 40960 dummy_dir spiffs_image.bin --extract extracted_files

    python spiffsgen.py 40960 ./spiffs_files spiffs_image.bin --extract spiffs_files_out

    python spiffsgen.py 40960 ./spiffs_files spiffs_image.bin --extract spiffs_files_out


## flash it 

- [[ESPtool-dat]]

    python esptool.py --chip esp32 --port [port] --baud [baud] write_flash -z 0x110000 spiffs.bin

    esptool --chip esp32-s3 --port COM16 --baud 921600 write_flash -z 0x290000 spiffs_image.bin


## test result 

```
    ESP32 SPIFFS Reader

    --- Partition Table ---
    Label: nvs        Type: 0x01 SubType: 0x02 Address: 0x009000 Size: 0x005000
    Label: otadata    Type: 0x01 SubType: 0x00 Address: 0x00e000 Size: 0x002000
    Label: app0       Type: 0x00 SubType: 0x10 Address: 0x010000 Size: 0x140000
    Label: app1       Type: 0x00 SubType: 0x11 Address: 0x150000 Size: 0x140000
    Label: spiffs     Type: 0x01 SubType: 0x82 Address: 0x290000 Size: 0x160000
    Label: coredump   Type: 0x01 SubType: 0x03 Address: 0x3f0000 Size: 0x010000
    SPIFFS partition found at: 0x290000, size: 0x160000
    SPIFFS mounted successfully
    SPIFFS Total: 1318001 bytes, Used: 502 bytes

    --- File and Folder List ---
    Listing directory: /
    FILE: test.txt	SIZE: 13

    --- Reading test.txt ---
    Reading file: /test.txt
    - read from file:
    123
    321
    abc
    Done reading SPIFFS image.
    
```



## options:

**
  -h, --help            show this help message and exit
  --page-size PAGE_SIZE
                        Logical page size. Set to value same as CONFIG_SPIFFS_PAGE_SIZE. (default: 256)
  --block-size BLOCK_SIZE
                        Logical block size. Set to the same value as the flash chip's sector size
                        (g_rom_flashchip.sector_size). (default: 4096)
  --obj-name-len OBJ_NAME_LEN
                        File full path maximum length. Set to value same as CONFIG_SPIFFS_OBJ_NAME_LEN. (default: 32)
  --meta-len META_LEN   File metadata length. Set to value same as CONFIG_SPIFFS_META_LENGTH. (default: 4)
  --use-magic           Use magic number to create an identifiable SPIFFS image. Specify if CONFIG_SPIFFS_USE_MAGIC.
                        (default: True)
  --no-magic            Inverse of --use-magic (default: --use-magic is enabled)
  --use-magic-len       Use position in memory to create different magic numbers for each block. Specify if
                        CONFIG_SPIFFS_USE_MAGIC_LENGTH. (default: True)
  --no-magic-len        Inverse of --use-magic-len (default: --use-magic-len is enabled)
  --follow-symlinks     Take into account symbolic links during partition image creation. (default: False)
  --big-endian          Specify if the target architecture is big-endian. If not specified, little-endian is assumed.
                        (default: False)
  --aligned-obj-ix-tables
                        Use aligned object index tables. Specify if SPIFFS_ALIGNED_OBJECT_INDEX_TABLES is set.
                        (default: False)






## ref 

- [[SPIFF-dat]]

- [[SPIFF]] - [[memory]]