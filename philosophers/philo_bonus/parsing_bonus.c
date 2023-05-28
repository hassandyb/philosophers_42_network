/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:50:58 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/05/28 11:56:59 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_check_1(int argc, char **argv)
{
	int	j;
	int	i;

	if (argc != 5 && argc != 6)
	{
		write(1, "Error\ncheck args number!", 25);
		return (0);
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
			return (0);
		}
		j++;
	}
	return (1);
}

int	ft_check_2(char **argv)
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
				return (0);
			}
			if (argv[j][i] == '+' && (argv[j][i + 1] == ' '
				|| argv[j][i + 1] == '\t' || argv[j][i + 1] == '\0'))
			{
				write(2, "Error\n A + followed by Tab, space or null char!", 50);
				return (0);
			}
		}
		j++;
	}
	return (1);
}

int	ft_check_3(char **argv)
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
				return (0);
			}
			if (argv[y][x] == '+' && argv[y][x] == '+')
			{
				write(1, "Error\nYou have double + or more", 32);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_4(t_info *i)
{
	if (i->n <= 0 || i->td <= 0 || i->te <= 0
		|| i->ts <= 0 || i->nt < -1 || i->nt == 0)
	{
		write(1, "Error\n One of your args equal to ZERO", 38);
		return (0);
	}
	return (1);
}

t_info	*ft_parsing(int argc, char **argv)
{
	t_info	*i;

	if (ft_check_1(argc, argv) == 0)
		return (NULL);
	if (ft_check_2(argv) == 0)
		return (NULL);
	if (ft_check_3(argv) == 0)
		return (NULL);
	i = malloc(sizeof(t_info));
	if (i == NULL)
		return (NULL);
	i->n = ft_atoi(argv[1]);
	i->td = ft_atoi(argv[2]);
	i->te = ft_atoi(argv[3]);
	i->ts = ft_atoi(argv[4]);
	if (argc == 6)
		i->nt = ft_atoi(argv[5]);
	else
		i->nt = -1;
	if (ft_check_4(i) == 0)
	{
		free (i);
		return (NULL);
	}
	return (i);
}
