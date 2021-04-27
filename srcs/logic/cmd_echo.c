/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:16:49 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/18 17:16:52 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_echo(t_list *argv)
{
	int	need_new_line;

	if (argv->content == 0)
		ft_putchar_fd('\n', 1);
	need_new_line = 1;
	if (ft_strncmp(argv->content, "-n", 3) == 0)
		need_new_line = 0;
	while (argv)
	{
		ft_putstr_fd(argv->content, 1);
		if (argv->next)
			ft_putchar_fd(' ', 1);
		argv = argv->next;
	}
	if (need_new_line)
		ft_putchar_fd('\n', 1);
}
