/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:37:52 by malbrand          #+#    #+#             */
/*   Updated: 2021/11/02 00:23:24 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

t_stack	*ft_quick_ten(t_stack *st, int slice)
{
	int		*tab;
	int		*tab_sort;
	int		size;
	t_mem	nb;

	size = ft_lst_size(st->st_a) - slice;
	tab = ft_init_tab(st->st_a);
	tab_sort = ft_sort_tab(tab, ft_lst_size(st->st_a));
	free(tab);
	while (ft_lst_size(st->st_a) > size)
	{
		tab = ft_init_tab(st->st_a);
		nb = ft_sort_end(tab, tab_sort, ft_lst_size(st->st_a), slice);
		st = ft_big_rotate(st, nb);
		st = ft_write_instruct("pb\n", st);
		free(tab);
	}
	free(tab_sort);
	return (st);
}

t_stack	*ft_quick_five(t_stack *st)
{
	int	chunck;
	int	max;
	int	slice;

	chunck = 0;
	slice = ft_lst_size((st->st_a)) / 10;
	while (chunck < 9)
	{
		st = ft_quick_ten(st, slice);
		chunck++;
	}
	st = ft_quick_ten(st, ft_lst_size(st->st_a));
	max = ft_check_max(st->st_b);
	st = ft_remoov(st, 1, 0, max);
	st = ft_write_instruct("pa\n", st);
	return (st);
}

int	ft_check_min(t_list *lst)
{
	int	max;

	max = lst->nb;
	while (lst->next)
	{
		if (max > lst->nb)
			max = lst->nb;
		lst = lst->next;
	}
	if (max > lst->nb)
		max = lst->nb;
	return (max);
}

t_stack	*ft_five(t_stack *st)
{
	int	min;

	min = ft_check_min(st->st_a);
	while (st->st_a->nb != min)
		st = ft_write_instruct("ra\n", st);
	st = ft_write_instruct("pb\n", st);
	min = ft_check_min(st->st_a);
	while (st->st_a->nb != min)
		st = ft_write_instruct("ra\n", st);
	st = ft_write_instruct("pb\n", st);
	st = ft_choose_three(st);
	st = ft_write_instruct("pa\n", st);
	st = ft_write_instruct("pa\n", st);
	return (st);
}
