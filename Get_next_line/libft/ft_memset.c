/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:53:16 by mavagner          #+#    #+#             */
/*   Updated: 2016/11/06 16:04:59 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *cc;

	cc = (unsigned char *)b;
	if (len == 0)
		return (b);
	while (len--)
	{
		*cc = (unsigned char)c;
		cc++;
	}
	return (b);
}
