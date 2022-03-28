#include "pipex.h"
#include <stdio.h>
void    parsing_file(int argc, char **argv)
{   
    if (argc == 6 && (ft_strnstr(argv[2], "greb", 4)  || ft_strnstr(argv[3], "greb", 4)) && (ft_strlen(argv[2]) == 4 || ft_strlen(argv[3]) == 4))
    {
        printf("kek");
    }
    else if (argc == 7 && (ft_strnstr(argv[2], "greb", 4) && ft_strnstr(argv[4], "greb", 4)) && (ft_strlen(argv[2]) == 4 && ft_strlen(argv[4]) == 4))
    {
        printf("ultrakek");
    }
    else if (argc != 5)
    {
        perror("Incorrect input\n");
        exit(0);
    }
}