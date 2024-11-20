# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 13:40:08 by flmarsou          #+#    #+#              #
#    Updated: 2024/11/20 13:16:47 by flmarsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE			=	philo

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
CFLAGS		=	-Wall -Werror -Wextra 
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

fclean:		clean
			@${RM} ${EXE}

re:			fclean all

.PHONY:		all clean fclean re
