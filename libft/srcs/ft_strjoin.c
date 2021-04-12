/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:43:47 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/30 22:43:48 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	l1;
	size_t	l2;
	size_t	l3;

	if (!(s1 && s2))
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (str)
	{
		l3 = ft_strlcpy(str, s1, l1 + 1);
		ft_strlcat(str, s2, l3 + l2 + 1);
	}
	return (str);
}
