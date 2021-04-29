/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 01:29:53 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/30 01:29:55 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_fd_out(t_parse *parse)
{
	int fd;

	fd = 1;
	if (parse->file_out)
	{
		if (parse->append_output)
			fd = open(parse->file_out, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
		else
			fd = open(parse->file_out, O_CREAT | O_WRONLY, S_IRWXU);
	}
	return (fd);
}

int		get_fd_in(t_parse *parse)
{
	int fd;

	fd = 0;
	if (parse->file_in)
		fd = open(parse->file_in, O_RDONLY);
	return (fd);
}
