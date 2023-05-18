/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:40:53 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/18 12:52:47 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
#include <sys/time.h>
typedef struct s_data
{
	int n;// number of philosophoers = number of forks.
	int	td;//if this time runs out and the philo did not eat again or after the beginig of the program they die,
	int	te;// the time needs bu a philo to eat, it requirse for a philo to hold tow forks.
	int	ts;//time the philo spend sleeping
	int	nt;// program stops when the philosophers eat nt times exactly.
	pthread_mutex_t lock_print;
	// pthread_mutex_t *forks;
	
}t_data;

typedef struct s_philo_data
{
	int id;// 1 2 3 4 5 
	
	pthread_t thread;
	pthread_mutex_t fork;
	t_data *data;
	long start_time;
	long last_meal;  //==> store the last time a philo eat
	int ntimes_must_eat;//(nt) for each one , int the number if phols must eat    => because for each philo we need to increment evry time he eats so we exit onc e the variable raecher zero for each  pholo
	struct s_philo_data *next;
	
}t_philo_data;
#endif