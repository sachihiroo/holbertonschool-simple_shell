#include "main.h"

void _free(char **str)

{
    int i;
    if (str == NULL)
    {
        return;
    }
    for (i = 0, str[i], i++)
    {
        free(str[i]);
        str[i] = NULL;
    }
    free(str);
    str = NULL;
}
