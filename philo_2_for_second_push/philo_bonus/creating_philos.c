/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:36:15 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/07 12:00:23 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_and_exit(t_info *i, t_philo *head)
{
	ft_free_linked_list(i->n, head);
	free(i);
	kill(0, SIGINT);
}

int	ft_atoi(char *arg)
{
	int		i;
	size_t	result;

	i = 0;
	result = 0;
	while (arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13))
		i++;
	if (arg[i] == '+')
		i++;
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		result = (result * 10) + (arg[i] - '0');
		i++;
	}
	while (arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13))
		i++;
	if (result > INT_MAX || arg[i] != '\0')
		return (0);
	return ((int)result);
}

void	ft_free_linked_list(int nodes_number, t_philo *p)
{
	int		x;
	t_philo	*node_saver;

	x = 0;
	while (x < nodes_number)
	{
		node_saver = p;
		p = p->next;
		free(node_saver);
		x++;
	}
	p = NULL;
}

t_philo	*ft_create_node(int nodes_number, t_philo *p, t_info *i)
{
	t_philo	*node;

	node = malloc(sizeof(t_philo));
	if (node == NULL)
	{
		ft_free_linked_list(nodes_number - 1, p);
		free (i);
		return (NULL);
	}
	node->id = nodes_number;
	node->eating_times = i->nt;
	node->info = i;
	node->next = NULL;
	node->last_eat = ft_epoch_time();
	return (node);
}

t_philo	*ft_create_philosophers(t_info *i)
{
	t_philo	*p;
	t_philo	*old;
	t_philo	*new;
	int		x;

	new = NULL;
	p = NULL;
	p = ft_create_node(1, p, i);
	if (p == NULL)
		exit(1);
	x = 0;
	old = p;
	while (x < i->n - 1)
	{
		new = ft_create_node(x + 2, p, i);
		if (p == NULL)
			exit (1);
		old->next = new;
		old = old->next;
		x++;
	}
	if (new != NULL)
		new->next = p;
	return (p);
}
