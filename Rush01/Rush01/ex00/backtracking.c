/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:37:12 by suhshin           #+#    #+#             */
/*   Updated: 2020/10/25 21:35:13 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtracking.h"

extern int	**g_grid;
extern int	*g_str;
extern int	g_size;

int		backtracking(int idx)
{
	int row;
	int col;
	int i;

	i = 1;
	row = idx / g_size;
	col = idx % g_size;
	if (idx >= g_size * g_size)
	{
		if (check())
			return (1);
		return (0);
	}
	while (i < g_size + 1)
	{
		if (rocl_check(row, col, i))
		{
			g_grid[row][col] = i;
			if (backtracking(idx + 1))
				return (1);
			g_grid[row][col] = 0;
		}
		i++;
	}
	return (0);
}

int		rocl_check(int row, int col, int value)
{
	int i;

	i = 0;
	while (i < g_size)
		if (g_grid[i++][col] == value)
			return (0);
	i = 0;
	while (i < g_size)
		if (g_grid[row][i++] == value)
			return (0);
	return (1);
}
