/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 02:51:35 by malbrand          #+#    #+#             */
/*   Updated: 2021/10/29 09:10:11 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int		nb;
	char		*str;
	struct s_list	*next;
}			t_list;

typedef struct s_stack
{
	struct s_list	*st_a;
	struct s_list	*st_b;
	struct s_list	*st_str;
}			t_stack;

typedef struct s_mem
{
	int	begin;
	int	b_place;
	int	end;
	int	e_place;
}		t_mem;

typedef struct s_pos
{
	int	min;
	int	min_place;
	int	size;
}		t_pos;

typedef struct s_nb
{
	int	aa;
	int	bb;
	int	cc;
}		t_nb;

int		ft_order(t_list *aa);
int		ft_val_end(t_list *lst);
int		ft_desc(t_list *aa);
int		ft_order(t_list *aa);
int		ft_check_argv(int ac, char **av);
int		ft_check_argv2(int ac, char **av);
int		ft_check_min_max(int ac, char **av);
int		ft_check_max(t_list *lst);
int		*ft_init_tab(t_list *aa);
int		ft_lst_size(t_list *lst);
int		ft_isdigit(int c);
int		ft_atoi(char const *s);
int		ft_strcmp(char *s1, char *s2);
int		*ft_sort_tab(int *tab, int size_list);
int		ft_check_min(t_list *lst);
int		*ft_sort_tab_rev(int *tab, int size_list);
void		ft_putstr(char *s);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_error(void);
void		ft_free_stack(t_stack *st);
char		*ft_itoa(int n, unsigned int j);
t_pos		ft_small(t_list *lst);
t_nb		ft_mem(t_list *a);
t_mem		ft_sort_end(int *tab, int *tab_sort, int size, int size_sort);
t_mem		ft_sort_sort(int *tab, int *tab_sort, int size, int size_sort);
t_list		*ft_init_a(int ac, char **av);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int nb);
t_list		*ft_lstnew_char(char *ope);
t_list		*ft_swap(t_list *stack);
t_list		*ft_rotate(t_list *stack);
t_list		*ft_r_rotate(t_list *stack);
t_stack		*test(t_stack *a);
t_stack		*ft_push_b(t_list *a, t_list *b);
t_stack		*ft_push_a(t_list *s, t_list *b);
t_stack		*ft_write_instruct(char *str, t_stack *st);
t_stack		*ft_write_instruct2(char *str, t_stack *st);
t_stack		*ft_quick_sort2(t_stack *st);
t_stack		*ft_first_sort(int *tab, int *tab_sort, int slice, t_stack *st);
t_stack		*ft_big_rotate(t_stack *st, t_mem nb);
t_stack		*ft_remoov(t_stack *st, int slice, int i);
t_stack		*ft_remoov_b(t_stack *st, int slice);
t_stack		*ft_quick_sort_b(t_stack *st, int slice);
t_stack		*ft_two(t_stack *st, char *str);
t_stack		*ft_three(t_stack *st);
t_stack		*ft_for(t_stack *st);
t_stack		*ft_five(t_stack *st);
t_stack		*ft_meduim(t_stack *st);
t_stack		*ft_nb_rotate(t_stack *st);
t_stack		*ft_choose_three(t_stack *st);
t_stack		*ft_first_sort_b(int *tab, int *tab_sort, int slice, t_stack *st);
t_stack		*ft_hundred(t_stack *st, int slice);
t_stack		*ft_hundred2(t_stack *st);
t_stack		*ft_quick_five(t_stack *st);
unsigned int	ft_count(unsigned int nb);
unsigned int	ft_sign(int n);

void	ft_print(t_stack *st);


#endif
