#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct s_var {
    int infile;
    int outfile;
    int pipe_fd[2];
    int pid_1;
    int pid_2;
    char    **my_path;
    
}   t_var;

typedef struct s_split {
    int i;
    int j;
    int c;
    int len;
    int word_counter;
}   t_split;


char	**ft_split_ppx(char *str, char c);


#endif
