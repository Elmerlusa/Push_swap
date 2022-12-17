/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slots.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:33:24 by javmarti          #+#    #+#             */
/*   Updated: 2022/12/16 16:33:24 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_num(t_stack stack_dst, t_stack stack_src, int num)
{
	int	index;

	index = get_index_num(stack_src, num);
	while (index != *(stack_src.size) - 1)
	{
		if (index >= *(stack_src.size) / 2)
			stack_rotate(stack_src, ROTATE_A);
		else
			stack_reverse_rotate(stack_src, R_ROTATE_A);
		index = get_index_num(stack_src, num);
	}
	stack_push(stack_dst, stack_src, PUSH_B);
	return ;
}

int	num_to_push(t_stack stack, t_stack slot)
{
	int	index;
	int	distance;

	index = 0;
	while (index < *(stack.size))
	{
		if (in_slot(slot, *(slot.size), stack.stack[index]))
			break ;
		index++;
	}
	distance = index + 1;
	index = *(stack.size) - 1;
	while (index >= 0)
	{
		if (in_slot(slot, *(slot.size), stack.stack[index]))
			break ;
		index--;
	}
	if (distance > *(stack.size) - index - 1)
		return (stack.stack[index]);
	else
		return (stack.stack[distance - 1]);
}

void	push_slot(t_stack stack_dst, t_stack stack_src, t_stack slot)
{
	int	index;
	int	num;

	index = 0;
	while (index < *(slot.size))
	{
		num = num_to_push(stack_src, slot);
		push_num(stack_dst, stack_src, num);
		index++;
	}
	return ;
}

t_stack	get_slot(t_stack stack, int size)
{
	t_stack	slot;
	int		index;
	int		slot_index;
	int		index_to_add;

	slot = create_stack((int *)ft_calloc(size, sizeof(int)), size);
	if (check_stack(slot) == 0)
		return (slot);
	slot_index = 0;
	while (slot_index < size)
	{
		index_to_add = 0;
		while (in_slot(slot, slot_index, stack.stack[index_to_add]))
			index_to_add++;
		index = 0;
		while (index < *(stack.size))
		{
			if (stack.stack[index] < stack.stack[index_to_add]
				&& in_slot(slot, slot_index, stack.stack[index]) == 0)
				index_to_add = index;
			index++;
		}
		slot.stack[slot_index++] = stack.stack[index_to_add];
	}
	return (slot);
}

int	in_slot(t_stack slot, int size, int num)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (slot.stack[index] == num)
			return (1);
		index++;
	}
	return (0);
}
