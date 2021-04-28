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

char	*get_env(char *key, char **env)
{
	int l;

	while (*env)
	{
		l = ft_strlen(key);
		if (ft_strncmp(key, *env, l) == 0 && (*env)[l] == '=')
			return (*env + l + 1);
		env++;
	}
	return (0);
}
