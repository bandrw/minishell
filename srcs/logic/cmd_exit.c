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
	int	fd_out;

	fd_out = get_fd_out(parse);
	if (fd_out != 1)
		close(fd_out);
	if (parse->argv)
		exit(ft_atoi(parse->argv->content));
	exit(0);
}
