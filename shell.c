#include "main.h"
/**
 * read_shell - reads commands
 * @argv: parameter
 * @size: parameter
 * Return: 0
 */
void read_shell(char **argv, size_t size)
{
        ssize_t n;
        char *msg_cpy = NULL, *token, *msg = NULL;
        int i, num = 0;
        const char *delim = " \n";

        size = 0;
        n = getline(&msg, &size, stdin);
        if (n == -1)
        {
                shell_printf("\n");
                exit(EXIT_FAILURE);
        }
        msg_cpy = malloc(sizeof(char) * n);
        if (msg_cpy == NULL)
        {
                perror("tsh: memory allloctaion error");
                shell_printf("Error\n");
                exit(EXIT_FAILURE);
        }
        strcpy(msg_cpy, msg);
        token = strtok(msg, delim);
        while (token != NULL)
        {
                num++;
                token = strtok(NULL, delim);
        }
        num++;
        argv = malloc(sizeof(char *) * num);
        token = strtok(msg_cpy, delim);
        for (i = 0; token != NULL; i++)
        {
                argv[i] = malloc(sizeof(char) * strlen(token));
                strcpy(argv[i], token);
		token = strtok(NULL, delim);
        }
        argv[i] = NULL;
        execute_shell(argv);
        free(msg);
        free(msg_cpy);
}
