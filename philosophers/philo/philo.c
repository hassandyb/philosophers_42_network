/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:09:11 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/19 19:10:20 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// creating philosophers.
void	ft_free_linked_list(int count, t_philo *p)
{
	int x;

	x = 0;
	t_philo	*node_saver;
	while(x < count)
	{
		node_saver = p;
		p = p->next;
		free(node_saver);
	}
}

t_philo *ft_create_node(int count, t_philo *head, t_info *i)
{
	int r;
	t_philo *node;
	node = malloc(sizeof(t_philo));
	if(node == NULL)
	{
		ft_free_linked_list(count, head);
		return NULL;
	}

	node->id = count;
	node->nt_count = i->nt;
	node->info = i;
	node->next = NULL;
	

	r = pthread_mutex_init(&node->fork, NULL);// to create a mutex for each thread - initize a mutex for each thread
	if(r != 0)
	{
		ft_free_linked_list(count, head);
		return NULL;
	}
	return (node);

}

t_philo *ft_create_philosophers(t_info *i)
{
	t_philo *p;
	t_philo *old;
	t_philo *new;
	int x;

	p = NULL;
	p = ft_create_node(1, p, i);

	x = 0;
	old = p;
	while(x < i->n - 1)// -1 cause we already create  node above
	{
		new = ft_create_node(x + 2, p, i);
		old->next = new;
		old = old->next;
		x++;
	}
	new->next = p;
	return (p);
}

// threads

void *ft_routine(void *arg)
{
	t_philo *p;
	
	p = arg;
	while(1)
	{
		pthread_mutex_lock(&(p->fork));// in this stage threads/ philos try to take their fork 
		
	}
	return NULL;
}

void ft_create_threads(t_philo *p)
{
	int j;
	int r;


	j = 0;
	while(j < p->info->n)
	{
		r = pthread_create(&(p->thread), NULL, ft_routine, p);
		if(r != 0)
		{
			printf("Error\npthread-create failed!");
			ft_free_linked_list(p->info->n, p);
			return ;
		}
		usleep(100);
		p = p->next;
		j++;

	}
}

void ft_join_threads(t_philo *p)
{
	int j;
	int r;
	

	j = 0;
	while(j < p->info->n)
	{
		r = pthread_join(p->thread, NULL);
		if(r != 0)
		{
			printf("Error\npthread_join failed!");
			ft_free_linked_list(p->info->n, p);
			return ;
		}
		p = p->next;
		j++;
	}
}

int main(int argc, char **argv)
{
	t_info i;
	t_philo *p;
	
	ft_check_1(argc, argv);
	ft_check_2(argv);
	ft_check_3(argv);
	ft_args_to_numbers(argc, argv, &i);
	ft_check_4(&i);
	p = ft_create_philosophers(&i);
	if(p != NULL)
	{
		ft_create_threads(p);
		ft_join_threads(p);

	}
	

		

	
}