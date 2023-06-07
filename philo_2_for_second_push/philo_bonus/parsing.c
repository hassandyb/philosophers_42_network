/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:36:35 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/07 12:02:44 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_1(int argc, char **argv)
{
	int	j;
	int	i;

	if (argc != 5 && argc != 6)
	{
		write(1, "Error\ncheck args number!", 25);
		exit (1);
	}
	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i] && (argv[j][i] == ' ' || argv[j][i] == '\t'))
			i++;
		if (argv[j][i] == '\0' || argv[j][0] == '\0')
		{
			write(1, "Error\nEmpty argument or arument full of tabs/spaces", 56);
			exit (1);
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
		i = -1;
		while (argv[j][++i])
		{
			if (argv[j][i] != ' ' && argv[j][i] != '\t' && argv[j][i] != '+'
				&& (argv[j][i] < '0' || argv[j][i] > '9'))
			{
				write(2, "Error\nWrong charcter or you have -!", 36);
				exit (1);
			}
			if (argv[j][i] == '+' && (argv[j][i + 1] == ' '
				|| argv[j][i + 1] == '\t' || argv[j][i + 1] == '\0'))
			{
				write(2, "Error\n A + followed by Tab, space or null char!", 50);
				exit (1);
			}
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
			if ((argv[y][x] >= '0' && argv[y][x] <= '9')
				&& argv[y][x + 1] == '+')
			{
				write(1, "Error\nAdd space or tab after the sign +", 40);
				exit (1);
			}
			if (argv[y][x] == '+' && argv[y][x] == '+')
			{
				write(1, "Error\nYou have double + or more", 32);
				exit (1);
			}
			x++;
		}
		y++;
	}
}

void	ft_check_4(t_info *i)
{
	if (i->n == 0 || i->td == 0 || i->te == 0
		|| i->ts == 0)
	{
		write(1, "Error\nMAX INT, Arg = zero or invalid arg", 41);
		free(i);
		exit (1);
	}
	if (i->nt == 0)
	{
		free(i);
		exit (1);
	}
}

t_info	*ft_parsing(int argc, char **argv)
{
	t_info	*i;

	ft_check_1(argc, argv);
	ft_check_2(argv);
	ft_check_3(argv);
	i = malloc(sizeof(t_info));
	if (i == NULL)
		exit (1);
	i->n = ft_atoi(argv[1]);
	i->td = ft_atoi(argv[2]);
	i->te = ft_atoi(argv[3]);
	i->ts = ft_atoi(argv[4]);
	sem_unlink("/fork_semaphore");
	sem_unlink("/lock_semaphore");
	sem_unlink("/print_semaphore");
	i->fork = sem_open("/fork_semaphore", O_CREAT, 0644, i->n);
	i->lock = sem_open("/lock_semaphore", O_CREAT, 0644, 1);
	i->print = sem_open("/print_semaphore", O_CREAT, 0644, 1);
	if (argc == 6)
		i->nt = ft_atoi(argv[5]);
	else
		i->nt = -1;
	ft_check_4(i);
	return (i);
}
