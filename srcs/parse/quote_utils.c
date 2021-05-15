/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 22:37:43 by pantigon          #+#    #+#             */
/*   Updated: 2021/05/15 22:37:46 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fshell(char **tmp, char **buff)
{
	char	*tmp1;

	if (*tmp)
	{
		tmp1 = *buff;
		*buff = ft_strjoin(*buff, *tmp);
		free(*tmp);
		if (tmp1)
			free(tmp1);
	}
}

int 	ft_strchar_int_q(const char *str, char *line)
{
	int	i;
	int	j;

	i = 0;
	line++;
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

char	*ft_for_print_q(char **str, t_parse *parse, char *ch)
{
	char	*tmp;
	int		i;

	i = ft_strchar_int_q(ch, *str) + 2;
	tmp = (char *) malloc(sizeof(char) * (i));
	ft_strlcpy(tmp, *str, i);
	(*str) += i - 1;
	return (tmp);
}
