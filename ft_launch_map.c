/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 22:52:32 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/09 22:52:34 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

char		**ft_get_array_map(char *map)
{
	char			**array_map;

	if (map == 0)
		return (0);
	if (ft_map_check(map))
		array_map = ft_map_check(map);
	else
		return (0);
	return (array_map);
}

t_square	ft_map_processing(char **array_map, char *map, t_mapstruct mapstr)
{
	int				obstacles;
	char			*vals;
	t_coord			*arr_coord;
	t_square		square;

	vals = ft_first_row(map);
	vals = ft_cut_vals(vals);
	obstacles = ft_get_obs_count(array_map, map, mapstr);
	arr_coord = ft_get_coord(array_map, vals[1], obstacles, mapstr);
	square = ft_find_big_square(arr_coord, obstacles, mapstr);
	return (square);
}

void		ft_check_square(t_square square, char **array_map, char *map)
{
	int				i;

	i = 0;
	if (square.width == 0)
	{
		while (array_map[i] != 0)
		{
			ft_putstr(array_map[i]);
			ft_putstr("\n");
			i++;
		}
	}
	else
		ft_print_square(square, map);
}

int			ft_launch_map(char *map)
{
	char			**array_map;
	t_mapstruct		mapstruct;
	t_square		square;

	square.width = 0;
	square.top_left_coord.x = 0;
	square.top_left_coord.y = 0;
	square.bot_right_coord.x = 0;
	square.bot_right_coord.x = 0;
	array_map = ft_get_array_map(map);
	if (array_map != 0)
	{
		mapstruct = ft_is_valid_shape(array_map);
		if (mapstruct.isvalid == 0)
			return (0);
		square = ft_map_processing(array_map, map, mapstruct);
		ft_check_square(square, array_map, map);
		return (1);
	}
	return (0);
}
