/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:13:53 by jkettani          #+#    #+#             */
/*   Updated: 2018/11/28 14:47:53 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	count;

	count = 0;
	if (*s2 == 0)
		return ((char *)s1);
	while (count < len && *s1)
	{
		if (*s1 == *s2)
		{
			i = 1;
			while (s1[i] == s2[i] && s1[i] && count + i < len)
				i++;
			if (s2[i] == 0)
				return ((char *)s1);
		}
		s1++;
		count++;
	}
	return (NULL);
}
