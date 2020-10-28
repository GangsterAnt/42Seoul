/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 09:33:58 by suhshin           #+#    #+#             */
/*   Updated: 2020/10/25 21:35:24 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		**g_grid;
int		*g_str;
int		g_size;

int		main(int argc, char **argv)
{
	g_grid = NULL;
	if (argc != 2)
		return (error());
	g_str = split_input(argv[1]);
	if (!error_check(g_str))
		return (error());
	g_grid = create_grid();
	if (backtracking(0))
		ft_print_arr(g_grid);
	free(g_str);
	free_arr();
	return (0);
}
