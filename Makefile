# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 17:10:39 by shinfray          #+#    #+#              #
#    Updated: 2023/06/25 00:02:15 by shinfray         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:

NAME:=	push_swap

BUILD_DIR:= build
SRCS_DIR:= src

EXT:=	.c

SRCS_PUSH_SWAP:=	main \
					initialization_closure/initialize_stacks \
					initialization_closure/parse \
					initialization_closure/closure \
					moves/s_moves \
					moves/p_moves \
					moves/r_moves \
					moves/rr_moves \
					dllist/dllist_creation_destruction \
					dllist/dllist_accessor \
					dllist/dllist_insertion \
					sorting/sort \
					sorting/sort_utils

SRCS:=	${addprefix ${SRCS_DIR}/,${addsuffix ${EXT},${SRCS_PUSH_SWAP}}}

OBJS:=	${SRCS:%.c=${BUILD_DIR}/%.o}

DEPS:=	${OBJS:.o=.d}

LIBFT:=	lib/libft/libft.a
CFLAGS:= -Wall -Wextra -Werror -Wpedantic

INC_DIRS:= include lib/libft/include

CPPFLAGS:= ${addprefix -I,${INC_DIRS}} -MMD -MP

LIB_DIR:= lib/libft
LDFLAGS:= ${addprefix -L,${LIB_DIR}}
LDLIBS:= -lft

RM:=	rm -rf

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${LDFLAGS} ${OBJS} ${LDLIBS} -o $@ -fsanitize=address

${LIBFT}:
	${MAKE} -C ${dir ${LIBFT}}

${BUILD_DIR}/%.o: %.c
	mkdir -p $(dir $@)
	${CC} ${CPPFLAGS} ${CFLAGS} -c $< -o $@

clean:
	${MAKE} clean -C ${dir ${LIBFT}}
	${RM} ${BUILD_DIR}

fclean: clean
	${RM} ${LIBFT}
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re

-include ${DEPS}
