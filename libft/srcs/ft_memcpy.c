/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:43:23 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/29 14:43:24 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;

	if (!(dst && src))
		return (dst);
	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	while (n > 0)
	{
		*dst_p = *src_p;
		dst_p++;
		src_p++;
		n--;
	}
	return (dst);
}
