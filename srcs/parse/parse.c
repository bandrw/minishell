/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:00:05 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/25 17:11:27 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	ft_get_echo(t_parse *parse, char *str)
{
	parse->command_id = CMD_ECHO;
	parse->argv = ft_split(str + 4, ' ');
}

void	ft_get_cd(t_parse *parse, char *str)
{
	parse->command_id = CMD_CD;
	parse->argv = ft_split(str + 2, ' ');
}

void	ft_get_pwd(t_parse *parse)
{
	parse->command_id = CMD_PWD;
	parse->argv = 0;
}

void	ft_get_other(t_parse *parse, char *str)
{
	parse->command_id = CMD_OTHER;
	parse->argv = ft_split(str, ' ');
}

void	parse_line(char *line, t_parse *parse)
{

	if (ft_strncmp("echo", line, 4) == 0 && (!line[4]
		|| ft_isspace(line[4])))
		ft_get_echo(parse, line);
	else if (ft_strncmp("echo", line, 4) == 0 && (!line[4]
		|| ft_isspace(line[4])))
		ft_get_cd(parse, line);
	else if (ft_strncmp("pwd", line, 4) == 0)
		ft_get_pwd(parse);
	else
		ft_get_other(parse, line);
		//	// echo example
//	parse->command_id = CMD_ECHO;
//	parse->argv = (char **)malloc(sizeof(char *) * 4);
//	parse->argv[0] = ft_strdup("abcd");
//	parse->argv[1] = ft_strdup("123");
//	parse->argv[2] = ft_strdup("456");
//	parse->argv[3] = 0;
}
