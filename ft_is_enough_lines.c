/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_enough_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 20:04:57 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/09 20:04:58 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_enough_lines(char **array_map, int count_rows)
{
	int		i;

	i = 0;
	while (array_map[i] != 0)
	{
		++i;
	}
	if (i == count_rows)
		return (1);
	return (0);
}
