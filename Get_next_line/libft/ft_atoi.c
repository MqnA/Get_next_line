/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:27:56 by mavagner          #+#    #+#             */
/*   Updated: 2016/11/13 17:46:02 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\r' || str[i] == '\f' || str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 - ('0' - str[i]);
		i++;
	}
	if (neg == 1)
		return (-nb);
	return (nb);
}
