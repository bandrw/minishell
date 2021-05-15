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

extern t_state	g_state;

char	*ft_get_argv(char **str)
{
	char	i;
	char	*env;
	int		j;

	i = '0';
	j = 0;
	while (j <= 9)
	{
		if (i == **str && j < g_state.argc)
		{
			env = ft_strdup(g_state.argv[j]);
			(*str) += 1;
			return (env);
		}
		i++;
		j++;
	}
	(*str) += 1;
	return (0);
}

int 	ft_strchar_isalnum(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isalnum(line[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_for_print_isalnum(char **str)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = ft_strchar_isalnum(*str) + 1;
	tmp = (char *) malloc(sizeof(char) * (i));
	ft_strlcpy(tmp, *str, i);
	(*str) += i - 1;
	return (tmp);
}

char	*ft_dollar(char **str, t_parse *parse)
{
	char	*buff;
	char	*env;

	(*str) += 1;
	if (ft_isdigit(**str) != 0)
		return (ft_get_argv(str));
	if (**str == '?')
	{
		env = ft_itoa(errno);
		(*str) += 1;
		return (env);
	}
	buff = ft_for_print_isalnum(str);
	env = ft_strdup(get_env(buff, parse->env));
	free(buff);
	return (env);
}
