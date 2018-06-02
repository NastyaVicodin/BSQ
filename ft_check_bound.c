/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bound.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprypesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 18:51:35 by vprypesh          #+#    #+#             */
/*   Updated: 2017/10/10 18:51:35 by vprypesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

t_bounds	ft_check_bound(t_coord *array_coords, int i, int j)
{
	t_bounds res;

	if (array_coords[i].x > array_coords[j].x)
	{
		res.x2 = array_coords[i].x;
		res.x1 = array_coords[j].x;
	}
	else
	{
		res.x2 = array_coords[j].x;
		res.x1 = array_coords[i].x;
	}
	if (array_coords[i].y > array_coords[j].y)
	{
		res.y2 = array_coords[i].y;
		res.y1 = array_coords[j].y;
	}
	else
	{
		res.y2 = array_coords[j].y;
		res.y1 = array_coords[i].y;
	}
	return (res);
}
