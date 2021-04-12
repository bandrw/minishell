/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:07:37 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/29 16:07:39 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;

	if (!(dst && src))
		return (dst);
	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	if (src_p > dst_p)
	{
		while (len-- > 0)
		{
			*dst_p = *src_p;
			dst_p++;
			src_p++;
		}
	}
	else if (src_p < dst_p)
	{
		while (len-- > 0)
			*(dst_p + len) = *(src_p + len);
	}
	return (dst);
}
