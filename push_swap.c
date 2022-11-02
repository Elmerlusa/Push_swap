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
#include <stdio.h>

static int	check_input(int argc, char *argv[]);

static int ft_isdigit(int c);

int	main(int argc, char *argv[])
{
	printf("CI -> %i\n", check_input(argc, argv));
	int index = 1;
	while (index < argc)
		printf("STACK -> %s\n", argv[index++]);
	return (0);
}

static int	check_input(int argc, char *argv[])
{
	int	index;

	index = 0;
	while (index < argc)
	{
		while (*argv[index])
		{
			if (ft_isdigit(*argv[index]) == 0)
				return (0);
			(argv[index])++;
		}
		index++;
	}
	return (1);
}

static int ft_isdigit(int c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}
