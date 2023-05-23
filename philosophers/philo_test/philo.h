/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:38:27 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/22 15:47:55 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
#include <sys/time.h>



typedef struct s_info
{
	int n;// number of philosophoers = number of forks.
	int	td;//if this time runs out and the philo did not eat again or after the beginig of the program they die,
	int	te;// the time needs by a philo to eat, it requirse for a philo to hold tow forks.
	int	ts;//time the philo spend sleeping
	int	nt;// number_of_times_each_philosopher_must_eat - program stops when the philosophers eat nt times exactly.
	pthread_mutex_t printf_mutex;

	
}t_info;

typedef struct s_philo
{
	//initilozed in tft_create_philosophers function;
	int id;
	int nt_count;//(nt) for each one , int the number if phols must eat    => because for each philo we need to increment evry time he eats so we exit onc e the variable raecher zero for each  pholo
	t_info *info;
	pthread_mutex_t fork;
	struct s_philo *next;
	
	// used in ft_pthread_craete and ft_pthread_join
	pthread_t thread;
	
	// used in ft_routine
	long started_time; // started epoch time for each thread - we need to store each time a thread started
	
	long last_eat;  //==> store the last time a philo eat
	pthread_mutex_t last_eat_mutex;
	int eating_times;
	pthread_mutex_t eating_times_mutex;
	
}t_philo;



void ft_check_1(int argc, char **argv);
void	ft_check_2(char **argv);
void	ft_check_3(char **argv);
int ft_atoi(char *arg);
void ft_args_to_numbers(int argc, char **argv, t_info *i);
void ft_check_4(t_info *i);
t_philo *ft_create_philosophers(t_info *i);
long ft_count_time(t_philo *p);
long ft_epoch_time();
#endif