/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetras_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:32:10 by piquerue          #+#    #+#             */
/*   Updated: 2016/11/25 14:35:25 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_tab(t_tetras *elem)
{
	int		i;
	int		j;
	char	**tab;

	tab = elem->points;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		if (j != 4)
			return (1);
		i++;
	}
	if (i != 4)
		return (i);
	return (0);
}

int			ft_check_real_tetras(t_tetras *elem)
{
	int		i;
	int		count;
	int		j;

	i = -1;
	count = 0;
	while (elem->points[++i])
	{
		j = -1;
		while (elem->points[i][++j])
		{
			if (elem->points[i][j] == '#')
			{
				if (j - 1 >= 0)
					count += (elem->points[i][j - 1] == '#') ? 1 : 0;
				if (j + 1 < 4)
					count += (elem->points[i][j + 1] == '#') ? 1 : 0;
				if (i - 1 >= 0)
					count += (elem->points[i - 1][j] == '#') ? 1 : 0;
				if (i + 1 < 4)
					count += (elem->points[i + 1][j] == '#') ? 1 : 0;
			}
		}
	}
	return ((count < 6) ? 1 : 0);
}

int			ft_count_dieses(t_tetras *elem)
{
	char	**tetra;
	int		i;
	int		nb;
	int		j;

	nb = 0;
	i = -1;
	tetra = elem->points;
	while (tetra[++i])
	{
		j = -1;
		while (tetra[i][++j])
			if (tetra[i][j] == '#')
				nb++;
		if (nb > 4)
			return (-1);
	}
	return ((nb == 4) ? 1 : -1);
}

int			ft_check_carac(t_tetras *elem)
{
	int		i;
	char	*tetra;
	int		count;

	count = 0;
	tetra = elem->str;
	i = 0;
	while (tetra[i])
	{
		if (tetra[i] != '.' && tetra[i] != '#' &&
				tetra[i] != '\n' && tetra[i] != '\0')
			count++;
		i++;
	}
	return (count);
}

int			ft_tetras_is_valid(t_tetras *elem)
{
	if (ft_check_tab(elem) != 0)
		return (0);
	if (ft_count_dieses(elem) == -1)
		return (0);
	if (ft_check_real_tetras(elem) != 0)
		return (0);
	if (ft_check_carac(elem) > 0)
		return (0);
	if (ft_check_size(elem) == -1)
		return (0);
	return (1);
}
