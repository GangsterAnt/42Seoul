/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyjung <kyjing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:47:36 by kyjung            #+#    #+#             */
/*   Updated: 2020/10/28 17:47:36 by kyjung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int length_counter(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int valid(char *base)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (length_counter(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void ft_out(int nbr, char *base)
{
	int a;

	if (nbr == 0)
		return;
	a = nbr % 10;
	ft_out(nbr / 10, base);
	write(1, base[a], 1);
}

void ft_putnbr_base(int nbr, char *base)
{
	int v;

	v = valid(base);
	if (v == 0)
		return;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	ft_out(nbr, base);
}
