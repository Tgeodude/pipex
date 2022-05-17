#include "pipex.h"

void    cmd_argv_parse(char *argv_str, int cmd_num)
{
    char **buffer_str;

    buffer_str = ft_split_ppx(argv_str, ' ');
    if (!buffer_str && cmd_num == 1)
        exit(0);
    else if (!buffer_str && cmd_num == 2)
        exit(0);
    
}