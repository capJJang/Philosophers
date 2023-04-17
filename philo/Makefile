# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segan <segan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 01:14:56 by segan             #+#    #+#              #
#    Updated: 2023/04/17 21:43:03 by segan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

CLIBS = -pthread

SRCS = main.c validation.c init.c ft_atoi.c calc_time.c\
		print/print_err.c print/print_philo.c print/print_simul_end.c\
		philo_stat/dining.c philo_stat/eating.c philo_stat/sleeping.c \
		philo_stat/thinking.c philo_stat/dying.c philo_stat/monitor.c\
		free.c
OBJS = $(SRCS:.c=.o)

DEBUG = -g -fsanitize=thread

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(DEBUG) $(CLIBS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(DEBUG) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -rf *.dSYM
	rm -f $(NAME)

re :
	make fclean
	make all

.Phony : all clean fclean re

