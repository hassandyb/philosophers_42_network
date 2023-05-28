/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:49:41 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/28 12:11:22 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


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
}