/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 05:42:11 by malbrand          #+#    #+#             */
/*   Updated: 2021/10/28 17:20:02 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	*ft_swap(t_list *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack == NULL || stack->next == NULL)
		return (stack);
	tmp1 = stack;
	tmp2 = stack->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	return (tmp2);
}

t_list	*ft_rotate(t_list *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack == NULL || stack->next == NULL)
		return (stack);
	tmp1 = stack->next;
	tmp2 = stack;
	while (stack->next)
		stack = stack->next;
	tmp2->next = NULL;
	stack->next = tmp2;
	return (tmp1);
}

t_list	*ft_r_rotate(t_list *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack == NULL || stack->next == NULL)
		return (stack);
	tmp1 = stack;
	while (stack->next)
	{
		tmp2 = stack;
		stack = stack->next;
	}
	tmp2->next = NULL;
	stack->next = tmp1;
	return (stack);
}
/*
t_stack *ft_push_a(t_stack *st)
{
	t_list *st_a;
	t_list *st_b;
	t_list *node;

	if (st->st_b == NULL)
		return (st);
	st_a = st->st_a;
	st_b = st->st_b;
	node = st_b;
	if (st_b->next)
		st_b = st_b->next;
	node->next = st_a;
	st_a = node;
	st->st_b = st_b;
	st->st_a = st_a;
	return (st);
}

t_stack *ft_push_b(t_stack *st)
{
	t_list *st_a;
	t_list *st_b;
	t_list *node;

	if (st->st_a == NULL)
		return (st);
	st_a = st->st_a;
	st_b = st->st_b;
	node = st_a;
	if (st_a->next)
		st_a = st_a->next;
	node->next = st_b;
	st_b = node;
	st->st_a = st_a;
	st->st_b = st_b;
	return (st);
}*/	

t_stack	*ft_push_b(t_list *aa, t_list *bb)
{
	t_stack	*st;
	t_list	*tmp1;

	tmp1 = malloc(sizeof(t_list));
	st = malloc(sizeof(t_stack));
	st->st_a = aa;
	st->st_b = bb;
	if (aa)
	{
		tmp1 = aa;
		aa = aa->next;
		if (bb)
			tmp1->next = bb;
		else
			tmp1->next = NULL;
		st->st_b = tmp1;
		st->st_a = aa;
	}
	return (st);
}

t_stack	*ft_push_a(t_list *aa, t_list *bb)
{
	t_stack	*st;
	t_list	*tmp1;

	tmp1 = malloc(sizeof(t_list));
	st = malloc(sizeof(t_stack));
	st->st_a = aa;
	st->st_b = bb;
	if (bb)
	{
		tmp1 = bb;
		bb = bb->next;
		tmp1->next = aa;
		st->st_a = tmp1;
		if (bb)
			st->st_b = bb;
		if (!(bb))
			st->st_b = NULL;
	}
	return (st);
}
