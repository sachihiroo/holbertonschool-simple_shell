#include "main.h"
/**
 * is_built_in - a function that checks whether
 * a command is a built-in command or not
 * @cmd: the command.
 * Return: 0
 */
int is_built_in(char **cmd)
{
	char *built[] = {"exit", "env", "cd", "help", NULL};
	int i;

	for (i = 0; built[i]; i++)
	{
		if (strcmp(cmd[0], built[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}
/**
 * handle_built_in - a function responsible for handling built-in commands
 * @command: the command.
 * @status: the status of the command.
 */
void handle_built_in(char **command, int *status)
{
	if (strcmp(command[0], "exit") == 0)
	{
		hsh_exit(command, status);
	}
	else if (strcmp(command[0], "env") == 0)
	{
		hsh_env(command, status);
	}
}
/**
 * hsh_exit - a function used to handle the "exit" built-in command
 * @cmd: the command.
 * @status: the status of the command.
 */
void hsh_exit(char **cmd, int *status)
{
	_free(cmd);
	exit(*status);
}
/**
 * hsh_env - a function used to handle the "env" built-in command
 * @cmd: the command.
 * @status: the status of the command.
 */
void hsh_env(char **cmd, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
	_free(cmd);
	(*status) = 0;
}
