/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:19:51 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/30 20:19:52 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	size_t			total_size;
	unsigned char	*tmp;

	total_size = count * size;
	p = malloc(total_size);
	if (p)
	{
		tmp = (unsigned char *)p;
		while (total_size > 0)
		{
			*tmp = 0;
			tmp++;
			total_size--;
		}
	}
	return (p);
}
