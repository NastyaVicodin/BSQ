/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprypesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 19:41:41 by vprypesh          #+#    #+#             */
/*   Updated: 2017/10/10 19:41:42 by vprypesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

t_square	ft_record_square(int width, t_bounds bds)
{
	t_square square;

	square.top_left_coord = create_new_coord(bds.x1 + 1, bds.y1 + 1);
	square.bot_right_coord = create_new_coord(bds.x1 + width, bds.y1 + width);
	square.width = width;
	return (square);
}

t_square	ft_make_square(t_bounds bds, int width, t_square old_square)
{
	t_square	square;
	int			ynew;
	int			xnew;

	xnew = bds.x1 + 1;
	ynew = bds.y1 + 1;
	if (old_square.width == width && old_square.top_left_coord.y == ynew &&
		old_square.top_left_coord.x > xnew)
		square = ft_record_square(width, bds);
	else if (old_square.width == width && old_square.top_left_coord.y > ynew)
		square = ft_record_square(width, bds);
	else if (old_square.width < width)
		square = ft_record_square(width, bds);
	else
		return (old_square);
	return (square);
}
