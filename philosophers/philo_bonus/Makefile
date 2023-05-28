# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 11:48:14 by hed-dyb           #+#    #+#              #
#    Updated: 2023/05/28 15:38:25 by hed-dyb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc 
RM = rm -f 
FLAGS = -Wall -Werror -Wextra #fsanitize
FILES = philo.c parsing.c creating_philos.c 

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
