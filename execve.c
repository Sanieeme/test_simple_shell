#include "main.h"
/**
 * execute_shell - execute using execve
 * @argv: parameter
 * Return: 0
 */
void execute_shell(char **argv)
{
        pid_t pid_child;


        char *msg = NULL;

        pid_child = fork();

        if (pid_child == -1)
        {
                perror("fork");
                exit(EXIT_FAILURE);
        }
        if (pid_child == 0)
        {
                if (argv)
                {
                        msg = argv[0];
                }
                if (execve(msg, argv, NULL) == -1)
                {
                        perror("execve");
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                wait(NULL);
        }
} 
