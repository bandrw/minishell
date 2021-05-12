/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:41:58 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/27 23:41:59 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_in_list(char *str, t_list *list)
{
	while (list)
	{
		if (ft_strncmp(str, list->content, ft_strlen(list->content)) == 0)
			return (1);
		list = list->next;
	}
	return (0);
}

static int	get_env_len(t_list *argv, char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	while (argv)
	{
		if (get_env(argv->content, env))
			i--;
		if (ft_isdigit(((char *)argv->content)[0]))
		{
			errno = 1;
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(argv->content, 2);
			ft_putendl_fd("': not a valid identifier", 2);
		}
		argv = argv->next;
	}
	return (i);
}

void	cmd_unset(t_parse *parse, char ***env)
{
	int		i;
	int		j;
	char	**arr;

	errno = 0;
	if (!parse->argv)
		return ;
	arr = (char **)malloc(sizeof(char *)
			* (get_env_len(parse->argv, *env) + 1));
	i = -1;
	j = 0;
	while ((*env)[++i])
	{
		if (!(is_in_list((*env)[i], parse->argv)))
			arr[j++] = (*env)[i];
		else
			free((*env)[i]);
	}
	arr[j] = 0;
	free(*env);
	*env = arr;
}
