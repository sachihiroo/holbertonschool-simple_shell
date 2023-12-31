#include "main.h"

/**
 * env_func - a function that searches for an environment variable
 * and returns its corresponding value
 * @pol: environment variable.
 * Return: Null.
 */

char *env_func(char *pol)
{
	char *tmp, *value, *key, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = strdup(environ[i]);
		key = strtok(tmp, "=");
		if (key != NULL && strcmp(key, pol) == 0)
		{
			value = strtok(NULL, "\n");
			if (value != NULL)
			{
				env = strdup(value);
			}
			else
				env = NULL;
			free(tmp), tmp = NULL;
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
