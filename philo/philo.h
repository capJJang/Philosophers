/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:10:51 by segan             #+#    #+#             */
/*   Updated: 2023/04/03 15:36:15 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <printf.h>

typedef struct s_rule
{
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_each_phil_eat;
}				t_rule;

typedef struct s_philo
{
	pthread_t		thread;
	t_rule			*rule;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				num_of_each_philo_eat;
}				t_philo;

int				argv_validation(int argc, char *argv[], t_rule *rule);
int				print_err_invalid_arg(void);
int				ft_atoi(char *s);

//init funcs start
t_philo			**init_philo(t_rule rule, pthread_mutex_t **forks);
pthread_mutex_t	**init_mutex(int num_of_forks);
pthread_mutex_t	*get_right_fork(pthread_mutex_t **forks, int i, int cnt);
pthread_mutex_t	*get_left_fork(pthread_mutex_t **forks, int i);
//init funcs end

//free funcs start
pthread_mutex_t	**free_forks(pthread_mutex_t **forks, int num_of_philos);
t_philo			**free_philo(t_philo **philo, int num_of_philos);
int				free_forks_and_philo(pthread_mutex_t **forks, \
				t_philo **philo, int philo_cnt);
//free funcs end

//
void	enter_dining_room(t_philo **philo);
//
#endif
