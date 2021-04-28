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

void	ft_push_argv(char *str, t_parse *parse, int n)
{
	char 	*buff;
	t_list	*new;
	t_list	*last;

	buff = 0;
	if (n == 1 && parse->argv)
	{
		last = ft_lstlast(parse->argv);
		buff = ft_strjoin(last->content, str);
		free(last->content);
		last->content = ft_strdup(buff);
	}
	else
		ft_lstadd_back(&parse->argv, ft_lstnew(str));
}

char	*ft_for_print(char **str, t_parse *parse, char *ch)
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
