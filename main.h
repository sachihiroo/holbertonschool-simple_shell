#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
extern char **environ;

char *read_line(void);
char **tokenizer(char *line);
int _exec(char **cmd, char **argv, int idx);
void _free(char **str);
char *env_func(char *pol);
char *get_path(char *command);

int is_built_in(char **cmd);
void handle_built_in(char **command, int *status);
void hsh_exit(char **cmd, int *status);
void hsh_env(char **cmd, int *status);

#endif
