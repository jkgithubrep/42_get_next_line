/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 11:21:19 by jkettani          #+#    #+#             */
/*   Updated: 2018/12/13 21:33:29 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_saved{
	char			*saved_buf;
	int				fd;
	struct s_saved	*next;
}					t_saved;

int					get_next_line(const int fd, char **line);

#endif
