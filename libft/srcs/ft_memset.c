/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:12:38 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/29 14:12:40 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_p;

	if (!b)
		return (b);
	b_p = (unsigned char *)b;
	while (len > 0)
	{
		*b_p = (unsigned char)c;
		b_p++;
		len--;
	}
	return (b);
}
