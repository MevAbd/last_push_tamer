#include "ft_push_swap.h"

t_stack	*ft_quick_ten(t_stack *st, int slice)
{
	int		*tab;
	int		*tab_sort;
	int		size;
	t_mem	nb;
		size = ft_lst_size(st->st_a) - slice;
	tab_sort = ft_sort_tab(ft_init_tab(st->st_a), ft_lst_size(st->st_a));
	while (ft_lst_size(st->st_a) > size)
	{
		tab = ft_init_tab(st->st_a);
		nb = ft_sort_end(tab, tab_sort, ft_lst_size(st->st_a), slice);
		st = ft_big_rotate(st, nb);
		st = ft_write_instruct("pb\n", st);
	}
	return (st);
}

t_stack	*ft_quick_five(t_stack *st)
{
	int	chunck;
	int	slice;

	chunck = 0;
	slice = ft_lst_size((st->st_a)) / 10;
	while (chunck < 9)
	{
//		printf("slice ============ %d\n", slice);
		st = ft_quick_ten(st, slice);
		chunck++;
	}
	st = ft_quick_ten(st, ft_lst_size(st->st_a));
//	if (ft_lst_size(st->st_a) == 2 && ft_order(st->st_a) != 1)
//		st = ft_write_instruct("sa\n", st);
	st = ft_remoov(st, 1, 0);
	st = ft_write_instruct("pa\n", st);
	return (st);	
}
