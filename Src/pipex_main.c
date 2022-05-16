#include "pipex.h"
#include "stdio.h"

char *find_path(char **env)
{
    if (!env)
    {
        write(2,"Error\n",6);
        exit(0);
    }
    while (ft_strncmp("PATH=", *env, 5))
    {
        env++;
        if (env == 0)
            return (NULL);
    }
    return (*env + 5);
}

int main(int argc, char **argv, char **env)
{   
    char **my_path;
    int pipe_fd[2];
    int i;
    int pid_1;
    int pid_2;

    if (argc != 5)
    {
        write(2,"Error\n",6);
        exit(0);        
    }
    my_path = ft_split(find_path(env), ':');
    i = -1;
    while (my_path[++i])
        printf("%s\n", my_path[i]);
    pipe(pipe_fd);
    pid_1 = fork();
    if (pid_1 == 0)
        child1();
    else if (pid_1 == -1)
    {
        write(2,"Error\n",6);
        exit(0);   
    }
    pid_2 = fork();
    if (pid_2 == 0)
        child2();
    else if (pid_2 == -1)
    {
        write(2,"Error\n",6);
        exit(0);   
    }
    
}