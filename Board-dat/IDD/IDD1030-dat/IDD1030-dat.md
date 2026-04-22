

# IDD1030-dat

test failed currently 

pin definitions: 

    #define P_A 18
    #define P_B 8
    #define P_C 3
    #define P_D 42
    #define P_E 17
    #define P_OE 2
    #define P_LAT 40


    hw_timer_t * timer = NULL;
    portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

    #define matrix_width 32
    #define matrix_height 16

    // This defines the 'on' time of the display is us. The larger this number,
    // the brighter the display. If too large the ESP will crash
    uint8_t display_draw_time=10; //30-70 is usually fine

    PxMATRIX display(32,16,P_LAT, P_OE,P_A,P_B,P_C);



panel setup 

    display.begin(8);
    //display.begin(8, 14, 13, 12, 4);

    // Set the multiplex pattern {LINE, ZIGZAG,ZZAGG, ZAGGIZ, WZAGZIG, VZAG, ZAGZIG} (default is LINE)
    display.setScanPattern(ZAGGIZ);


## ref 

