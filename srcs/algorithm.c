/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:44:31 by javmarti          #+#    #+#             */
/*   Updated: 2022/12/17 13:44:31 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_max(t_stack stack_dst, t_stack stack_src);
static void		sort_stack_3(t_stack stack);

void	long_stack_algorithm(t_stack stack_a, t_stack stack_b)
{
	int		num_slots;
	int		slot_size;
	t_stack	slot;

	num_slots = 2 + *(stack_a.size) * 4 / 100 - *(stack_a.size) * 9 / 500;
	slot_size = *(stack_a.size) / num_slots - 1;
	while (num_slots-- > 0 && is_sorted(stack_a) == 0)
	{
		slot = get_slot(stack_a, slot_size);
		if (check_stack(slot) == 0)
			return ;
		push_slot(stack_b, stack_a, slot);
		free_stack(slot);
	}
	while (*(stack_a.size) > 3)
		push_num(stack_b, stack_a, get_min_num(stack_a));
	sort_stack_3(stack_a);
	while (*(stack_b.size) != 0)
		push_max(stack_a, stack_b);
	return ;
}

static void	push_max(t_stack stack_dst, t_stack stack_src)
{
	int	max_num;
	int	index_max;

	max_num = get_max_num(stack_src);
	index_max = get_num_index(stack_src, max_num);
	while (index_max != *(stack_src.size) - 1)
	{
		if (index_max == *(stack_src.size) - 2)
			stack_swap(stack_src, SWAP_B);
		else if (index_max >= *(stack_src.size) / 2)
			stack_rotate(stack_src, ROTATE_B);
		else
			stack_reverse_rotate(stack_src, R_ROTATE_B);
		index_max = get_num_index(stack_src, max_num);
	}
	stack_push(stack_dst, stack_src, PUSH_A);
	return ;
}

void	short_stack_algorithm(t_stack stack_a, t_stack stack_b)
{
	if (*(stack_a.size) == 2)
		stack_swap(stack_a, SWAP_A);
	else
	{
		while (*(stack_a.size) > 3)
			push_num(stack_b, stack_a, get_min_num(stack_a));
		sort_stack_3(stack_a);
		while (*(stack_b.size) > 0)
			stack_push(stack_a, stack_b, PUSH_A);
	}
	return ;
}

static void	sort_stack_3(t_stack stack)
{
	int	index_min;
	int	index_max;

	while (is_sorted(stack) == 0)
	{
		index_min = get_num_index(stack, get_min_num(stack));
		index_max = get_num_index(stack, get_max_num(stack));
		if (index_min == 1 && index_max == 2)
			stack_rotate(stack, ROTATE_A);
		else if (index_min == 0 && index_max == 1)
			stack_reverse_rotate(stack, R_ROTATE_A);
		else
			stack_swap(stack, SWAP_A);
	}
	return ;
}
