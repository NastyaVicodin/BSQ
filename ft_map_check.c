/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprypesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:57:14 by vprypesh          #+#    #+#             */
/*   Updated: 2017/10/09 16:57:15 by vprypesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

int		ft_check_new_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

char	*ft_cut_vals(char *str)
{
	int		i;
	int		len;
	int		j;
	char	*res;

	j = 0;
	i = 0;
	len = ft_strlen(str);
	res = malloc(3);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (len - i != 3)
		return (0);
	while (str[i] != '\0')
	{
		res[j] = str[i];
		i++;
		j++;
	}
	return (res);
}

int		ft_cut_size(char *str)
{
	int		i;
	int		len;
	char	*res;

	len = ft_strlen(str);
	res = malloc(len + 1);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res[i] = str[i];
		i++;
	}
	if (i == 0)
		return (0);
	return (ft_atoi(res));
}

char	*ft_first_row(char *str)
{
	char	*str1;
	int		i;

	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	str1 = malloc(sizeof(char) * i);
	i = 0;
	while (str[i] != '\n')
	{
		str1[i] = str[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

char	**ft_map_check(char *map)
{
	char	**res;
	char	*first_row;
	char	*vals;
	int		size;
	int		len;

	if (ft_check_new_line(map) == 0)
		return (0);
	first_row = ft_first_row(map);
	size = ft_cut_size(first_row);
	len = ft_strlen(first_row);
	if ((vals = ft_cut_vals(first_row)) == 0)
		return (0);
	map = map + len + 1;
	if (ft_verify_char(map, vals) == 0)
		return (0);
	res = ft_make_array(map);
	if (ft_is_enough_lines(res, size) == 1)
		return (res);
	else
		return (0);
}
