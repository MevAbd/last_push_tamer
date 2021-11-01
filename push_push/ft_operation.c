/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 05:42:11 by malbrand          #+#    #+#             */
/*   Updated: 2021/11/01 23:10:01 by malbrand         ###   ########.fr       */
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

void	ft_push_lst(t_list **aa, t_list **bb)
{
	t_list	*tmp1;

	if (*aa)
	{
		tmp1 = *aa;
		*aa = (*aa)->next;
		if (*bb)
			tmp1->next = *bb;
		else
			tmp1->next = NULL;
		*bb = tmp1;
	}
}
