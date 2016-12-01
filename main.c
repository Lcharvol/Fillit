/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:17:19 by piquerue          #+#    #+#             */
/*   Updated: 2016/11/25 11:57:33 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_list_push_back(t_tetras **begin, char *str)
{
	t_tetras	*elem;
	int			i;

	i = 0;
	elem = *begin;
	if (elem)
	{
		++i;
		while (elem->next)
		{
			++i;
			elem = elem->next;
		}
		elem->next = ft_create_elem(str, i);
	}
	else
		*begin = ft_create_elem(str, i);
}

int				check_last_entry(const char *str)
{
	int			i;

	i = -1;
	while (str[++i])
		;
	if (i < 20)
		return (-1);
	if (str[20] != '\n' && str[20] != '\0')
		return (-1);
	if (i != 21 && i != 20)
		return (-1);
	return (1);
}

int				read_f(char **argv, t_tetras **tetras)
{
	int			file[4];
	t_tetras	*elem;
	char		buffer[22];

	file[1] = 0;
	file[0] = open(argv[1], O_RDONLY);
	while ((file[2] = read(file[0], buffer, 21)) != 0)
	{
		file[3] = file[2];
		buffer[file[2]] = 0;
		buffer[21] = 0;
		if (check_last_entry(buffer) != 1 || ++file[1] > 26)
			return (-1);
		ft_list_push_back(tetras, buffer);
	}
	elem = *tetras;
	if (!elem || file[3] != 20)
		return (-1);
	while (elem)
	{
		if (ft_tetras_is_valid(elem) == 0)
			return (-1);
		elem = elem->next;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_tetras	*tetras;
	t_map		*map;
	int			i;

	i = -1;
	tetras = NULL;
	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (read_f(argv, &tetras) == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	map = ft_create_elem_map(&tetras, size_map_min(&tetras), 0, 0);
	while (resolve(map, tetras) == -1)
		map = ft_create_elem_map(&tetras, map->width + 1, 0, 0);
	while (++i < map->width)
		ft_putendl(map->map[i]);
	return (1);
}
