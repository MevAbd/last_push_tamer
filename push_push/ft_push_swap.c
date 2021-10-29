
#include "ft_push_swap.h"

t_stack	*ft_choose_three(t_stack *st)
{
	st = ft_three(st);
	if (ft_order(st->st_a) != 1)
		st = ft_three(st);
	return (st);
}


t_stack	*ft_choose_algo(t_stack *st, int ac)
{
(void)ac;
/*
	if (ac == 3)
		st = ft_two(st, "sa\n");
	else if (ac == 4)
		st = ft_choose_three(st);
	else if (ac == 5)
		st = ft_for(st);
	else if (ac == 6)
		st = ft_five(st);
	else if (ac < 52)
		st = ft_meduim(st);
	else if (ac < 470)*/
	//	st = ft_quick_sort2(st);
	//st = ft_hundred2(st);
	st = test(st);
	return (st);
}

int	main(int ac, char **av)
{
	t_stack	*st;

	st = malloc(sizeof(t_stack));
	if (st == NULL)
		return (0);
	st->st_a = NULL;
	st->st_b = NULL;
	st->st_str = NULL;
	if (ac == 2)
		return (0);
	if (ft_check_min_max(ac, av) == -1)
		ft_error();
	st->st_a = ft_init_a(ac, av);
	st->st_b = ft_init_a(0, NULL);
//	return (0);
	if (ft_order(st->st_a) == -1)
		st = ft_choose_algo(st, ac);
//	ft_free_stack(st);
	return (0);
}
