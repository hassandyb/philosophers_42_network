/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:02:20 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/25 13:58:20 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_optimised_usleep(long sleeping_time)
{
	long starting_time;

	starting_time = ft_epoch_time();
	while(ft_epoch_time() - starting_time < sleeping_time)
	{
		usleep(100);
	}
}

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
	free(i);
	ft_free_linked_list(i->n, p);
	return (0);
}
