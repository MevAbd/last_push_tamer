/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:00:46 by malbrand          #+#    #+#             */
/*   Updated: 2021/11/01 23:21:18 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_mem	ft_sort_sort(int *tab, int *tab_sort, int size, int size_sort)
{
	int		i;
	int		j;
	t_mem	nb;

	i = 0;
	nb.begin = tab[i];
	nb.b_place = i;
	while (i < size)
	{
		j = 0;
		while (j < size_sort)
		{
			if (tab[i] == tab_sort[j])
			{
				nb.begin = tab[i];
				nb.b_place = i;
				return (nb);
			}
			j++;
		}
		i++;
	}
	return (nb);
}

t_mem	ft_sort_end(int *tab, int *tab_sort, int size, int size_sort)
{
	int		j;
	t_mem	nb;

	nb = ft_sort_sort(tab, tab_sort, size, size_sort);
	size--;
	nb.end = tab[size];
	nb.e_place = size;
	while (size > 0)
	{
		j = 0;
		while (j < (size_sort))
		{
			if (tab[size] == tab_sort[j])
			{
				nb.end = tab[size];
				nb.e_place = size;
				return (nb);
			}
			j++;
		}
		size--;
	}
	return (nb);
}

t_stack	*ft_big_rotate(t_stack *st, t_mem nb)
{
	int	nb_rrotate;

	nb_rrotate = ft_lst_size(st->st_a) - nb.e_place;
	if (nb.b_place <= nb_rrotate)
	{
		while (nb.b_place-- > 0)
			st = ft_write_instruct("ra\n", st);
		return (st);
	}
	else
	{
		while (nb_rrotate-- > 0)
			st = ft_write_instruct("rra\n", st);
	}
	return (st);
}

t_stack	*ft_normi(t_stack *st, int i, int size)
{
	int	nb_rrotate;

	if (i <= size)
	{
		while (i-- > 0)
			st = ft_write_instruct("rb\n", st);
	}
	else
	{
		nb_rrotate = ft_lst_size(st->st_b) - i;
		while (nb_rrotate-- > 0)
			st = ft_write_instruct("rrb\n", st);
	}
	return (st);
}

t_stack	*ft_remoov(t_stack *st, int slice, int i, int max)
{
	int	*tab;

	tab = ft_init_tab(st->st_b);
	while (ft_lst_size(st->st_b) > slice)
	{
		i = 0;
		while (tab[i] != max)
			i++;
		st = ft_normi(st, i, (ft_lst_size(st->st_b) / 2));
		st = ft_write_instruct("pa\n", st);
		free(tab);
		tab = ft_init_tab(st->st_b);
		max = ft_check_max(st->st_b);
	}
	free(tab);
	return (st);
}
