/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:32:49 by piquerue          #+#    #+#             */
/*   Updated: 2016/11/25 14:19:35 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			size_map_min(t_tetras **elem)
{
	int		nb;
	int		size;

	nb = ft_count_tetras(elem);
	size = 2;
	while (size * size < (nb * 4))
		++size;
	return (size);
}

t_map		*ft_create_elem_map(t_tetras **t, int w, int id, int fd)
{
	t_map	*elem;
	int		i;
	int		j;
	char	**map;

	i = -1;
	elem = (t_map *)malloc(sizeof(t_map));
	elem->id_tetras = id;
	elem->fd = fd;
	elem->pt = (t_point *)malloc(sizeof(t_point));
	elem->pt->x = 0;
	elem->pt->y = 0;
	elem->width = w;
	map = (char **)malloc(sizeof(char *) * w);
	while (++i < w)
	{
		map[i] = (char *)malloc(sizeof(char) * w);
		j = -1;
		while (++j < w)
			map[i][j] = '.';
	}
	elem->map = map;
	elem->tetras = t;:
	return (elem);
}

void		ft_map_correct_pos(t_map *elem, int x, int y)
{
	elem->pt->x = x;
	elem->pt->y = y;
}

int			ft_check_solvable(t_map *map, t_tetras *tetras)
{
	if (!tetras)
		return (1);
	if (map->pt->y >= map->width)
		ft_map_correct_pos(map, (map->pt->x + 1), 0);
	if (map->pt->x >= map->width)
		return (-1);
	return (0);
}
