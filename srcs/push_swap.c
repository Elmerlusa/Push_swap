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

static void	sort_stack(t_stack stack_a, t_stack stack_b);
static void	sort_algorithm(t_stack stack_a, t_stack stack_b);

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
	if (check_stack(stack_a) && check_stack(stack_b))
		sort_stack(stack_a, stack_b);
	else
		ft_putstr_fd("Error\n", 2);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

static void	sort_stack(t_stack stack_a, t_stack stack_b)
{
	while (is_sorted(stack_a) == 0)
	{
		sort_algorithm(stack_a, stack_b);
	}
	while (*(stack_b.size) != 0)
		stack_push(stack_a, stack_b, PUSH_A);
	return ;
}

static void	sort_algorithm(t_stack stack_a, t_stack stack_b)
{
	int	index1;
	int	index2;

	index1 = get_min_index(stack_a);
	index2 = get_second_min_index(stack_a);
	if (index1 == *(stack_a.size) - 1)
		stack_push(stack_b, stack_a, PUSH_B);
	else if (index1 == *(stack_a.size) - 2 && index2 == *(stack_a.size) - 1)
		stack_swap(stack_a, SWAP_A);
	else if (index1 >= *(stack_a.size) / 2)
		stack_rotate(stack_a, ROTATE_A);
	else
		stack_reverse_rotate(stack_a, R_ROTATE_A);
	return ;
}
