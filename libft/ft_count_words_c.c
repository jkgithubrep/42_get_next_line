/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:55:52 by jkettani          #+#    #+#             */
/*   Updated: 2018/12/09 15:12:51 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_count_words_c(char const *str, char c)
{
	size_t	nb;

	nb = 0;
	if (!str)
		return (0);
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			nb++;
			while (*str && *str != c)
				str++;
		}
	}
	return (nb);
}
