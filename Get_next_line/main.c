/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:07:51 by mavagner          #+#    #+#             */
/*   Updated: 2016/12/09 17:56:16 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			main(int ac, char **av)
{
	int		i;
	char	*str;
	int		fd;

	i = 3;
	if (ac >= 2)
	{
		fd = open(av[1], O_RDONLY);
		if (get_next_line(fd, &str))
		{
			ft_putstr(str);
			get_next_line(fd, &str);
			ft_putstr(str);
			get_next_line(fd, &str);
			ft_putstr(str);
		}
	}
	return (0);
}
