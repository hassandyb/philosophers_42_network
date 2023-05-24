/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:02:20 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/24 16:37:27 by hed-dyb          ###   ########.fr       */
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
// case of one phlio,
// usleep function...
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
	ms_sleep(p->info->te);
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
		ms_sleep(p->info->ts);
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

int ft_create_threads(t_philo *p)
{
	int	j;
	j = 0;
	p->last_eat = ft_epoch_time();
	//printf("here --------\n");
	p->info->started_time = ft_epoch_time();
	pthread_mutex_init(&(p->info->printf_mutex), NULL);
	while(p && j < p->info->n)
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
//--------------------------
//how to check if gied 
int ft_check_death_and_eating_times(t_philo *p)
{
	int j;

	j = 0;
	if(ft_epoch_time() - p->last_eat >= p->info->td)
	{
		ft_print(p, "is died");
		return 0;
	}
	while(j < p->info->n)
	{
		if(p->eating_times == 0)
			p = p->next;
		else
			break ;
		j++;
	}
	return 1;
	
}

int main(int argc, char **argv)
{	
	t_info	*i;
	t_philo *p;

	i = ft_parsing(argc, argv);
	if( i == NULL)
		return (0);
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
	while (1)
	{
		if(ft_check_death_and_eating_times(p) == 0)
			break;
		usleep(500);
	}
	return (0);
}
