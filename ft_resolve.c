/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:30:11 by piquerue          #+#    #+#             */
/*   Updated: 2016/11/25 14:31:45 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			can_place_elem(t_map **args, t_tetras *tetras)
{
	t_map	*map;

	map = *args;
	if (tetras->width > map->width || tetras->height > map->width)
		return (-1);
	return (1);
}

char		**place_item(char **cpy, int x, int y, t_tetras *t)
{
	int		i;

	i = -1;
	while (++i < 4)
		cpy[x + t->positions[i][0]][y + t->positions[i][1]] = t->c;
	return (cpy);
}

int			can_place(char **str, t_point *pt, t_tetras *t, int width)
{
	int		i;

	i = 0;
	if (!t)
		return (-1);
	if (t->width > width || t->height > width)
		return (-1);
	while (i < 4)
	{
		if ((pt->x + t->positions[i][0]) < 0)
			return (-1);
		if ((pt->y + t->positions[i][1]) < 0)
			return (-1);
		if ((pt->x + t->positions[i][0]) >= width)
			return (-1);
		if ((pt->y + t->positions[i][1]) >= width)
			return (-1);
		if (str[pt->x + t->positions[i][0]][pt->y + t->positions[i][1]])
			if (str[pt->x + t->positions[i][0]][pt->y + t->positions[i][1]] !=
			'.')
				return (-1);
		i++;
	}
	return (1);
}

char		**clear_chain(char **str, t_tetras *elem, int width)
{
	int		i;
	int		j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < width)
		{
			if (str[i][j] == elem->c)
				str[i][j] = '.';
			j++;
		}
		i++;
	}
	return (str);
}

int			resolve(t_map *map, t_tetras *tetras)
{
	char	**cpy;
	int		x;
	int		y;

	if (ft_check_solvable(map, tetras) != 0)
		return (ft_check_solvable(map, tetras));
	x = map->pt->x;
	y = map->pt->y + 1;
	cpy = clear_chain(map->map, tetras, map->width);
	if (can_place(cpy, map->pt, tetras, map->width) == 1)
	{
		map->map = place_item(cpy, map->pt->x, map->pt->y, tetras);
		ft_map_correct_pos(map, 0, 0);
		if (resolve(map, tetras->next) == -1)
		{
			ft_map_correct_pos(map, x, y);
			return (resolve(map, tetras));
		}
	}
	else
	{
		ft_map_correct_pos(map, x, y);
		return (resolve(map, tetras));
	}
	return (1);
}
