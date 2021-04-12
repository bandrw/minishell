/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:46:07 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/30 18:46:09 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!(haystack && needle))
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (len > 0)
	{
		i = 0;
		while (haystack[i] != '\0' && haystack[i] == needle[i] && i < len)
		{
			i++;
		}
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
