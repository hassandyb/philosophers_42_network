/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:35:04 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/22 15:49:13 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


//--------------------
void print_log(t_philo *philo, char *log)
{
	pthread_mutex_lock(&philo->info->printf_mutex);
	printf("%ld  %d %s\n", ft_count_time(philo), philo->id, log);
	
	pthread_mutex_unlock(&philo->info->printf_mutex);
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
