#include "main.h"
/**
 * get_path - a function that  locates the full path of an executable command.
 * @command: name of the command.
 * Return: Null.
 */
char *get_path(char *command)
{
	char *env, *path, *cmd;
	struct stat buffer;
	int i;

	/* IF COMMAND WITH PATH EXEMPL(/bin/ls)*/

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &buffer) == 0)
				return (strdup(command));

			return (NULL);
		}
	}
	/*	IF COMMAND WITHOUT PATH EXEMPL(ls)*/
	env = env_func("PATH");
	if (env == NULL)
		return (NULL);

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
			return (NULL);
		}
	}

	free(env);
	return (NULL);
}
