#include "pipex.h"

void    cmd_argv_parse(t_var *vars, char *argv_str, int cmd_num)
{
    char **buffer_str;

    buffer_str = ft_split_ppx(argv_str, ' ');
    if (!buffer_str && cmd_num == 1)
        exit(0);
    else if (!buffer_str && cmd_num == 2)
        exit(0);
    if (cmd_num == 1)
    {
        vars->cmd1 = *buffer_str;
        vars->argv_cmd1 = buffer_str;
    }
    else if (cmd_num == 2)
    {
        vars->cmd2 = *buffer_str;
        vars->argv_cmd2 = buffer_str;
    }
}