/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:35:50 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/29 14:35:51 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_p;

	if (!s)
		return ;
	s_p = (unsigned char *)s;
	while (n > 0)
	{
		*s_p = 0;
		s_p++;
		n--;
	}
}
