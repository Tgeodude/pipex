/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <tgeodude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:07:08 by tgeodude          #+#    #+#             */
/*   Updated: 2022/05/24 12:07:31 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **env, t_var *vars)
{
	if (!env)
		printerror("Error\n");
	vars->env_pointer = env;
	while (ft_strncmp("PATH=", *env, 5))
	{
		env++;
		if (env == 0)
			return (NULL);
	}
	return (*env + 5);
}

char	*comp_find_path(t_var *vars, char *cmd, int cmd_num)
{
	char	*temp;
	char	*path;
	int		i;

	if (access(cmd, X_OK | F_OK) != -1)
		return (ft_strdup(cmd));
	i = 0;
	while (vars->my_path[i])
	{
		temp = ft_strjoin(vars->my_path[i++], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK | F_OK) != -1)
			return (path);
		free(path);
	}
	return (NULL);
	if (cmd_num == 1)
		free_child_error("Error\n", vars, 1);
	else
		free_child_error("Error\n", vars, 2);
	return (NULL);
}

void	check_path(char **env, t_var *vars)
{
	vars->my_path = ft_split(find_path(env, vars), ':');
}
