/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_from_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:35:00 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/09 17:35:01 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

#define BUFLEN 4096

int			ft_check_open_close(int fd)
{
	if (fd == -1)
		return (0);
	return (1);
}

char		*ft_record_from_file(int fd, char *str)
{
	char	*result;
	int		bufcharnum;
	char	readbuf[BUFLEN + 1];

	result = malloc(1);
	while ((bufcharnum = read(fd, readbuf, BUFLEN)))
	{
		str = ft_strdup(result, (bufcharnum + 1));
		str = ft_strncat(str, readbuf, bufcharnum);
		free(result);
		result = str;
	}
	return (result);
}

char		*ft_read_from_file(char *str)
{
	int		fd;
	int		check;
	char	*result;

	fd = open(str, O_RDONLY);
	check = ft_check_open_close(fd);
	if (check == 0)
		return (0);
	result = ft_record_from_file(fd, str);
	close(fd);
	check = ft_check_open_close(fd);
	if (check == 0)
		return (0);
	return (result);
}
