/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:56:58 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/24 19:56:59 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_cd(t_list *argv, char ***env)
{
	char *buf;

	if (argv->content)
	{
		chdir(argv->content);
		if (errno)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			ft_putstr_fd(argv->content, 2);
			ft_putstr_fd(": ", 2);
			ft_putendl_fd(strerror(errno), 2);
			errno = 0;
		}
		else
		{
			buf = (char*)malloc(sizeof(char) * 1024);
			insert_env("PWD", ft_strjoin("PWD=", getcwd(buf, 1024)), env);
		}
	}
}
