#include "ft_push_swap.h"

t_stack	*ft_quick_sort_rev(t_stack *st, int slice_first)
{
	int	*tab;
	int	*tab_sort;
	int	slice;
	(void)slice_first;

	slice = ft_lst_size(st->st_b) / 2;
	while (ft_lst_size(st->st_b) >= 2)
	{
		tab = ft_init_tab(st->st_b);
		tab_sort = ft_sort_tab_rev(ft_init_tab(st->st_b), ft_lst_size(st->st_b));
		st = ft_first_sort_b(tab, tab_sort, slice, st);
		slice = ft_lst_size(st->st_b) / 2;
	}
	return (st);
}

t_stack	*ft_remoov2(t_stack *st, int slice, int i)
{
	int	max;
	int	nb_rrotate;
	int	*tab;
	int	min_b;

	min_b = ft_lst_size(st->st_b) - slice;
	tab = ft_init_tab(st->st_b);
	max = ft_check_max(st->st_b);
	printf("min = %d\n", min_b);
	while (ft_lst_size(st->st_b) > min_b)
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


t_stack	*ft_hundred3(t_stack *st, int slice_mem)
{
	int	*tab;
	int	*tab_sort;
	int	slice;

	
	slice = ft_lst_size(st->st_a) / 2;
	while (ft_lst_size(st->st_a) >= slice_mem)
	{
		tab = ft_init_tab(st->st_a);
		tab_sort = ft_sort_tab(ft_init_tab(st->st_a), ft_lst_size(st->st_a));
		st = ft_first_sort(tab, tab_sort, slice, st);
		slice = (ft_lst_size(st->st_a) - slice_mem) / 2;
	}
	st = ft_remoov2(st, slice_mem, 0);
	st = ft_quick_sort_rev(st, 2);
	st = ft_write_instruct("pa\n", st);
	return (st);
}

t_stack	*ft_hundred2(t_stack *st)
{
	int	slice_mem;
//	int	slice_ev;

	slice_mem = ft_lst_size(st->st_a) / 10;
	st = ft_hundred(st, slice_mem);
//	slice_ev = slice_mem + slice_mem;
//	st = ft_hundred3(st, slice_ev);
	return (st);
}

t_stack	*ft_hundred(t_stack *st, int slice_mem)
{
	int	*tab;
	int	*tab_sort;
	int	slice;
	(void)slice_mem;

	
	slice = ft_lst_size(st->st_a) / 2;
	while (ft_lst_size(st->st_a) >= 2)
	{
		tab = ft_init_tab(st->st_a);
		tab_sort = ft_sort_tab(ft_init_tab(st->st_a), ft_lst_size(st->st_a));
		st = ft_first_sort(tab, tab_sort, slice, st);
		slice = ft_lst_size(st->st_a) / 2;
	}
	st = ft_remoov2(st, slice_mem, 0);
//	st = ft_quick_sort_rev(st, 2);
//	st = ft_write_instruct("pa\n", st);
	return (st);
}

