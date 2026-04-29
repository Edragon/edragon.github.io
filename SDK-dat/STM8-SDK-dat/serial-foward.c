/*
 * Usage summary:
 * - UART1 TX: PD5
 * - UART1 RX: PD6
 * - Send "555" over the serial port to receive "OK555" and blink PB5 three times.
 * - Send "444" over the serial port to receive "OK444" and blink PB4 three times.
 * - Blink timing is 1 second ON, 1 second OFF for each of the three blinks.
 */

#include "stm8s.h"

#define UART_BAUDRATE 9600UL
#define BLINK_COUNT 3U

static void clock_init(void);
static void gpio_init(void);
static void uart1_init(void);
static void uart1_send_char(char value);
static void uart1_send_string(const char *text);
static void delay_ms(uint16_t milliseconds);
static void blink_pin(GPIO_TypeDef *port, GPIO_Pin_TypeDef pin, uint8_t count);
static void handle_command(const char *window);

int main(void)
{
	char rx_window[3] = {'\0', '\0', '\0'};

	clock_init();
	gpio_init();
	uart1_init();

	while (1)
	{
		if (UART1_GetFlagStatus(UART1_FLAG_RXNE) != RESET)
		{
			char received = (char)UART1_ReceiveData8();

			rx_window[0] = rx_window[1];
			rx_window[1] = rx_window[2];
			rx_window[2] = received;

			handle_command(rx_window);
		}
	}
}

static void clock_init(void)
{
	CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
}

static void gpio_init(void)
{
	GPIO_DeInit(GPIOD);
	GPIO_DeInit(GPIOB);

	GPIO_Init(GPIOD, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_FAST);
	GPIO_Init(GPIOD, GPIO_PIN_6, GPIO_MODE_IN_FL_NO_IT);

	GPIO_Init(GPIOB, GPIO_PIN_4, GPIO_MODE_OUT_PP_LOW_FAST);
	GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);
}

static void uart1_init(void)
{
	UART1_DeInit();
	UART1_Init(
		UART_BAUDRATE,
		UART1_WORDLENGTH_8D,
		UART1_STOPBITS_1,
		UART1_PARITY_NO,
		UART1_SYNCMODE_CLOCK_DISABLE,
		UART1_MODE_TXRX_ENABLE);
	UART1_Cmd(ENABLE);
}

static void uart1_send_char(char value)
{
	while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET)
	{
	}

	UART1_SendData8((uint8_t)value);
}

static void uart1_send_string(const char *text)
{
	while (*text != '\0')
	{
		uart1_send_char(*text);
		text++;
	}

	while (UART1_GetFlagStatus(UART1_FLAG_TC) == RESET)
	{
	}
}

static void delay_ms(uint16_t milliseconds)
{
	uint16_t ms;
	volatile uint16_t ticks;

	for (ms = 0; ms < milliseconds; ms++)
	{
		for (ticks = 0; ticks < 1600; ticks++)
		{
		}
	}
}

static void blink_pin(GPIO_TypeDef *port, GPIO_Pin_TypeDef pin, uint8_t count)
{
	uint8_t index;

	for (index = 0; index < count; index++)
	{
		GPIO_WriteHigh(port, pin);
		delay_ms(1000);
		GPIO_WriteLow(port, pin);
		delay_ms(1000);
	}
}

static void handle_command(const char *window)
{
	if ((window[0] == '5') && (window[1] == '5') && (window[2] == '5'))
	{
		uart1_send_string("OK555\r\n");
		blink_pin(GPIOB, GPIO_PIN_5, BLINK_COUNT);
	}
	else if ((window[0] == '4') && (window[1] == '4') && (window[2] == '4'))
	{
		uart1_send_string("OK444\r\n");
		blink_pin(GPIOB, GPIO_PIN_4, BLINK_COUNT);
	}
}

