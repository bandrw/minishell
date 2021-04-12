/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:13:22 by kfriese           #+#    #+#             */
/*   Updated: 2020/10/31 14:13:22 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_number_length(int nbr)
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

static void	positive_fill(char *str, int n, int l)
{
	str[l] = '\0';
	while (l > 0)
	{
		l--;
		str[l] = (char)(n % 10 + '0');
		n = n / 10;
	}
}

static void	negative_fill(char *str, int n, int l)
{
	str[l] = '\0';
	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return ;
	}
	n = -n;
	while (l > 1)
	{
		l--;
		str[l] = (char)(n % 10 + '0');
		n = n / 10;
	}
	str[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	l;

	l = get_number_length(n);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (str)
	{
		if (n == 0)
			ft_strlcpy(str, "0", 2);
		else if (n > 0)
			positive_fill(str, n, l);
		else
			negative_fill(str, n, l);
	}
	return (str);
}
