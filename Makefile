# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 17:10:39 by shinfray          #+#    #+#              #
#    Updated: 2023/06/28 13:08:00 by shinfray         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:
.SILENT:

NAME:=	push_swap
B_NAME:= checker

SRCS_DIR:= src
BUILD_DIR:= build
INC_DIRS:= include lib/libft/include

LDLIBS:= -lft
LIBFT:=	lib/libft/libft.a
LIB_DIRS:= lib/libft

CFLAGS:= -Wall -Wextra -Werror -Wpedantic

EXT:=	.c

SRCS_FILES:=	main \
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
				sorting/check_index \
				sorting/choose_moves_to_b \
				sorting/do_moves \
				sorting/sort_utils

B_SRCS_FILES:=	bonus/main_bonus \
				bonus/silent_moves/s_moves_bonus \
				bonus/silent_moves/p_moves_bonus \
				bonus/silent_moves/r_moves_bonus \
				bonus/silent_moves/rr_moves_bonus \
				bonus/checker_utils_bonus \
				initialization_closure/initialize_stacks \
				initialization_closure/parse \
				initialization_closure/closure \
				dllist/dllist_creation_destruction \
				dllist/dllist_accessor \
				dllist/dllist_insertion \
				sorting/sort_utils

SRCS:=	${addprefix ${SRCS_DIR}/,${addsuffix ${EXT},${SRCS_FILES}}}
B_SRCS:= ${addprefix ${SRCS_DIR}/,${addsuffix ${EXT},${B_SRCS_FILES}}}

OBJS:=	${SRCS:%.c=${BUILD_DIR}/%.o}
B_OBJS:= ${B_SRCS:%.c=${BUILD_DIR}/%.o}

DEPS:=	${OBJS:.o=.d}
B_DEPS:= ${B_OBJS:.o=.d}

CPPFLAGS:= ${addprefix -I,${INC_DIRS}} -MMD -MP

LDFLAGS:= ${addprefix -L,${LIB_DIRS}}

RM:=	rm -rf

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${LDFLAGS} ${OBJS} ${LDLIBS} -o $@

bonus: ${B_NAME}

${B_NAME}: ${B_OBJS} ${LIBFT}
	${CC} ${LDFLAGS} ${B_OBJS} ${LDLIBS} -o $@

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
	${RM} ${NAME} ${B_NAME}

re: fclean all

.PHONY:	all clean fclean re bonus

-include ${DEPS}
-include ${B_DEPS}
