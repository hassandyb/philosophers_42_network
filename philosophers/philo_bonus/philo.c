/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:49:41 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/31 16:02:16 by hed-dyb          ###   ########.fr       */
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
	sem_wait(p->info->print);
	printf("%ld %d %s\n", ft_count_time(p), p->id, msg);
	if(msg[3] == 'd')
		return ;
	sem_post(p->info->print);
}

void ft_eating(t_philo *p)
{
	sem_wait(p->info->fork);
	ft_print(p, "has taken a fork");
	sem_wait(p->info->fork);// you have to add the case of 1 philo
	ft_print(p, "has taken the second fork");
	ft_print(p, "is eating");
	sem_wait(p->info->lock);
	p->last_eat = ft_epoch_time();
	sem_post(p->info->lock);
	ft_optimised_usleep(p->info->te);
	sem_post(p->info->fork);
	sem_post(p->info->fork);
}

void *ft_routine(void *arg)
{
	t_philo *p;
	
	p = arg;
	if(p->id % 2 == 0)
		usleep(200);
	while(1)
	{
		ft_eating(p);
		ft_print(p, "is sleeping");
		ft_optimised_usleep(p->info->ts);
		ft_print(p, "is thinking");
		sem_wait(p->info->lock);
		if(p->info->nt != -1)
			p->eating_times--;
		if(p->eating_times == 0)
		{
			sem_post(p->info->lock);
			break;
		}
		sem_post(p->info->lock);
	}
	return (NULL);
}

void ft_free_and_exit(t_info *i, t_philo *head)
{
	ft_free_linked_list(i->n, head);
	free(i);
	exit (1);
}

void ft_check_death(t_philo *p)
{
	sem_wait(p->info->lock);
	if(ft_epoch_time() - p->last_eat >= p->info->td != p->info->nt != 0)
	{
		ft_print(p, "is died");
		kill (0, SIGINT);
	}
	sem_post(p->info->lock);
}

void ft_check_eating_times(t_philo *p)
{
	sem_wait(p->info->lock);
	if(p->eating_times == -1)
		return ;
	sem_post(p->info->lock);
	sem_wait(p->info->lock);
	if(p->eating_times == 0)
		exit (0);
	sem_post(p->info->lock);
}

void ft_create_processes(t_philo *p, t_info *i)
{
	int j;
	t_philo *head;

	head = p;
	p->info->started_time = ft_epoch_time();
	j = 0;
	while (p != NULL && j < p->info->n)
	{
		p->pid = fork();
		if(p->pid == 0)
		{
			// printf("here ----\n");
			pthread_create(&(p->thread), NULL, ft_routine, p);// same as mandotory add semafore
			pthread_detach(p->thread);
			while(1)
			{
				// ft_check_death(p);// if the he dead, kill all the process group
				// ft_check_eating_times(p);// if a philo eated enough times exit the process
				usleep(1000);
			}
		}
		if (p->pid == -1)
			ft_free_and_exit(i, p);
		p = p->next;
		j++;
	}
}
// how do you grantee that those process are charing the same semaphore i mean when 
//i use sem_wait or post how those this is chred between them even if they are defrent processess.

//kill(0, SIGINT)   //

// you need to know the optimised rpoch ..function work    // 
//pthread_detach  //
//wait pid  // 
//tests
int main (int argc, char **argv)
{
	t_info	*i;
	t_philo	*p;
	int j;
	
	i = ft_parsing(argc, argv);
	p = ft_create_philosophers(i);

	
	ft_create_processes(p, i);
	j = 0;
	while (j < i->n)
	{
		
		waitpid(p->pid, NULL, 0);
		j++;
		p = p->next;
	}
}










