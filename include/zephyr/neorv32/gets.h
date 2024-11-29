#include <stdint.h>
#include <stdio.h>

#ifndef ZEPHYR_INCLUDE_ZEPHYR_NEORV32_GETS_H_
#define ZEPHYR_INCLUDE_ZEPHYR_NEORV32_GETS_H_

/**
 * @brief Reads a string from the NEORV32 UART.
 *
 * This function reads a string from the NEORV32 UART until a \0, \r, or \n character is encountered.
 * The newline character is replaced with a null terminator.
 *
 * @param buffer Pointer to the buffer where the read string will be stored.
 */
void neorv32_gets(char* buffer);

#endif /* ZEPHYR_INCLUDE_ZEPHYR_NEORV32_GETS_H_ */