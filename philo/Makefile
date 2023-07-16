# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 18:52:19 by rchbouki          #+#    #+#              #
#    Updated: 2023/07/15 16:37:56 by rchbouki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = -I ./includes
OBJS = ${SRCS:.c=.o}
SRCS =	philo.c \
		init_philo.c \
		philo_life.c \
		philo_utils.c
NAME = philo

GREEN = "\033[1;32m"
EOC = "\033[0;0m"

.c.o :
	@${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	@echo $(GREEN)"     Compiling Riri's Philo..." $(EOC)
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all : ${NAME}

clean :
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re