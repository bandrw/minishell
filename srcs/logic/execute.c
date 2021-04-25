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
	if (parse->command_id == CMD_OTHER)
		ft_other(parse, env);
	else if (parse->command_id == CMD_ECHO)
		ft_echo(parse->argv, env);
	else if (parse->command_id == CMD_CD)
		ft_cd(parse->argv, env);
	else if (parse->command_id == CMD_PWD)
		ft_pwd();
	else if (parse->command_id == CMD_EXPORT)
		ft_export(parse->argv, env);
}
