/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:17:49 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/23 14:53:45 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_linked_list(int nodes_number, t_philo *p)
{
	int x;

	x = 0;
	t_philo	*node_saver;
	while(x < nodes_number)
	{
		node_saver = p;
		p = p->next;
		free(node_saver);
		x++;
	}
	p = NULL;
}

t_philo *ft_create_node(int nodes_number, t_philo *p, t_info *i)
{
	t_philo *node;
	node = malloc(sizeof(t_philo));
	if(node == NULL)
	{
		ft_free_linked_list(nodes_number - 1, p);
		free (i);
		return NULL;
	}

	node->id = nodes_number;
	node->eating_times = i->nt;
	node->info = i;
	node->next = NULL;
	if(pthread_mutex_init(&node->fork, NULL) != 0 || pthread_mutex_init(&node->lock, NULL) != 0)
	{
		printf("Eror\npthread_mutex_init failed!");
		ft_free_linked_list(nodes_number - 1, p);
		free (i);
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
	if(p == NULL)
		return NULL;
	x = 0;
	old = p;
	while(x < i->n - 1)// -1 cause we already create  node above
	{
		new = ft_create_node(x + 2, p, i);
		if(p == NULL)
			return NULL;
		old->next = new;
		old = old->next;
		x++;
	}
	new->next = p;
	return (p);
}
