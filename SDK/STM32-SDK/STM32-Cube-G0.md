
# STM32-CUBE-G0


G0 - v1.6
https://www.st.com/content/ccc/resource/technical/software/firmware/group1/57/41/a6/d8/d1/2b/44/8b/stm32cubeg0_v1-6-0/files/stm32cubeg0_v1-6-0.zip/jcr:content/translations/en.stm32cubeg0_v1-6-0.zip


### GPIO 

en.stm32cubeg0_v1-6-0\STM32Cube_FW_G0_V1.6.0\Projects\NUCLEO-G031K8\Examples\GPIO\GPIO_IOToggle


    #include "stm32g0xx_hal.h"
        en.stm32cubeg0_v1-6-0\STM32Cube_FW_G0_V1.6.0\Drivers\STM32G0xx_HAL_Driver\Inc

Board BSP 

    #include "stm32g0xx_nucleo_32.h"
        en.stm32cubeg0_v1-6-0\STM32Cube_FW_G0_V1.6.0\Drivers\BSP\STM32G0xx_Nucleo_32

    #define LED3_PIN                           GPIO_PIN_6
    #define LED3_GPIO_PORT                     GPIOC
    #define LED3_GPIO_CLK_ENABLE()             __HAL_RCC_GPIOC_CLK_ENABLE()
    #define LED3_GPIO_CLK_DISABLE()            __HAL_RCC_GPIOC_CLK_DISABLE()