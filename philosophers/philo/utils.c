/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:26:11 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/24 16:43:10 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ms_sleep(long time_ms)
{
long  start_tm = (long)ft_epoch_time();
//printf("%ld %ld\n",time_ms , start_tm);
while (ft_epoch_time() -  start_tm  <=  time_ms)
{
	usleep(100);
}
//printf("%ld %ld\n",ft_epoch_time() -  start_tm );
	
}