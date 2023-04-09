# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segan <segan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 01:14:56 by segan             #+#    #+#              #
#    Updated: 2023/04/08 20:46:36 by segan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

CLIBS = -pthread

SRCS = main.c validation.c init.c ft_atoi.c calc_time.c\
		print/print_err.c print/print_philo.c\
		philo_stat/dining.c philo_stat/eating.c philo_stat/sleeping.c \
		philo_stat/thinking.c philo_stat/dying.c\
		free.c
OBJS = $(SRCS:.c=.o)

DEBUG = -g

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(DEBUG) $(CLIBS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(DEBUG) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.Phony : all clean fclean re

