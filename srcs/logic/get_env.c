/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:48:07 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/24 20:48:08 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(char *s, char **env)
{
	int l;

	while (*env)
	{
		l = ft_strlen(s);
		if (ft_strncmp(s, *env, l) == 0 && env[0][l] == '=')
			return (*env + l + 1);
		env++;
	}
	return (0);
}
