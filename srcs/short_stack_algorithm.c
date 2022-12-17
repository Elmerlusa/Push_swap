/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:57:25 by javmarti          #+#    #+#             */
/*   Updated: 2022/12/13 18:57:25 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack_3(t_stack stack);

void	short_stack_algorithm(t_stack stack_a, t_stack stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (*(stack_a.size) == 2)
		stack_swap(stack_a, SWAP_A);
	else
	{
		while (*(stack_a.size) > 3)
			push_min(stack_b, stack_a);
		sort_stack_3(stack_a);
		while (*(stack_b.size) > 0)
			stack_push(stack_a, stack_b, PUSH_A);
	}
	return ;
}

void	push_min(t_stack stack_dst, t_stack stack_src)
{
	int	min_index;
	int	second_min_index;

	min_index = get_min_index(stack_src);
	second_min_index = get_second_min_index(stack_src);
	while (min_index != *(stack_src.size) - 1)
	{
		if (min_index == *(stack_src.size) - 2
			&& second_min_index == *(stack_src.size) - 1)
			stack_swap(stack_src, SWAP_A);
		else if (min_index >= *(stack_src.size) / 2)
			stack_rotate(stack_src, ROTATE_A);
		else
			stack_reverse_rotate(stack_src, R_ROTATE_A);
		min_index = get_min_index(stack_src);
		second_min_index = get_second_min_index(stack_src);
	}
	stack_push(stack_dst, stack_src, PUSH_B);
	return ;
}

static void	sort_stack_3(t_stack stack)
{
	int	min_index;
	int	sec_min_index;

	while (is_sorted(stack) == 0)
	{
		min_index = get_min_index(stack);
		sec_min_index = get_second_min_index(stack);
		if (min_index == 1 && sec_min_index == 0)
			stack_rotate(stack, ROTATE_A);
		else if (min_index == 0 && sec_min_index == 2)
			stack_reverse_rotate(stack, R_ROTATE_A);
		else
			stack_swap(stack, SWAP_A);
	}
	return ;
}
