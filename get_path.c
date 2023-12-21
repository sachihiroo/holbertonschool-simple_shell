#include "main.h"

/**
 * is_absolute_path - Checks if the command is an absolute path.
 * @command: The command to check.
 * Return: 1 if it is an absolute path, 0 otherwise.
 */
int is_absolute_path(const char *command)
{
	int i;

	for (i = 0; command[i] && command[i] != '/'; i++)
		;

	return command[i] == '/';
}

/**
 * get_full_path - Locates the full path of an executable command.
 * @command: Name of the command.
 * Return: Full path of the command or NULL.
 */
char *get_full_path(char *command)
{
	char *env, *path, *cmd;
	struct stat buffer;

	if (is_absolute_path(command))
		return (stat(command, &buffer) == 0 ? strdup(command) : NULL);

	env = env_func("PATH");
	if (!env)
		return (NULL);

	path = strtok(env, ":");

	while (path)
	{
		cmd = malloc(strlen(path) + strlen(command) + 2);
		if (!cmd)
		{
			free(env);
			return (NULL);
		}

		snprintf(cmd, strlen(path) + strlen(command) + 2, "%s/%s", path, command);
		if (stat(cmd, &buffer) == 0)
		{
			free(env);
			return (cmd);
		}

		free(cmd);
		path = strtok(NULL, ":");
	}

	free(env);
	return (NULL);
}
