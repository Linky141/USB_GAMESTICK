#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <string.h>

#include "../../Libraries/Headers/usart.h"
#include "../../Libraries/Headers/gpio.h"
#include "../../Libraries/Headers/delay.h"
#define BUFF_SIZE   25

const char foo_string[] PROGMEM
		= "Unluckily gcc string polling doesn't work for PROGMEM/PSTR() strings";

int main(void) {
	uart_set_FrameFormat(
			USART_8BIT_DATA|USART_1STOP_BIT|USART_NO_PARITY|USART_ASYNC_MODE); // default settings
	uart_init(BAUD_CALC(9600)); // 8n1 transmission is set as default

	stdout = &uart0_io; // attach uart stream to stdout & stdin
	stdin = &uart0_io; // uart0_in and uart0_out are only available if NO_USART_RX or NO_USART_TX is defined

	sei(); // enable interrupts, library wouldn't work without this

	GPIO_PinDirection(PC_0, 1);
	GPIO_PinDirection(PC_1, 1);
	GPIO_PinDirection(PC_2, 1);
	GPIO_PinDirection(PC_3, 1);
	GPIO_PinDirection(PC_4, 1);
	GPIO_PinDirection(PC_5, 1);
	GPIO_PinDirection(PD_7, 1);
	GPIO_PinDirection(PD_6, 1);
	GPIO_PinDirection(PD_5, 1);
	GPIO_PinDirection(PD_4, 1);

	uart_puts("PROGRAM IS STARTING...\r\n");

	uint8_t btn1 = 0;
	uint8_t btn2 = 0;
	uint8_t btn3 = 0;
	uint8_t btn4 = 0;
	uint8_t btn5 = 0;
	uint8_t btn6 = 0;
	uint8_t btn7 = 0;
	uint8_t btn8 = 0;
	uint8_t btn9 = 0;
	uint8_t btn10 = 0;
	uint32_t delayClock = 10;

	while (1) {

		if (GPIO_PinRead(PC_0) == 1 && btn1 == 0) {
			btn1 = 1;
			uart_puts("d1\r\n");
			DELAY_ms(delayClock);
		} else if (GPIO_PinRead(PC_0) == 0 && btn1 == 1) {
			btn1 = 0;
			uart_puts("u1\r\n");
			DELAY_ms(delayClock);
		}

		if (GPIO_PinRead(PC_1) == 1 && btn2 == 0) {
			btn2 = 1;
			uart_puts("d2\r\n");
			DELAY_ms(delayClock);
		} else if (GPIO_PinRead(PC_1) == 0 && btn2 == 1) {
			btn2 = 0;
			uart_puts("u2\r\n");
			DELAY_ms(delayClock);
		}

		if (GPIO_PinRead(PC_2) == 1 && btn3 == 0) {

				btn3 = 1;
				uart_puts("d3\r\n");
				DELAY_ms(delayClock);
			} else if (GPIO_PinRead(PC_2) == 0 && btn3 == 1) {

				btn3 = 0;
				uart_puts("u3\r\n");
				DELAY_ms(delayClock);
			}





		if (GPIO_PinRead(PC_3) == 1 && btn4 == 0) {

			btn4 = 1;
				uart_puts("d4\r\n");
				DELAY_ms(delayClock);
			} else if (GPIO_PinRead(PC_3) == 0 && btn4 == 1) {

				btn4 = 0;
				uart_puts("u4\r\n");
				DELAY_ms(delayClock);
			}



		if (GPIO_PinRead(PC_4) == 1 && btn5 == 0) {

			btn5 = 1;
				uart_puts("d5\r\n");
				DELAY_ms(delayClock);
			} else if (GPIO_PinRead(PC_4) == 0 && btn5 == 1) {

				btn5 = 0;
				uart_puts("u5\r\n");
				DELAY_ms(delayClock);
			}




		if (GPIO_PinRead(PC_5) == 1 && btn6 == 0) {

			btn6 = 1;
				uart_puts("d6\r\n");
				DELAY_ms(delayClock);
			} else if (GPIO_PinRead(PC_5) == 0 && btn6 == 1) {

				btn6 = 0;
				uart_puts("u6\r\n");
				DELAY_ms(delayClock);
			}



		if (GPIO_PinRead(PD_7) == 1 && btn7 == 0) {

			btn7 = 1;
				uart_puts("d7\r\n");
				DELAY_ms(delayClock);
			} else if (GPIO_PinRead(PD_7) == 0 && btn7 == 1) {

				btn7 = 0;
				uart_puts("u7\r\n");
				DELAY_ms(delayClock);
			}





		if (GPIO_PinRead(PD_6) == 1 && btn8 == 0) {

			btn8 = 1;
				uart_puts("d8\r\n");
				DELAY_ms(delayClock);
			} else if (GPIO_PinRead(PD_6) == 0 && btn8 == 1) {

				btn8 = 0;
				uart_puts("u8\r\n");
				DELAY_ms(delayClock);
			}




		if (GPIO_PinRead(PD_5) == 1 && btn9 == 0) {

			btn9 = 1;
				uart_puts("d9\r\n");
				DELAY_ms(delayClock);
			} else if (GPIO_PinRead(PD_5) == 0 && btn9 == 1) {

				btn9 = 0;
				uart_puts("u9\r\n");
				DELAY_ms(delayClock);
			}




		if (GPIO_PinRead(PD_4) == 1 && btn10 == 0) {

			btn10 = 1;
				uart_puts("d10\r\n");
				DELAY_ms(delayClock);
			} else if (GPIO_PinRead(PD_4) == 0 && btn10 == 1) {

				btn10 = 0;
				uart_puts("u10\r\n");
				DELAY_ms(delayClock);
			}



	}

	return 0;
}
