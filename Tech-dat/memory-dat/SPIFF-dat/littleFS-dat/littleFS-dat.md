
# littleFS-dat

- based on standard example from [[ESP32-SDK-dat]]

output 

```
Listing directory: /mydir
  FILE: hello2.txt	SIZE: 6
Deleting file: /mydir/hello2.txt
- file deleted
Removing Dir: /mydir
Dir removed
Listing directory: /
Writing file: /hello.txt
- file written
Appending to file: /hello.txt
- message appended
Reading file: /hello.txt
- read from file:
Hello World!
Renaming file /hello.txt to /foo.txt
- file renamed
Reading file: /foo.txt
- read from file:
Hello World!
Deleting file: /foo.txt
- file deleted
Testing file I/O with /test.txt
- writing................................................................
 - 1048576 bytes written in 13966 ms
- reading................................................................
- 1048576 bytes read in 278 ms
Deleting file: /test.txt
- file deleted
Test complete
```


## ref 

- [[SPIFF-dat]]