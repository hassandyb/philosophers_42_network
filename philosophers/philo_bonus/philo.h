/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:37:10 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/01 16:52:07 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_info
{
	int		n;
	int		td;
	int		te;
	int		ts;
	int		nt;
	long	started_time;
	sem_t	*fork;
	sem_t	*lock;
	sem_t	*print;

}t_info;

typedef struct s_philo
{
	int				id;
	struct s_philo	*next;
	t_info			*info;
	int				eating_times;
	long			last_eat;
	pid_t			pid;
	pthread_t		thread;
}t_philo;

t_info	*ft_parsing(int argc, char **argv);
void	ft_check_1(int argc, char **argv);
void	ft_check_2(char **argv);
void	ft_check_3(char **argv);
void	ft_check_4(t_info *i);
int		ft_atoi(char *arg);
void	ft_free_linked_list(int nodes_number, t_philo *p);
t_philo	*ft_create_node(int nodes_number, t_philo *p, t_info *i);
t_philo	*ft_create_philosophers(t_info *i);
long	ft_epoch_time(void);
long	ft_count_time(t_philo *p);
void	ft_free_and_exit(t_info *i, t_philo *head);
void	ft_print(t_philo *p, char *msg);
void	ft_eating(t_philo *p);
void	*ft_routine(void *arg);
void	ft_free_and_exit(t_info *i, t_philo *head);
void	ft_optimised_usleep(long sleeping_time);
void	ft_check_death(t_philo *p);
void	ft_check_eating_times(t_philo *p);
void	ft_create_processes(t_philo *p, t_info *i);

#endif