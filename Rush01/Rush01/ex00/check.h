/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyjung <kyjung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:44:03 by kyjung            #+#    #+#             */
/*   Updated: 2020/10/25 20:03:13 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

int		r_l(int **map, int row);
int		r_r(int **map, int row);
int		c_u(int **map, int col);
int		c_d(int **map, int col);
int		check(void);

#endif
