#include "main.h"
/**
 *
 *
 *
 */
char *get_path(char *command)
{
	char *env, *path, *cmd;
	struct stat buffer;
	/* IF COMMAND WITH PATH EXEMPL(/bin/ls)*/

	if (stat(command, &buffer) == 0)
	{
		return (command);
	}

	/*	IF COMMAND WITHOUT PATH EXEMPL(ls)*/
	env = env_func("PATH");
	if (env == NULL)
		return NULL;

	path = strtok(env, ":");

	while (path)
	{
		cmd = malloc(strlen(path) + strlen(command) + 2);

		if (cmd != NULL)
		{
			snprintf(cmd, strlen(path) + strlen(command) + 2, "%s/%s", path, command);
			if (stat(cmd, &buffer) == 0)
			{
				free(env);
				return (cmd);
			}

			free(cmd);

			path = strtok(NULL, ":");
		}
		else
		{
			free(env);
			return NULL;
		}
	}

	free(env);
	return NULL;
}
