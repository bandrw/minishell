/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 01:45:39 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/30 01:45:40 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect(int fd_in, int fd_out)
{
	char	*line;

	if (fd_in == 0)
		return ;
	while (get_next_line(fd_in, &line) == 1)
	{
		ft_putendl_fd(line, fd_out);
		free(line);
	}
	if (*line != '\0')
	{
		ft_putstr_fd(line, fd_out);
		free(line);
	}
}
