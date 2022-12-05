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
# include "get_next_line.h"

# define SWAP_A "sa"
# define SWAP_B "sb"
# define SWAP_A_B "ss"
# define PUSH_A "pa"
# define PUSH_B "pb"
# define ROTATE_A "ra"
# define ROTATE_B "rb"
# define ROTATE_A_B "rr"
# define R_ROTATE_A "rra"
# define R_ROTATE_B "rrb"
# define R_ROTATE_A_B "rrr"

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
void	stack_swap_both(t_stack stack_a, t_stack stack_b);
void	stack_rotate_both(t_stack stack_a, t_stack stack_b);
void	stack_reverse_rotate_both(t_stack stack_a, t_stack stack_b);
int		is_sorted(t_stack stack);
int		get_min_index(t_stack stack);
int		get_second_min_index(t_stack stack);
void	sort_algorithm(t_stack stack_a, t_stack stack_b);
void	sort_stack(t_stack stack_a, t_stack stack_b);
void	free_split(char **split);

#endif
