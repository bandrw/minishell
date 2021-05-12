/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:26:41 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/28 17:26:42 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_arr(char **arr)
{
	int		j;
	int		i;
	char	*tmp;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_strcmp(arr[i], arr[j]) > 0)
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
			j++;
		}
		i++;
	}
}

char	**arr_realloc(char **arr)
{
	int		i;
	char	**r;

	i = 0;
	while (arr[i])
		i++;
	r = (char **)malloc(sizeof(char *) * (i + 1));
	if (r)
	{
		i = 0;
		while (arr[i])
		{
			r[i] = ft_strdup(arr[i]);
			i++;
		}
		r[i] = 0;
	}
	return (r);
}

char	*get_env(char *key, char **env)
{
	int	l;

	while (*env)
	{
		l = (int)ft_strlen(key);
		if (ft_strncmp(key, *env, l) == 0 && (*env)[l] == '=')
			return (*env + l + 1);
		env++;
	}
	return (0);
}

int	is_valid_key(char *key)
{
	if (ft_isdigit(key[0]))
		return (0);
	while (*key)
	{
		if (!ft_isalnum(*key) && *key != '_')
			return (0);
		key++;
	}
	return (1);
}
