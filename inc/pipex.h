#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
#include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_var {
    int     infile;
    int     outfile;
    int     pipe_fd[2];
    int     pid_1;
    int     pid_2;
    char    **my_path;
    char    *cmd1;
    char    *cmd2;
    char    **argv_cmd1;
    char    **argv_cmd2;
    char    *path_cmd1;
    char    *path_cmd2;
    char    **env_pointer;
    char    **argv;
}   t_var;

typedef struct s_split {
    int     i;
    int     k;
    char    *str;
    int     j;
    int     c;
    int     len;
    int     word_counter;
    char    **big_str;
}   t_split;


char	**ft_split_ppx(char *str, char c);
void    cmd_argv_parse(t_var *vars, char *argv_str, int cmd_num);
void	word_counter_ppx(char *str, char c, t_split *s);
void    printerror(char *str);
void    free_parent_error(char *str, t_var *vars);
void    free_child_error(char *str, t_var *vars, int child_num);

#endif
