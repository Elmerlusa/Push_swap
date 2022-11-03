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

int	main(int argc, char *argv[])
{
	int	*stack_a;
	int	stack_b[argc - 1];

	if (argc == 1)
		return (0);
	stack_a = get_input(argc, argv);
	if (stack_a == NULL)
	{
		printf("ERROR\n");
		return (0);
	}



	ft_bzero(stack_b, (argc - 1) * sizeof(int));
	int index = argc - 1;
	while (--index > 0)
		printf("%i  %i\n", stack_a[index], stack_b[index]);
	printf("%c  %c\n", '-', '-');
	printf("%c  %c\n", 'a', 'b');
	free(stack_a);
	return (0);
}
