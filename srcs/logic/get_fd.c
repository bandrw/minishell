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
	int		fd;
	int		pipe_fd[2];

	if (parse->pipe_info.pipe_to_next)
	{
		pipe(pipe_fd);
		parse->parse_next->pipe_info.fd_in = pipe_fd[0];
		return (pipe_fd[1]);
	}
	if (parse->pipe_info.file_out)
	{
		if (parse->pipe_info.append_output)
			fd = open(parse->pipe_info.file_out, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
		else
			fd = open(parse->pipe_info.file_out, O_CREAT | O_WRONLY, S_IRWXU);
		return (fd);
	}
	return (1);
}

int		get_fd_in(t_parse *parse)
{
	if (parse->pipe_info.fd_in)
		return (parse->pipe_info.fd_in);
	if (parse->pipe_info.file_in)
		return (open(parse->pipe_info.file_in, O_RDONLY));
	return (0);
}
