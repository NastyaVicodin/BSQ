/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_big_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 19:27:30 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/10 19:27:31 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

t_square	ft_calc_square(int *int_variables, t_bounds bounds, t_square square)
{
	int_variables[3] = bounds.y2 - bounds.y1 - 1;
	if (int_variables[2] >= int_variables[3])
		square = ft_make_square(bounds, int_variables[3], square);
	else if (int_variables[2] < int_variables[3])
		square = ft_make_square(bounds, int_variables[2], square);
	return (square);
}

t_square	ft_find_big_square(t_coord *arr_c, int obs, t_mapstruct mp)
{
	int			int_variables[4];
	t_bounds	bounds;
	t_square	square;

	int_variables[0] = 0;
	int_variables[1] = 1;
	square.width = 0;
	square.top_left_coord.x = 0;
	square.top_left_coord.y = 0;
	square.bot_right_coord.x = 0;
	square.bot_right_coord.x = 0;
	while (int_variables[0] < obs - 1)
	{
		while (int_variables[1] < obs)
		{
			bounds = ft_check_bound(arr_c, int_variables[0], int_variables[1]);
			int_variables[2] = bounds.x2 - bounds.x1 - 1;
			bounds = ft_find(bounds, arr_c, mp, obs);
			square = ft_calc_square(int_variables, bounds, square);
			++int_variables[1];
		}
		++int_variables[0];
		int_variables[1] = int_variables[0] + 1;
	}
	return (square);
}
