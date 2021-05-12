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

int	throw_open_error(char *file)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	errno = 1;
	return (-1);
}

int		get_fd_in(t_parse *parse)
{
	int fd;

	if (parse->pipe_info.file_in)
	{
		fd = open(parse->pipe_info.file_in, O_RDONLY);
		if (fd < 0)
			return (throw_open_error(parse->pipe_info.file_in));
		return (fd);
	}
	else if (parse->pipe_info.fd_in)
		return (parse->pipe_info.fd_in);
	return (0);
}

int		get_fd_out(t_parse *parse)
{
	int	fd;
	int	pipe_fd[2];

	if (parse->pipe_info.pipe_to_next)
	{
		pipe(pipe_fd);
		parse->next_parse_fd_in = pipe_fd[0];
		return (pipe_fd[1]);
	}
	if (parse->pipe_info.file_out)
	{
		if (parse->pipe_info.append_output)
			fd = open(parse->pipe_info.file_out, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else
			fd = open(parse->pipe_info.file_out, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
			return (throw_open_error(parse->pipe_info.file_out));
		return (fd);
	}
	return (1);
}

int		get_fd_err(t_parse *parse)
{
	int	fd;

	if (parse->pipe_info.err_file_out)
	{
		if (parse->pipe_info.append_err_output)
			fd = open(parse->pipe_info.err_file_out, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else
			fd = open(parse->pipe_info.err_file_out, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
			return (throw_open_error(parse->pipe_info.err_file_out));
		return (fd);
	}
	return (2);
}
