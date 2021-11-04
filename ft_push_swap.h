/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 02:51:35 by malbrand          #+#    #+#             */
/*   Updated: 2021/11/02 00:07:31 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				nb;
	struct s_list	*next;
}					t_list;

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
	int	dd;
	int	ee;
}		t_nb;

int				ft_isdigit(int c);
int				ft_order(t_list *aa);
int				ft_atoi(char const *s);
int				ft_strcmp(char *s1, char *s2);
int				ft_lst_size(t_list *lst);
int				ft_check_argv(int ac, char **av);
int				ft_check_argv2(int ac, char **av);
int				ft_check_min_max(int ac, char **av);
int				*ft_init_tab(t_list *aa);
int				*ft_sort_tab(int *tab, int size_list);
int				ft_check_max(t_list *lst);
char			*ft_itoa(int n, unsigned int j);
void			ft_error(void);
void			ft_free_lst(t_list *lst);
void			ft_free_stack(t_stack *st);
void			ft_lstadd_back(t_list **alst, t_list *new);
t_mem			ft_sort_sort(int *tab, int *tab_sort, int size, int size_sort);
t_mem			ft_sort_end(int *tab, int *tab_sort, int size, int size_sort);
t_nb			ft_fill(t_stack *st);
t_list			*ft_lstnew(int nb);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_init_a(int ac, char **av);
t_list			*ft_swap(t_list *stack);
t_list			*ft_r_rotate(t_list *stack);
t_list			*ft_rotate(t_list *stack);
t_stack			*ft_three(t_stack *st);
t_stack			*ft_choose_three(t_stack *st);
t_stack			*ft_two(t_stack *st, char *str);
void			ft_push_lst(t_list **aa, t_list **bb);
t_stack			*ft_big_rotate(t_stack *st, t_mem nb);
t_stack			*ft_remoov(t_stack *st, int slice, int i, int max);
t_stack			*ft_write_instruct(char *str, t_stack *st);
t_stack			*ft_write_instruct2(char *str, t_stack *st);
t_stack			*ft_quick_ten(t_stack *st, int slice);
t_stack			*ft_quick_five(t_stack *st);
t_stack			*ft_choose_five(t_stack *st);
t_stack			*ft_five(t_stack *st);
t_stack			*ft_moov(t_stack *st);
t_stack			*ft_moov_bis(t_stack *st);
unsigned int	ft_sign(int n);
unsigned int	ft_count(unsigned int nb);
void			ft_print(t_stack *st);

#endif
