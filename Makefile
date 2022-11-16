# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 17:26:08 by javmarti          #+#    #+#              #
#    Updated: 2022/10/19 17:26:08 by javmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCSDIR = ./srcs/
CFILES = push_swap.c get_input.c one_stack_moves.c two_stack_moves.c

SRCS = ${addprefix ${SRCSDIR}, ${CFILES}}

OBJS = ${SRCS:.c=.o}
INC = -I ./includes/ -I ./libft/includes/

NAME = push_swap

LIB = libft.a
LIBDIR = ./libft/

RM = rm -rf
################################################################################
.PHONY: all re fclean clean test error
################################################################################
all:		${NAME}

test:		all
		./${NAME} 2 1 3 6 5 8

error:		all
		./${NAME} 0 -2 3 4 3
		./${NAME} 0 -2 3 +4 -2
		./${NAME} 0 --2 +3 4
		./${NAME} 0 a 3 4
		./${NAME} 0 -2 3 4 2147483647
		./${NAME} 0 -2 3 4 2147483648
		./${NAME} 0 -2 3 4 -2147483648
		./${NAME} 0 -2 3 4 -2147483649

${NAME}:	${OBJS}
		@make -s ${LIB}
		@${CC} $^ -L ${LIBDIR} -l ft -o ${NAME}

${LIB}:
		@make -s -C ${LIBDIR}

%.o:		%.c
		@${CC} -c ${CFLAGS} $^ -o $@ ${INC}

re:			fclean all

fclean:		clean
		@make -s -C ${LIBDIR} fclean
		@${RM} ${NAME}

clean:
		@make -s -C ${LIBDIR} clean
		@${RM} ${OBJS}
################################################################################
