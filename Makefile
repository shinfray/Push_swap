# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 17:10:39 by shinfray          #+#    #+#              #
#    Updated: 2023/06/15 11:05:19 by shinfray         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:

NAME:=	push_swap

BUILD_DIR:= build
SRCS_DIR:= srcs

SRCS_PUSH_SWAP:=	main.c

SRCS:=	${addprefix ${SRCS_DIR}/,${SRCS_PUSH_SWAP}}

OBJS:=	${SRCS:%.c=${BUILD_DIR}/%.o}

DEPS:=	${OBJS:.o=.d}

LIBFT:=	libs/libft/libft.a
CFLAGS:= -Wall -Wextra -Werror

INC_DIRS:= includes libs/libft/includes

CPPFLAGS:= ${addprefix -I,${INC_DIRS}} -MMD -MP

LIB_DIR:= libs/libft
LDFLAGS:= ${addprefix -L,${LIB_DIR}}
LDLIBS:= -lft

RM:=	rm -rf

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${LDFLAGS} ${OBJS} ${LDLIBS} -o $@

${LIBFT}:
	${MAKE} -C ${dir ${LIBFT}}

${BUILD_DIR}/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	${MAKE} clean -C ${dir ${LIBFT}}
	${RM} ${BUILD_DIR}

fclean: clean
	${RM} ${LIBFT}
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re

-include ${DEPS}
