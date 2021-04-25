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

}

void	ft_get_pwd(t_parse *parse)
{
	parse->command_id = CMD_PWD;
	parse->argv = (char **)malloc(sizeof(char*) * 2);
//		if (!parse->argv)
	parse->argv[0] = ft_strdup("pwd");
	parse->argv[1] = 0;
}

void	ft_get_other(t_parse *parse, char *str)
{
	parse->command_id = CMD_OTHER;
	parse->argv = ft_split(str, ' ');
}

void	parse_line(char *command_line, t_parse *parse)
{

	if (ft_strncmp("echo", command_line, 5))
		ft_get_echo(parse, command_line);
	if (ft_strncmp("pwd", command_line, 4))
		ft_get_pwd(parse);
	else
		ft_get_other(parse, command_line);
		//	// echo example
//	parse->command_id = CMD_ECHO;
//	parse->argv = (char **)malloc(sizeof(char *) * 4);
//	parse->argv[0] = ft_strdup("abcd");
//	parse->argv[1] = ft_strdup("123");
//	parse->argv[2] = ft_strdup("456");
//	parse->argv[3] = 0;
}
