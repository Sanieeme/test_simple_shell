#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void prompt(void);
void shell_printf(const char *format);
void read_shell(char **argv, size_t size);
void execute_shell(char **argv);

#endif
