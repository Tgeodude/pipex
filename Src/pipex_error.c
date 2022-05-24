#include "pipex.h"

void    printerror(char *str)
{
    write(2, str, ft_strlen(str));
    exit(0);
}