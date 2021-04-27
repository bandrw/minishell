/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:35:32 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/27 19:35:35 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_dollar(char **str, t_parse *parse, int *ac)
{
	char	*tmp;
	char	*env;
	int		i;
	int		j;

	j = 0;
	i = ft_strchar_int("$\t\n\v\f\r ", *str) + 1;
	tmp = (char *) malloc(sizeof(char) * (i));
	ft_strlcpy(tmp, *str, i);
	(*str) += i - 1;
	env = getenv(tmp);
	if (!env)
		ft_putendl_fd("not env", 1);
	ft_lstadd_back(&parse->argv, ft_lstnew(env));
	(*ac)++;
}

void	ft_dollar(char **str, t_parse *parse, int *ac)
{
	(*str) += 1;
	ft_parse_dollar(str, parse, ac);
}
