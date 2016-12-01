/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:47:00 by piquerue          #+#    #+#             */
/*   Updated: 2016/11/25 09:53:29 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t				ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void				*ft_memset(void *ptr, int value, size_t size)
{
	char			*pt;

	pt = (char *)ptr;
	while (size--)
		*pt++ = (char)value;
	return (ptr);
}

char				*ft_strncpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	ft_memset(dest, 0, size);
	while (0 < size && src[i])
	{
		dest[i] = src[i];
		--size;
		++i;
	}
	return (dest);
}

void				*ft_memmalloc(size_t size)
{
	void			*mem;

	mem = malloc(size);
	return ((mem == NULL) ? NULL : ft_memset(mem, 0, size));
}

char				*ft_strnew(size_t size)
{
	return ((char *)ft_memmalloc(++size));
}
