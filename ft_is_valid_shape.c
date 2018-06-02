/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_shape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 23:55:23 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/07 23:55:24 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

t_mapstruct	ft_results(t_mapstruct res)
{
	if ((res.y > 0) && (res.x > 0))
		res.isvalid = 1;
	else
		res.isvalid = 0;
	return (res);
}

t_mapstruct	ft_is_valid_shape(char **c)
{
	int				i;
	int				prev;
	int				tmp;
	t_mapstruct		res;

	i = 0;
	tmp = 0;
	prev = ft_strlen(c[i]);
	while (c[i] != 0)
	{
		tmp = ft_strlen(c[i]);
		if (prev != tmp)
		{
			res.x = 0;
			res.y = 0;
			res.isvalid = 0;
			return (res);
		}
		i++;
	}
	res.y = i;
	res.x = tmp;
	res = ft_results(res);
	return (res);
}
