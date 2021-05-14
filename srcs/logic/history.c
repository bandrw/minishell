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

static void	history_realloc(t_history *history)
{
	int		i;
	char	**arr;

	history->size = (int)(history->size * 1.5);
	printf("Realloc to %d\n", history->size);
	arr = (char **)malloc(sizeof(char *) * history->size);
	i = 0;
	while (i < history->current)
	{
		arr[i] = history->content[i];
		i++;
	}
	free(history->content);
	history->content = arr;
}

void	history_add(t_history *history, char *command_line)
{
	if (history->current >= history->size - 1)
		history_realloc(history);
	history->content[history->current] = ft_strdup(command_line);
	history->current++;
	printf("<%d>\n", history->current);
}
