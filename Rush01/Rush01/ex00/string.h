/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:59:01 by suhshin           #+#    #+#             */
/*   Updated: 2020/10/25 19:15:58 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H
# include <stdlib.h>
# include <stdio.h>

void	make_int_array(char *arr, int *number_arr, int *index, int *word_flag);
int		*allocation_int_array(int num);
int		cal_length_to_make_int_array(char *arr);
int		*split_input(char *arr);

#endif
