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
		ft_putendl_fd("Error", 2);
		parse->command_id = -1;
	}
	else
	{
		ft_push_argv(buff, parse, n);
		(*str) += 1;
	}
}

void	ft_parse_wquotes(char **str, t_parse *parse)
{
	int		check;
	char	*buff;

	while (**str && **str != '\"')
	{
		check = 0;
		if (**str == '\'')
			ft_quote(str, parse, check);
//		if (**str == '$')
//			ft_dollar(str, parse, check);
		else
		{
			buff = ft_for_print(str, parse, "$\'\"");
			ft_push_argv(buff, parse, check);
		}
	}
}

void	ft_wquote(char **str, t_parse *parse, int n, int *num_quote)
{
	int		check;
	char	*buff;

	//n = 1;
	(*str) += 1;
	*num_quote += 1;
	if (*num_quote % 2 != 0)
	{
		buff = ft_for_print(str, parse, "$\'\"");
		ft_push_argv(buff, parse, n);
		while (**str && **str != '\"')
			ft_parse_wquotes(str, parse);
		if (**str != '\"')
		{
			ft_putendl_fd("Error", 2);
			parse->command_id = -1;
		}
//		else
//		{
//			ft_push_argv(buff, parse, n);
//			(*str) += 1;
//		}
	}
}
