/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:10:51 by segan             #+#    #+#             */
/*   Updated: 2023/04/01 05:19:55 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>

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
	pthread_t	thread;
	t_rule		*rule;
	int			i;
}				t_philo;

int		argv_validation(int argc, char *argv[], t_rule *rule);
void	*init_mutex(int num_of_forks);
int		print_err_invalid_arg(void);
int		ft_atoi(char *s);

//init funcs start
t_philo	**init_philo(t_rule rule);
void	*init_mutex(int num_of_forks);
//init funcs end

//free funcs start
int		free_forks(pthread_mutex_t *forks, int num_of_philos);
t_philo	**free_philo(t_philo **philo, int num_of_philos);
int		free_forks_and_philo(pthread_mutex_t *forks, t_philo **philo, \
		int philo_cnt);
//free funcs end
#endif
