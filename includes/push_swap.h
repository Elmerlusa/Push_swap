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

int		*get_input(int argc, char *argv[]);
void	stack_swap(int **stack, int size);
void	stack_push(int **stack_dst, int *size_dst, \
					int **stack_src, int *size_src);
void	stack_rotate(int **stack, int size);
void	stack_reverse_rotate(int **stack, int size);
void	stack_swap_both(int **stack_a, int size_a, int **stack_b, int size_b);
void	stack_rotate_both(int **stack_a, int size_a, int **stack_b, int size_b);
void	stack_reverse_rotate_both(int **stack_a, int size_a, \
								int **stack_b, int size_b);
int		is_sorted(int *stack, int size);
int		get_min_index(int *stack, int size);
int		get_second_min_index(int *stack, int size);

#endif
