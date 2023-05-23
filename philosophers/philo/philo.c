/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:02:20 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/23 12:30:05 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		x++;
	}
	p = NULL;
}

t_philo *ft_create_node(int count, t_philo *p, t_info *i)
{
	t_philo *node;
	node = malloc(sizeof(t_philo));
	if(node == NULL)
	{
		ft_free_linked_list(count, p);
		free (i);
		return NULL;
	}

	node->id = count;
	node->nt_count = i->nt;
	node->info = i;
	node->next = NULL;

	node->eating_times = i->nt;
	if(pthread_mutex_init(&node->fork, NULL) != 0 || pthread_mutex_init(&node->lock, NULL) != 0)
	{
		printf("Eror\npthread_mutex_init failed!");
		ft_free_linked_list(count, p);
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

	p = ft_create_node(1, p, i);
	if(p == NULL)
		return NULL;
	x = 0;
	old = p;
	while(x < i-> n - 1)// -1 cause we already create  node above
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

int main(int argc, char **argv)
{	
	t_info	*i;
	t_philo *p;

	i = ft_parsing(argc, argv);
	if( i == NULL)
		return (0);
	p = ft_create_philosophers(i);
	if(p == NULL)
		return (0);

	printf("")
	
}
