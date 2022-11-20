/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:38:16 by javmarti          #+#    #+#             */
/*   Updated: 2022/11/03 22:38:16 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_stack stack, char *move)
{
	int	aux;

	if (*(stack.size) <= 1)
		return ;
	aux = stack.stack[*(stack.size) - 1];
	stack.stack[*(stack.size) - 1] = stack.stack[*(stack.size) - 2];
	stack.stack[*(stack.size) - 2] = aux;
	if (move != NULL)
		ft_printf("%s\n", move);
	return ;
}

void	stack_rotate(t_stack stack, char *move)
{
	int	index;
	int	aux1;
	int	aux2;

	if (*(stack.size) <= 1)
		return ;
	index = 0;
	aux1 = stack.stack[index];
	while (index < *(stack.size) - 1)
	{
		aux2 = stack.stack[index + 1];
		stack.stack[index + 1] = aux1;
		aux1 = aux2;
		index++;
	}
	stack.stack[0] = aux1;
	if (move != NULL)
		ft_printf("%s\n", move);
	return ;
}

void	stack_reverse_rotate(t_stack stack, char *move)
{
	int	index;
	int	aux1;
	int	aux2;

	if (*(stack.size) <= 1)
		return ;
	index = *(stack.size) - 1;
	aux1 = stack.stack[index];
	while (index > 0)
	{
		aux2 = stack.stack[index - 1];
		stack.stack[index - 1] = aux1;
		aux1 = aux2;
		index--;
	}
	stack.stack[*(stack.size) - 1] = aux1;
	if (move != NULL)
		ft_printf("%s\n", move);
	return ;
}
