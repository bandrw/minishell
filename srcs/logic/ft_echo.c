/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:16:49 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/18 17:16:52 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **argv, char **env)
{
	int	i;
	int	need_new_line;

	if (argv[0] == 0)
		ft_putchar_fd('\n', 1);
	need_new_line = 1;
	if (ft_strncmp(argv[0], "-n", 3) == 0)
		need_new_line = 0;
	i = -1;
	if (!need_new_line)
		i = 0;
	while (argv[++i])
	{
		ft_putstr_fd(argv[i], 1);
		ft_putchar_fd(' ', 1);
	}
	if (need_new_line)
		ft_putchar_fd('\n', 1);
}
