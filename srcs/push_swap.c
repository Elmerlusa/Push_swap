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
static int		check_stack(t_stack stack);
static void		free_stack(t_stack stack);

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		stack_size;

	if (argc == 1)
		return (0);
	stack_size = get_size(argv);
	stack_a = create_stack(get_input(argv, stack_size), stack_size);
	stack_b = create_stack((int *)ft_calloc(stack_size, sizeof(int)), 0);
	if (check_stack(stack_a) || check_stack(stack_b))
		sort_stack(stack_a, stack_b);
	else
		ft_putstr_fd("Error\n", 2);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

static int	check_stack(t_stack stack)
{
	if (stack.stack == NULL || stack.size == NULL)
		return (0);
	return (1);
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
