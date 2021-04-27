/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:43:55 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/27 17:43:57 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_push_argv(char *str, t_parse *parse, int *ac)
{
	ft_lstadd_back(&parse->argv, ft_lstnew(str));
	(*ac)++;
}

char	*ft_for_print(char **str, t_parse *parse, int *ac)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = ft_strchar_int("$\t\n\v\f\r ", *str) + 1;
	tmp = (char *) malloc(sizeof(char) * (i));
	ft_strlcpy(tmp, *str, i);
	(*str) += i - 1;
	return (tmp);
}

int 	ft_strchar_int(const char *str, char *line)
{
	int i;
	int j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[j] == line[i])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
