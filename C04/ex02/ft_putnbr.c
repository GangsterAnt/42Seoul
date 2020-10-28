/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyjung <kyjing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:13:30 by kyjung            #+#    #+#             */
/*   Updated: 2020/10/28 17:13:30 by kyjung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

#	include <unistd.h>

long long	reverser(long long nb)
{
	long long	ret;
	long long	temp;

	temp = 0;
	ret = 0;
	if (nb < 0)
		temp = -1 * nb;
	else
		temp = nb;
	while (temp > 0)
	{
		ret *= 10;
		ret += temp % 10;
		temp /= 10;
	}
	return (ret);
}

int			cal_len(long long nb)
{
	int ret;

	ret = 0;
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		ret++;
		nb /= 10;
	}
	return (ret);
}

void		ft_putnbr(int nb)
{
	char		a;
	long long	rev_nb;
	int			length;
	int			index;

	index = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	length = cal_len(nb);
	rev_nb = reverser(nb);
	if (nb < 0)
		write(1, "-", 1);
	while (index < length)
	{
		a = rev_nb % 10 + '0';
		write(1, &a, 1);
		rev_nb /= 10;
		index++;
	}
}
