# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segan <segan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 01:14:56 by segan             #+#    #+#              #
#    Updated: 2023/04/05 17:02:59 by segan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

CLIBS = -pthread

SRCS = main.c validation.c init.c ft_atoi.c calc_time.c\
		print/print_err.c print/print_philo.c\
		philo_stat/dining.c philo_stat/eating.c philo_stat/sleeping.c \
		philo_stat/thinking.c\
		free.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CLIBS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.Phony : all clean fclean re

