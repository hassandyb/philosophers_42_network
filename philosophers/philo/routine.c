/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:56:57 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/25 13:57:22 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long ft_epoch_time()
{
	struct timeval tv;
	if(gettimeofday(&tv, NULL) != 0)
		return 0;
	
	return((tv.tv_sec * 1000) + (tv.tv_usec * 0.001));
}

long ft_count_time(t_philo *p)
{
	return(ft_epoch_time() - p->info->started_time);
}

void ft_print(t_philo *p, char *msg)
{
	pthread_mutex_lock(&(p->info->printf_mutex));
	printf("%ld %d %s\n", ft_count_time(p), p->id, msg);
	if(msg[3] == 'd')
		return ;
	pthread_mutex_unlock(&(p->info->printf_mutex));
}

void ft_eating(t_philo *p)
{

	pthread_mutex_lock(&(p->fork));
	ft_print(p, "has taken a fork");
	if (p->info->n == 1)
		pthread_mutex_lock(&(p->fork));
	else
		pthread_mutex_lock(&(p->next->fork));
	ft_print(p, "has taken the second fork");
	ft_print(p, "is eating");
	
	pthread_mutex_lock(&(p->lock));
	p->last_eat = ft_epoch_time();
	pthread_mutex_unlock(&(p->lock));
	ft_optimised_usleep(p->info->te);
	pthread_mutex_unlock(&(p->fork));
	pthread_mutex_unlock(&(p->next->fork));	
}

void *ft_routine(void *arg)
{
	t_philo *p;
	p = arg;
	
	if(p->id % 2 == 0)
		usleep(800);
	while(1)
	{
		ft_eating(p);
		
		ft_print(p, "is sleeping");
		ft_optimised_usleep(p->info->ts);
		ft_print(p, "is thinking");

		pthread_mutex_lock(&(p->lock));
		if(p->info->nt != -1)
			p->eating_times--;
		if(p->eating_times == 0)
			break;
		pthread_mutex_unlock(&(p->lock));
	}
	return NULL;
}

