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

int	get_min_index(t_stack stack)
{
	int	index;
	int	min_index;

	if (*(stack.size) == 0)
		return (-1);
	min_index = 0;
	index = 1;
	while (index < *(stack.size))
	{
		if (stack.stack[min_index] > stack.stack[index])
			min_index = index;
		index++;
	}
	return (min_index);
}

int	get_second_min_index(t_stack stack)
{
	int	index;
	int	min_index;
	int	second_min_index;

	if (*(stack.size) == 0)
		return (-1);
	min_index = get_min_index(stack);
	second_min_index = 0;
	index = 1;
	while (index < *(stack.size))
	{
		if (index != min_index
			&& stack.stack[second_min_index] > stack.stack[index])
			second_min_index = index;
		index++;
	}
	return (second_min_index);
}

int	is_sorted(t_stack stack)
{
	int	index;

	index = 0;
	while (index < *(stack.size) - 1)
	{
		if (stack.stack[index + 1] > stack.stack[index])
			return (0);
		index++;
	}
	return (1);
}

void	free_split(char **split)
{
	int	index;

	index = 0;
	while (split[index])
		free(split[index++]);
	free(split);
}

int	check_zero(char *expected_num)
{
	if (*expected_num == '+' || *expected_num == '-')
		expected_num++;
	while (*expected_num == '0')
		expected_num++;
	if (*expected_num != '\0')
		return (0);
	return (1);
}
