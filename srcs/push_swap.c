/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:45:07 by javmarti          #+#    #+#             */
/*   Updated: 2022/10/19 17:45:07 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	create_stack(int *stack, int size);
static void		free_stack(t_stack stack);

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (0);
	stack_a = create_stack(get_input(argc, argv), argc - 1);
	stack_b = create_stack((int *)ft_calloc(argc - 1, sizeof(int)), 0);
	if (stack_a.stack == NULL || stack_a.size == NULL
		|| stack_b.stack == NULL || stack_b.size == NULL)
		ft_putstr_fd("Error\n", 2);
	else
		sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

static void	free_stack(t_stack stack)
{
	free(stack.size);
	free(stack.stack);
	return ;
}

static t_stack	create_stack(int *stack, int size)
{
	t_stack	new_stack;

	new_stack.size = (int *)ft_calloc(1, sizeof(int));
	*(new_stack.size) = size;
	new_stack.stack = stack;
	return (new_stack);
}
