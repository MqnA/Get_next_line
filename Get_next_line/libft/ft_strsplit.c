/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:25:11 by mavagner          #+#    #+#             */
/*   Updated: 2016/11/13 18:38:04 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_count(char const *s, char c, int a)
{
	int i;

	i = 0;
	while (s[a] != c && s[a])
	{
		i++;
		a++;
	}
	return (i);
}

static int	size_tab(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			j++;
		}
		else
			i++;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		d;
	char	**tab;

	if (!s || !(tab = (char**)ft_memalloc(sizeof(char*) * size_tab(s, c) + 1)))
		return (NULL);
	tab[size_tab(s, c)] = NULL;
	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] != c)
		{
			d = 0;
			if ((tab[++j] = (char*)ft_memalloc(sizeof(char) * char_count(s, c,
				i) + 1)) == NULL)
				return (NULL);
			while (s[i] != c && s[i] != '\0')
				tab[j][d++] = s[i++];
		}
		else
			i++;
	}
	return (tab);
}
