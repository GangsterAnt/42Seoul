/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 09:36:54 by suhshin           #+#    #+#             */
/*   Updated: 2020/10/25 21:16:32 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

extern int	g_size;

int		error(void)
{
	write(1, "Error", 5);
	return (0);
}

int		error_check(int *str)
{
	int index_l;

	if (str == NULL)
		return (0);
	index_l = 0;
	while (index_l < g_size * 4)
	{
		if (str[index_l] < 1 || str[index_l] > g_size)
			return (0);
		index_l++;
	}
	return (1);
}
