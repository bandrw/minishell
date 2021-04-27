/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
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
	int	i;

	i = -1;
	while (env[++i])
	{
		ft_putstr("declare -x ");
		ft_putendl_fd(env[i], 1);
	}
}

void	ft_export(t_list *argv, char **env)
{
	char	**pair;

	if (!argv)
		write_vars(env);
	else
	{
		while (argv)
		{
			pair = ft_split(argv->content, '=');
			if (pair[1])
				printf("Export: %s will be %s\n", pair[0], pair[1]);
			else
				printf("Export: %s (null)\n", pair[0]);
			argv = argv->next;
		}
	}
}
