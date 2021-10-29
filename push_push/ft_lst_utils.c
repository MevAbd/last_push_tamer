/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:09:02 by malbrand          #+#    #+#             */
/*   Updated: 2021/10/28 22:26:47 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_desc(t_list *aa)
{
	int	mem;

	mem = aa->nb;
	aa = aa->next;
	if (mem < aa->nb)
		return (-1);
	while (aa->next)
	{
		mem = aa->nb;
		aa = aa->next;
		if (mem < aa->nb)
			return (-1);
	}
	return (1);
}

int	ft_val_end(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst->nb);
}

t_stack	*ft_nb_rotate(t_stack *st)
{
	t_pos	pos;
	int		nb_rrotate;

	pos = ft_small(st->st_a);
	if (pos.min_place <= pos.size / 2)
	{
		while (pos.min_place > 0)
		{
			st = ft_write_instruct("ra\n", st);
			pos.min_place--;
		}
		st = ft_write_instruct("pb\n", st);
	}
	else if (pos.min_place > pos.size / 2)
	{
		nb_rrotate = pos.size - pos.min_place;
		while (nb_rrotate-- >= 0)
			st = ft_write_instruct("rra\n", st);
		st = ft_write_instruct("pb\n", st);
	}
	return (st);
}

t_stack	*ft_meduim(t_stack *st)
{
	int	size;

	size = ft_lst_size(st->st_a);
	while (size >= 1)
	{
		st = ft_nb_rotate(st);
		size = ft_lst_size(st->st_a);
	}
	size = ft_lst_size(st->st_b);
	while (size > 0)
	{
		st = ft_write_instruct("pa\n", st);
		size = ft_lst_size(st->st_b);
	}
	while (ft_order(st->st_a) != 1)
		st = ft_meduim(st);
	return (st);
}
