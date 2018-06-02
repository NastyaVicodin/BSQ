/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:45:44 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/27 17:45:45 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

char	*ft_strcpy(char *dest, char *src)
{
	char *tmpdest;

	tmpdest = dest;
	while (*src != '\0')
	{
		*tmpdest = *src;
		tmpdest++;
		src++;
	}
	*tmpdest = '\0';
	return (dest);
}

char	*ft_strdup(char *src, int extra)
{
	char			*res;
	unsigned int	len;

	res = src;
	len = 1;
	while (*res)
	{
		res++;
		len++;
	}
	res = (char*)malloc(sizeof(char) * (len + extra));
	return (ft_strcpy(res, src));
}
