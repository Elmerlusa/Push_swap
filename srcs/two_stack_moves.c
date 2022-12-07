/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:58:20 by javmarti          #+#    #+#             */
/*   Updated: 2022/11/04 16:58:20 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack stack_dst, t_stack stack_src, char *move)
{
	if (stack_src.size == 0)
		return ;
	*stack_src.size -= 1;
	stack_dst.stack[*(stack_dst.size)] = stack_src.stack[*(stack_src.size)];
	*stack_dst.size += 1;
	if (move != NULL)
		ft_printf("%s", move);
	return ;
}

void	stack_swap_both(t_stack stack_a, t_stack stack_b)
{
	stack_swap(stack_a, NULL);
	stack_swap(stack_b, NULL);
	ft_printf("%s", SWAP_A_B);
}

void	stack_rotate_both(t_stack stack_a, t_stack stack_b)
{
	stack_rotate(stack_a, NULL);
	stack_rotate(stack_b, NULL);
	ft_printf("%s", ROTATE_A_B);
}

void	stack_reverse_rotate_both(t_stack stack_a, t_stack stack_b)
{
	stack_reverse_rotate(stack_a, NULL);
	stack_reverse_rotate(stack_b, NULL);
	ft_printf("%s", R_ROTATE_A_B);
}
