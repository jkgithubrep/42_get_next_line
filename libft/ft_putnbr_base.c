/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:15:18 by jkettani          #+#    #+#             */
/*   Updated: 2018/11/29 09:53:11 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int nbr, int base_size)
{
	long	n;
	char	*base;

	if (base_size >= 2 && base_size <= 16)
	{
		n = nbr;
		base = "0123456789ABCDEF";
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n >= base_size)
		{
			ft_putnbr_base(n / base_size, base_size);
			ft_putchar(base[n % base_size]);
		}
		else
			ft_putchar(base[n]);
	}
}
