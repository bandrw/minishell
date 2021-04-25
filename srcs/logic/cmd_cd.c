/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:56:58 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/24 19:56:59 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char **argv, char **env)
{
	if (argv[0])
	{
		chdir(argv[0]);
		if (errno)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			ft_putstr_fd(argv[0], 2);
			ft_putstr_fd(": ", 2);
			ft_putendl_fd(strerror(errno), 2);
			errno = 0;
		}
	}
}
