
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define $PRINT(x) print_list(x);
#define $BR exit(0);
#define $PRINT2(x, y) print_list(x);print_list(y);
#define $PRINT_INT(x, s) print_int_tab(x, s);

typedef struct s_list
{
	int				nb;
	struct s_list	*n;
}					t_list;

t_list	*new_node(int n)
{
	t_list *ret;

	ret = malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->nb = n;
	ret->n = NULL;
}

void	add(t_list **src, t_list *node)
{
	t_list *tmp;
	if (!*src)
		*src = node;
	else
	{
		node->n = *src;
		*src = node;
	}
}

int	push(t_list **src, t_list **dst)
{
	t_list *node;

	if (!*src)
		return (0);
	node = *src;
	(*src) = (*src)->n;
	add(dst, node);
	return (1);
}

int	list_len(t_list *src)
{
	t_list *iter;
	int		i;

	i = 0;
	iter = src;
	if (!iter)
		return (0);
	while (iter)
	{
		iter = iter->n;
		i++;
	}
	return (i);
}

int	swap(t_list **src)
{
	t_list *next;

	if (!*src || list_len(*src) == 1)
		return (0);
	next = (*src)->n;
	(*src)->n = next->n;
	next->n = *src;
	*src = next;
	return (1);
}

int	rotate(t_list **src)
{
	t_list *node;

	if (!*src || list_len(*src) == 1)
		return (0);
	else if (list_len(*src) == 2)
		return (swap(src));
	node = *src;
	while (node && node->n)
		node = node->n;
	node->n = *src;
	(*src) = (*src)->n;
	node->n->n = NULL;
	return (1);
}

int	rrotate(t_list **src)
{
	t_list *node;
	t_list *node1;

	if (!*src || list_len(*src) == 1)
		return (0);
	else if (list_len(*src) == 2)
		return (swap(src));
	node = *src;
	while ((*src) && (*src)->n)
	{
		node1 = *src;
		*src = (*src)->n;
	}
	node1->n = NULL;
	(*src)->n = node;
}

int		is_same(char *s1, char *s2)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s1[i])
		i++;
	while (s2[y])
		y++;
	if (i != y)
		return (0);
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	write_op(t_list **a, t_list **b, char *str)
{
	if (is_same(str, "pa\n"))
		push(b, a);
	else if (is_same(str, "pb\n"))
		push(a, b);
	else if (is_same(str, "ra\n"))
		rotate(a);
	else if (is_same(str, "rb\n"))
		rotate(b);
	else if (is_same(str, "sa\n"))
		swap(a);
	else if (is_same(str, "sb\n"))
		swap(b);
	else if (is_same(str, "rra\n"))
		rrotate(a);
	else if (is_same(str, "rrb\n"))
		rrotate(b);
}

void	print_list(t_list *src)
{
	t_list *iter;

	iter = src;
	if (!iter)
		printf("is empty.\n");
	while (iter)
	{
		printf("[%d]\n", iter->nb);	
		iter = iter->n;
	}
	printf("\n\n\n");
}

void	print_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("| %d | - ", tab[i]);
		i++;
	}
	printf("\n");
}

void	arg_to_list(t_list **a, int argc, char **argv)
{
	while (argc > 1)
	{
		add(a, new_node(atoi(argv[argc - 1])));
		argc--;
	}
}

int		*list_to_int(t_list *src)
{
	int		*ret;
	int		i;
	t_list	*iter;
	
	i = 0;
	if (!src)
		return (NULL);
	ret = malloc(sizeof(int) * list_len(src));
	if (!ret)
		return (NULL);
	iter = src;
	while (iter)
	{
		ret[i] = iter->nb;
		iter = iter->n;
		i++;
	}
	return (ret);
}

void	sort_int(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i + 1 < size)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else 
			i++;
	}
}

int		getmax(int *tab, int size)
{
	int	max;

	max = 0;
	while (!(max = (size / 2) - 1))
		max++;
	return (max + 1);
}

void	a_to_b(t_list **a, t_list **b, t_list **c)
{
	(void)a;
	(void)b;
	(void)c;
	int	*tab;
	int	to_find;
	int	len;
	int	max;
	t_list	*ptr;

	ptr = *a;
	tab = list_to_int(ptr);
	sort_int(tab, list_len(ptr));
	len = list_len(ptr);
	max = len / 2;//getmax(tab, list_len(ptr));
	add(c, new_node(max));
	while (max)
	{
		while (!(ptr->nb < tab[len / 2]))
			rotate(*a);
		write_op(a, b, "pb\n");
		write(1, "x", 1);
	}
	$PRINT(*b);
	//$PRINT2(*a, *b)
	//$PRINT_INT(tab, len);
	//printf("max is: %d\n", max);
	//printf("mid is: %d\n", tab[len / 2]);
}

int	main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	t_list *c;

	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		printf("Error\n");
		return (0);
	}
	arg_to_list(&a, argc, argv);
	a_to_b(&a, &b, &c);
}
