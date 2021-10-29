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
	tab = (int *)malloc(sizeof(int) * ft_lst_size(aa) + 1);
	if (tab == NULL)
		return (NULL);
	while (aa->next)
	{
		tab[i] = aa->nb;
		i++;
		aa = aa->next;
	}
	tab[i] = aa->nb;
	i++;
	tab[i] = '\0';
	return (tab);
}

int	*ft_sort_tab(int *tab, int size_list)
{
	int	i;
	int	tmp;
	int	*tab2;

	tab2 = (int *)malloc(sizeof(int) * size_list + 1);
	if (tab2 == NULL)
		return (NULL);
	tab2 = tab;
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

t_stack	*ft_quick_sort(t_stack *st)
{
	int	*tab;
	int	*tab_sort;
	int	slice;
	int	slice_first;

	slice = ft_lst_size(st->st_a) / 2;
	slice_first = ft_lst_size(st->st_a) / 2;
	while (ft_lst_size(st->st_a) >= 2)
	{
		tab = ft_init_tab(st->st_a);
		tab_sort = ft_sort_tab(ft_init_tab(st->st_a), ft_lst_size(st->st_a));
		st = ft_first_sort(tab, tab_sort, slice, st);
		slice = ft_lst_size(st->st_a) / 2;
	}
	st = ft_remoov(st, slice_first, 0);
	st = ft_quick_sort_b(st, slice_first);
	st = ft_write_instruct("pa\n", st);
	return (st);
}

t_stack	*ft_quick_sort2(t_stack *st)
{
	int	*tab;
	int	*tab_sort;
	int	slice;
	int	slice_first;

	slice_first = ft_lst_size(st->st_a) / 2;
	st = ft_quick_sort(st);
	slice = ft_lst_size(st->st_a) / 2 / 2;
	while (ft_lst_size(st->st_a) >= slice_first)
	{
		tab = ft_init_tab(st->st_a);
		tab_sort = ft_sort_tab(ft_init_tab(st->st_a), ft_lst_size(st->st_a));
		st = ft_first_sort(tab, tab_sort, slice, st);
		slice = slice / 2;
	}
	st = ft_remoov(st, 1, 0);
	st = ft_write_instruct("pa\n", st);
	return (st);
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
