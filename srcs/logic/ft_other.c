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
	int		i;
	int		pid;
	int		status;
	char	*path;
	char	*str;
	char	**paths;

	path = get_env("PATH", env);
	if (!path)
		return ;
	paths = ft_split(path, ':');
	i = -1;
	status = 1;
	while (paths[++i] && status != 0)
	{
		pid = fork();
		if (pid == 0)
		{
			str = ft_strjoin(paths[i], "/");
			char *tmp = str;
			str = ft_strjoin(tmp, parse->argv[0]);
			free(tmp);
			execve(str, parse->argv, env);
			free(str);
			exit(1);
		}
		else
			waitpid(pid, &status, 0);
		free(paths[i]);
	}
	free(paths);
}
