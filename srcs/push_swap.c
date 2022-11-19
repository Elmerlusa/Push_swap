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
	int	index;

	size_b = 0;
	while (is_sorted(*stack_a, size_a) == 0)
	{
		index = get_min_index(*stack_a, size_a);
		if (index == size_a - 1)
		{
			ft_printf("pb\n");
			stack_push(stack_b, &size_b, stack_a, &size_a);
		}
		else if (index == size_a - 2 &&
				get_second_min_index(*stack_a, size_a) == size_a - 1)
		{
			ft_printf("sa\n");
			stack_swap(stack_a, size_a);
		}
		else if (index >= size_a / 2)
		{
			ft_printf("ra\n");
			stack_rotate(stack_a, size_a);
		}
		else
		{
			ft_printf("rra\n");
			stack_reverse_rotate(stack_a, size_a);
		}
	}
	while (size_b != 0)
	{
		ft_printf("pa\n");
		stack_push(stack_a, &size_a, stack_b, &size_b);
	}
	// print_stacks(*stack_a, *stack_b, size_a, size_b);
	return;
}

// void	print_stacks(int *stack_a, int *stack_b, int size_a, int size_b)
// {
// 	int index;
// 	ft_printf("-------------------------------\n");
// 	if (size_a > size_b)
// 	{
// 		index = size_a - 1;
// 		while (index >= 0)
// 		{
// 			if (index >= size_b)
// 				ft_printf("%i    \n", stack_a[index]);
// 			else
// 				ft_printf("%i   %i\n", stack_a[index], stack_b[index]);
// 			index--;
// 		}
// 	}
// 	else
// 	{
// 		index = size_b - 1;
// 		while (index >= 0)
// 		{
// 			if (index >= size_a)
// 				ft_printf("    %i\n", stack_b[index]);
// 			else
// 				ft_printf("%i   %i\n", stack_a[index], stack_b[index]);
// 			index--;
// 		}
// 	}
// 	ft_printf("-   -\n");
// 	ft_printf("a   b\n");
// 	ft_printf("-------------------------------\n");
// }
