/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:04:46 by mavagner          #+#    #+#             */
/*   Updated: 2016/11/11 17:57:31 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len2;

	i = 0;
	if (!little[i])
		return ((char *)big);
	len2 = ft_strlen(little);
	while (big[i] && len-- >= len2)
	{
		if (ft_memcmp(big + i, little, len2) == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
