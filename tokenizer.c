#include "main.h"
/**
 * tokenizer - a function that that tokenizes a given string
 * into an array of strings based on specified delimiters.
 * @line: a string.
 * Return: cmd.
 */
char **tokenizer(char *line)
{
	char *token;
	char *tmp = NULL;
	char delim[] = " \t\n";
	char **cmd = NULL;
	int i = 0, j = 0;

	if (line == NULL)
		return (NULL);

	tmp = strdup(line);
	token = strtok(tmp, delim);

	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	while (token)
	{
		i++;
		token = strtok(NULL, delim);
	}
	free(tmp), tmp = NULL;

	cmd = malloc(sizeof(char *) * (i + 1));
	if (cmd == NULL)
	{
		free(line);
		return (NULL);
	}

	token = strtok(line, delim);
	while (token)
	{
		cmd[j] = strdup(token);
		token = strtok(NULL, delim);
		j++;
	}
	free(line), line = NULL;
	cmd[j] = NULL;
	return (cmd);
}
