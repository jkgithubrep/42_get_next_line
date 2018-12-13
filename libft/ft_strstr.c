/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:14:57 by jkettani          #+#    #+#             */
/*   Updated: 2018/11/28 14:48:42 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;

	if (*s2 == 0)
		return ((char *)s1);
	while (*s1)
	{
		if (*s1 == *s2)
		{
			i = 1;
			while (s1[i] == s2[i] && s1[i])
				i++;
			if (s2[i] == 0)
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
