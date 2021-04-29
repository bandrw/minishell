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

void	cmd_echo(t_parse *parse)
{
	int	need_new_line;
	int	fd;

	fd = get_fd_out(parse);
	if (parse->argv->content == 0)
		ft_putchar_fd('\n', 1);
	need_new_line = 1;
	if (ft_strncmp(parse->argv->content, "-n", 3) == 0)
		need_new_line = 0;
	while (parse->argv)
	{
		ft_putstr_fd(parse->argv->content, fd);
		if (parse->argv->next)
			ft_putchar_fd(' ', fd);
		parse->argv = parse->argv->next;
	}
	if (need_new_line)
		ft_putchar_fd('\n', fd);
	if (fd != 1)
		close(fd);
}
