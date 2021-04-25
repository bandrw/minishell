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

void	ft_export(char **argv, char **env)
{
	int		i;
	char	**pair;

	i = -1;
	while (argv[++i])
	{
		pair = ft_split(argv[i], '=');
		printf("Export: %s will be %s\n", pair[0], pair[1]);
	}
}
