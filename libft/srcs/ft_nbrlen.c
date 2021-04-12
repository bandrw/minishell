/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:11:45 by kfriese           #+#    #+#             */
/*   Updated: 2020/11/19 11:11:46 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int nbr)
{
	size_t	l;

	l = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			return (11);
		nbr = -nbr;
		l++;
	}
	while (nbr > 0)
	{
		l++;
		nbr = nbr / 10;
	}
	return (l);
}
