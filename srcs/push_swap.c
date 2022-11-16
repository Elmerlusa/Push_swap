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

void	print_stacks(int *stack_a, int *stack_b, int size_a, int size_b);
static void	sort_stack(int **stack_a, int **stack_b, int size);
static int	is_sorted(int *stack, int size);
static int	get_min_index(int *stack, int size);

int	main(int argc, char *argv[])
{
	int	*stack_a;
	int	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = get_input(argc, argv);
	stack_b = (int *)ft_calloc(argc - 1, sizeof(int));
	if (stack_a == NULL || stack_b == NULL)
		ft_printf("ERROR\n");
	else
		sort_stack(&stack_a, &stack_b, argc - 1);
	free(stack_a);
	free(stack_b);
	return (0);
}

static void	sort_stack(int **stack_a, int **stack_b, int size_a)
{
	int	size_b;
	int	sorted;

	size_b = 0;
	sorted = is_sorted(*stack_a, size_a);
	while (sorted == 0  || size_b != 0)
	{
		ft_printf("MIN -> %i\n", get_min_index(*stack_a, size_a));
		break ;
		// stack_swap(stack_b, size_b);
		// stack_push(stack_b, &size_b, stack_a, &size_a);
		// stack_reverse_rotate(stack_a, size_a);
		// stack_rotate(stack_a, size_a);
		sorted = is_sorted(*stack_a, size_a);
	}
	print_stacks(*stack_a, *stack_b, size_a, size_b);
	return;
}

static int	get_min_index(int *stack, int size)
{
	int	index;
	int	min_index;

	if (size == 0)
		return (-1);
	min_index = 0;
	index = 1;
	while (index < size)
	{
		if (stack[min_index] > stack[index])
			min_index = index;
		index++;
	}
	return (min_index);
}

static int	is_sorted(int *stack, int size)
{
	int	index;

	index = 0;
	while (index < size - 1)
	{
		if (stack[index] > stack[index + 1])
			return (0);
		index++;
	}
	return (1);
}

void	print_stacks(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int index;
	if (size_a > size_b)
	{
		index = size_a - 1;
		while (index >= 0)
		{
			if (index >= size_b)
				ft_printf("%i    \n", stack_a[index]);
			else
				ft_printf("%i   %i\n", stack_a[index], stack_b[index]);
			index--;
		}
	}
	else
	{
		index = size_b - 1;
		while (index >= 0)
		{
			if (index >= size_a)
				ft_printf("    %i\n", stack_b[index]);
			else
				ft_printf("%i   %i\n", stack_a[index], stack_b[index]);
			index--;
		}
	}
	ft_printf("-   -\n");
	ft_printf("a   b\n");
}
