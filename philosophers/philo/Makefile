# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 12:01:59 by hed-dyb           #+#    #+#              #
#    Updated: 2023/06/01 16:31:43 by hed-dyb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc 
RM = rm -f 
FLAGS = -Wall -Werror -Wextra 
FILES = philo.c parsing.c creating_philos.c routine.c

OBJ = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c philo.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME)
	
re : fclean all
