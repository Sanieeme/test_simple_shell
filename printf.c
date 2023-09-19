#include "main.h"
/**
 * shell_printf - printf
 * @format: parameter
 * Return: 0
 */
void shell_printf(const char *format)
{
        write(STDOUT_FILENO, format, strlen(format));
} 
