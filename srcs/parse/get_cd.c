/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:35:16 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/27 16:35:18 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_cd(t_parse *parse, char **str)
{
	char	*tmp;

	tmp = *str + 2;
	parse->command_id = CMD_CD;
	ft_read_line(&tmp, parse,0);
}

