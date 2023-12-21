#include "main.h"

int _exec(char **cmd, char **argv, int idx)

{
	char *full_cmd;
	pid_t child;
	int stat;

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
		if (strcmp(cmd[0], full_cmd) != 0)
			free(full_cmd), full_cmd = NULL;
		_free(cmd);
	}
	return (WEXITSTATUS(stat));
}
