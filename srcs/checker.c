/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:36:50 by javmarti          #+#    #+#             */
/*   Updated: 2022/11/20 13:36:50 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_sort_stack();

int	main(int argc, char *argv[])
{
	int	*stack_a;
	int	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = get_input(argc, argv);
	stack_b = (int *)ft_calloc(argc - 1, sizeof(int));
	ft_printf("sa\n");
	ft_printf("sb\n");
	ft_printf("sc\n");
	ft_printf("sd\n");
	if (stack_a == NULL || stack_b == NULL)
		ft_putstr_fd("Error\n", 2);
	else
		check_sort_stack();
	free(stack_a);
	free(stack_b);
	return (0);
}

static void	check_sort_stack()
{
	t_list	*move_list;

	move_list = ft_lstnew(get_next_line(1));
	ft_printf("-> %s", move_list->content);
	return ;
}
