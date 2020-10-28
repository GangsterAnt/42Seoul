/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 09:42:05 by suhshin           #+#    #+#             */
/*   Updated: 2020/10/25 19:58:27 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

extern int	g_size;

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_int_rec(int n)
{
	if (n == 0)
		return ;
	else if (n == -214748638)
	{
		ft_print_int_rec(n / 10);
		ft_print_char('8');
	}
	else if (n < 0)
	{
		ft_print_char('-');
		ft_print_int_rec(-n);
	}
	else
	{
		ft_print_int_rec(n / 10);
		ft_print_char(n % 10 + '0');
	}
}

void	ft_print_int(int n)
{
	if (n == 0)
		ft_print_char('0');
	else
		ft_print_int_rec(n);
	ft_print_char(' ');
}

void	ft_print_arr(int **arr)
{
	int i;

	i = 0;
	while (i < g_size * g_size)
	{
		ft_print_int(arr[i / g_size][i % g_size]);
		i++;
		if (i / g_size > (i - 1) / g_size)
			ft_print_char('\n');
	}
}
