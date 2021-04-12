/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:22:17 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/30 18:22:22 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	if (!s)
		return (NULL);
	tmp = NULL;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			tmp = (char *)s;
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (tmp);
}
