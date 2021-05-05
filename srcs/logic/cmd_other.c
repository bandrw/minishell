/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:45:21 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/24 20:45:23 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_relative(t_parse *parse, char **env, char **argv_arr)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		execve(parse->argv->content, argv_arr, env);
		exit(1);
	}
	else
		waitpid(pid, &status, 0);
	if (status == 256)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(parse->argv->content, 2);
		ft_putendl_fd(": command not found", 2);
	}
}

static void	exec_from_path(t_parse *parse, char **env, char **argv_arr, char *path)
{
	int		i;
	pid_t 	pid;
	int		status;
	char	*str;
	char	**paths;

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
			str = ft_strjoin(tmp, parse->argv->content);
			free(tmp);
			execve(str, argv_arr, env);
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
		ft_putstr_fd(parse->argv->content, 2);
		ft_putendl_fd(": command not found", 2);
	}
	free(paths);
}

void	cmd_other(t_parse *parse, char **env)
{
	char	*path;
	char	**argv_arr;

	errno = 0;
	argv_arr = ft_lsttoarr(parse->argv);
	if (argv_arr)
	{
		path = get_env("PATH", env);
		if (argv_arr[0][0] == '/' || argv_arr[0][0] == '.' || !path)
			exec_relative(parse, env, argv_arr);
		else
			exec_from_path(parse, env, argv_arr, path);
	}
}
