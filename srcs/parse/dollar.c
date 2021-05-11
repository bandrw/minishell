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

	buff = 0;
	line = 0;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == ';')
	{
		ft_putendl_fd("syntax error near unexpected token `;'", 2);
		return (0);//d
	}
	while (**str && ft_strchr(";", **str) == 0)
	{
		if (**str == '\'')
		{
			(*str)++;
			line = ft_strjoin(line, ft_for_print(str, parse, "\'"));
			(*str)++;
		}
		else if (**str == '$')
			line = ft_strjoin(line, ft_dollar(str, parse, ac, av));
		else
		{
			line = ft_strjoin(line, ft_for_print(str, parse, "$;\'"));
		}
	}
//	if (**str == '<')
//		ft_get_infile(str, parse);
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
		(*str) += 1;
		return (env);
	}
	else
	{
		buff = ft_for_print(str, parse, "$;\t\n\v\f\r\'\" |<>");
		env = get_env(buff, parse->env);
		if (env)
			return (env);
	}
	return (0);
}
