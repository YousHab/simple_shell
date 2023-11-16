#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define SEP " \t\n"

extern char **envp;


char *readline(void);
char **spliter(char *);
char *get_environ(char *var);
char *get_path(char *line);

void FreeArray(char **array);
char *_itoa(int n);
void display_error(char *name, char *cmd, int count);
void rev_str(char *str, int length);

char *my_strdup(char *s);
int my_strcmp(char *s1, char *s2);
int _strlen(char *s);
const char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

int my_execute(char **command_line, char **av, int index, char **envp);
void FreeArray(char **array);



#endif
