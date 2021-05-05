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

char	*ft_convers_dol(t_parse *parse, char **str)
{
	char *line;
	char *buff;
	char *env;

	buff = 0;
	line = 0;
	while (**str && ft_strchr(";", **str) == 0)
	{
		if (**str == '\'')
		{
			(*str)++;
			line = ft_strjoin(line, ft_for_print(str, parse, "\'"));
			(*str)++;
		}
		else if (**str == '$')
			line = ft_strjoin(line, ft_dollar(str, parse));
		else
		{
			line = ft_strjoin(line, ft_for_print(str, parse, "$;\'"));
		}
		//(*str)++;
	}
	return (line);
}

char	*ft_dollar(char **str, t_parse *parse)
{
	char	*buff;
	char	*env;

	(*str) += 1;
//	if (**str == '?')
//	{
//		env = ft_itoa(errno);
//		ft_push_argv(env, parse, 0);
//		(*str) += 1;
//	}
	//else
	//{
	buff = ft_for_print(str, parse, "$;\t\n\v\f\r\'\" |<>");
	env = get_env(buff, parse->env);
	if (env)
		return (env);
	return (0);
	//}
}
