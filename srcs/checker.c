/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:59:27 by javmarti          #+#    #+#             */
/*   Updated: 2022/12/07 13:59:27 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_list	**get_moves(void);
static int		execute_moves(t_stack stack_a, t_stack stack_b, \
							t_list **move_list);
static int		moves(t_stack stack_a, t_stack stack_b, char *move);

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		stack_size;
	t_list	**move_list;

	if (argc == 1)
		return (0);
	stack_size = get_size(argv);
	stack_a = create_stack(get_input(argv, stack_size), stack_size);
	stack_b = create_stack((int *)ft_calloc(stack_size, sizeof(int)), 0);
	move_list = get_moves();
	if (check_stack(stack_a) && check_stack(stack_b)
		&& execute_moves(stack_a, stack_b, move_list) != -1)
	{
		if (is_sorted(stack_a) && *(stack_b.size) == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		ft_putstr_fd("Error\n", 2);
	free_stack(stack_a);
	free_stack(stack_b);
	ft_lstclear(move_list, &free);
	return (0);
}

static int	moves(t_stack stack_a, t_stack stack_b, char *move)
{
	if (ft_strncmp(move, SWAP_A, ft_strlen(move)) == 0)
		stack_swap(stack_a, NULL);
	else if (ft_strncmp(move, SWAP_B, ft_strlen(move)) == 0)
		stack_swap(stack_b, NULL);
	else if (ft_strncmp(move, SWAP_A_B, ft_strlen(move)) == 0)
		stack_swap_both(stack_a, stack_b, NULL);
	else if (ft_strncmp(move, PUSH_A, ft_strlen(move)) == 0)
		stack_push(stack_a, stack_b, NULL);
	else if (ft_strncmp(move, PUSH_B, ft_strlen(move)) == 0)
		stack_push(stack_b, stack_a, NULL);
	else if (ft_strncmp(move, ROTATE_A, ft_strlen(move)) == 0)
		stack_rotate(stack_a, NULL);
	else if (ft_strncmp(move, ROTATE_B, ft_strlen(move)) == 0)
		stack_rotate(stack_b, NULL);
	else if (ft_strncmp(move, ROTATE_A_B, ft_strlen(move)) == 0)
		stack_rotate_both(stack_a, stack_b, NULL);
	else if (ft_strncmp(move, R_ROTATE_A, ft_strlen(move)) == 0)
		stack_reverse_rotate(stack_a, NULL);
	else if (ft_strncmp(move, R_ROTATE_B, ft_strlen(move)) == 0)
		stack_reverse_rotate(stack_b, NULL);
	else if (ft_strncmp(move, R_ROTATE_A_B, ft_strlen(move)) == 0)
		stack_reverse_rotate_both(stack_a, stack_b, NULL);
	else
		return (-1);
	return (1);
}

static int	execute_moves(t_stack stack_a, t_stack stack_b, t_list **move_list)
{
	char	*move;

	while (*move_list != NULL)
	{
		move = (*move_list)->content;
		if (moves(stack_a, stack_b, move) == -1)
			return (-1);
		*move_list = (*move_list)->next;
	}
	return (1);
}

static t_list	**get_moves(void)
{
	t_list	**move_list;
	char	*line;

	move_list = (t_list **)ft_calloc(1, sizeof(t_list *));
	if (move_list == NULL)
		return (NULL);
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		ft_lstadd_back(move_list, ft_lstnew(line));
		line = get_next_line(STDIN_FILENO);
	}
	return (move_list);
}
