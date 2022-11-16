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

void	stack_swap(int **stack, int size)
{
	int	aux;

	if (size <= 1)
		return ;
	aux = (*stack)[size - 1];
	(*stack)[size - 1] = (*stack)[size - 2];
	(*stack)[size - 2] = aux;
	return ;
}

void	stack_rotate(int **stack, int size)
{
	int	index;
	int	aux1;
	int	aux2;

	if (size <= 1)
		return ;
	index = 0;
	aux1 = (*stack)[index];
	while (index < size - 1)
	{
		aux2 = (*stack)[index + 1];
		(*stack)[index + 1] = aux1;
		aux1 = aux2;
		index++;
	}
	(*stack)[0] = aux1;
	return ;
}

void	stack_reverse_rotate(int **stack, int size)
{
	int	index;
	int	aux1;
	int	aux2;

	if (size <= 1)
		return ;
	index = size - 1;
	aux1 = (*stack)[index];
	while (index > 0)
	{
		aux2 = (*stack)[index - 1];
		(*stack)[index - 1] = aux1;
		aux1 = aux2;
		index--;
	}
	(*stack)[size - 1] = aux1;
}
