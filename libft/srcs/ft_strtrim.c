/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:02:50 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/30 23:02:52 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	l;

	if (!(s1 && set))
		return (NULL);
	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	l = ft_strlen(s1);
	if (l > 0)
		while (ft_strchr(set, s1[l - 1]))
			l--;
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (str)
		ft_strlcpy(str, s1, l + 1);
	return (str);
}
