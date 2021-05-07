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

static void	execute(char *exec_file, char **env, char **argv_arr)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		execve(exec_file, argv_arr, env);
		exit(1);
	}
	else
		waitpid(pid, &status, 0);
}

static int	check_executable_silent(char *executable)
{
	struct stat	file;

	ft_bzero(&file, sizeof(file));
	if (lstat(executable, &file) != 0)
		return (1);
	if (S_ISDIR(file.st_mode))
		return (2);
	if ((file.st_mode & S_IXUSR) == 0)
		return (3);
	return (0);
}

static char	*get_execute_str(char *str, char *path)
{
	int		i;
	char	*tmp;
	char	**paths;

	if (path)
	{
		paths = ft_split(path, ':');
		i = -1;
		while (paths[++i])
		{
			tmp = (char *)malloc(sizeof(char) * (ft_strlen(paths[i]) +
				ft_strlen(str) + 2));
			ft_strlcpy(tmp, paths[i], ft_strlen(paths[i]) + 1);
			ft_strlcat(tmp, "/", ft_strlen(tmp) + 2);
			ft_strlcat(tmp, str, ft_strlen(tmp) + ft_strlen(str) + 1);
			if (check_executable_silent(tmp) == 0)
				return (tmp);
			free(tmp);
			free(paths[i]);
		}
		free(paths);
	}
	return (0);
}

static int	check_executable(char *file_name, char *argv_0)
{
	struct stat	file;

	ft_bzero(&file, sizeof(file));
	if (lstat(file_name, &file) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(argv_0, 2);
		ft_putendl_fd(": No such file or directory", 2);
		errno = 127;
		return (1);
	}
	if (S_ISDIR(file.st_mode))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(argv_0, 2);
		ft_putendl_fd(": is a directory", 2);
		errno = 126;
		return (2);
	}
	if ((file.st_mode & S_IXUSR) == 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(argv_0, 2);
		ft_putendl_fd(": Permission denied", 2);
		errno = 126;
		return (3);
	}
	return (0);
}

void	cmd_other(t_parse *parse, char **env)
{
	char	**argv_arr;
	char	*executable_file;

	errno = 0;
	argv_arr = ft_lsttoarr(parse->argv);
	if (argv_arr)
	{
		executable_file = argv_arr[0];
		if (!(argv_arr[0][0] == '/' || argv_arr[0][0] == '.'))
			executable_file = get_execute_str(argv_arr[0], get_env("PATH", env));
		if (check_executable(executable_file, parse->argv->content) == 0)
			execute(executable_file, env, argv_arr);
	}
}
