/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:35:13 by suhshin           #+#    #+#             */
/*   Updated: 2020/10/25 21:22:31 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid_maker.h"

extern int	**g_grid;
extern int	*g_str;
extern int	g_size;

int		**create_grid(void)
{
	int	j;
	int i;

	i = 0;
	j = 0;
	g_grid = (int **)malloc(sizeof(int *) * g_size);
	while (i < g_size)
	{
		g_grid[i] = (int *)malloc(sizeof(int) * g_size);
		j = 0;
		if (g_grid[i] == NULL)
		{
			free_arr();
			return (0);
		}
		while (j < g_size)
		{
			g_grid[i][j] = 0;
			j++;
		}
		i++;
	}
	if (g_grid == NULL)
		return (0);
	return (g_grid);
}

void	free_arr(void)
{
	int i;

	i = 0;
	while (i < g_size)
	{
		free(g_grid[i]);
		i++;
	}
	free(g_grid);
}
