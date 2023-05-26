/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:10:02 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/26 16:03:37 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int				n;
	int				td;
	int				te;
	int				ts;
	int				nt;
	long			started_time;
	pthread_mutex_t	printf_mutex;
}t_info;

typedef struct s_philo
{
	int				id;
	int				eating_times;
	long			last_eat;
	t_info			*info;
	struct s_philo	*next;
	pthread_mutex_t	fork;
	pthread_mutex_t	lock;
	pthread_t		thread;
}t_philo;

int		ft_check_1(int argc, char **argv);
int		ft_check_2(char **argv);
int		ft_check_3(char **argv);
int		ft_atoi(char *arg);
t_info	*ft_parsing(int argc, char **argv);
int		ft_check_4(t_info *i);
t_philo	*ft_create_philosophers(t_info *i);
t_philo	*ft_create_node(int count, t_philo *p, t_info *i);
void	ft_free_linked_list(int count, t_philo *p);
long	ft_epoch_time(void);
void	ft_optimised_usleep(long sleeping_time);
long	ft_count_time(t_philo *p);
void	ft_print(t_philo *p, char *msg);
void	ft_eating(t_philo *p);
void	*ft_routine(void *arg);
int		ft_create_threads(t_philo *p);
int		ft_check_eating_times(t_philo *p);
int		ft_check_death(t_philo *p);

#endif