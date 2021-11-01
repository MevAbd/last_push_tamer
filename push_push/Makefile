# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malbrand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 08:16:12 by malbrand          #+#    #+#              #
#    Updated: 2021/11/01 23:11:16 by malbrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
 
SRC = ft_push_swap.c ft_error.c ft_instruct.c ft_itoa.c ft_init.c ft_lib.c ft_big_sort1.c ft_big_sort2.c ft_operation.c ft_free.c ft_small_algo.c

OBJ = ${SRC:.c=.o}

FLAGS = -Wall -Wextra -Werror -g

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

NAME = push_swap

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
