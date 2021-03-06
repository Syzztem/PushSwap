# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 14:45:40 by lothieve          #+#    #+#              #
#    Updated: 2021/03/05 16:03:19 by lothieve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER_SRC_R = checker.c run_and_check.c furbiddun_cunstunt.c swap.c push.c rotate.c rrotate.c
CHECKER_SRC = $(addprefix ${CHECKER_SRC_PATH}, ${CHECKER_SRC_R})
CHECKER_SRC_PATH = checker_dir/src/
CHECKER_INC_PATH = checker_dir/includes
CHECKER_NAME = checker
CHECKER_OBJS = ${CHECKER_SRC:.c=.o}

PUSW_SRC_R = push_swap.c
PUSW_SRC = $(addprefix ${PUSW_SRC_PATH}, ${PUSW_SRC_R})
PUSW_SRC_PATH =	push_swap_dir/src/
PUSW_INC_PATH = push_swap_dir/includes
PUSW_NAME = push_swap
PUSW_OBJS = ${PUSW_SRC:.c=.o}

OBJS = ${CHECKER_OBJS} ${PUSW_OBJS}
SRC = ${CHECKER_SRC} ${PUSW_SRC}
NAME = ${PUSW_NAME} ${CHECKER_NAME}


CC = clang
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all:			${NAME}

${PUSW_NAME}:	${PUSW_OBJS}
				${CC} ${CFLAGS} -o ${PUSW_NAME} ${PUSW_OBJS}

${CHECKER_NAME}:		${CHECKER_OBJS}
				${CC} ${CFLAGS} -o ${CHECKER_NAME} ${CHECKER_OBJS}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all


.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${CHECKER_INC_PATH} -I${PUSW_INC_PATH} -I${LIBFT_PATH}

.PHONY:			all asm corewar clean fclean re
