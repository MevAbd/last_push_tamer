/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:37:52 by malbrand          #+#    #+#             */
/*   Updated: 2021/10/27 13:34:53 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_pos	ft_small(t_list *lst)
{
	t_pos	pos;
	int		i;

	i = 0;
	pos.size = ft_lst_size(lst);
	pos.min = lst->nb;
	pos.min_place = i;
	while (lst->next)
	{
		if (pos.min > lst->nb)
		{
			pos.min = lst->nb;
			pos.min_place = i;
		}
		lst = lst->next;
		i++;
	}
	i++;
	if (pos.min > lst->nb)
	{
		pos.min = lst->nb;
		pos.min_place = i;
	}
	return (pos);
}

t_stack	*ft_two(t_stack *st, char *str)
{
	st = ft_write_instruct(str, st);
	return (st);
}

t_stack	*ft_three(t_stack *st)
{
	int		a;
	int		b;
	int		c;
	t_list	*tmp1;

	tmp1 = st->st_a;
	a = tmp1->nb;
	tmp1 = tmp1->next;
	b = tmp1->nb;
	tmp1 = tmp1->next;
	c = tmp1->nb;
	if ((a > b && b < c && c > a) || (a > b && b > c && c < a))
		st = ft_write_instruct("sa\n", st);
	else if (a > b && b < c && c < a)
		st = ft_write_instruct("ra\n", st);
	else if (a < b && b > c && c > a)
		st = ft_write_instruct("sa\n", st);
	else if (a < b && b > c && c < a)
		st = ft_write_instruct("rra\n", st);
	return (st);
}

t_stack	*ft_for(t_stack *st)
{
	st = ft_nb_rotate(st);
	st = ft_choose_three(st);
	st = ft_write_instruct("pa\n", st);
	return (st);
}

t_stack	*ft_five(t_stack *st)
{
	st = ft_nb_rotate(st);
	st = ft_nb_rotate(st);
	st = ft_choose_three(st);
	if (ft_order(st->st_b) == 1)
		ft_two(st, "sb\n");
	st = ft_write_instruct("pa\n", st);
	st = ft_write_instruct("pa\n", st);
	while (ft_order(st->st_a) != 1)
		st = ft_five(st);
	return (st);
}
