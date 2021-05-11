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

char	*ft_convers_dol(t_parse *parse, char **str, int ac, char **av)
{
	char	*line;
	char	*buff;
	char	*env;
	char	*tmp;
	char	*tmp1;

	buff = 0;
	line = 0;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == ';')
	{
		ft_putendl_fd("syntax error near unexpected token `;'", 2);
		return (0);
	}
	while (**str && ft_strchr(";", **str) == 0)
	{
		if (**str == '\'')
		{
			(*str)++;
			tmp = ft_for_print(str, parse, "\'");
			line = ft_strjoin(line, tmp);
			free(tmp);
			if (!line)
			{
				ft_putendl_fd("malloc fail", 2);
				return (0);
			}
			(*str)++;
		}
		else if (**str == '$')
		{
			tmp = ft_dollar(str, parse, ac, av);
			if (tmp)
			{
				tmp1 = line;
				line = ft_strjoin(line, tmp);
				free(tmp);
				free(tmp1);
			}
//			if (!line)
//			{
//				ft_putendl_fd("malloc fail", 2);
//				return (0);
//			}
		}
		else
		{
			tmp = ft_for_print(str, parse, "$;\'");
			tmp1 = line;
			line = ft_strjoin(line, tmp);
			free(tmp);
			free(line);
			if (!line)
			{
				ft_putendl_fd("malloc fail", 2);
				return (0);
			}
		}
	}
	return (line);
}

char	*ft_get_argv(char **str, t_parse *parse, int argc, char **argv)
{
	char	i;
	char	*env;
	int		j;

	i = '0';
	j = 0;
	while (j <= 9)
	{
		if (i == **str && j < argc)
		{
			env = ft_strdup(argv[j]);
			if (!env)
			{
				ft_putendl_fd("malloc fail", 2);
				return (0);
			}
			(*str) += 1;
			return (env);
		}
		i++;
		j++;
	}
	(*str) += 1;
	return (0);
}

char	*ft_dollar(char **str, t_parse *parse, int argc, char **argv)
{
	char	*buff;
	char	*env;

	(*str) += 1;
	if (ft_isdigit(**str) != 0)
		return (ft_get_argv(str, parse, argc, argv));
	if (**str == '?')
	{
		env = ft_itoa(errno);
		if (!env)
		{
			ft_putendl_fd("malloc fail", 2);
			return (0);
		}
		(*str) += 1;
		return (env);
	}
	buff = ft_for_print(str, parse, "$;\t\n\v\f\r\'\" |<>");
	env = ft_strdup(get_env(buff, parse->env));
	free(buff);
	return (env);
}
