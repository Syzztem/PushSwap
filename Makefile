# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 14:45:40 by lothieve          #+#    #+#              #
#    Updated: 2021/12/02 16:21:40 by lothieve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_R =		push.c push_swap.c rotate.c rrotate.c solve.c solve_small.c stack_utils.c swap.c utils.c
SRC =		$(addprefix ${SRC_PATH}, ${SRC_R})
SRC_PATH =	src/
INC_PATH =	includes/
NAME =		push_swap
OBJS =		${SRC:.c=.o}

CC = clang
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

all:		${NAME}

${NAME}:	${OBJS}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all


.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INC_PATH}

.PHONY:		all clean fclean re
