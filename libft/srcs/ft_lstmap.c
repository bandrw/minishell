/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:49:24 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/31 17:49:25 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_item;
	t_list	*list;

	list = 0;
	while (lst)
	{
		new_list_item = ft_lstnew((*f)(lst->content));
		if (new_list_item)
			ft_lstadd_back(&list, new_list_item);
		else
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (list);
}
