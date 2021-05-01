/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 00:08:20 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/28 00:08:21 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_env(t_parse *parse, t_parse *parse_next, char **env)
{
	int	fd_out;

	fd_out = get_fd_out(parse, parse_next);
	sort_arr(env);
	while (*env)
	{
		if (ft_strchr(*env, '='))
			ft_putendl_fd(*env, fd_out);
		env++;
	}
}
