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
CFILES = push_swap.c get_input.c
OBJS = ${CFILES:.c=.o}
INC = -I ./ -I ${LIBDIR}

NAME = push_swap
LIB = libft.a
LIBDIR = ./Libft/

RM = rm -rf
################################################################################
.PHONY: all re fclean clean test error
################################################################################
all:		${NAME}

test:		all
		./${NAME} 1 2 3 4 5
		./${NAME} 0 -2 +3 4

error:		all
		./${NAME} 0 -2 3 4 3
		./${NAME} 0 -2 3 +4 -2
		./${NAME} 0 --2 +3 4
		./${NAME} 0 a 3 4
		./${NAME} 0 -2 3 4 2147483647
		./${NAME} 0 -2 3 4 2147483648
		./${NAME} 0 -2 3 4 -2147483648
		./${NAME} 0 -2 3 4 -2147483649

${NAME}:	${LIB} ${OBJS}
		@${CC} ${OBJS} -L ${LIBDIR} -l ft -o ${NAME}

${LIB}:
		@make -C ${LIBDIR} --silent

%.o:		%.c
		@${CC} -c ${CFLAGS} $< -o $@ ${INC}

re:			fclean all
		@make -C ${LIBDIR} re --silent

fclean:		clean
		@make -C ${LIBDIR} fclean --silent
		@${RM} ${NAME}

clean:
		@make -C ${LIBDIR} clean --silent
		@${RM} ${OBJS}
################################################################################
