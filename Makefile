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
CFILES = push_swap.c
OBJS = ${CFILES:.c=.o}

NAME = push_swap
LIB = libft.a
LIBDIR = ./Libft/

RM = rm -rf
################################################################################
.PHONY: all re fclean clean
################################################################################
all:		${NAME}

test:		all
		./${NAME} 1 2 3 4 5

${NAME}:	${LIB} ${OBJS}
		${CC} -L ${LIBDIR} -lft ${OBJS} -o ${NAME}

${LIB}:
		@make -C ${LIBDIR} --silent

%.o:		%.c
		@${CC} -c ${CFLAGS} $< -o $@

re:			fclean all
		@make -C ${LIBDIR} re --silent

fclean:		clean
		@make -C ${LIBDIR} fclean --silent
		@${RM} ${NAME}

clean:
		@make -C ${LIBDIR} clean --silent
		@${RM} ${OBJS}
################################################################################
