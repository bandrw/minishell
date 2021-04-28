/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:47:13 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/28 16:47:15 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_quote(char **str, t_parse *parse, int n)
{
	int		check;
	char	*buff;

	check = 1;
	(*str) += 1;
	buff = ft_for_print(str, parse, "\'");
	if (**str != '\'')
	{
		ft_putendl_fd("Error: need second quote", 2);
		parse->command_id = -1;
	}
	else
	{
		ft_push_argv(buff, parse, n);
		(*str) += 1;
	}
}

void	ft_wquote(char **str, t_parse *parse, int n, int num_quote)
{
	int		check;
	char	*buff;

	check = 1;
	(*str) += 1;
	if (num_quote % 2 != 0)
	{
		buff = ft_for_print(str, parse, "$\"");
		while (**str && **str != '\"')
			ft_read_line(str, parse);
		if (**str != '\"')
		{
			ft_putendl_fd("Error: need second quote", 2);
			parse->command_id = -1;
		}
		else
		{
			ft_push_argv(buff, parse, n);
			(*str) += 1;
		}
	}
}
