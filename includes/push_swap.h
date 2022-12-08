/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:40:15 by javmarti          #+#    #+#             */
/*   Updated: 2022/10/19 17:40:15 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

# define SWAP_A "sa\n"
# define SWAP_B "sb\n"
# define SWAP_A_B "ss\n"
# define PUSH_A "pa\n"
# define PUSH_B "pb\n"
# define ROTATE_A "ra\n"
# define ROTATE_B "rb\n"
# define ROTATE_A_B "rr\n"
# define R_ROTATE_A "rra\n"
# define R_ROTATE_B "rrb\n"
# define R_ROTATE_A_B "rrr\n"

typedef struct s_stack
{
	int	*size;
	int	*stack;
}	t_stack;

int		*get_input(char *argv[], int stack_size);
int		get_size(char *argv[]);
void	stack_swap(t_stack stack, char *move);
void	stack_push(t_stack stack_dst, t_stack stack_src, char *move);
void	stack_rotate(t_stack stack, char *move);
void	stack_reverse_rotate(t_stack stac, char *movek);
void	stack_swap_both(t_stack stack_a, t_stack stack_b, char *move);
void	stack_rotate_both(t_stack stack_a, t_stack stack_b, char *move);
void	stack_reverse_rotate_both(t_stack stack_a, t_stack stack_b, char *move);
int		is_sorted(t_stack stack);
int		get_min_index(t_stack stack);
int		get_second_min_index(t_stack stack);
void	free_split(char **split);
t_stack	create_stack(int *stack, int size);
int		check_stack(t_stack stack);
void	free_stack(t_stack stack);
int		check_zero(char *expected_num);

#endif
