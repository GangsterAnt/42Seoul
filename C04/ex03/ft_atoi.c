/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyjung <kyjing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:18:59 by kyjung            #+#    #+#             */
/*   Updated: 2020/10/28 17:18:59 by kyjung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int return_ret(char *str, int index)
{
	int ret;

	ret = 0;
	while ('0' <= str[index] && str[index] <= '9')
	{
		ret *= 10;
		ret += str[index] - '0';
		index++;
	}
	return ret;
}

int	ft_atoi(char *str)
{
	int index;
	int ret;
	int p_m;

	p_m = 0;
	ret = 0;
	index = 0;
	while ( str[index] != '\0')
	{
		if( str[index] == '-')
			p_m++;
		else if('0' <= str[index] && str[index] <= '9')
		{
			ret = return_ret(str, index);
			break;
		}
		index++;
	}

	if (p_m % 2 == 0)
		return (ret);
	return (ret * -1);
}
