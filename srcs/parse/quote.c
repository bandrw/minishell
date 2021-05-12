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

char	*ft_prequote(char **str, t_parse *parse)
{
	char	*buff;

	(*str) += 1;
	buff = ft_for_print(str, parse, "\'");
	if (**str != '\'')
	{
		ft_putendl_fd("Error: need second quote", 2);
		parse->command_id = -1;
		return (0);
	}
	else
	{
		(*str) += 1;
		return (buff);
	}
}

char	*ft_preparse_wquotes(char **str, t_parse *parse, int ac, char **av)
{
	char	*buff;
	char	*tmp;
	char	*tmp1;

	buff = 0;
	while (**str && **str != '\"')
	{
		if (**str == '$')
			tmp = ft_dollar(str, parse, ac, av);
		else
			tmp = ft_for_print(str, parse, "$\"");
		if (tmp)
		{
			tmp1 = buff;
			buff = ft_strjoin(buff, tmp);
			free(tmp);
			if (tmp1)
				free(tmp1);
		}
	}
	return (buff);
}

int	ft_check_num_quote(char ch, t_parse *parse)
{
	if (ch != '\"')
	{
		ft_putendl_fd("Error: need second quote", 2);
		parse->command_id = -1;
		return (-1);
	}
	return (1);
}

char	*ft_prewquote(char **str, t_parse *parse, int ac, char **av)
{
	char	*buff;
	char	*tmp;
	char	*tmp1;

	(*str) += 1;
	parse->num_quote++;
	tmp = 0;
	if (parse->num_quote % 2 != 0)
	{
		buff = ft_for_print(str, parse, "$\"");
		while (**str && **str != '\"')
			tmp = ft_preparse_wquotes(str, parse, ac, av);
		if (ft_check_num_quote(**str, parse) == -1)
			return (0);
		tmp1 = buff;
		buff = ft_strjoin(buff, tmp);
		free(tmp);
		if (tmp1)
			free(tmp1);
		parse->num_quote++;
		(*str)++;
		return (buff);
	}
	return (0);
}
