/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:16:40 by mavagner          #+#    #+#             */
/*   Updated: 2016/11/13 18:34:39 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*fresh;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(fresh = ft_strdup(s)))
		return (NULL);
	while (*fresh == ' ' || *fresh == '\t' || *fresh == '\n')
		fresh++;
	i = ft_strlen(fresh) - 1;
	while (fresh[i] == ' ' || fresh[i] == '\t' || fresh[i] == '\n')
		i--;
	fresh[++i] = '\0';
	return (ft_strdup(fresh));
}
