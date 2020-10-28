/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:59:15 by jlim              #+#    #+#             */
/*   Updated: 2020/10/25 21:13:25 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

extern int	g_size;

void	make_int_array(char *arr, int *number_arr, int *index, int *word_flag)
{
	int save_num;
	int number_arr_index;

	save_num = 0;
	number_arr_index = 0;
	*word_flag = 0;
	*index = 0;
	while (arr[*index] != '\0')
	{
		if (!(*word_flag) && (arr[*index] != ' ') && arr[*index] != '\t')
			*word_flag = 1;
		else if (*word_flag && (arr[*index] == ' ' || arr[*index] == '\t'))
		{
			number_arr[number_arr_index++] = save_num;
			save_num = 0;
			*word_flag = 0;
		}
		if (*word_flag)
			save_num = (save_num * 10 + (int)(arr[*index] - 48));
		*index += 1;
	}
	if (*word_flag)
		number_arr[number_arr_index] = save_num;
}

int		*allocation_int_array(int num)
{
	int *arr;
	int index;

	index = 0;
	arr = (int *)malloc(sizeof(int) * (num + 1));
	while (index <= (num + 1))
	{
		arr[index] = 0;
		index++;
	}
	return (arr);
}

int		cal_length_to_make_int_array(char *arr)
{
	int index;
	int word_flag;
	int the_number_of_words;

	index = 0;
	word_flag = 0;
	the_number_of_words = 0;
	while (arr[index] != '\0')
	{
		if (!word_flag && arr[index] != ' ' && arr[index] != '\t')
			word_flag = 1;
		else if (word_flag && (arr[index] == ' ' || arr[index] == '\t'))
		{
			word_flag = 0;
			the_number_of_words += 1;
		}
		index++;
	}
	if (word_flag)
		the_number_of_words++;
	return (the_number_of_words);
}

int		*split_input(char *arr)
{
	int *number_arr;
	int index;
	int size_of_arr;
	int word_flag;

	index = 0;
	word_flag = 0;
	size_of_arr = cal_length_to_make_int_array(arr);
	number_arr = allocation_int_array(size_of_arr);
	make_int_array(arr, number_arr, &index, &word_flag);
	g_size = size_of_arr / 4;
	return (number_arr);
}
