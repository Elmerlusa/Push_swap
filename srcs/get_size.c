/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:04:38 by javmarti          #+#    #+#             */
/*   Updated: 2022/12/05 13:04:38 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_size(char *str);

int	get_size(char *argv[])
{
	int		size;
	int		index;

	size = 0;
	index = 0;
	while (argv[++index])
	{
		if (ft_strchr(argv[index], ' ') == NULL)
			size++;
		else
			size += count_size(argv[index]);
	}
	return (size);
}

static int	count_size(char *str)
{
	int		count;
	char	**split;

	split = ft_split(str, ' ');
	count = 0;
	while (split[count])
		count++ ;
	free_split(split);
	return (count);
}
