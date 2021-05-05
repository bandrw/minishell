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
	int		fd[2];
	char	*path;
	char	**argv_arr;
	int		fd_in;
	int		fd_out;
	int		stdout_copy;
	int		stdin_copy;

	errno = 0;
	argv_arr = ft_lsttoarr(parse->argv);
	if (argv_arr)
	{
		path = get_env("PATH", env);
		pipe(fd);
		stdout_copy = dup(1);
		stdin_copy = dup(0);
		dup2(fd[1], 1);
		close(fd[1]);
		fd_in = get_fd_in(parse);
		if (parse->pipe_info.fd_in)
			dup2(parse->pipe_info.fd_in, 0);
		else if (parse->pipe_info.file_in)
			dup2(fd_in, 0);
		if (argv_arr[0][0] == '/' || argv_arr[0][0] == '.' || !path)
			exec_relative(parse, env, argv_arr);
		else
			exec_from_path(parse, env, argv_arr, path);
		dup2(stdout_copy, 1);
		dup2(stdin_copy, 0);
		close(stdin_copy);
		close(stdout_copy);
		fd_out = get_fd_out(parse);
		redirect(fd[0], fd_out);
		if (fd_out != 1)
			close(fd_out);
		if (fd_in != 0)
			close(fd_in);
		close(fd[0]);
	}
}
