/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:19:07 by javmarti          #+#    #+#             */
/*   Updated: 2022/11/03 18:19:07 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_number(char *number);
static int	check_overflow(char *expected_num);
static int	check_duplicates(int *stack, int size);
static int	check_value_input(char *arg, int *stack, \
							int stack_size, int *index);

int	*get_input(char *argv[], int stack_size)
{
	int		index;
	int		*stack_a;

	stack_a = (int *)ft_calloc(stack_size, sizeof(int));
	if (stack_a == NULL)
		return (NULL);
	index = 0;
	while (*(++argv))
	{
		if (check_value_input(*argv, stack_a, stack_size, &index) == 0)
		{
			free(stack_a);
			return (NULL);
		}
	}
	if (check_duplicates(stack_a, stack_size) == -1)
	{
		free(stack_a);
		return (NULL);
	}
	return (stack_a);
}

static int	check_value_input(char *arg, int *stack, int stack_size, int *index)
{
	char	**split;
	int		split_index;

	split = ft_split(arg, ' ');
	split_index = -1;
	while (split[++split_index])
	{
		if (check_number(split[split_index]) == 0
			|| check_overflow(split[split_index]) == 0)
			return (0);
		stack[stack_size - 1 - *index] = ft_atoi(split[split_index]);
		*(index) += 1;
	}
	free_split(split);
	return (1);
}

static int	check_duplicates(int *stack, int size)
{
	int	index1;
	int	index2;

	index1 = 0;
	while (index1 < size - 1)
	{
		index2 = index1 + 1;
		while (index2 < size)
		{
			if (stack[index1] == stack[index2])
				return (-1);
			index2++;
		}
		index1++;
	}
	return (1);
}

int	check_overflow(char *expected_num)
{
	char	*arr_num;
	int		overflow;
	int		index;

	overflow = 1;
	index = 0;
	arr_num = ft_itoa(ft_atoi(expected_num));
	if (ft_strncmp(arr_num, "0", ft_strlen(arr_num)) == 0)
	{
		free(arr_num);
		return (check_zero(expected_num));
	}
	if (*expected_num == '+')
		expected_num++;
	else if (*expected_num == '-' && *arr_num == '-')
	{
		expected_num++;
		index++;
	}
	while (*expected_num == '0')
		expected_num++;
	if (ft_strncmp(arr_num + index, expected_num, ft_strlen(expected_num)) != 0)
		overflow = 0;
	free(arr_num);
	return (overflow);
}

int	check_number(char *number)
{
	int	index;

	index = 0;
	if (number[index] == '-' || number[index] == '+')
	{
		if (ft_isdigit(number[++index]) == 0)
			return (0);
	}
	while (number[index])
	{
		if (ft_isdigit(number[index++]) == 0)
			return (0);
	}
	return (1);
}
