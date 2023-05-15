/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:40:53 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/15 13:15:13 by hed-dyb          ###   ########.fr       */
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
	
}t_data;

typedef struct s_philo_data
{
	int id;// 1 2 3 4 5 
	
	pthread_t thread;
	pthread_mutex_t fork;
	t_data *data;
	struct s_philo_data *next;
	
}t_philo_data;
#endif