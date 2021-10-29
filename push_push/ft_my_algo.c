#include "ft_push_swap.h"

t_nb	ft_mem(t_list *a)
{
		t_nb	nbr;

		nbr.aa = a->nb;
		a = a->next;
		nbr.bb = a->nb;
		while (a->next)
				a = a->next;
		nbr.cc = a->nb;
		return (nbr);
}

t_stack	*ft_ope(t_stack *st, int i)
{
		if (i == 1)
		{
				st = ft_write_instruct("rra\n", st);
				st = ft_write_instruct("sa\n", st);
				st = ft_write_instruct("ra\n", st);
				st = ft_write_instruct("sa\n", st);
		}
		else if (i == 2)
				st = ft_write_instruct("sa\n", st);
		else if (i == 3)
				st = ft_write_instruct("ra\n", st);
		if (i == 4)
		{
				st = ft_write_instruct("sa\n", st);
				st = ft_write_instruct("rra\n", st);
				st = ft_write_instruct("sa\n", st);
		}
		else if (i == 5)
		{
				st = ft_write_instruct("sa\n", st);
				st = ft_write_instruct("rra\n", st);
				st = ft_write_instruct("sa\n", st);
				st = ft_write_instruct("ra\n", st);
				st = ft_write_instruct("sa\n", st);
		}
		return (st);
}


t_stack	*ft_ope3(t_stack *st)
{
		st = ft_write_instruct("rra\n", st);
		st = ft_write_instruct("sa\n", st);
		return (st);
}

t_stack	*test(t_stack *st)
{
		t_nb	nbr;
		int		test;

		nbr = ft_mem(st->st_a);
		test = ft_order(st->st_a);
		while (test == -1)
		{
				if (nbr.aa < nbr.bb && nbr.aa < nbr.cc && nbr.bb < nbr.cc)
						st = ft_ope(st, 1);
				else if (nbr.aa > nbr.bb && nbr.aa > nbr.cc && nbr.bb > nbr.cc)
						st = ft_ope(st, 2);
				else if (nbr.aa < nbr.bb && nbr.aa > nbr.cc && nbr.bb > nbr.cc)
						st = ft_ope(st, 3);
				else if (nbr.aa > nbr.bb && nbr.aa > nbr.cc && nbr.bb < nbr.cc)
						st = ft_ope(st, 4);
				else if (nbr.aa > nbr.bb && nbr.aa < nbr.cc && nbr.bb < nbr.cc)
						st = ft_ope(st, 5);
				else if (nbr.aa < nbr.bb && nbr.aa < nbr.cc && nbr.bb > nbr.cc)
						st = ft_ope3(st);
				nbr = ft_mem(st->st_a);
				test = ft_order(st->st_a);
		}
		if (ft_order(st->st_a) == 1)
				return (st);
		st = ft_write_instruct("rra\n", st);
		st = ft_write_instruct("sa\n", st);
		return (st);
}

