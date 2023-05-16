/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:40:53 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/16 13:57:35 by hed-dyb          ###   ########.fr       */
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
	int n;
	int	td;
	int	te;
	int	ts;
	int	nt;
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