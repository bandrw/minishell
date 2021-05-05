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
	int		quote;

	tmp = *str + 4;
	quote = 0;
	while (ft_isspace(*tmp))
		tmp++;
	parse->command_id = CMD_EXIT;
	ft_read_line(&tmp, parse, &quote);
	*str = tmp;
}
