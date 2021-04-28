/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:08:41 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/28 16:08:43 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_exit(t_parse *parse, char **str)
{
	char	*tmp;

	tmp = *str + 4;
	parse->command_id = CMD_EXPORT;
	ft_read_line(&tmp, parse);
}
