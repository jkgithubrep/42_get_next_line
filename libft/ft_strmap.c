/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:51:08 by jkettani          #+#    #+#             */
/*   Updated: 2018/12/06 11:27:22 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*s2;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	s2 = (char *)ft_memalloc(ft_strlen(s) + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s[i] && f)
	{
		s2[i] = f(s[i]);
		i++;
	}
	s2[i] = 0;
	return (s2);
}
