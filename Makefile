# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 13:40:08 by flmarsou          #+#    #+#              #
#    Updated: 2024/09/10 15:44:47 by flmarsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE			=	philo

# Files
SRC			=	./src/main.c \

SRC_UTILS	=	./src/utils/ft_atou.c \
				./src/utils/ft_atolu.c \

SRC_PARSER	=	./src/parser/parser.c \

SOURCES		=	${SRC}
OBJECTS		=	${SOURCES:%.c=obj/%.o}

# Variables
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g
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
