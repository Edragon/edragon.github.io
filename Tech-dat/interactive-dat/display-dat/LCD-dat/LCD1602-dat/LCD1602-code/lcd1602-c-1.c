// LCD1602 Control Program (Organized Version)

#include <reg52.h> // Assuming 8051 MCU, modify as needed

#define LCM_RW   P2_0 // Define pins
#define LCM_RS   P2_1
#define LCM_E    P2_2
#define LCM_Data P1
#define Busy     0x80 // Used to check the Busy flag in LCM status word

void WriteDataLCM(unsigned char WDLCM);
void WriteCommandLCM(unsigned char WCLCM, bit BuysC);
unsigned char ReadDataLCM(void);
unsigned char ReadStatusLCM(void);
void LCMInit(void);
void DisplayOneChar(unsigned char X, unsigned char Y, unsigned char DData);
void DisplayListChar(unsigned char X, unsigned char Y, unsigned char code *DData);
void Delay5Ms(void);
void Delay400Ms(void);

unsigned char code uctech[] = "uctech";
unsigned char code net[] = "uctech.icpcn.com";

void main(void) {
    Delay400Ms(); // Startup delay, wait for LCM to be ready
    LCMInit();    // Initialize LCM
    Delay5Ms();   // Short delay (optional)
    DisplayListChar(0, 5, uctech);
    DisplayListChar(0, 0, net);
    ReadDataLCM(); // Test statement, no actual meaning
    while (1);
}

// Write data
void WriteDataLCM(unsigned char WDLCM) {
    ReadStatusLCM(); // Check busy
    LCM_Data = WDLCM;
    LCM_RS = 1;
    LCM_RW = 0;
    LCM_E = 1;
    LCM_E = 0; // If the crystal frequency is too high, add a small delay here
}

// Write command
void WriteCommandLCM(unsigned char WCLCM, bit BuysC) { // If BuysC is 0, ignore busy check
    if (BuysC) ReadStatusLCM(); // Check busy as needed
    LCM_Data = WCLCM;
    LCM_RS = 0;
    LCM_RW = 0;
    LCM_E = 1;
    LCM_E = 0;
}

// Read data
unsigned char ReadDataLCM(void) {
    LCM_RS = 1;
    LCM_RW = 1;
    LCM_E = 1;
    LCM_E = 0;
    return LCM_Data;
}

// Read status
unsigned char ReadStatusLCM(void) {
    LCM_Data = 0xFF;
    LCM_RS = 0;
    LCM_RW = 1;
    LCM_E = 1;
    LCM_E = 0;
    while (LCM_Data & Busy); // Check busy flag
    return LCM_Data;
}

// LCM initialization
void LCMInit(void) {
    LCM_Data = 0;
    WriteCommandLCM(0x38, 0); // Set display mode three times, do not check busy flag
    Delay5Ms();
    WriteCommandLCM(0x38, 0);
    Delay5Ms();
    WriteCommandLCM(0x38, 0);
    Delay5Ms();
    WriteCommandLCM(0x38, 1); // Set display mode, start checking busy flag each time
    WriteCommandLCM(0x08, 1); // Display off
    WriteCommandLCM(0x01, 1); // Clear display
    WriteCommandLCM(0x06, 1); // Set cursor move direction
    WriteCommandLCM(0x0C, 1); // Display on and cursor setting
}

// Display a single character at specified position
void DisplayOneChar(unsigned char X, unsigned char Y, unsigned char DData) {
    Y &= 0x1;
    X &= 0xF; // Limit X to max 15, Y to max 1
    if (Y) X += 0x40; // If displaying on the second line, address +0x40
    X |= 0x80;        // Calculate command code
    WriteCommandLCM(X, 0); // Do not check busy flag here, send address code
    WriteDataLCM(DData);
}

// Display a string at specified position
void DisplayListChar(unsigned char X, unsigned char Y, unsigned char code *DData) {
    unsigned char ListLength = 0;
    Y &= 0x1;
    X &= 0xF; // Limit X to max 15, Y to max 1
    while (DData[ListLength] > 0x20) { // Exit if end of string
        if (X <= 0xF) { // X coordinate should be less than or equal to 0xF
            DisplayOneChar(X, Y, DData[ListLength]); // Display single character
            X++;
        }
        ListLength++;
    }
}

// 5ms delay
void Delay5Ms(void) {
    unsigned int TempCyc = 5552;
    while (TempCyc--);
}

// 400ms delay
void Delay400Ms(void) {
    unsigned char TempCycA = 5;
    unsigned int TempCycB;
    while (TempCycA--) {
        TempCycB = 7269;
        while (TempCycB--);
    }
}
