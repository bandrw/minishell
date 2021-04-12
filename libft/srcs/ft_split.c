/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:43:28 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/30 23:43:29 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_arr_length(char const *s, char c)
{
	size_t	l;

	l = 0;
	while (*s != '\0' && *s == c)
		s++;
	if (*s == '\0')
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
			if (*s != '\0')
				l++;
			s--;
		}
		s++;
	}
	return (l + 1);
}

static size_t	get_next_length(char const *s, char c)
{
	size_t	l;

	l = 0;
	while (*s != '\0' && *s != c)
	{
		l++;
		s++;
	}
	return (l);
}

static char	**destroy_array(char **arr, size_t len)
{
	while (len > 0)
	{
		len--;
		free(arr[len]);
	}
	free(arr);
	return (0);
}

int	array_alloc(const char *s, char c, char ***arr)
{
	if (!s)
		return (1);
	*arr = (char **)malloc(sizeof(char *) * (get_arr_length(s, c) + 1));
	if (!*arr)
		return (2);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	next_length;
	size_t	i;

	if (array_alloc(s, c, &arr))
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			next_length = get_next_length(s, c);
			arr[i] = (char *)malloc(sizeof(char) * (next_length + 1));
			if (arr[i])
				ft_strlcpy(arr[i], s, next_length + 1);
			else
				return (destroy_array(arr, i));
			i++;
			s += next_length;
		}
	}
	arr[i] = NULL;
	return (arr);
}
