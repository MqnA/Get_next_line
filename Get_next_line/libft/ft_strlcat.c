/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:11:39 by mavagner          #+#    #+#             */
/*   Updated: 2016/11/09 19:19:07 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	buff_size;

	i = 0;
	while (dst[i] && i < size)
		i++;
	buff_size = i;
	while (src[i - buff_size] && i < size - 1)
	{
		dst[i] = src[i - buff_size];
		i++;
	}
	if (buff_size < size)
		dst[i] = '\0';
	return (buff_size + ft_strlen(src));
}
