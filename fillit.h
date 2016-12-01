/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 07:23:16 by piquerue          #+#    #+#             */
/*   Updated: 2016/11/25 14:36:54 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/*
** Struct def...
*/
typedef struct		s_tetras
{
	int				id;
	char			*str;
	char			**points;
	struct s_tetras	*next;
	int				width;
	int				height;
	int				**positions;
	char			c;
}					t_tetras;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_map
{
	int				width;
	int				fd;
	struct s_point	*pt;
	int				id_tetras;
	char			**map;
	struct s_tetras	**tetras;
}					t_map;
/*
** Content of file  ft_put.c
*/
void				ft_putchar(const char c);
void				ft_putstr(const char *str);
void				ft_putendl(const char *str);
/*
** Content of file ft_str_utils.c
*/
size_t				ft_strlen(const char *str);
void				*ft_memset(void *ptr, int value, size_t size);
char				*ft_strncpy(char *dest, char const *src, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
/*
** Content of file ft_str_split.c
*/
char				*ft_strsub(char const *s, unsigned int rem, size_t len);
int					ft_nbword(char const *s, char c);
int					ft_length(char const *s, char c);
char				**ft_strsplit(char const *s, char c);
/*
** Content of file ft_elem_tetras.c
*/
int					ft_check_width(int **argv);
int					ft_check_height(int **argv);
int					ft_count_tetras(t_tetras **tetras);
int					**get_position_dieze(char **str);
t_tetras			*ft_create_elem(char *str, int id);
/*
** Content of file ft_tetras_check.c
*/
int					ft_check_tab(t_tetras *elem);
int					ft_check_real_tetras(t_tetras *elem);
int					ft_count_dieses(t_tetras *elem);
int					ft_check_carac(t_tetras *elem);
int					ft_tetras_is_valid(t_tetras *elem);
/*
** Content of file ft_tetras_check2.c
*/
int					ft_check_pos(int tab[4], int c);
int					ft_check_size(t_tetras *elem);
/*
** Content of file ft_elem_map.c
*/
int					size_map_min(t_tetras **elem);
t_map				*ft_create_elem_map(t_tetras **t, int w, int id, int fd);
void				ft_map_correct_pos(t_map *elem, int x, int y);
int					ft_check_solvable(t_map *map, t_tetras *tetras);
/*
** Content of file ft_resolve.c
*/
int					resolve(t_map *map, t_tetras *tetra);
int					can_place_elem(t_map **args, t_tetras *tetras);
char				**place_item(char **cpy, int x, int y, t_tetras *tetras);
int					can_place(char **str, t_point *pt, t_tetras *t, int w);
char				**clear_chain(char **str, t_tetras *elem, int width);

#endif
