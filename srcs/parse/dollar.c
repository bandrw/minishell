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

char	*ft_check_env(char *buff)
{
	char	*n;

	while (*buff)
	{
		if (*buff == '\'' || *buff == '\"')
			*buff = '\0';
		buff++;
	}
	return (buff);
}

void	ft_dollar(char **str, t_parse *parse, int n)
{
	char	*buff;
	char	*env;

	(*str) += 1;
	if (**str == '?')
	{
		env = ft_itoa(errno);
		ft_push_argv(env, parse, 0);
		(*str) += 1;
	}
	else
	{
		buff = ft_for_print(str, parse, "$\t\n\v\f\r\'\" ");
		//buff = ft_check_env(buff);	//todo: leaks
		env = getenv(buff);
		if (!env)
			ft_putendl_fd("Error: not env", 2);
		else
			ft_push_argv(env, parse, n);
	}
}
