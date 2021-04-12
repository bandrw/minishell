/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:29:30 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/30 16:29:32 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l;

	l = 0;
	while (*dst != '\0' && dstsize > 0)
	{
		dst++;
		dstsize--;
		l++;
	}
	while (*src != '\0' && dstsize > 1)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
		l++;
	}
	if (dstsize != 0)
		*dst = '\0';
	while (*src != '\0')
	{
		src++;
		l++;
	}
	return (l);
}
