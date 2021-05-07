/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 00:02:50 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/28 00:02:53 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_exit(t_parse *parse)
{
	if (parse->argv)
	{
		if (!ft_isdigit(((char *)parse->argv->content)[0]))
		{
			ft_putendl_fd("exit", 2);
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(parse->argv->content, 2);
			ft_putendl_fd(": numeric argument required", 2);
			exit(255);
		}
		if (parse->argv->next)
		{
			errno = 1;
			ft_putendl_fd("exit", 2);
			ft_putendl_fd("minishell: exit: too many arguments", 2);
			return ;
		}
		exit(ft_atoi(parse->argv->content));
	}
	exit(0);
}
