# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 13:40:08 by flmarsou          #+#    #+#              #
#    Updated: 2024/11/22 11:18:54 by flmarsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE			=	philo
ARG			=	""

# Files
SRC			=	./src/main.c \
				./src/parser.c \

SRC_UTILS	=	./src/utils/ft_atou.c \
				./src/utils/ft_gettime.c \

SRC_THREADS	=	./src/routines/routine_monitor.c \
				./src/routines/routine.c \
				./src/routines/ft_eat.c \
				./src/routines/ft_sleep.c \
				./src/routines/rest.c \
				./src/routines/printer.c \

SOURCES		=	${SRC} ${SRC_UTILS} ${SRC_THREADS}
OBJECTS		=	${SOURCES:%.c=obj/%.o}

# Variables
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g
RM			=	rm -rf

# Makefile
all:		${EXE}

${EXE}:		${OBJECTS}
			@${CC} ${CFLAGS} ${OBJECTS} -o ${EXE}

obj/%.o:	%.c
			@mkdir -p obj/$(dir $<)
			@${CC} ${CFLAGS} -c $< -o $@

clean:
			@${RM} obj
			@${RM} ${EXE}.log

fclean:		clean
			@${RM} ${EXE}

re:			fclean all

log:		re
			@./${EXE} ${ARG} > ${EXE}.log \
			&& echo "\e[32m➜  Success\e[0m: Check ${EXE}.log" \
			|| echo "\e[31m➜  Error\e[0m: Wrong Arguments!"

.PHONY:		all clean fclean re
