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

char    *comp_find_path(t_var vars, char *cmd, int cmd_num)
{
    char    *temp;
    char    *path;
    int     i;

    if (access(cmd, X_OK | F_OK) != -1)
		return (ft_strdup(cmd));
    i = -1;
    while (vars->my_path[++i])
    {
		temp = ft_strjoin(vars->my_path[i++], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK | F_OK) != -1)
			return (path);
		free(path);
    }
    return (NULL);
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
    cmd_argv_parse(vars, 1);
    vars->path_cmd1 = comp_find_path(vars, vars->cmd1, 1);
    if (dup2(vars->pipe_fd[1], 1) < 0 || dup2(vars->infile;, 0) < 0)
        exit(0);
    	close(vars->pipe_fd[0]);
	close(vars->pipe_fd[1]);
	close(vars->infile);
	if (execve(vars->path_cmd1, vars->argv_cmd1, vars->env_ptr) == -1)
        exit(0);
}

void    child2(t_var *vars)
{
    cmd_argv_parse(vars, 2);
    vars->path_cmd2 = comp_find_path(vars, vars->cmd2, 1);
    if (dup2(vars->pipe_fd[0], 0) < 0 || dup2(vars->outfile;, 1) < 0)
        exit(0);
    close(vars->pipe_fd[0]);
	close(vars->pipe_fd[1]);
	close(vars->outfile);
	if (execve(vars->path_cmd2, vars->argv_cmd2, vars->env_ptr) == -1)
        exit(0);
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
        child2(vars);
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