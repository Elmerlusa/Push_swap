# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 23:07:34 by javmarti          #+#    #+#              #
#    Updated: 2022/10/25 15:55:21 by javmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c
OBJS = ${CFILES:.c=.o}
CBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
	ft_lstmap_bonus.c
OBONUS = ${CBONUS:.c=.o}

AR = ar rcs
NAME = libft.a

RM = rm -rf
################################################################################
ifdef WITH_BONUS
	TOTAL_OBJS = ${OBJS} ${OBONUS}
else
	TOTAL_OBJS = ${OBJS}
endif
################################################################################
all:		${NAME}

${NAME}:	${TOTAL_OBJS}
		@${AR} $@ $^

bonus:
		@make WITH_BONUS=1

%.o:		%.c
		@${CC} -c ${CFLAGS} $< -o $@

re:			fclean all

fclean:		clean
		@$(RM) ${NAME}

clean:
		@$(RM) $(OBJS) ${OBONUS}
################################################################################
.PHONY: all re fclean clean bonus
