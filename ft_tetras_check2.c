/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetras_check2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:35:39 by piquerue          #+#    #+#             */
/*   Updated: 2016/11/25 14:37:06 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_size(t_tetras *elem)
{
	int		i;

	i = 0;
	while (elem->str[i])
		i++;
	if (i != 21 && i != 20)
		return (-1);
	i = 0;
	while (elem->str[i])
	{
		if ((elem->str[i] == '\n' && ((i + 1) % 5) != 0) &&
				(elem->str[i] == '\n' && i != 20))
			return (-1);
		i++;
	}
	return (1);
}

int			ft_check_pos(int tab[4], int c)
{
	int		j;

	j = -1;
	while (++j)
		if (((tab[j] + 1) == c) || ((tab[j] + 5) == c))
			return (1);
	return (0);
}
