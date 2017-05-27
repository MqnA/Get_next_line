/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:57:27 by mavagner          #+#    #+#             */
/*   Updated: 2016/11/06 16:08:22 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;

	len = ft_strlen(s1);
	str = ((char *)malloc(sizeof(char) * (len + 1)));
	if (!s1)
		return (NULL);
	if (str == NULL)
		return (str);
	ft_strcpy(str, s1);
	return (str);
}
