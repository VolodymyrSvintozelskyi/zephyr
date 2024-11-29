#include <zephyr/neorv32/gets.h>

#define NEORV32_UART0_BASE   (0xFFFFF500U) /**< Primary Universal Asynchronous Receiver and Transmitter (UART0) */
#define UART_CTRL_RX_NEMPTY	 16 /**< UART control register(16) (r/-): RX FIFO not empty */
#define UART_DATA_RTX_LSB	 0 /**< UART data register(0) (r/w): UART receive/transmit data, LSB */
#define NEORV32_UART0 ((neorv32_uart_t*) (NEORV32_UART0_BASE))

/**********************************************************************//**
 * @name IO Device: Primary/Secondary Universal Asynchronous Receiver and Transmitter (UART0 / UART1)
 **************************************************************************/
/**@{*/
/** UART module prototype */
typedef volatile struct __attribute__((packed,aligned(4))) {
  uint32_t CTRL;  /**< offset 0: control register (#NEORV32_UART_CTRL_enum) */
  uint32_t DATA;  /**< offset 4: data register  (#NEORV32_UART_DATA_enum) */
} neorv32_uart_t;

/**********************************************************************//**
 * Get char from UART.
 *
 * @note This function is blocking.
 *
 * @param[in,out] UARTx Hardware handle to UART register struct, #neorv32_uart_t.
 * @return Received char.
 **************************************************************************/
char neorv32_uart_getc(neorv32_uart_t *UARTx) {

  while (1) {
    if (UARTx->CTRL & (1<<UART_CTRL_RX_NEMPTY)) { // data available?
      return (char)(UARTx->DATA >> UART_DATA_RTX_LSB);
    }
  }
}

void neorv32_gets(char *buffer) {
	char c;
	size_t i = 0;

	do {
		c = neorv32_uart_getc(NEORV32_UART0);
		buffer[i++] = c;
		printf("%c", c);
	} while (c != '\0' && c != '\n' && c != '\r');
}
