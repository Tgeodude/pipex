#include "pipex.h"

void    printerror(char *str)
{
    perror(str);
    exit(0);
}