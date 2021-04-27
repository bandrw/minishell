/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:31:34 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/27 16:31:37 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_pwd_env(t_parse *parse, int id)
{
	if (id == 3)
		parse->command_id = CMD_PWD;
	else
		parse->command_id = CMD_ENV;
	parse->argv = 0;
}
