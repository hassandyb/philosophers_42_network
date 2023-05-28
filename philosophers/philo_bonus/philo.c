/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:49:41 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/28 15:46:45 by hed-dyb          ###   ########.fr       */
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



// typedef struct s_info
// {
// 	int				n;
// 	int				td;
// 	int				te;
// 	int				ts;
// 	int				nt;
// 	long			started_time;
	

// }t_info;

// typedef struct s_philo
// {
// 	int				id;
// 	struct s_philo	*next;
// 	t_info			*info;
// 	int				eating_times;
// 	long			last_eat;



	
// 	// pthread_t		thread;
// }t_philo;

int ft_create_processes(t_philo *p)
{
	int j;
	int r;
	
	p->info->started_time = ft_epoch_time();
	j = 0;
	while(p != NULL && j < p->info->n )
	{
		r = fork();
		if(r > 0)
	}
}

int main (int argc, char **argv)
{
		t_info	*i;
	t_philo	*p;

	i = ft_parsing(argc, argv);
	if (i == NULL)
		return (0);
	p = ft_create_philosophers(i);
	if (p == NULL)
		return (0);
	if(ft_create_processes(p) == 0)
	{
		free (i);
		ft_free_linked_list(i->n, p);
		return (0);
	}
}