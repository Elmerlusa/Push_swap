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

void	stack_push(int **stack_dst, int *size_dst, \
					int **stack_src, int *size_src)
{
	if (*size_src == 0)
		return ;
	(*stack_dst)[(*size_dst)++] = (*stack_src)[--(*size_src)];
	return ;
}

void	stack_swap_both(int **stack_a, int size_a, int **stack_b, int size_b)
{
	stack_swap(stack_a, size_a);
	stack_swap(stack_b, size_b);
	ft_printf("ss\n");
}

void	stack_rotate_both(int **stack_a, int size_a, int **stack_b, int size_b)
{
	stack_rotate(stack_a, size_a);
	stack_rotate(stack_b, size_b);
	ft_printf("rr\n");
}

void	stack_reverse_rotate_both(int **stack_a, int size_a, \
								int **stack_b, int size_b)
{
	stack_reverse_rotate(stack_a, size_a);
	stack_reverse_rotate(stack_b, size_b);
	ft_printf("rrr\n");
}
