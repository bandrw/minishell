/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:37:08 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/27 16:37:10 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_export(t_parse *parse, char *str)
{
	parse->command_id = CMD_EXPORT;
	parse->argv = ft_split(str + 6, ' ');
}
