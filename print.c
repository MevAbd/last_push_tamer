#include "ft_push_swap.h"
void	ft_print(t_stack *st)
{
	int	size_a;
	int	size_b;

	t_list *a;
	t_list *b;

	a = st->st_a;
	b = st->st_b;
	size_a = ft_lst_size(a);
	size_b = ft_lst_size(st->st_b);

	printf("size_a: %d | size_b: %d\n", size_a, size_b);
	if (size_a > size_b)
	{
		while(size_a > 0)
		{
			if(size_a > size_b)
			{
				//printf("\033[34;01m%d\033[00m\n", a->nb);
				printf("%d\n", a->nb);
			}
			else
			{
				if (a->nb / 10 > 0)
				{
				//	printf("\033[34;01m%d\033[00m  %d\n", a->nb, b->nb);
					printf("%d  %d\n", a->nb, b->nb);
				}
				else
				{
			//		printf("\033[34;01m%d\033[00m   %d\n", a->nb, b->nb);
					printf("%d   %d\n", a->nb, b->nb);
				}
			}
			if (size_a == size_b)
			{
				b = b->next;
				size_b--;
			}
			size_a--;
			a = a->next;
		}
	}
	else
	{
		while(size_b > 0)
		{
			if(size_b > size_a)
				printf("    %d\n", b->nb);
			else
			{
				if (a->nb / 10 > 0)
				{
			//		printf("\033[34;01m%d\033[00m  %d\n", a->nb, b->nb);
					printf("%d  %d\n", a->nb, b->nb);
				}
				else
				{
					printf("%d   %d\n", a->nb, b->nb);
					//printf("\033[34;01m%d\033[00m   %d\n", a->nb, b->nb);
				}
			}
			if (size_b == size_a)
			{
				size_a--;
				a = a->next;
			}
			size_b--;
			b = b->next;
		}
	}
	printf("\n================\n");
}

