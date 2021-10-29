/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 05:03:26 by malbrand          #+#    #+#             */
/*   Updated: 2021/10/29 09:21:24 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_write_instruct(char *str, t_stack *st)
{
	if (str[0] == 's' && str[1] == 'a')
	{
		st->st_a = ft_swap(st->st_a);
		write(1, str, 3);
	}
	else if (str[0] == 'r' && str[1] == 'a')
	{
		st->st_a = ft_rotate(st->st_a);
		write(1, str, 3);
	}
	else if (str[0] == 'p' && str[1] == 'a')
	{
		st = ft_push_a(st->st_a, st->st_b);
		write(1, str, 3);
	}
	else if (str[0] == 'p' && str[1] == 'b')
	{
		st = ft_push_b(st->st_a, st->st_b);
		write(1, str, 3);
	}
	else
		ft_write_instruct2(str, st);
//	ft_print(st);
	return (st);
}

t_stack	*ft_write_instruct2(char *str, t_stack *st)
{
	int	i;

	i = 0;
	if (str[0] == 's' && str[1] == 'b')
	{
		st->st_b = ft_swap(st->st_b);
		write(1, str, 3);
	}
	else if (str[0] == 'r' && str[1] == 'b')
	{
		st->st_b = ft_rotate(st->st_b);
		write(1, str, 3);
	}
	else if (str[i] == 'r' && str[i + 1] == 'r' && str[i + 2] == 'a')
	{
		st->st_a = ft_r_rotate(st->st_a);
		write(1, str, 4);
	}
	else if (str[i] == 'r' && str[i + 1] == 'r' && str[i + 2] == 'b')
	{
		st->st_b = ft_r_rotate(st->st_b);
		write(1, str, 4);
	}
//	ft_print(st);
	return (st);
}
