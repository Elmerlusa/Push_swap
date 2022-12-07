/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:53:52 by javmarti          #+#    #+#             */
/*   Updated: 2022/12/07 13:53:52 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack(t_stack stack)
{
	if (stack.stack == NULL || stack.size == NULL)
		return (0);
	return (1);
}

void	free_stack(t_stack stack)
{
	free(stack.size);
	free(stack.stack);
	return ;
}

t_stack	create_stack(int *stack, int size)
{
	t_stack	new_stack;

	new_stack.size = (int *)ft_calloc(1, sizeof(int));
	*(new_stack.size) = size;
	new_stack.stack = stack;
	return (new_stack);
}
