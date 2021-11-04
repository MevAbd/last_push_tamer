/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:00:46 by malbrand          #+#    #+#             */
/*   Updated: 2021/11/01 23:40:55 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_nb	ft_fill(t_stack *st)
{
	t_nb	nb;
	t_list	*tmp;

	tmp = st->st_a;
	nb.aa = tmp->nb;
	tmp = tmp->next;
	nb.bb = tmp->nb;
	tmp = tmp->next;
	nb.cc = tmp->nb;
	if (tmp->next)
	{
		tmp = tmp->next;
		nb.dd = tmp->nb;
	}
	if (tmp->next)
	{
		tmp = tmp->next;
		nb.ee = tmp->nb;
	}
	return (nb);
}

t_stack	*ft_write_moov2(t_stack *st, int nb)
{
	if (nb == 0)
		st = ft_write_instruct("pa\n", st);
	else if (nb == 1)
	{
		st = ft_write_instruct("pa\n", st);
		st = ft_write_instruct("ra\n", st);
	}
	else if (nb == 2)
	{
		st = ft_write_instruct("pa\n", st);
		st = ft_write_instruct("sa\n", st);
	}
	return (st);
}

t_stack	*ft_write_moov(t_stack *st, int nb)
{
	if (nb < 3)
		st = ft_write_moov2(st, nb);
	else if (nb == 3)
	{
		st = ft_write_instruct("rra\n", st);
		st = ft_write_instruct("pa\n", st);
		st = ft_write_instruct("ra\n", st);
		st = ft_write_instruct("ra\n", st);
	}
	else if (nb == 4)
	{
		st = ft_write_instruct("ra\n", st);
		st = ft_write_instruct("ra\n", st);
		st = ft_write_instruct("pa\n", st);
		st = ft_write_instruct("rra\n", st);
		st = ft_write_instruct("rra\n", st);
	}
	return (st);
}

t_stack	*ft_moov(t_stack *st)
{
	t_nb	nb;
	int		b;

	b = st->st_b->nb;
	nb = ft_fill(st);
	if (b > nb.aa && b > nb.bb & b > nb.cc)
		st = ft_write_moov(st, 1);
	if (b < nb.aa && b < nb.bb & b < nb.cc)
		st = ft_write_moov(st, 0);
	if (b > nb.aa && b < nb.bb & b < nb.cc)
		st = ft_write_moov(st, 2);
	if (b > nb.aa && b > nb.bb & b < nb.cc)
		st = ft_write_moov(st, 3);
	return (st);
}

t_stack	*ft_moov_bis(t_stack *st)
{
	t_nb	nb;
	int		b;

	b = st->st_b->nb;
	nb = ft_fill(st);
	if (b > nb.aa && b > nb.bb & b > nb.cc && b > nb.dd)
		st = ft_write_moov(st, 1);
	if (b < nb.aa && b < nb.bb & b < nb.cc && b < nb.dd)
		st = ft_write_moov(st, 0);
	if (b > nb.aa && b < nb.bb & b < nb.cc && b < nb.dd)
		st = ft_write_moov(st, 2);
	if (b > nb.aa && b > nb.bb & b < nb.cc && b < nb.dd)
		st = ft_write_moov(st, 4);
	if (b > nb.aa && b > nb.bb & b > nb.cc && b < nb.dd)
		st = ft_write_moov(st, 3);
	return (st);
}
