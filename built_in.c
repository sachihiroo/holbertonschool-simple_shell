#include "main.h"
/**
 * 
 * 
 * 
 * 
*/
int is_built_in(char **cmd)
{
	char *built[] = {"exit", "env","cd","help", NULL};
	int i;
	
	for (i = 0; built[i]; i++)
	{
		if (strcmp(cmd[0], built[i] )== 0)
		{
			return (1);
		}
	}
	return (0);
}
/**
 * 
 * 
 * 
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
 * 
 * 
 * 
*/
void hsh_exit(char **cmd, int *status)
{
	_free(cmd);
	exit(*status);
}
/**
 * 
 * 
 * 
 * 
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
