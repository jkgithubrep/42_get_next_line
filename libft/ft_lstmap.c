/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:06:48 by jkettani          #+#    #+#             */
/*   Updated: 2018/12/09 15:35:58 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2;
	t_list	*lst2_begin;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = NULL;
	lst2_begin = NULL;
	tmp = f(lst);
	if (!(lst2 = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	lst2_begin = lst2;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(lst2->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		lst = lst->next;
		lst2 = lst2->next;
	}
	return (lst2_begin);
}
