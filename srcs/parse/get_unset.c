/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:38:02 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/27 16:38:04 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_unset(t_parse *parse, char *str)
{
	parse->command_id = CMD_UNSET;
	//parse->argv = ft_split(str + 5, ' ');
}
