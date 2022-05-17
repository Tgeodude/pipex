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

void    check_path(char **env, t_var *vars)
{
    int i;

    vars->my_path = ft_split(find_path(env), ':');
    i = -1;
    while (vars->my_path[++i])
        printf("%s\n", vars->my_path[i]);
}

void    child1(t_var *vars)
{

}

void    process_part(t_var *vars)
{
    pipe(vars->pipe_fd);
    vars->pid_1 = fork();
    if (vars->pid_1 == 0)
        child1(vars);
    else if (vars->pid_1 == -1)
    {
        write(2,"Error\n",6);
        exit(0);   
    }
    vars->pid_2 = fork();
    if (vars->pid_2 == 0)
        child2();
    else if (vars->pid_2 == -1)
    {
        write(2,"Error\n",6);
        exit(0);   
    }
    close(vars->pipe_fd[0]);
	close(vars->pipe_fd[1]);
	waitpid(vars->pid_1, NULL, 0);
	waitpid(vars->pid_2, NULL, 0);
}

int main(int argc, char **argv, char **env)
{   
    t_var vars;

    if (argc != 5)
    {
        write(2,"Error\n",6);
        exit(0);        
    }
    check_path(env, &vars);
    process_part(&vars);
}