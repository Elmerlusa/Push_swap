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

int	main(int argc, char *argv[])
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;

	if (argc == 1)
		return (0);
	stack_a = get_input(argc, argv);
	stack_b = (int *)ft_calloc(argc - 1, sizeof(int));
	if (stack_a == NULL || stack_b == NULL)
		printf("ERROR\n");
	else
	{
		size_a = argc - 1;
		size_b = 0;
		stack_swap(&stack_a, size_a);
		print_stacks(stack_a, stack_b, size_a, size_b);
		stack_push(&stack_b, &size_b, &stack_a, &size_a);
		print_stacks(stack_a, stack_b, size_a, size_b);
		stack_rotate(&stack_a, size_a);
		print_stacks(stack_a, stack_b, size_a, size_b);
		stack_reverse_rotate(&stack_a, size_a);
		print_stacks(stack_a, stack_b, size_a, size_b);
	}
	free(stack_a);
	free(stack_b);
	return (0);
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
				printf("%i    \n", stack_a[index]);
			else
				printf("%i   %i\n", stack_a[index], stack_b[index]);
			index--;
		}
	}
	else
	{
		index = size_b - 1;
		while (index >= 0)
		{
			if (index >= size_a)
				printf("    %i\n", stack_a[index]);
			else
				printf("%i   %i\n", stack_a[index], stack_b[index]);
			index--;
		}
	}
	printf("-   -\n");
	printf("a   b\n");
}
