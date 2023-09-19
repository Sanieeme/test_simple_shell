#include "main.h"
/**
 * main - entry
 * Return: 0
 */

int main(void)
{
        char **argv = NULL;

        while (1)
        {
                prompt();
                read_shell(argv, sizeof(argv));
        }
        return (0);
} 
