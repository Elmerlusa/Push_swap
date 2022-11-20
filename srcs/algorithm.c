/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:32:37 by javmarti          #+#    #+#             */
/*   Updated: 2022/11/20 17:32:37 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack stack_a, t_stack stack_b)
{
	while (is_sorted(stack_a) == 0)
		sort_algorithm(stack_a, stack_b);
	while (*(stack_b.size) != 0)
		stack_push(stack_a, stack_b, PUSH_A);
	return ;
}

void	sort_algorithm(t_stack stack_a, t_stack stack_b)
{
	int	index;

	index = get_min_index(stack_a);
	if (index == *(stack_a.size) - 1)
		stack_push(stack_b, stack_a, PUSH_B);
	else if (index == *(stack_a.size) - 2
		&& get_second_min_index(stack_a) == *(stack_a.size) - 1)
		stack_swap(stack_a, SWAP_A);
	else if (index >= *(stack_a.size) / 2)
		stack_rotate(stack_a, ROTATE_A);
	else
		stack_reverse_rotate(stack_a, R_ROTATE_A);
	return ;
}
