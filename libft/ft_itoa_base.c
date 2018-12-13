/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:17:54 by jkettani          #+#    #+#             */
/*   Updated: 2018/11/28 18:40:34 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_digit_base(int n, int base_size)
{
	size_t	count;
	long	nb;

	count = 1;
	nb = n;
	nb = (nb < 0) ? -nb : nb;
	while (nb >= base_size)
	{
		count++;
		nb /= base_size;
	}
	return (count);
}

char			*ft_itoa_base(int n, int base_size)
{
	size_t	count;
	char	*str;
	char	*base;
	int		neg;
	long	nb;

	neg = (n < 0) ? 1 : 0;
	count = nb_digit_base(n, base_size);
	if (!(str = (char *)ft_strnew(count + neg)))
		return (NULL);
	base = "0123456789ABCDEF";
	nb = n;
	nb = (nb < 0) ? -nb : nb;
	if (neg)
		str[0] = '-';
	while (count > 0)
	{
		str[count + neg - 1] = base[nb % base_size];
		nb /= base_size;
		count--;
	}
	return (str);
}
