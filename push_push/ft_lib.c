/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:02:12 by malbrand          #+#    #+#             */
/*   Updated: 2021/10/28 13:00:23 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_order(t_list *aa)
{
	int	mem;

	mem = aa->nb;
	aa = aa->next;
	if (mem > aa->nb)
		return (-1);
	while (aa->next)
	{
		mem = aa->nb;
		aa = aa->next;
		if (mem > aa->nb)
			return (-1);
	}
	return (1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
			write(1, &s[i++], 1);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(char const *s)
{
	int	i;
	int	ret;
	int	neg;

	i = 0;
	ret = 0;
	neg = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg *= -1;
		i++;
	}
	if (s[i] == '-' || s[i] == '+')
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
	{
		ret = ret * 10 + s[i] - '0';
		i++;
	}
	ret = ret * neg;
	return (ret);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

