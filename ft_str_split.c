/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:06:07 by piquerue          #+#    #+#             */
/*   Updated: 2016/11/25 11:15:50 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_strsub(char const *s, unsigned int rem, size_t len)
{
	char	*str;

	str = ft_strnew(len);
	if (!s || !str)
		return (NULL);
	if (str)
	{
		while (rem--)
			++s;
		ft_strncpy(str, s, len);
		str[len] = 0;
	}
	return (str);
}

int			ft_nbword(char const *s, char c)
{
	int		i;
	int		isword;

	i = 0;
	isword = 0;
	while (*s)
	{
		if (isword == 0 && *s != c)
		{
			isword = 1;
			++i;
		}
		else if (isword == 1 && *s == c)
			isword = 0;
		++s;
	}
	return (i);
}

int			ft_length(char const *s, char c)
{
	int		length;

	length = 0;
	while (*s && *s != c)
	{
		++s;
		++length;
	}
	return (length);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i;
	int		nbword;

	if (!s)
		return (0);
	nbword = ft_nbword(s, c);
	tab = (char **)malloc(sizeof(char *) * (nbword + 1));
	if (!tab)
		return (0);
	i = 0;
	while (nbword--)
	{
		while (*s && *s == c)
			++s;
		tab[i] = ft_strsub(s, 0, ft_length(s, c));
		if (!tab[i])
			return (0);
		s = s + ft_length(s, c);
		++i;
	}
	tab[i] = 0;
	return (tab);
}
