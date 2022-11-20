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

static void	sort_stack(int **stack_a, int **stack_b, int size);
static void	sort_algorithm(int **stack_a, int **stack_b, \
						int *size_a, int *size_b);

int	main(int argc, char *argv[])
{
	int	*stack_a;
	int	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = get_input(argc, argv);
	stack_b = (int *)ft_calloc(argc - 1, sizeof(int));
	if (stack_a == NULL || stack_b == NULL)
		ft_putstr_fd("Error\n", 2);
	else
		sort_stack(&stack_a, &stack_b, argc - 1);
	free(stack_a);
	free(stack_b);
	return (0);
}

static void	sort_stack(int **stack_a, int **stack_b, int size_a)
{
	int	size_b;

	size_b = 0;
	while (is_sorted(*stack_a, size_a) == 0)
		sort_algorithm(stack_a, stack_b, &size_a, &size_b);
	while (size_b != 0)
	{
		ft_printf("pa\n");
		stack_push(stack_a, &size_a, stack_b, &size_b);
	}
	return ;
}

static void	sort_algorithm(int **stack_a, int **stack_b, \
						int *size_a, int *size_b)
{
	int	index;

	index = get_min_index(*stack_a, *size_a);
	if (index == *size_a - 1)
	{
		ft_printf("pb\n");
		stack_push(stack_b, size_b, stack_a, size_a);
	}
	else if (index == *size_a - 2
		&& get_second_min_index(*stack_a, *size_a) == *size_a - 1)
	{
		ft_printf("sa\n");
		stack_swap(stack_a, *size_a);
	}
	else if (index >= *size_a / 2)
	{
		ft_printf("ra\n");
		stack_rotate(stack_a, *size_a);
	}
	else
	{
		ft_printf("rra\n");
		stack_reverse_rotate(stack_a, *size_a);
	}
	return ;
}
