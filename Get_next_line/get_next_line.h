/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:37:42 by mavagner          #+#    #+#             */
/*   Updated: 2016/12/14 16:25:31 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MY_FD (*cpy)->my_fd
# define CPY (*cpy)->content
# define IF_LINE (*cpy)->if_line
# define BUFF_SIZE 1
# include "libft/libft.h"

typedef struct			s_next
{
	char				*content;
	int					my_fd;
	int					if_line;
	struct s_next		*next;
}						t_content;

int						get_next_line(const int fd, char **line);

#endif
