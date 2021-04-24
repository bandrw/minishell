/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:45:21 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/24 20:45:23 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_other(t_parse *parse, char **env)
{
	int		pid;
	int		status;
	char	*path;

	pid = fork();
	if (pid == 0)
	{
		path = get_env("PATH", env);
		if (execve(parse->argv[0], parse->argv, env) == -1)
		{
			ft_putendl_fd("<execve error>", 2);
			exit(1);
		}
	}
	else
		waitpid(pid, &status, 0);
}
