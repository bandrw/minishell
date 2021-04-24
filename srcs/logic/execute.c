/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:04:36 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/18 17:04:39 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command_line(t_parse *parse, char **env)
{
	int	pid;
	int	status;

	if (parse->command_id == CMD_ECHO)
		ft_echo(parse->argv, env);
	else if (parse->command_id == CMD_CD)
		ft_cd(parse->argv, env);
	else if (parse->command_id == CMD_OTHER)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(parse->argv[0], parse->argv, env) == -1)
			{
				ft_putendl_fd("execve error", 2);
				exit(1);
			}
		}
		else
			waitpid(pid, &status, 0);
	}
}
