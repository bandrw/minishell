/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:35:48 by kfriese           #+#    #+#             */
/*   Updated: 2020/11/03 16:35:49 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int	final_string_alloc(t_list **list, char **line)
{
	if (!*list)
		tmp_lstadd_back(list, ft_strdup(""));
	if (!line)
	{
		ft_lstclear(list, free);
		return (-1);
	}
	*line = (char *)malloc(sizeof(char) * (get_list_len(*list) + 1));
	if (!*line)
	{
		ft_lstclear(list, free);
		return (-1);
	}
	return (0);
}

static int	final_string(t_list **list, char **line)
{
	char	*tmp;
	t_list	*list_tmp;
	size_t	len;

	final_string_alloc(list, line);
	tmp = *line;
	list_tmp = *list;
	while (list_tmp)
	{
		len = ft_strlen((char *)list_tmp->content);
		ft_strlcpy(tmp, (char *)list_tmp->content, len + 1);
		tmp += len;
		list_tmp = list_tmp->next;
	}
	ft_lstclear(list, free);
	return (1);
}

static int	new_line_handle(char **new_line_p, t_list **list, char **line)
{
	char	*ptr;
	size_t	len;

	if (*new_line_p)
	{
		ptr = ft_strchr(*new_line_p + 1, '\n');
		if (ptr)
			len = ptr - (*new_line_p + 1);
		else
			len = ft_strlen(*new_line_p + 1);
		if (tmp_lstadd_back(list, ft_substr(*new_line_p + 1, 0, len)) == -1)
			return (0);
		*new_line_p = ft_strchr(*new_line_p + 1, '\n');
		if (*new_line_p)
		{
			if (final_string(list, line) == 1)
				return (1);
			*new_line_p = 0;
			return (1);
		}
	}
	return (0);
}

static int	iter_action(char **new_line_p, char *str, t_list **list,
				char **line)
{
	size_t	len;

	*new_line_p = ft_strchr(str, '\n');
	if (*new_line_p)
	{
		if (*new_line_p)
			len = *new_line_p - str;
		else
			len = ft_strlen(str);
		if (tmp_lstadd_back(list, ft_substr(str, 0, len)) == -1)
			return (-1);
		return (final_string(list, line));
	}
	if (tmp_lstadd_back(list, ft_strdup("")) == -1)
		return (-1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			r;
	int			bytes_read;
	t_list		*list;
	static char	*new_line_p;
	static char	str[BUFFER_SIZE + 1];

	list = 0;
	if (new_line_handle(&new_line_p, &list, line) == 1)
		return (1);
	bytes_read = read(fd, str, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		str[bytes_read] = '\0';
		r = iter_action(&new_line_p, str, &list, line);
		if (r == -1)
			return (-1);
		else if (r != 0)
			return (r);
		bytes_read = read(fd, str, BUFFER_SIZE);
	}
	if (final_string(&list, line) == 1)
		return (bytes_read);
	return (-1);
}
