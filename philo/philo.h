/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:10:51 by segan             #+#    #+#             */
/*   Updated: 2023/04/18 22:22:51 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdbool.h>
# include <stdatomic.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_rule
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_each_phil_eat;
	atomic_bool		someone_died;
}				t_rule;

typedef struct s_philo
{
	pthread_t		thread;
	t_rule			*rule;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*printer;
	struct timeval	last_eating;
	struct timeval	dining_start;
	atomic_bool		alive;
	atomic_int		num_of_each_philo_eat;
	atomic_bool		im_full;
	int				whoami;
}				t_philo;

//validation funcs start
int				argv_validation(int argc, char *argv[], t_rule *rule);
int				print_err_invalid_arg(void);
//validation funcs end

int				ft_atoi(char *s);
long long		calc_time(struct timeval based_time);
long long		calc_time2(struct timeval past, struct timeval present);

//print util funcs start
void			print_rule(t_rule rule);
void			print_philo_stat(t_philo *philo, int whoami, char *stat);
void			print_simul_end(pthread_mutex_t *printer);
//print util funcs end

//init funcs start
t_philo			**init_philo(t_rule rule, pthread_mutex_t **forks, \
							pthread_mutex_t *printer);
pthread_mutex_t	**init_mutex(int num_of_forks);
pthread_mutex_t	*init_printer(void);
pthread_mutex_t	*get_right_fork(pthread_mutex_t **forks, int i, int cnt);
pthread_mutex_t	*get_left_fork(pthread_mutex_t **forks, int i);
//init funcs end

//free funcs start
pthread_mutex_t	**free_forks(pthread_mutex_t **forks, int num_of_philos);
t_philo			**free_philo(t_philo **philo, int num_of_philos);
int				free_forks_printer_philo(pthread_mutex_t **forks, \
				pthread_mutex_t *printer, t_philo **philo, int philo_cnt);
//free funcs end

//philo_stat funcs start;
void			*run_dining(void *arg);
void			enter_dining_room(t_philo **philo, int argc);
int				get_fork(t_philo *philo);
void			return_fork(t_philo *philo);
void			detect_philo_eat_enough(t_philo **philo, int num_of_philos);
void			detect_philo_death(t_philo **philo, int num_of_philos);
void			eating(t_philo *philo);
int				thinking(t_philo *philo);
void			sleeping(t_philo *philo);
int				am_i_alive(t_philo *philo);
//philo_stat funcs end;
#endif
