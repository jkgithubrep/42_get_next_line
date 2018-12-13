/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:38:34 by jkettani          #+#    #+#             */
/*   Updated: 2018/12/09 16:55:35 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		**clean_tb(char **tb, int last)
{
	int		i;

	i = 0;
	while (i < last)
		free(tb[i++]);
	free(tb);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tb;
	int		i;

	if (!s)
		return (NULL);
	if (!(tb = (char **)malloc(sizeof(*tb) * (ft_count_words_c(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!(tb[i] = ft_strdup_c(s, c)))
				return (clean_tb(tb, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tb[i] = NULL;
	return (tb);
}
