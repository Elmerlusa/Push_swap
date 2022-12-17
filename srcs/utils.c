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

int	get_max_num(t_stack stack)
{
	int	index;
	int	index_max;

	if (*(stack.size) == 0)
		return (-1);
	index_max = 0;
	index = 1;
	while (index < *(stack.size))
	{
		if (stack.stack[index_max] < stack.stack[index])
			index_max = index;
		index++;
	}
	return (stack.stack[index_max]);
}

int	get_min_num(t_stack stack)
{
	int	index;
	int	index_min;

	if (*(stack.size) == 0)
		return (-1);
	index_min = 0;
	index = 1;
	while (index < *(stack.size))
	{
		if (stack.stack[index_min] > stack.stack[index])
			index_min = index;
		index++;
	}
	return (stack.stack[index_min]);
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
