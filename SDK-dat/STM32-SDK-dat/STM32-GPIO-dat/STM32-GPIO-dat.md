
# STM32-GPIO-dat 

    void GPIO_Toggle_INIT(void)
    {
        GPIO_InitTypeDef GPIO_InitStructure = {0}; // ?

        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); //GPIO-D
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; // PIN 0
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOD, &GPIO_InitStructure);
    }
