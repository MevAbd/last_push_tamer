/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:00:46 by malbrand          #+#    #+#             */
/*   Updated: 2021/11/02 04:04:15 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lstnew(int nb)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (elem == NULL)
		return (0);
	elem->nb = nb;
	elem->next = 0;
	return (elem);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}

t_list	*ft_init_a(int ac, char **av)
{
	int		i;
	t_list	*a;
	t_list	*add_a;

	i = 1;
	if (ac == 0)
	{
		a = NULL;
		return (a);
	}
	a = ft_lstnew(ft_atoi(av[i]));
	i++;
	while (ac > i)
	{
		add_a = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(&a, add_a);
		i++;
	}
	return (a);
}
