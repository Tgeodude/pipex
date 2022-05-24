/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <tgeodude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:26:37 by tgeodude          #+#    #+#             */
/*   Updated: 2022/05/24 12:26:52 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_parent_error(char *str, t_var *vars)
{
	int	i;

	i = 0;
	if (vars->my_path)
	{
		while (vars->my_path[i])
			free(vars->my_path[i++]);
		free(vars->my_path);
	}
	printerror(str);
}

void	free_child_error(char *str, t_var *vars, int child_num)
{
	int	i;

	i = 0;
	if (child_num == 1 && vars->argv_cmd1)
	{
		while (vars->argv_cmd1[i])
			free(vars->argv_cmd1[i++]);
		free(vars->argv_cmd1);
	}
	else if (child_num == 2 && vars->argv_cmd2)
	{
		while (vars->argv_cmd2[i])
			free(vars->argv_cmd2[i++]);
		free(vars->argv_cmd2);
	}
	if (child_num == 1 && vars->path_cmd1)
		free(vars->path_cmd1);
	else if (child_num == 2 && vars->path_cmd2)
		free(vars->path_cmd2);
	free_parent_error(str, vars);
}
