/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:59:11 by javmarti          #+#    #+#             */
/*   Updated: 2022/11/19 16:59:11 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(int *stack, int size)
{
	int	index;
	int	min_index;

	if (size == 0)
		return (-1);
	min_index = 0;
	index = 1;
	while (index < size)
	{
		if (stack[min_index] > stack[index])
			min_index = index;
		index++;
	}
	return (min_index);
}

int	get_second_min_index(int *stack, int size)
{
	int	index;
	int	min_index;
	int	second_min_index;

	if (size == 0)
		return (-1);
	min_index = get_min_index(stack, size);
	second_min_index = 0;
	index = 1;
	while (index < size)
	{
		if (index != min_index && stack[second_min_index] > stack[index])
			second_min_index = index;
		index++;
	}
	return (second_min_index);
}

int	is_sorted(int *stack, int size)
{
	int	index;

	index = 0;
	while (index < size - 1)
	{
		if (stack[index + 1] > stack[index])
			return (0);
		index++;
	}
	return (1);
}
