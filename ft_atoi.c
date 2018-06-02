/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:30:21 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/25 18:30:23 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int i;
	int result;
	int min;

	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		++i;
	min = i;
	if (str[min] == '+' || str[min] == '-')
		++i;
	while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9')
	{
		result = 10 * result + str[i] - '0';
		++i;
	}
	if (str[min] == '-')
		result *= -1;
	return (result);
}
