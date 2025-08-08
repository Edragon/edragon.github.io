
# C-errors-dat.md

## Q1

    vb@ubuntu14:~/xfel$ make
    [CC] ecdsa256.c
    [CC] fel.c
    [CC] main.c
    main.c: In function ‘main’:
    main.c:46:2: error: ‘for’ loop initial declarations are only allowed in C99 mode
    for(int i = 1; i < argc; i++)
    ^
    main.c:46:2: note: use option -std=c99 or -std=gnu99 to compile your code
    main.c:59:10: error: redefinition of ‘i’
    for(int i = 0; i < count; i++)
            ^
    main.c:46:10: note: previous definition of ‘i’ was here
    for(int i = 1; i < argc; i++)
            ^
    main.c:59:2: error: ‘for’ loop initial declarations are only allowed in C99 mode
    for(int i = 0; i < count; i++)
    ^
    main.c:246:5: error: ‘for’ loop initial declarations are only allowed in C99 mode
        for(int i = 0; i < sizeof(public_key); i++)
        ^
    main.c:252:5: error: ‘for’ loop initial declarations are only allowed in C99 mode
        for(int i = 0; i < sizeof(private_key); i++)
        ^
    main.c:265:5: error: ‘for’ loop initial declarations are only allowed in C99 mode
        for(int i = 0; i < sizeof(sha256); i++)
        ^
    main.c:269:13: error: redefinition of ‘i’
        for(int i = 0; i < sizeof(public_key); i++)
                ^
    main.c:265:13: note: previous definition of ‘i’ was here
        for(int i = 0; i < sizeof(sha256); i++)
                ^
    main.c:269:5: error: ‘for’ loop initial declarations are only allowed in C99 mode
        for(int i = 0; i < sizeof(public_key); i++)
        ^
    main.c:273:13: error: redefinition of ‘i’
        for(int i = 0; i < sizeof(private_key); i++)
                ^
    main.c:269:13: note: previous definition of ‘i’ was here
        for(int i = 0; i < sizeof(public_key); i++)
                ^
    main.c:273:5: error: ‘for’ loop initial declarations are only allowed in C99 mode
        for(int i = 0; i < sizeof(private_key); i++)
        ^
    main.c:277:13: error: redefinition of ‘i’
        for(int i = 0; i < sizeof(signature); i++)
                ^
    main.c:273:13: note: previous definition of ‘i’ was here
        for(int i = 0; i < sizeof(private_key); i++)
                ^
    main.c:277:5: error: ‘for’ loop initial declarations are only allowed in C99 mode
        for(int i = 0; i < sizeof(signature); i++)
        ^
    make: *** [main.o] Error 1


## A1 

Enable C99 mode in your compiler

Add -std=c99 (or -std=gnu99) to your gcc or make command:

    make CFLAGS="-std=c99"

    make clean && make CFLAGS="-std=c99"

## Q2 

    vb@ubuntu14:~/xfel$ make CFLAGS="-std=c99"
    [CC] main.c
    [CC] misc.c
    [CC] progress.c
    [CC] sha256.c
    [CC] spinand.c
    spinand.c: In function ‘spinand_reset’:
    spinand.c:207:2: warning: implicit declaration of function ‘usleep’ [-Wimplicit-function-declaration]
    usleep(100 * 1000);
    ^
    [CC] spinor.c
    [CC] chips/a10.c
    [CC] chips/a13_a10s_r8.c
    [CC] chips/a20.c
    [CC] chips/a23.c
    [CC] chips/a31.c
    [CC] chips/a33_r16.c
    [CC] chips/a40i_r40.c
    [CC] chips/a50.c
    [CC] chips/a523_a527_t527.c
    [CC] chips/a537_a333.c
    [CC] chips/a64.c
    [CC] chips/a733.c
    [CC] chips/a80.c
    [CC] chips/a83t.c
    [CC] chips/d1_f133.c
    [CC] chips/f1c100s_f1c200s_f1c500s.c
    [CC] chips/h135.c
    [CC] chips/h2_h3.c
    chips/h2_h3.c: In function ‘chip_sid’:
    chips/h2_h3.c:25:3: error: initializer element is not constant
    cpu_to_le32(0xe59f0040), /*    0:  ldr   r0, [pc, #64]           */
    ^
    chips/h2_h3.c:25:3: error: (near initialization for ‘payload[0]’)
    chips/h2_h3.c:26:3: error: initializer element is not constant
    cpu_to_le32(0xe3a01000), /*    4:  mov   r1, #0                  */
    ^
    chips/h2_h3.c:26:3: error: (near initialization for ‘payload[1]’)
    chips/h2_h3.c:27:3: error: initializer element is not constant
    cpu_to_le32(0xe28f303c), /*    8:  add   r3, pc, #60             */
    ^
    chips/h2_h3.c:27:3: error: (near initialization for ‘payload[2]’)
    chips/h2_h3.c:29:3: error: initializer element is not constant
    cpu_to_le32(0xe1a02801), /*    c:  lsl   r2, r1, #16             */
    ^
    chips/h2_h3.c:29:3: error: (near initialization for ‘payload[3]’)
    chips/h2_h3.c:30:3: error: initializer element is not constant
    cpu_to_le32(0xe3822b2b), /*   10:  orr   r2, r2, #44032          */
    ^
    chips/h2_h3.c:30:3: error: (near initialization for ‘payload[4]’)
    chips/h2_h3.c:31:3: error: initializer element is not constant
    cpu_to_le32(0xe3822002), /*   14:  orr   r2, r2, #2              */
    ^
    chips/h2_h3.c:31:3: error: (near initialization for ‘payload[5]’)
    chips/h2_h3.c:32:3: error: initializer element is not constant
    cpu_to_le32(0xe5802040), /*   18:  str   r2, [r0, #64]           */
    ^
    chips/h2_h3.c:32:3: error: (near initialization for ‘payload[6]’)
    chips/h2_h3.c:34:3: error: initializer element is not constant
    cpu_to_le32(0xe5902040), /*   1c:  ldr   r2, [r0, #64]           */
    ^
    chips/h2_h3.c:34:3: error: (near initialization for ‘payload[7]’)
    chips/h2_h3.c:35:3: error: initializer element is not constant
    cpu_to_le32(0xe3120002), /*   20:  tst   r2, #2                  */
    ^
    chips/h2_h3.c:35:3: error: (near initialization for ‘payload[8]’)
    chips/h2_h3.c:36:3: error: initializer element is not constant
    cpu_to_le32(0x1afffffc), /*   24:  bne   1c <sid_read_wait>      */
    ^
    chips/h2_h3.c:36:3: error: (near initialization for ‘payload[9]’)
    chips/h2_h3.c:37:3: error: initializer element is not constant
    cpu_to_le32(0xe5902060), /*   28:  ldr   r2, [r0, #96]           */
    ^
    chips/h2_h3.c:37:3: error: (near initialization for ‘payload[10]’)
    chips/h2_h3.c:38:3: error: initializer element is not constant
    cpu_to_le32(0xe7832001), /*   2c:  str   r2, [r3, r1]            */
    ^
    chips/h2_h3.c:38:3: error: (near initialization for ‘payload[11]’)
    chips/h2_h3.c:39:3: error: initializer element is not constant
    cpu_to_le32(0xe2811004), /*   30:  add   r1, r1, #4              */
    ^
    chips/h2_h3.c:39:3: error: (near initialization for ‘payload[12]’)
    chips/h2_h3.c:40:3: error: initializer element is not constant
    cpu_to_le32(0xe3510010), /*   34:  cmp   r1, #16                 */
    ^
    chips/h2_h3.c:40:3: error: (near initialization for ‘payload[13]’)
    chips/h2_h3.c:41:3: error: initializer element is not constant
    cpu_to_le32(0x3afffff3), /*   38:  bcc   c <sid_read_loop>       */
    ^
    chips/h2_h3.c:41:3: error: (near initialization for ‘payload[14]’)
    chips/h2_h3.c:42:3: error: initializer element is not constant
    cpu_to_le32(0xe3a02000), /*   3c:  mov   r2, #0                  */
    ^
    chips/h2_h3.c:42:3: error: (near initialization for ‘payload[15]’)
    chips/h2_h3.c:43:3: error: initializer element is not constant
    cpu_to_le32(0xe5802040), /*   40:  str   r2, [r0, #64]           */
    ^
    chips/h2_h3.c:43:3: error: (near initialization for ‘payload[16]’)
    chips/h2_h3.c:44:3: error: initializer element is not constant
    cpu_to_le32(0xe12fff1e), /*   44:  bx    lr                      */
    ^
    chips/h2_h3.c:44:3: error: (near initialization for ‘payload[17]’)
    chips/h2_h3.c:45:3: error: initializer element is not constant
    cpu_to_le32(0x01c14000), /* SID base addr */
    ^
    chips/h2_h3.c:45:3: error: (near initialization for ‘payload[18]’)
    make: *** [chips/h2_h3.o] Error 1

## A2 

- [[ubuntu-14-dat]]

