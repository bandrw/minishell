/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:00:05 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/18 17:00:06 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_line(char *command_line, t_parse *parse)
{
//	// echo example
//	parse->command_id = CMD_ECHO;
//	parse->argv = (char **)malloc(sizeof(char *) * 4);
//	parse->argv[0] = ft_strdup("abcd");
//	parse->argv[1] = ft_strdup("123");
//	parse->argv[2] = ft_strdup("456");
//	parse->argv[3] = 0;

	// other commands example
	parse->command_id = CMD_OTHER;
	parse->argv = (char **)malloc(sizeof(char *) * 3);
	parse->argv[0] = ft_strdup("ls");
	parse->argv[1] = ft_strdup("-l");
	parse->argv[2] = 0;
}
