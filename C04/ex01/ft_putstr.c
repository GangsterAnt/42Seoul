/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyjung <kyjing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:11:52 by kyjung            #+#    #+#             */
/*   Updated: 2020/10/28 17:11:52 by kyjung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#	include <unistd.h>

int		ft_strlen(char *str)
{
	int size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}

void	ft_putstr(char *str)
{
	int size;

	size = ft_strlen(str);
	write(1, str, size);
}
