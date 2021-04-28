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

void	execute_command_line(t_parse *parse, char ***env)
{
	if (parse->command_id == CMD_OTHER)
		cmd_other(parse, *env);
	else if (parse->command_id == CMD_ECHO)
		cmd_echo(parse);
	else if (parse->command_id == CMD_CD)
		cmd_cd(parse->argv, env);
	else if (parse->command_id == CMD_PWD)
		cmd_pwd();
	else if (parse->command_id == CMD_EXPORT)
		cmd_export(parse->argv, env);
	else if (parse->command_id == CMD_UNSET)
		cmd_unset(parse->argv, env);
	else if (parse->command_id == CMD_ENV)
		cmd_env(*env);
	else if (parse->command_id == CMD_EXIT)
		cmd_exit(parse->argv);
}
