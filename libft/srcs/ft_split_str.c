//
// Created by Proteus Antigone on 5/4/21.
//

#include "libft.h"

static char	*ft_crt_word(char **str, size_t len_word, size_t i)
{
	str[i] = (char *)malloc(sizeof(char) * (len_word + 1));
	if (str[i] == NULL)
	{
		while (i > -1)
			free(str[i--]);
		free(str);
		return (NULL);
	}
	return (str[i]);
}

static size_t	ft_len_word(char const *s, char *c)
{
	size_t	len;

	len = 0;
	while (ft_strchr(c, *s) == 0 && *s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

static size_t	ft_word_count(char const *s, char *c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && ft_strchr(c, *s) != 0)
			s++;
		if (*s != '\0' && ft_strchr(c, *s) == 0)
			count++;
		while (*s != '\0' && ft_strchr(c, *s) == 0)
			s++;
	}
	return (count);
}

char	**ft_split_str(char *str, char *sep)
{
	char	**arr;
	size_t	word_count;
	size_t	len_word;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	word_count = ft_word_count(str, sep);
	arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (arr == NULL)
		return (NULL);
	while (*str && i < word_count)
	{
		while (*str != '\0' && ft_strchr(sep, *str) != 0)
			str++;
		len_word = ft_len_word(str, sep);
		arr[i] = ft_crt_word(arr, len_word, i);
		if (arr[i] == NULL)
			return (NULL);
		ft_strlcpy(arr[i++], str, len_word + 1);
		str = str + len_word;
	}
	arr[i] = 0;
	return (arr);
}
