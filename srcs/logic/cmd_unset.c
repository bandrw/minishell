/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:41:58 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/27 23:41:59 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_in_list(char *str, t_list *list)
{
	while (list)
	{
		if (ft_strncmp(str, list->content, ft_strlen(list->content)) == 0)
			return (1);
		list = list->next;
	}
	return (0);
}

void	cmd_unset(t_parse *parse, char ***env)
{
	int		i;
	int		j;
	char	**arr;
	int		fd_out;

	fd_out = get_fd_out(parse);
	if (fd_out != 1)
		close(fd_out);
	if (!parse->argv)
		return ;
	i = 0;
	while ((*env)[i])
		i++;
	arr = (char**)malloc(sizeof(char*) * (i + 1 - ft_lstsize(parse->argv)));
	i = -1;
	j = 0;
	while ((*env)[++i])
	{
		if (!is_in_list((*env)[i], parse->argv))
			arr[j++] = (*env)[i];
	}
	arr[j] = 0;
	*env = arr;
}
