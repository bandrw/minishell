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

void	ft_dollar(char **str, t_parse *parse, int *ac)
{
	char	*buff;
	char	*env;

	(*str) += 1;
	buff = ft_for_print(str, parse, ac);
	env = getenv(buff);
	if (!env)
		ft_putendl_fd("not env", 1);
	ft_push_argv(env, parse, ac);
}
