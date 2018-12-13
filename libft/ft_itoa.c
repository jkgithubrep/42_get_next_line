/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:24:06 by jkettani          #+#    #+#             */
/*   Updated: 2018/11/28 14:53:02 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_digit(int n)
{
	size_t	count;
	long	nb;

	count = 1;
	nb = n;
	nb = (nb < 0) ? -nb : nb;
	while (nb >= 10)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	size_t	count;
	char	*str;
	int		neg;
	long	nb;

	neg = (n < 0) ? 1 : 0;
	count = nb_digit(n);
	if (!(str = (char *)ft_strnew(count + neg)))
		return (NULL);
	nb = n;
	nb = (nb < 0) ? -nb : nb;
	if (neg)
		str[0] = '-';
	while (count > 0)
	{
		str[count + neg - 1] = (nb % 10) + '0';
		nb /= 10;
		count--;
	}
	return (str);
}
