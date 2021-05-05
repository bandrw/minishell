/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:34:21 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/27 16:34:24 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	ft_get_echo(t_parse *parse, char **str)
{
	char	*tmp;

	tmp = *str + 4;
	while (ft_isspace(*tmp))
		tmp++;
	parse->command_id = CMD_ECHO;
	ft_read_line(&tmp, parse, 0);
	*str = tmp;
//	// Redirect example
//	parse->file_out = ft_strdup("out.txt"); // (echo 123 > out.txt)
//	parse->append_output = 1; // (echo 123 >> out.txt)
}
