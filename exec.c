#include "main.h"

/**
 * _exec - a function that executes a command
 * @cmd: the command.
 * @argv: the program's arguments.
 * @idx: the index of the command in the input.
 * Return: WEXITSTATUS(stat).
 */

int _exec(char **cmd, char **argv, int idx)

{
	pid_t child;
	int stat;
	char *full_cmd;

	full_cmd = get_path(cmd[0]);
	if (!full_cmd)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", argv[0], idx, cmd[0]);
		_free(cmd);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, cmd, environ) == -1)
		{
			free(full_cmd);
			_free(cmd);
		}
	}
	else
	{
		waitpid(child, &stat, 0);
		free(full_cmd), full_cmd = NULL;
		_free(cmd);
	}
	return (WEXITSTATUS(stat));
}
