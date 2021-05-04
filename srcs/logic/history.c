/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:31:54 by kfriese           #+#    #+#             */
/*   Updated: 2021/05/04 03:31:55 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	history_add(t_history *history, char *command_line)
{
	if (history->current < history->size)
	{
		history->content[history->current] = ft_strdup(command_line);
		history->current++;
	}
}
