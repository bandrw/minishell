/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:51:12 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/30 21:51:13 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (l < start)
		return (ft_strdup(""));
	if (l < start + len)
	{
		str = (char *)malloc(sizeof(char) * (l - start + 1));
		if (str)
			ft_strlcpy(str, s + start, l - start + 1);
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
		ft_strlcpy(str, s + start, len + 1);
	return (str);
}
