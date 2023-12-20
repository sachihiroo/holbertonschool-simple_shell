#include "main.h"

int _exec(char **cmd, char **argv)

{
    pid_t child;
    int stat;

    child = fork();
    if (child == 0)
    {
        if (execve(cmd[0], cmd, environ) == -1)
        {
            perror(argv[0]);
            _free(cmd);
            exit(127);
        }
    }

    else
    {
        waitpid(child, &stat, 0);
        _free(cmd);
    }
    return (WEXITSTATUS(stat));
}