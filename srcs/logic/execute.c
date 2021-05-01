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

void	execute_command_line(t_list *parse_list, char ***env)
{
	t_parse	*parse;
	t_parse	*next_parse;

	while (parse_list)
	{
		parse = (t_parse *)parse_list->content;
		next_parse = 0;
		if (parse_list->next)
			next_parse = parse_list->next->content;
		if (parse->command_id == CMD_OTHER)
			cmd_other(parse, next_parse, *env);
		else if (parse->command_id == CMD_ECHO)
			cmd_echo(parse, next_parse);
		else if (parse->command_id == CMD_CD)
			cmd_cd(parse->argv, env);
		else if (parse->command_id == CMD_PWD)
			cmd_pwd(parse_list->next->content);
		else if (parse->command_id == CMD_EXPORT)
			cmd_export(parse->argv, parse_list->next->content, env);
		else if (parse->command_id == CMD_UNSET)
			cmd_unset(parse->argv, env);
		else if (parse->command_id == CMD_ENV)
			cmd_env(parse_list->next->content, *env);
		else if (parse->command_id == CMD_EXIT)
			cmd_exit(parse->argv);
		parse_list = parse_list->next;
	}
}
