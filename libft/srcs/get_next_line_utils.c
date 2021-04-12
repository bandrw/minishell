/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:42:03 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/12 17:42:06 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	tmp_lstadd_back(t_list **lst, void *data)
{
	t_list	*list;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!data || !new)
	{
		ft_lstclear(lst, free);
		if (new)
			free(new);
		return (-1);
	}
	new->content = data;
	new->next = NULL;
	if (!*lst)
		*lst = new;
	else
	{
		list = *lst;
		while (list->next)
			list = list->next;
		list->next = new;
	}
	return (0);
}

size_t	get_list_len(t_list *list)
{
	size_t	l;

	l = 0;
	while (list)
	{
		l += ft_strlen((char *)list->content);
		list = list->next;
	}
	return (l);
}
