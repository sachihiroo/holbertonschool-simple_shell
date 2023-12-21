#include "main.h"

/**
 * main - Main function of the Simple Shell program
 * @argv: the program's arguments.
 * @ac: argument count.
 * Return: stat.
 */

int main(int ac, char **argv)
{
	char **cmd = NULL;
	char *line = NULL;
	int stat = 0;
	int idx = 0;
	(void)ac;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO) == 1)
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (stat);
		}
		idx++;
		cmd = tokenizer(line);

		if (!cmd)
			continue;
		if (is_built_in(cmd) == 1)
		{
			handle_built_in(cmd, &stat);
		}
		else
			stat = _exec(cmd, argv, idx);
	}
}
