/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:35:46 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/25 22:35:47 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	write_vars(t_parse *parse, int fd_out, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		ft_putstr_fd("declare -x ", fd_out);
		write(fd_out, env[i], ft_strchr(env[i], '=') - env[i] + 1);
		write(fd_out, "\"", 1);
		ft_putstr_fd(ft_strchr(env[i], '=') + 1, fd_out);
		write(fd_out, "\"\n", 2);
	}
}

static void	insert_new_env(char *new_env, char ***env)
{
	int		l;
	char	**arr;

	l = 0;
	while ((*env)[l])
		l++;
	arr = (char**)malloc(sizeof(char*) * (l + 2));
	l = -1;
	while ((*env)[++l])
		arr[l] = (*env)[l];
	arr[l] = new_env;
	arr[l + 1] = 0;
	*env = arr;
	sort_arr(*env);
}

void	insert_env(char *key, char *new_env, char ***env)
{
	int i;

	i = -1;
	while ((*env)[++i])
	{
		if (ft_strncmp((*env)[i], key, ft_strlen(key)) == 0)
		{
			(*env)[i] = new_env;
			return ;
		}
	}
	insert_new_env(new_env, env);
}

void	cmd_export(t_parse *parse, char ***env)
{
	int		fd_out;
	char	**pair;
	char	*new_env;
	t_list	*argv;

	argv = parse->argv;
	fd_out = get_fd_out(parse);
	if (!argv)
		write_vars(parse, fd_out, *env);
	else
	{
		while (argv)
		{
			pair = ft_split(argv->content, '=');
			new_env = (char *)malloc(sizeof(char) * (ft_strlen(pair[0]) + ft_strlen(pair[1]) + 1));
			ft_strlcpy(new_env, pair[0], ft_strlen(pair[0]) + 1);
			if (pair[1])
			{
				ft_strlcat(new_env, "=", ft_strlen(new_env) + 2);
				ft_strlcat(new_env, pair[1], ft_strlen(new_env) + ft_strlen(pair[1]) + 1);
			}
			insert_env(pair[0], new_env, env);
			argv = argv->next;
		}
	}
	if (fd_out != 1)
		close(fd_out);
}
