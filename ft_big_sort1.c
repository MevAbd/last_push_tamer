/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:00:46 by malbrand          #+#    #+#             */
/*   Updated: 2021/11/01 22:10:33 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_lst_size(t_list *lst)
{
	int	i;

	i = 0;
	if (lst && lst->next == NULL)
		return (1);
	if (lst && lst->next)
	{
		while (lst != NULL)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}

int	*ft_init_tab(t_list *aa)
{
	int	*tab;
	int	i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * ft_lst_size(aa) + 4);
	if (tab == NULL)
		return (NULL);
	while (aa->next)
	{
		tab[i] = aa->nb;
		i++;
		aa = aa->next;
	}
	tab[i] = aa->nb;
	return (tab);
}

int	*ft_tabcpy(int *tab, int size)
{
	int	i;
	int	*tab_cpy;

	tab_cpy = (int *)malloc(sizeof(int) * size + 4);
	if (tab_cpy == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab_cpy[i] = tab[i];
		i++;
	}
	return (tab_cpy);
}

int	*ft_sort_tab(int *tab, int size_list)
{
	int	i;
	int	tmp;
	int	*tab2;

	tab2 = ft_tabcpy(tab, size_list);
	i = 0;
	while (i + 1 < size_list)
	{
		if (tab2[i] > tab2[i + 1] && i + 1 < size_list)
		{
			tmp = tab2[i];
			tab2[i] = tab2[i + 1];
			tab2[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	tab2[i] = '\0';
	return (tab2);
}

int	ft_check_max(t_list *lst)
{
	int	max;

	max = lst->nb;
	while (lst->next)
	{
		if (max < lst->nb)
			max = lst->nb;
		lst = lst->next;
	}
	if (max < lst->nb)
		max = lst->nb;
	return (max);
}
