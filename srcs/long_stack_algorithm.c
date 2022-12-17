/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_stack_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:32:21 by javmarti          #+#    #+#             */
/*   Updated: 2022/12/14 15:32:21 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		get_max_index(t_stack stack);
static void		push_max(t_stack stack_dst, t_stack stack_src);
static int		get_second_max_index(t_stack stack);

void	long_stack_algorithm(t_stack stack_a, t_stack stack_b)
{
	int		num_slots;
	int		slot_size;
	t_stack	slot;

	num_slots = 2 + *(stack_a.size)*3/100 - *(stack_a.size)*6/500;
	slot_size = *(stack_a.size) / num_slots;
	while (num_slots-- > 0 && is_sorted(stack_a) == 0)
	{
		slot = get_slot(stack_a, slot_size);
		if (check_stack(slot) == 0)
			return ;
		push_slot(stack_b, stack_a, slot);
		free_stack(slot);
	}
	while (*(stack_a.size) != 0)
		push_min(stack_b, stack_a);
	while (*(stack_b.size) != 0)
		push_max(stack_a, stack_b);
	return ;
}

static void	push_max(t_stack stack_dst, t_stack stack_src)
{
	int	max_index;
	int	second_max_index;

	max_index = get_max_index(stack_src);
	second_max_index = get_second_max_index(stack_src);
	while (max_index != *(stack_src.size) - 1)
	{
		if (max_index == *(stack_src.size) - 2
			&& second_max_index == *(stack_src.size) - 1)
			stack_swap(stack_src, SWAP_B);
		else if (max_index >= *(stack_src.size) / 2)
			stack_rotate(stack_src, ROTATE_B);
		else
			stack_reverse_rotate(stack_src, R_ROTATE_B);
		max_index = get_max_index(stack_src);
		second_max_index = get_second_max_index(stack_src);
	}
	stack_push(stack_dst, stack_src, PUSH_A);
	return ;
}

static int	get_second_max_index(t_stack stack)
{
	int	index;
	int	max_index;
	int	second_max_index;

	if (*(stack.size) == 0)
		return (-1);
	max_index = get_max_index(stack);
	second_max_index = 0;
	if (max_index == 0)
		second_max_index = 1;
	index = 1;
	while (index < *(stack.size))
	{
		if (index != max_index
			&& stack.stack[second_max_index] < stack.stack[index])
			second_max_index = index;
		index++;
	}
	return (second_max_index);
}

static int	get_max_index(t_stack stack)
{
	int	index;
	int	max_index;

	if (*(stack.size) == 0)
		return (-1);
	max_index = 0;
	index = 1;
	while (index < *(stack.size))
	{
		if (stack.stack[max_index] < stack.stack[index])
			max_index = index;
		index++;
	}
	return (max_index);
}
