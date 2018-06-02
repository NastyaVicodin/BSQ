/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_head.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:11:09 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/07 13:11:09 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_HEAD_H
# define BSQ_HEAD_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct	s_mapstruct
{
	int			isvalid;
	int			x;
	int			y;
}				t_mapstruct;

typedef	struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_square
{
	t_coord		top_left_coord;
	t_coord		bot_right_coord;
	int			width;
}				t_square;

typedef struct	s_bounds
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
}				t_bounds;

void			ft_print_square(t_square square, char *map);
char			**ft_get_array_map(char *map);
t_coord			create_new_coord(int x, int y);
char			*ft_first_row(char *str);
char			*ft_cut_vals(char *str);
void			ft_map_error();
void			ft_putchar(char c);
void			ft_putstr(char *str);
char			*ft_strdup(char *src, int extra);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strncat(char *dest, char *src, int nb);
char			*ft_read_input(void);
char			*ft_read_from_file(char *str);
char			**ft_make_array(char *str);
int				ft_verify_char(char *map, char *vals);
int				ft_is_enough_lines(char **array_map, int count_rows);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
t_mapstruct		ft_is_valid_shape(char **c);
char			**ft_map_check(char *map);
int				ft_get_obs_count(char **array_map, char *map, t_mapstruct mpst);
t_coord			*ft_get_coord(char **map, char obs, int size, t_mapstruct mpst);
int				ft_launch_map(char *map);
t_bounds		ft_check_bound(t_coord *array_coords, int i, int j);
t_bounds		ft_find(t_bounds bds, t_coord *arr_c, t_mapstruct mps, int obs);
t_square		ft_make_square(t_bounds bds, int width, t_square old_sqr);
t_square		ft_find_big_square(t_coord *arr_c, int obs, t_mapstruct mp);
#endif
