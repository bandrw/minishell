/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:19:40 by pantigon          #+#    #+#             */
/*   Updated: 2021/05/05 18:19:42 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_text(char **str, t_parse *parse, int n)
{
	char	*buff;

	buff = ft_for_print(str, parse, " ;|<>\t\n\v\f\r\'\"");
	ft_push_argv(buff, parse, n);
}

void	ft_get_other(t_parse *parse, char **str)
{
	int	quote;

	quote = 0;
	parse->command_id = CMD_OTHER;
	ft_read_line(str, parse, &quote);
}
