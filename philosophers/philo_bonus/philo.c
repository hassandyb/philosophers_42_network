/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:49:41 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/30 18:27:59 by hed-dyb          ###   ########.fr       */
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
	printf("%ld %d %s\n", ft_count_time(p), p->id, msg);
}

void ft_eating(t_philo *p)
{
	ft_print(p, "has taken a fork");
	ft_print(p, "has taken the second fork");
	ft_print(p, "is eating");
	p->last_eat = ft_epoch_time();
	ft_optimised_usleep(p->info->te);
}

void ft_routine(t_philo *p, t_info *i)
{
	if(p->id % 2 == 0)
		usleep(200);
	while(1)
	{
		ft_eating(p);
		ft_print(p, "is sleeping");
		ft_optimised_usleep(p->info->ts);
		ft_print(p, "is thinking");
		if(p->info->nt != -1)
			p->eating_times--;
		if(p->eating_times == 0)
			break;

	}
	ft_free_linked_list(i->n, p);
	free(i);
	exit (0);
}

void ft_create_processes(t_philo *p, t_info *i)
{
	int j;
	// t_philo *head;
	// pthread_t	philo;

	head = p;
	p->info->started_time = ft_epoch_time();
	j = 0;
	while (p != NULL && j < p->info->n)
	{
		p->pid = fork();
		if(p->pid == 0)
		{
			pthread_create(&ph)// same as mandotory add semafore
			//pthread detach//
			while(1)
			{
				//ft_check death// if the he dead, kill all the process group
				//ft_check eating times// if a philo eated enough times exit the process
			}
		}
		if (p->pid == -1)
		{
			ft_free_linked_list(i->n, head);
			free(i);
			exit (1);
		}
		p = p->next;
		j++;
	}

}
//kill(0, SIGINT)

//wulie(i < philonumber)

int main (int argc, char **argv)
{
		t_info	*i;
	t_philo	*p;

	i = ft_parsing(argc, argv);
	p = ft_create_philosophers(i);

	ft_create_processes(p, i);
	while (i < i->n)
	{
		waitpid(p->pid, NULL, 0);
		i++;
		p = p->next;
	}
}







//------------------------------------
// After calling `sem_wait(sem)` and `sem_post(sem)`, the `sem` variable remains unchanged. The `sem` variable is a semaphore descriptor that is used to identify and operate on the semaphore.

// The `sem_wait` function is used to decrement the value of the semaphore. If the semaphore value is greater than zero, it decrements the value and allows the calling process/thread to proceed. If the semaphore value is already zero, indicating that it is being used by another process/thread, `sem_wait` will block the calling process/thread until the semaphore becomes available.

// Here's an example of how you can use `sem_wait`:

// ```c
// sem_wait(semaphore);
// // Critical section - code that should be accessed by only one philosopher at a time
// sem_post(semaphore);
// ```

// The `sem_post` function is used to increment the value of the semaphore. It "posts" (or releases) the semaphore, indicating that it is available for other processes/threads to use.

// Here's an example of how you can use `sem_post`:

// ```c
// // Perform some operations before entering the critical section

// sem_post(semaphore);

// // Continue with other operations

// ```

// In the example above, `sem_wait` is called before entering the critical section to acquire the semaphore, ensuring that only one philosopher can access the critical section at a time. `sem_post` is called after the critical section to release the semaphore, allowing other philosophers to acquire it and access the critical section.

// The `sem` variable serves as a handle to the semaphore and is used as an argument to both `sem_wait` and `sem_post` functions to operate on the semaphore identified by the handle.



