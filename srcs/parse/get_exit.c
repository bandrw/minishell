/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:38:56 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/27 16:38:59 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_exit(t_parse *parse, char *str)
{
	parse->command_id = CMD_EXIT;
	parse->argv = ft_split(str + 4, ' ');
}
