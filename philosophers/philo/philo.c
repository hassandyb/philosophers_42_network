/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:02:20 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/23 16:53:22 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(char *arg)
{
	int i;
	int result;
	
	i = 0;
	result = 0;
	while(arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13))
		i++;
	if(arg[i] == '+')
		i++;
	while(arg[i])
	{
		result = (result * 10) + (arg[i] - '0');
		i++;
	}

	return result;
}
//-----------------------

long ft_epoch_time()
{
	struct timeval tv;
	if(gettimeofday(&tv, NULL) != 0)
		return 0;
	
	return((tv.tv_sec * 1000) + (tv.tv_usec * 0.001));
}


// ft_print(t_philo *p, char *msg)
// {
// 	pthread_mutex_lock(&(p->info->printf_mutex));
// 	printf()
// 	if()
// 	pthread_mutex_unlock(&(p->info->printf_mutex));
// }


void *ft_routine(void *arg)
{
	t_philo *p;
	p = arg;
	if(p->id % 2 == 0)
		usleep(100);
	while(1)
	{
		pthread_mutex_lock(&(p->fork));
		ft_print(p, "has taken a fork");
		pthread_mutex_lock(&(p->next->fork));
		ft_print(p, "has taken the second fork");
		ft_print(p, "is eating");
		
		pthread_mutex_lock(&(p->lock));
		p->last_eat = ft_epoch_time();
		pthread_mutex_lock(&(p->lock));
		usleep(p->info->te * 1000);

		pthread_mutex_unlock(&(p->fork));
		pthread_mutex_unlock(&(p->next->fork));
		
		ft_print(p, "is sleeping");
		usleep(p->info->ts * 1000);
		ft_print(p, "is thinking");

		pthread_mutex_lock(&(p->lock));
		if(p->info->nt != -1)
			p->eating_times--;
		if(p->eating_times == 0)
			break;
		pthread_mutex_unlock(&(p->lock));
	}
	// return 
}

int ft_create_threads(t_philo *p)
{
	int	j;

	j = 0;
	p->info->started_time = ft_epoch_time();
	pthread_mutex_init(&(p->info->printf_mutex), NULL);
	if(p->info->started_time == 0)
		return (0);
	while(j < p->info->n)
	{
		if(pthread_create(&(p->thread), NULL, ft_routine, p) != 0)
			return 0;
		if(pthread_detach(p->thread) != 0)
			return 0;
		p = p->next;
		j++;
	}
	return (1);
}


int main(int argc, char **argv)
{	
	t_info	*i;
	t_philo *p;

	i = ft_parsing(argc, argv);
	if( i == NULL)
		return (0);
	// printf("%d   %d   %d   %d    %d\n", i->n, i->td, i->te, i->ts,  i->nt);
	p = ft_create_philosophers(i);
	if(p == NULL)
		return (0);
	i->started_time = -1;
	if(ft_create_threads(p) == 0)
	{
		ft_free_linked_list(i->n, p);
		free(i);
		return (0);
	}
	
}
