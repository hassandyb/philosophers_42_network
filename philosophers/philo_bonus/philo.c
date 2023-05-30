/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:49:41 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/30 17:08:14 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_optimised_usleep(long sleeping_time)
{
	long	starting_time;

	starting_time = ft_epoch_time();
	while (ft_epoch_time() - starting_time < sleeping_time)
	{
		usleep(100);
	}
}

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

void ft_print(t_philo *p, char *msg)
{
	printf("%ld %d %s\n", ft_count_time(p), p->id, msg);
}

void ft_eating(t_philo *p)
{
	ft_print(p, "has taken a fork");
	ft_print(p, "has taken the second fork");
	ft_print(p, "is eating");
	p->last_eat = ft_epoch_time();
	ft_optimised_usleep(p->info->te);
}

void ft_routine(t_philo *p, t_info *i)
{
	if(p->id % 2 == 0)
		usleep(200);
	while(1)
	{
		ft_eating(p);
		ft_print(p, "is sleeping");
		ft_optimised_usleep(p->info->ts);
		ft_print(p, "is thinking");
		if(p->info->nt != -1)
			p->eating_times--;
		if(p->eating_times == 0)
			break;

	}
	ft_free_linked_list(i->n, p);
	free(i);
	exit (0);
}

void ft_create_processes(t_philo *p, t_info *i)
{
	int j;
	t_philo *head;

	head = p;
	p->info->started_time = ft_epoch_time();
	j = 0;
	while(p != NULL && j < p->info->n)
	{
		p->pid = fork();
		if(p->pid == 0)
		{

			//pthread_create
			//pthread detach
			//ft_check death
			//ft_check eating times
		}
		if(p->pid == -1)
		{
			ft_free_linked_list(i->n, head);
			free(i);
			exit (1);
		}
		p = p->next;
		j++;
	}
}

int main (int argc, char **argv)
{
		t_info	*i;
	t_philo	*p;

	i = ft_parsing(argc, argv);
	p = ft_create_philosophers(i);

	ft_create_processes(p, i);
}