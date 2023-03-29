/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:10:51 by segan             #+#    #+#             */
/*   Updated: 2023/03/30 00:32:51 by segan            ###   ########.fr       */
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
	t_rule		rule;
	int			i;
}				t_philo;

typedef struct s_table
{
}				t_table;

int		argv_validation(int argc, char *argv[], t_rule *rule);
void	*init_mutex(int num_of_forks);
int		print_err_invalid_arg(void);
int		ft_atoi(char *s);

#endif
