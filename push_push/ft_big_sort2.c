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
		while (j <= size_sort)
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
		while (j <= (size_sort))
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

t_stack	*ft_first_sort(int *tab, int *tab_sort, int slice, t_stack *st)
{
	t_mem		nb;
	int		size_lst;
	int		size_sort;
	int		max;

	size_sort = ft_lst_size(st->st_a);
	max = size_sort - slice - 1;
	while (ft_lst_size(st->st_a) > max)
	{
		tab = ft_init_tab(st->st_a);
		size_lst = ft_lst_size(st->st_a);
		nb = ft_sort_end(tab, tab_sort, size_lst, slice);
		st = ft_big_rotate(st, nb);
		st = ft_write_instruct("pb\n", st);
	}
	return (st);
}

t_stack	*ft_remoov(t_stack *st, int slice, int i)
{
	int	max;
	int	nb_rrotate;
	int	*tab;

	tab = ft_init_tab(st->st_b);
	max = ft_check_max(st->st_b);
	while (ft_lst_size(st->st_b) > slice)
	{
		i = 0;
		while (tab[i] != max)
			i++;
		if (i <= ft_lst_size(st->st_b) / 2)
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
		st = ft_write_instruct("pa\n", st);
		tab = ft_init_tab(st->st_b);
		max = ft_check_max(st->st_b);
	}
	return (st);
}
