/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:39:52 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/20 15:01:18 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void ft_check_1(int argc, char **argv)
{
	int j;
	int i;
	
	if(argc != 5 && argc != 6)
	{
		write(1, "Error\ncheck args number!", 25);
		exit(1);
	}
	j = 1;// to avid the excutable
	while(argv[j])
	{
		i = 0;
		while(argv[j][i] && (argv[j][i] == ' ' || argv[j][i] == '\t'))
			i++;
		if(argv[j][i] == '\0' || argv[j][0] == '\0')
		{
			write(1, "Error\nEmpty argument or arument full of tabs and spaces",56);
			exit(1);
		}
		j++;
	}
}

void	ft_check_2(char **argv)
{
	int	j;
	int	i;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] != ' ' && argv[j][i] != '\t' && argv[j][i] != '+' 
				&& (argv[j][i] < '0' || argv[j][i] > '9'))
			{
				write(2, "Error\nWrong charcter or you have -!", 36);
				exit(0);
			}
			if (argv[j][i] == '+' && (argv[j][i + 1] == ' ' || argv[j][i + 1] == '\t' || argv[j][i + 1] == '\0'))
			{
				write(2, "Error\nSign + followed by Tab, space or null char!", 50);
				exit(0);
			}
			i++;
		}
		j++;
	}
}

void	ft_check_3(char **argv)
{
	int	y;
	int	x;

	y = 1;
	while (argv[y])
	{
		x = 0;
		while (argv[y][x])
		{
			if ((argv[y][x] >= '0' && argv[y][x] <= '9') && argv[y][x + 1] == '+')
			{
				write(1, "Error\nAdd space or tab after the sign +", 40);
				exit (0);
			}
			if(argv[y][x] == '+' && argv[y][x] == '+')
			{
				write(1, "Error\nYou have double + or more", 32);
				exit(0);
			}
			x++;
		}
		y++;
	}
}
//--------------------
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

void ft_args_to_numbers(int argc, char **argv, t_data *f)
{
	f->n = ft_atoi(argv[1]);// indice 0 is the executable
	f->td = ft_atoi(argv[2]);
	f->te = ft_atoi(argv[3]);
	f->ts = ft_atoi(argv[4]);
	if(argc == 6)
		f->nt = ft_atoi(argv[5]);
	else
		f->nt = -1;	
	// f->forks = malloc(sizeof(pthread_mutex_t) * f->n);
}

void ft_check_4(t_data *f)
{
	if(f->n == 0 || f->td == 0 || f->te == 0 || f->ts == 0 || f->nt == 0)
	{
		write(1, "Error\n One of your args equal to ZERO", 1);
		exit(0);
	}
}
//-------------------------------

t_philo_data *ft_create_philosophers(t_data *f)
{
	t_philo_data *p;
	t_philo_data *old;
	t_philo_data *new;
	int i;

	p = NULL;
	p = ft_create_node(1, p, f);

	i = 0;
	old = p;
	while(i < f->n - 1)// -1 cause we already create  node above
	{
		new = ft_create_node(i + 2, p, f);
		old->next = new;
		old = old->next;
		i++;
	}
	new->next = p;
	return (p);
}
// cerculare linked list
// you should handler freeing creculaire list also you need to change the function you create for the liked list befor you made it curculaire .
//--------------------------------

long ft_timer()
{
	struct timeval t;
	
	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

long ft_duration(long start_time)
{
	return (ft_timer() - start_time);
}

void  *ft_routine(void *philo)
{
	t_philo_data *p;
	p = philo;
	p->last_meal = ft_timer();
	p->start_time = ft_timer();
	// pthread_mutex_init(&p->fork, NULL);
	// (void)p->fork.__sig;
	// printf("%ld\n", p->fork.__sig);
	// printf("thread number %d stared, fork = %ld\n", p->id, p->fork.__sig);
	
	while(1)
	{
		
		// printf("");
		pthread_mutex_lock(&(p->fork));// first thread or philo thathis ft_routines runs will lock all aother thrids. 
		printf("%ld %d has taken his fork\n", ft_duration(p->start_time), p->id); 
		pthread_mutex_lock(&(p->next->fork));
		printf("%ld %d has taken right fork\n", ft_duration(p->start_time), p->id);
		p->last_meal = ft_timer();
		printf("%ld %d is eating\n", ft_duration(p->start_time), p->id);

		(p->ntimes_must_eat)--;
		
		
		usleep(1000 * p->data->te);
		pthread_mutex_unlock(&(p->next->fork));
		pthread_mutex_unlock(&(p->fork));

		if(p->ntimes_must_eat == 0)
		{
			break;// or return not xit cause we should wait other threads to reach 0;
			
		}
		printf("%ld %d is sleeping\n", ft_duration(p->start_time), p->id);
		usleep(1000 * p->data->ts);
		
		printf("%ld %d is thinking\n", ft_duration(p->start_time), p->id);
		
		
	}
	 return (NULL);
}

void ft_print(long time, char *msg,t_philo_data *p)// cause riutines are working in the same time time we need to lock it utile the first one printf the folloed by the second and so on
{
	pthread_mutex_lock(&(p->data->lock_print));
	printf("%ld %d %s\n", time, p->id, msg);
	pthread_mutex_unlock(&(p->data->lock_print));
	
}

void ft_check_death(t_philo_data *p)
{
	while(1)
	{
		if((ft_timer() - p->last_meal) > (p->data->td))
		{
			//free
			printf("%ld %d died", ft_duration(p->start_time), p->id);// lock the mutex but dont unlock it cause this is the last mesage
			return;
		}
		p = p->next;
	}
}

void ft_launch(t_philo_data **p)
{
	int i;

	i = 0;
 	while(i < (*p)->data->n)
	{
		if(pthread_create(&((*p)->thread), NULL, ft_routine, *p) != 0)
		{
			write(1, "Error\nPthread_create function failed!", 38);
			exit (1);
		}
		usleep(100);
		(*p) = (*p)->next;
		i++;
	}

	ft_check_death(*p);
	
	i = 0;
	while(i < (*p)->data->n)
	{
		if(pthread_join((*p)->thread, NULL) != 0)
		{
			write(1, "Error\npthread_join failed!", 27);
			exit (1);
		}
		*p = (*p)->next;
		i++;
	}
}

//---------------------------------
void print_list(t_philo_data *p)
{
	while(p)
	{
		p = p->next;
		if (p->id == 1)
		 	break;
	}
	
}



int main (int argc, char **argv)
{
	//dont forget to protect pthread create and join...
	t_data f;
	t_philo_data *p;
	// int i = -1;

	p = NULL;
	ft_check_1(argc, argv);
	ft_check_2(argv);
	ft_check_3(argv);
	ft_args_to_numbers(argc, argv, &f);
	ft_check_4(&f);
	// while (++i < f.n)
	// 	pthread_mutex_init(f.forks, NULL);
	p = ft_create_philosophers(&f);
	ft_launch(&p);
	// printf("%d     %d     %d   %d    %d", f.n, f.td, f.te, f.ts, f.nt);


}

// for each philo :
// thread  create_
// id 0 1 2 3 
// fork  mutex