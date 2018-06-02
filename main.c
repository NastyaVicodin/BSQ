/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:56:52 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/09 16:56:55 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

void	ft_map_error(void)
{
	write(2, "map error", 9);
	ft_putstr("\n");
}

void	ft_print_square(t_square square, char *map)
{
	char		**array_map;
	char		*vals;
	int			int_values[2];

	int_values[0] = 0;
	int_values[1] = 0;
	vals = ft_first_row(map);
	vals = ft_cut_vals(vals);
	array_map = ft_get_array_map(map);
	while (array_map[int_values[0]] != 0)
	{
		while (array_map[int_values[0]][int_values[1]] != '\0')
		{
			if (square.top_left_coord.x <= int_values[1] &&
				int_values[1] <= square.bot_right_coord.x &&
				square.top_left_coord.y <= int_values[0] &&
				int_values[0] <= square.bot_right_coord.y)
				array_map[int_values[0]][int_values[1]] = vals[2];
			++int_values[1];
		}
		int_values[1] = 0;
		ft_putstr(array_map[int_values[0]]);
		ft_putstr("\n");
		++int_values[0];
	}
}

void	ft_map_from_file(char *file, char *map)
{
	if (ft_read_from_file(file) == 0)
		ft_map_error();
	else
	{
		map = ft_read_from_file(file);
		if (ft_launch_map(map) == 0)
			ft_map_error();
	}
}

int		main(int argc, char **argv)
{
	char			*map;
	int				i;

	i = 1;
	if (argc == 1)
	{
		map = ft_read_input();
		if (ft_launch_map(map) == 0)
		{
			ft_map_error();
			return (0);
		}
	}
	if (argc > 1)
	{
		while (argv[i] != 0)
		{
			ft_map_from_file(argv[i], map);
			if (i != argc - 1)
				ft_putstr("\n");
			++i;
		}
	}
	return (0);
}
