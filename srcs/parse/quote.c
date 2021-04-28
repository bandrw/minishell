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

char	*ft_for_print_qoute(char **str, t_parse *parse, char *ch)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = ft_strchar_int(ch, *str) + 1;
	tmp = (char *) malloc(sizeof(char) * (i));
	ft_strlcpy(tmp, *str, i);
	(*str) += i - 1;
	return (tmp);
}

void	ft_quote(char **str, t_parse *parse, int n)
{
	int		check;
	char	*buff;

	check = 1;
	(*str) += 1;
	buff = ft_for_print_qoute(str, parse, "\'");
	if (**str != '\'')
	{
		ft_putendl_fd("need second quote", 1);
		parse->argv = (void *)-1;
	}
	else
	{
		ft_push_argv(buff, parse, n);
		(*str) += 1;
	}
}
