/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:35:46 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/25 22:35:47 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	write_vars(char **env)
{
	int		i;
	char	*delimiter;

	i = -1;
	while (env[++i])
	{
		delimiter = ft_strchr(env[i], '=');
		ft_putstr_fd("declare -x ", 1);
		if (delimiter)
		{
			write(1, env[i], delimiter - env[i] + 1);
			write(1, "\"", 1);
			ft_putstr_fd(delimiter + 1, 1);
			write(1, "\"\n", 2);
		}
		else
			ft_putendl_fd(env[i], 1);
	}
}

static void	insert_new_env(char *new_env, char ***env)
{
	int		l;
	char	**arr;

	l = 0;
	while ((*env)[l])
		l++;
	arr = (char **)malloc(sizeof(char *) * (l + 2));
	l = -1;
	while ((*env)[++l])
		arr[l] = (*env)[l];
	arr[l] = new_env;
	arr[l + 1] = 0;
	free(*env);
	*env = arr;
	sort_arr(*env);
}

void	insert_env(char *key, char *new_env, char ***env)
{
	int	i;

	i = -1;
	while ((*env)[++i])
	{
		if (ft_strncmp((*env)[i], key, ft_strlen(key)) == 0)
		{
			free((*env)[i]);
			(*env)[i] = new_env;
			return ;
		}
	}
	insert_new_env(new_env, env);
}

void	do_export(char **pair, char ***env)
{
	char	*new_env;

	new_env = (char *)malloc(sizeof(char)
			* (ft_strlen(pair[0]) + ft_strlen(pair[1]) + 1));
	ft_strlcpy(new_env, pair[0], ft_strlen(pair[0]) + 1);
	if (pair[1])
	{
		ft_strlcat(new_env, "=", ft_strlen(new_env) + 2);
		ft_strlcat(new_env, pair[1], ft_strlen(new_env)
			+ ft_strlen(pair[1]) + 1);
	}
	if (pair[1] || !get_env(pair[0], *env))
		insert_env(pair[0], new_env, env);
}

void	cmd_export(t_parse *parse, char ***env)
{
	char	**pair;
	t_list	*argv;

	errno = 0;
	argv = parse->argv;
	if (!argv)
		write_vars(*env);
	else
	{
		while (argv)
		{
			pair = ft_split(argv->content, '=');
			if (!is_valid_key(pair[0]))
			{
				errno = 1;
				ft_putstr_fd("export: not an identifier: ", 2);
				ft_putendl_fd(pair[0], 2);
				argv = argv->next;
				continue ;
			}
			do_export(pair, env);
			clear_array(pair);
			argv = argv->next;
		}
	}
}
