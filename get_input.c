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
static int	check_overflow(int num, char *expected_num);
static int	check_duplicates(int *stack, int size);

int	*get_input(int argc, char *argv[])
{
	int	index;
	int	*stack_a;

	stack_a = (int *)ft_calloc(argc - 1, sizeof(int));
	if (stack_a == NULL)
		return (NULL);
	index = 0;
	while (++index < argc)
	{
		stack_a[argc - 1- index] = ft_atoi(argv[index]);
		if (check_overflow(stack_a[argc - 1- index], argv[index]) == 0
			|| check_number(argv[index]) == 0)
		{
			free(stack_a);
			return (NULL);
		}
	}
	if (check_duplicates(stack_a, argc - 1) == 0)
	{
		free(stack_a);
		return (NULL);
	}
	return (stack_a);
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
				return (0);
			index2++;
		}
		index1++;
	}
	return (1);
}

static int	check_overflow(int num, char *expected_num)
{
	char	*arr_num;

	arr_num = ft_itoa(num);
	if (*expected_num == '+')
		expected_num++;
	if (ft_strncmp(arr_num, expected_num, ft_strlen(expected_num)) != 0)
	{
		free(arr_num);
		printf("AQUI");
		return (0);
	}
	free(arr_num);
	return (1);
}

static int	check_number(char *number)
{
	int	index;

	index = 0;
	if (number[index] == '-' || number[index] == '+')
	{
		index++;
		if (ft_isdigit(number[index]) == 0)
			return (0);
	}
	while (number[index])
	{
		if (ft_isdigit(number[index]) == 0)
			return (0);
		index++;
	}
	return (1);
}
