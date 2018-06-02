/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:10:42 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/07 17:10:43 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

#define BUFLEN 4096

char		*ft_read_input(void)
{
	int		bufcharnum;
	char	readbuf[BUFLEN + 1];
	char	*str;
	char	*result;

	result = malloc(1);
	while ((bufcharnum = read(0, readbuf, BUFLEN)))
	{
		str = ft_strdup(result, (bufcharnum + 1));
		str = ft_strncat(str, readbuf, bufcharnum);
		free(result);
		result = str;
	}
	return (result);
}
