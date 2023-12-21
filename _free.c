#include "main.h"

/**
 * _free - a function designed to free the memory associated
 * with a two-dimensional array of strings
 * @str: two-dimensional array of strings.
 */

void _free(char **str)

{
	int i;

	if (str == NULL)
	{
		return;
	}
	for (i = 0; str[i]; i++)
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}
