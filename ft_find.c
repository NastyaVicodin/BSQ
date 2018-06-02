/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprypesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 19:00:15 by vprypesh          #+#    #+#             */
/*   Updated: 2017/10/10 19:00:17 by vprypesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

t_bounds	bds_to_zero(t_bounds bds)
{
	bds.y1 = 0;
	bds.y2 = 0;
	bds.x1 = 0;
	bds.x2 = 0;
	return (bds);
}

t_bounds	ft_find(t_bounds bds, t_coord *arr_c, t_mapstruct mps, int obs)
{
	int k;
	int ytop_ybot[2];

	k = 0;
	ytop_ybot[0] = -1;
	ytop_ybot[1] = mps.y - 1;
	while (k < obs)
	{
		if (arr_c[k].x > bds.x1 && arr_c[k].x < bds.x2)
		{
			if (arr_c[k].y < bds.y1)
				ytop_ybot[0] = arr_c[k].y;
			if (arr_c[k].y >= bds.y1 && arr_c[k].y <= bds.y2)
				return (bds_to_zero(bds));
			if (arr_c[k].y > bds.y2)
			{
				ytop_ybot[1] = arr_c[k].y;
				break ;
			}
		}
		k++;
	}
	bds.y1 = ytop_ybot[0];
	bds.y2 = ytop_ybot[1];
	return (bds);
}
