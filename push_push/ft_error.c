/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:00:46 by malbrand          #+#    #+#             */
/*   Updated: 2021/10/28 10:37:14 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	ft_check_argv(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 1)
		return (-1);
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (!(ft_strcmp(av[i], av[j])))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_argv2(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ft_check_argv(ac, av) == -1)
		ft_error();
	else
	{
		while (av[i])
		{
			if (ft_atoi(av[i]) == 0 && av[i][0] != '0')
				return (-1);
			j = 0;
			while (av[i][j])
			{
				if (j == 0 && av[i][j] == '-')
					j++;
				if (ft_isdigit(av[i][j]) == 0)
					return (-1);
				j++;
			}
			i++;
		}
	}
	return (1);
}

int	ft_check_min_max(int ac, char **av)
{
	int				index;
	unsigned int	j;
	char			*str;

	j = 0;
	index = 1;
	if (ft_check_argv2(ac, av) == -1)
		ft_error();
	else
	{
		while (ac > index)
		{
			str = ft_itoa(ft_atoi(av[index]), j);
			if (ft_strcmp(str, av[index]) != 0)
			{
				free(str);
				return (-1);
			}
			free(str);
			index++;
		}
	}
	return (1);
}
