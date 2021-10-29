#include "ft_push_swap.h"

int	*ft_sort_tab_rev(int *tab, int size_list)
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
		if (tab2[i] < tab2[i + 1] && i + 1 < size_list)
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

t_stack	*ft_big_rotate_b(t_stack *st, t_mem nb)
{
	int	nb_rrotate;

	nb_rrotate = ft_lst_size(st->st_b) - nb.e_place;
	if (nb.b_place <= nb_rrotate)
	{
		while (nb.b_place-- > 0)
			st = ft_write_instruct("rb\n", st);
		return (st);
	}
	else
	{
		while (nb_rrotate-- > 0)
			st = ft_write_instruct("rrb\n", st);
	}
	return (st);
}

t_stack	*ft_first_sort_b(int *tab, int *tab_sort, int slice, t_stack *st)
{
	t_mem		nb;
	int		size_lst;
	int		size_sort;
	int		max;

	size_sort = ft_lst_size(st->st_b);
	max = size_sort - slice - 1;
	while (ft_lst_size(st->st_b) > max)
	{
		tab = ft_init_tab(st->st_b);
		size_lst = ft_lst_size(st->st_b);
		nb = ft_sort_end(tab, tab_sort, size_lst, slice);
		st = ft_big_rotate_b(st, nb);
		st = ft_write_instruct("pa\n", st);
	}
	return (st);
}

t_stack	*ft_quick_sort_b(t_stack *st, int slice_first)
{
	int	*tab;
	int	*tab_sort;
	int	slice;
	(void)slice_first;

	slice = ft_lst_size(st->st_b) / 2;
	while (ft_lst_size(st->st_b) >= 2)
	{
		tab = ft_init_tab(st->st_b);
		tab_sort = ft_sort_tab(ft_init_tab(st->st_b), ft_lst_size(st->st_b));
		st = ft_first_sort_b(tab, tab_sort, slice, st);
		slice = ft_lst_size(st->st_b) / 2;
	}
	return (st);
}

int	ft_check_min(t_list *lst)
{
	int	min;

	min = lst->nb;
	while (lst->next)
	{
		if (min > lst->nb)
			min = lst->nb;
		lst = lst->next;
	}
	if (min > lst->nb)
		min = lst->nb;
	return (min);
}
