/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprypesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:02:25 by vprypesh          #+#    #+#             */
/*   Updated: 2017/10/09 18:02:25 by vprypesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

t_coord	create_new_coord(int x, int y)
{
	struct s_coord new_coord;

	new_coord.x = x;
	new_coord.y = y;
	return (new_coord);
}

t_coord	*ft_add_frame1(t_coord *arr_coord, int k, t_mapstruct mapstr, int size)
{
	int i;

	i = 0;
	while (k < size - mapstr.y)
	{
		arr_coord[k] = create_new_coord(-1, i);
		i++;
		k++;
	}
	i = 0;
	while (k < size)
	{
		arr_coord[k] = create_new_coord(i, -1);
		i++;
		k++;
	}
	return (arr_coord);
}

t_coord	*ft_add_frame(t_coord *arr_coord, int k, t_mapstruct mapstr, int size)
{
	int i;

	i = 0;
	while (k < size - (mapstr.x) * 2 - mapstr.y)
	{
		arr_coord[k] = create_new_coord(mapstr.x, i);
		k++;
		i++;
	}
	i = 0;
	while (k < size - mapstr.y - mapstr.x)
	{
		arr_coord[k] = create_new_coord(i, mapstr.y);
		i++;
		k++;
	}
	return (ft_add_frame1(arr_coord, k, mapstr, size));
}

t_coord	*ft_get_coord(char **map, char obs, int size, t_mapstruct mapstr)
{
	struct s_coord	*arr_coord;
	int				i;
	int				j;
	int				k;

	arr_coord = malloc(sizeof(t_coord) * size);
	i = 0;
	j = 0;
	k = 0;
	while (map[i])
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == obs)
			{
				arr_coord[k] = create_new_coord(j, i);
				k++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	arr_coord = ft_add_frame(arr_coord, k, mapstr, size);
	return (arr_coord);
}

int		ft_get_obs_count(char **array_map, char *map, t_mapstruct mapstr)
{
	int		i;
	int		j;
	int		k;
	char	*vals;
	char	obstacle;

	i = 0;
	j = 0;
	k = 0;
	vals = ft_first_row(map);
	vals = ft_cut_vals(vals);
	obstacle = vals[1];
	while (array_map[i])
	{
		while (array_map[i][j] != '\0')
		{
			if (array_map[i][j] == obstacle)
				k++;
			j++;
		}
		j = 0;
		i++;
	}
	return (k + (mapstr.x + mapstr.y) * 2);
}
