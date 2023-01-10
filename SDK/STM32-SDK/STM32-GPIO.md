

## BSP init

    void BSP_LED_Init(Led_TypeDef Led)

this is wrap of: GPIO init + HAL_GPIO_Init + HAL_GPIO_WritePin


### main work : 
- init clk, pin, mode, pull, speed

        void BSP_LED_Init(Led_TypeDef Led)
        {
            GPIO_InitTypeDef  GPIO_InitStruct;

            /* Enable the GPIO_LED Clock */
            LEDx_GPIO_CLK_ENABLE(Led);

            /* Configure the GPIO_LED pin */
            GPIO_InitStruct.Pin = LED_PIN[Led];
            GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
            GPIO_InitStruct.Pull = GPIO_NOPULL;
            GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

            HAL_GPIO_Init(LED_PORT[Led], &GPIO_InitStruct);

            HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_RESET);
        }

toggle: 

    HAL_GPIO_TogglePin(LED3_GPIO_PORT, LED3_PIN);
    /* Insert delay 100 ms */
    HAL_Delay(100);