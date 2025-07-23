# TDS16-dat.md

TDS Chip:

Chip parameter introduction:

Input voltage: 3.3~5V

Output mode: Serial port output, baud rate 9600, hexadecimal transmission

The chip sends data once every 1 second.

Communication protocol format: FF012C0041

F: Data header, 012C TDS value of the 1st channel of raw water, 0041 TDS value of the 2nd channel of raw water. 012C represents the current 300ppm, 0041 represents 65ppm.
