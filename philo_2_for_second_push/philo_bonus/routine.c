/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:34:50 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/01 16:54:10 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_epoch_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec * 0.001));
}

long	ft_count_time(t_philo *p)
{
	return (ft_epoch_time() - p->info->started_time);
}

void	ft_print(t_philo *p, char *msg)
{
	sem_wait(p->info->print);
	printf("%ld %d %s\n", ft_count_time(p), p->id, msg);
	if (msg[3] == 'd')
		return ;
	sem_post(p->info->print);
}

void	ft_eating(t_philo *p)
{
	sem_wait(p->info->fork);
	ft_print(p, "has taken a fork");
	sem_wait(p->info->fork);
	ft_print(p, "has taken the second fork");
	ft_print(p, "is eating");
	sem_wait(p->info->lock);
	p->last_eat = ft_epoch_time();
	sem_post(p->info->lock);
	ft_optimised_usleep(p->info->te);
	sem_post(p->info->fork);
	sem_post(p->info->fork);
}

void	*ft_routine(void *arg)
{
	t_philo	*p;

	p = arg;
	if (p->id % 2 == 0)
		usleep(200);
	while (1)
	{
		ft_eating(p);
		ft_print(p, "is sleeping");
		ft_optimised_usleep(p->info->ts);
		ft_print(p, "is thinking");
		sem_wait(p->info->lock);
		if (p->info->nt != -1)
			p->eating_times--;
		if (p->eating_times == 0)
		{
			sem_post(p->info->lock);
			break ;
		}
		sem_post(p->info->lock);
	}
	return (NULL);
}
