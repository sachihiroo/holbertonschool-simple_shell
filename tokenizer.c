#include "main.h"
/**
 * count_tokens - Counts the number of tokens in a string.
 * @line: The input string.
 * @delim: The delimiters to use for tokenization.
 * Return: The number of tokens.
 */
int count_tokens(const char *line, const char *delim)
{
	char *tmp;
	char *token;
	int count = 0;

	if (line == NULL)
		return (0);

	tmp = strdup(line);
	token = strtok(tmp, delim);

	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}

	free(tmp);
	return (count);
}

/**
 * tokenizer - Tokenizes a given string into an array of strings.
 * @line: The input string.
 * Return: An array of strings.
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

	i = count_tokens(line, delim);

	cmd = malloc(sizeof(char *) * (i + 1));
	if (cmd == NULL)
	{
		free(line);
		return (NULL);
	}

	tmp = strdup(line);
	token = strtok(tmp, delim);

	while (token)
	{
		cmd[j] = strdup(token);
		token = strtok(NULL, delim);
		j++;
	}

	free(tmp);
	free(line);
	cmd[j] = NULL;
	return (cmd);
}
