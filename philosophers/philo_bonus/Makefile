# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 11:48:14 by hed-dyb           #+#    #+#              #
#    Updated: 2023/05/28 12:09:41 by hed-dyb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc 
RM = rm -f 
FLAGS = -Wall -Werror -Wextra fsanitize
FILES = philo_bonus.c parsing_bonus.c creating_philos_bonus.c 

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
