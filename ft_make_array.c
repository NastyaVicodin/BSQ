/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 13:38:43 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/30 13:38:43 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

int		ft_is_new_line(char *c)
{
	return ((*c == '\0') || (*c == '\n'));
}

char	*ft_extract_word(int *count, char *w)
{
	char	*c;
	char	*word;
	int		length;

	c = w;
	length = 0;
	while (!ft_is_new_line(c++))
		length++;
	word = malloc((length + 1) * sizeof(char));
	while (!ft_is_new_line(w))
		*word++ = *w++;
	*count = length;
	*word = '\0';
	return (word - length);
}

int		ft_count_words(char *str)
{
	int		count;
	char	*s;
	char	*word;
	int		*l;

	l = malloc(sizeof(int));
	count = 0;
	s = str;
	while (*s)
	{
		if (!ft_is_new_line(s))
		{
			word = ft_extract_word(l, s);
			s = s + *l;
			if (*l > 0)
				count++;
		}
		else
			s++;
	}
	return (count);
}

char	**ft_make_array(char *str)
{
	char	**ret;
	char	*word;
	int		*l;
	int		w_count;
	int		i;

	w_count = ft_count_words(str);
	ret = malloc((w_count + 1) * sizeof(char *));
	l = malloc(sizeof(int));
	i = 0;
	while (*str)
	{
		if (!ft_is_new_line(str))
		{
			word = ft_extract_word(l, str);
			str += *l;
			if (*l > 0)
				*(ret + i++) = word;
		}
		else
			str++;
	}
	*(ret + i) = 0;
	return (ret);
}
