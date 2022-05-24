/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <tgeodude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:28:46 by tgeodude          #+#    #+#             */
/*   Updated: 2022/05/24 12:33:08 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(t_var *vars)
{
	cmd_argv_parse(vars, vars->argv[2], 1);
	vars->path_cmd1 = comp_find_path(vars, vars->cmd1, 1);
	if (dup2(vars->pipe_fd[1], 1) < 0 || dup2(vars->infile, 0) < 0)
		free_child_error("Error\n", vars, 1);
	close(vars->pipe_fd[0]);
	close(vars->pipe_fd[1]);
	close(vars->infile);
	if (execve(vars->path_cmd1, vars->argv_cmd1, vars->env_pointer) == -1)
		free_child_error("Error\n", vars, 1);
}

void	child2(t_var *vars)
{
	cmd_argv_parse(vars, vars->argv[3], 2);
	vars->path_cmd2 = comp_find_path(vars, vars->cmd2, 1);
	if (dup2(vars->pipe_fd[0], 0) < 0 || dup2(vars->outfile, 1) < 0)
		free_child_error("Error\n", vars, 2);
	close(vars->pipe_fd[0]);
	close(vars->pipe_fd[1]);
	close(vars->outfile);
	if (execve(vars->path_cmd2, vars->argv_cmd2, vars->env_pointer) == -1)
		free_child_error("Error\n", vars, 2);
}

void	process_part(t_var *vars)
{
	if (pipe(vars->pipe_fd) == -1)
		free_parent_error("Error\n", vars);
	vars->pid_1 = fork();
	if (vars->pid_1 == -1)
		free_parent_error("Error\n", vars);
	else if (vars->pid_1 == 0)
		child1(vars);
	vars->pid_2 = fork();
	if (vars->pid_2 == -1)
		free_parent_error("Error\n", vars);
	else if (vars->pid_2 == 0)
		child2(vars);
	close(vars->pipe_fd[0]);
	close(vars->pipe_fd[1]);
	waitpid(vars->pid_1, NULL, 0);
	waitpid(vars->pid_2, NULL, 0);
}

void	init_vars(t_var *vars, char **argv)
{
	vars->cmd1 = NULL;
	vars->path_cmd1 = NULL;
	vars->argv_cmd1 = NULL;
	vars->cmd2 = NULL;
	vars->path_cmd2 = NULL;
	vars->argv_cmd2 = NULL;
	vars->argv = argv;
	vars->my_path = NULL;
	vars->env_pointer = NULL;
}

int	main(int argc, char **argv, char **env)
{
	t_var	vars;

	if (argc != 5)
		printerror("Error\n");
	filename_parser(argv, &vars);
	init_vars(&vars, argv);
	check_path(env, &vars);
	process_part(&vars);
	free_parent_error("", &vars);
	return (0);
}
