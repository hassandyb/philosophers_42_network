/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:49:41 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/07 12:46:18 by hed-dyb          ###   ########.fr       */
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

void	ft_check_death(t_philo *p)
{
	sem_wait(p->info->lock);
	if (ft_epoch_time() - p->last_eat >= p->info->td && p->info->nt != 0)
	{
		ft_print(p, "is died");
		kill (0, SIGINT);
	}
	sem_post(p->info->lock);
}

void	ft_check_eating_times(t_philo *p)
{
	sem_wait(p->info->lock);
	if (p->eating_times == -1)
	{
		sem_post(p->info->lock);
		return ;
	}
	sem_post(p->info->lock);
	sem_wait(p->info->lock);
	if (p->eating_times == 0)
	{
		sem_post(p->info->lock);
		exit (0);
	}
	sem_post(p->info->lock);
}

void	ft_create_processes(t_philo *p, t_info *i)
{
	int		j;
	t_philo	*head;

	head = p;
	p->info->started_time = ft_epoch_time();
	j = -1;
	while (p != NULL && ++j < p->info->n)
	{
		p->pid = fork();
		if (p->pid == 0)
		{
			p->last_eat = ft_epoch_time();
			pthread_create(&(p->thread), NULL, ft_routine, p);
			pthread_detach(p->thread);
			while (1)
			{
				ft_check_death(p);
				ft_check_eating_times(p);
				usleep (200);
			}
		}
		if (p->pid == -1)
			ft_free_and_exit(i, p);
		p = p->next;
	}
}

int	main(int argc, char **argv)
{
	t_info	*i;
	t_philo	*p;
	int		j;

	i = ft_parsing(argc, argv);
	p = ft_create_philosophers(i);

	ft_create_processes(p, i);
	j = 0;
	while (p && j < i->n)
	{
		waitpid(p->pid, NULL, 0);
		j++;
		p = p->next;
	}
	ft_free_linked_list(i->n, p);
	free (i);
}
