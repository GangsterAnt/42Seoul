/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyjung <kyjung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 09:33:58 by suhshin           #+#    #+#             */
/*   Updated: 2020/10/25 19:59:28 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

extern int	**g_grid;
extern int	*g_str;
extern int	g_size;

int		r_l(int **map, int row)
{
	int max_level;
	int index;
	int left_val;
	int l;

	l = g_str[g_size * 2 + row];
	index = 0;
	max_level = 0;
	left_val = 0;
	while (index < g_size)
	{
		if (map[row][index] > max_level)
		{
			left_val++;
			max_level = map[row][index];
		}
		index++;
	}
	if (left_val == l)
		return (1);
	return (0);
}

int		r_r(int **map, int row)
{
	int max_level;
	int index;
	int r_val;
	int r;

	r = g_str[g_size * 3 + row];
	index = g_size - 1;
	max_level = 0;
	r_val = 0;
	while (index >= 0)
	{
		if (map[row][index] > max_level)
		{
			r_val++;
			max_level = map[row][index];
		}
		index--;
	}
	if (r_val == r)
		return (1);
	return (0);
}

int		c_u(int **map, int col)
{
	int max_level;
	int index;
	int u_val;
	int u;

	u = g_str[col];
	index = 0;
	max_level = 0;
	u_val = 0;
	while (index < g_size)
	{
		if (map[index][col] > max_level)
		{
			u_val++;
			max_level = map[index][col];
		}
		index++;
	}
	if (u_val == u)
		return (1);
	return (0);
}

int		c_d(int **map, int col)
{
	int max_level;
	int index;
	int d_val;
	int d;

	d = g_str[g_size + col];
	index = g_size - 1;
	max_level = 0;
	d_val = 0;
	while (index >= 0)
	{
		if (map[index][col] > max_level)
		{
			d_val++;
			max_level = map[index][col];
		}
		index--;
	}
	if (d_val == d)
		return (1);
	return (0);
}

int		check(void)
{
	int r;
	int c;

	r = 0;
	c = 0;
	while (r < g_size)
	{
		if (r_l(g_grid, r) && r_r(g_grid, r))
			r++;
		else
			return (0);
	}
	while (c < g_size)
	{
		if (c_u(g_grid, c) && c_d(g_grid, c))
			c++;
		else
			return (0);
	}
	return (1);
}
