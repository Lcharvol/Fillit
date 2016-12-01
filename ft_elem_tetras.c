/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_tetras.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:25:02 by piquerue          #+#    #+#             */
/*   Updated: 2016/11/25 11:01:33 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_check_width_tetras(int **argv)
{
	int			max;
	int			i;

	max = 0;
	i = -1;
	while (++i < 4)
		if (argv[i][1] > max)
			max = argv[i][1];
	return ((max == 0) ? 2 : ++max);
}

int				ft_check_height_tetras(int **argv)
{
	int			max;
	int			i;

	i = -1;
	max = 0;
	while (++i < 4)
		if (argv[i][0] > max)
			++max;
	return (++max);
}

int				**get_position_dieze(char **str)
{
	int			**pos;
	int			i;
	int			x;
	int			y;

	i = -1;
	pos = (int **)malloc(sizeof(int *) * 4);
	while (++i < 4 && (x = -1))
		pos[i] = (int *)malloc(sizeof(int) * 4);
	i = 0;
	while (str[++x] && (y = -1))
		while (str[x][++y])
			if (str[x][y] == '#')
			{
				if (++i == 5)
					return (pos);
				pos[i - 1][0] = x;
				pos[i - 1][1] = y;
			}
	while (--i >= 0)
	{
		pos[i][1] -= pos[0][1];
		pos[i][0] -= pos[0][0];
	}
	return (pos);
}

t_tetras		*ft_create_elem(char *str, int id)
{
	t_tetras	*elem;

	elem = (t_tetras *)malloc(sizeof(t_tetras));
	elem->id = id;
	elem->str = str;
	elem->points = ft_strsplit(str, '\n');
	elem->positions = get_position_dieze(elem->points);
	elem->width = ft_check_width_tetras(elem->positions);
	elem->height = ft_check_height_tetras(elem->positions);
	elem->c = 'A' + id;
	elem->next = NULL;
	return (elem);
}

int				ft_count_tetras(t_tetras **tetras)
{
	int			c;
	t_tetras	*elem;

	c = 0;
	elem = *tetras;
	while (elem)
	{
		++c;
		elem = elem->next;
	}
	return (c);
}
