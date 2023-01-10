

## BSP version 

    void BSP_LED_Init(Led_TypeDef Led)

this is wrap of: GPIO init (init clk, pin, mode, pull, speed) + HAL_GPIO_Init + HAL_GPIO_WritePin

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




## HAL 


    /**
    * @brief GPIO Initialization Function
    * @param None
    * @retval None
    */
    static void MX_GPIO_Init(void)
    {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET);

    /*Configure GPIO pin : PC15 */
    GPIO_InitStruct.Pin = GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /*Configure GPIO pin : PA1 */
    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    }