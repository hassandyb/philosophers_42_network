/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:53:16 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/28 12:13:55 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

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
	

}t_info;

typedef struct s_philo
{
	int				id;
	struct s_philo	*next;
	t_info			*info;
	int				eating_times;
	long			last_eat;



	
	// pthread_t		thread;
}t_philo;





t_info	*ft_parsing(int argc, char **argv);
int	ft_check_1(int argc, char **argv);
int	ft_check_2(char **argv);
int	ft_check_3(char **argv);
int	ft_check_4(t_info *i);
int	ft_atoi(char *arg);
void	ft_free_linked_list(int nodes_number, t_philo *p);
t_philo	*ft_create_node(int nodes_number, t_philo *p, t_info *i);
t_philo	*ft_create_philosophers(t_info *i);
long	ft_epoch_time(void);
long	ft_count_time(t_philo *p);


#endif