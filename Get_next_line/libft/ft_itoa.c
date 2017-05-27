/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:29:35 by mavagner          #+#    #+#             */
/*   Updated: 2016/11/12 14:32:27 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char		*nbr;
	int			i;
	long int	tmp;

	tmp = n;
	i = 1;
	while (n /= 10)
		i++;
	i += (tmp < 0) ? 1 : 0;
	if ((nbr = ft_strnew(i)) == NULL)
		return (NULL);
	if (tmp < 0)
	{
		nbr[0] = '-';
		tmp *= -1;
	}
	if (tmp == 0)
		nbr[0] = '0';
	while (tmp)
	{
		nbr[--i] = '0' + tmp % 10;
		tmp = tmp / 10;
	}
	return (nbr);
}
