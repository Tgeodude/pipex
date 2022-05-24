/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <tgeodude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:10:46 by tgeodude          #+#    #+#             */
/*   Updated: 2022/05/24 12:24:33 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_argv_parse(t_var *vars, char *argv_str, int cmd_num)
{
	char	**buffer_str;

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

void	filename_parser(char **argv, t_var *vars)
{
	if (access(argv[1], R_OK | F_OK) == -1)
		printerror("infile doesn't exist\n");
	vars->infile = open(argv[1], O_RDONLY);
	vars->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (vars->infile < 0 || vars->outfile < 0)
		printerror("error: can't open");
}
