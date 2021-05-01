/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:47:45 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/25 19:47:46 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_pwd(t_parse *parse)
{
	int		fd_out;
	char	pwd[1024];

	fd_out = get_fd_out(parse);
	ft_putendl_fd(getcwd(pwd, 1024), fd_out);
	if (fd_out != 1)
		close(fd_out);
}
