/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:36:56 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/31 17:40:51 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*prev;

	list = *lst;
	while (list)
	{
		prev = list;
		list = list->next;
		if (del)
			(*del)(prev->content);
		free(prev);
	}
	*lst = NULL;
}
