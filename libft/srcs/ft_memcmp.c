/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:44:27 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/29 17:44:28 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_p;
	unsigned char	*s2_p;

	if (!(s1 && s2))
		return (0);
	s1_p = (unsigned char *)s1;
	s2_p = (unsigned char *)s2;
	while (n > 0)
	{
		if (*s1_p != *s2_p)
			return (*s1_p - *s2_p);
		s1_p++;
		s2_p++;
		n--;
	}
	return (0);
}
