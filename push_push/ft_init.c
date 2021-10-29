#include "ft_push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lstnew_char(char *ope)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (elem == NULL)
		return (0);
	elem->str = ope;
	elem->next = 0;
	return (elem);
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

