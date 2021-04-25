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

static void	exec_relative(t_parse *parse, char **env)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		execve(parse->argv[0], parse->argv, env);
		exit(1);
	}
	else
		waitpid(pid, &status, 0);
	if (status == 256)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(parse->argv[0], 2);
		ft_putendl_fd(": command not found", 2);
	}
}

static void	exec_absolute(t_parse *parse, char **env)
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
	if (status == 256)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(parse->argv[0], 2);
		ft_putendl_fd(": command not found", 2);
	}
	free(paths);
}

void	ft_other(t_parse *parse, char **env)
{
	if (parse->argv[0][0] == '/' || parse->argv[0][0] == '.')
		exec_relative(parse, env);
	else
		exec_absolute(parse, env);
}
