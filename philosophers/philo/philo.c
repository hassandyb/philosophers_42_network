/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:39:52 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/11 12:54:04 by hed-dyb          ###   ########.fr       */
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
void	ft_free_linked_list(t_philo_data *head)
{
	t_philo_data	*node_saver;
	while(head != NULL)
	{
		node_saver = head;
		head = head->next;
		free(node_saver);
	}
}

t_philo_data *ft_create_node(int i, t_philo_data *head)
{
	t_philo_data *node;
	node = malloc(sizeof(t_philo_data));
	printf("here   %d ------\n", i);
	if(node == NULL)
	{
		ft_free_linked_list(head);
		exit (1);
	}
	
	node->id = i;
	node->next = NULL;
	return (node);

}


t_philo_data *ft_create_philosophers(t_data *f)
{
	t_philo_data *p;
	t_philo_data *old;
	t_philo_data *new;
	int i;

	p = NULL;
	p = ft_create_node(1, p);

	i = 0;
	old = p;
	while(i < f->n - 1)
	{
		new = ft_create_node(i + 2, p);
		

		old->next = new;
		old = old->next;
		i++;
	}
	return (p);
}
//--------------------
void print_list(t_philo_data *p)
{
	while(p)
	{
		// printf("id = %d\n", p->id);
		if(p->next == NULL)
			break;
		p = p->next;
	}
	
}



int main (int argc, char **argv)
{
	//dont forget to protect pthread create and join...
	t_data f;
	t_philo_data *p;

	p = NULL;
	ft_check_1(argc, argv);
	ft_check_2(argv);
	ft_check_3(argv);
	ft_args_to_numbers(argc, argv, &f);
	ft_check_4(&f);
	p = ft_create_philosophers(&f);// re create the this function and printf list function


	
	print_list(p);
	
	// printf("%d     %d     %d   %d    %d", f.n, f.td, f.te, f.ts, f.nt);


	// ft_args_protection(argc, argv);
}

// for each philo :
// thread  create_
// id 0 1 2 3 
// fork  mutex