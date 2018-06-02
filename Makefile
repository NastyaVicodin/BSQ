#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alukyane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/07 13:10:33 by alukyane          #+#    #+#              #
#    Updated: 2017/10/07 13:10:34 by alukyane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

BSQ = bsq
SRC = *.c
FLAGS = -Wall -Wextra -Werror

all:
	gcc $(FLAGS) $(SRC) -o $(BSQ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(BSQ)

re: clean all
