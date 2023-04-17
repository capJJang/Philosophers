/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:23:46 by segan             #+#    #+#             */
/*   Updated: 2023/04/17 19:09:12 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	argv_validation(int argc, char *argv[], t_rule *rule)
{
	if (argc < 5 || argc > 6)
		return (print_err_invalid_arg());
	rule->num_of_philos = ft_atoi(argv[1]);
	rule->time_to_die = ft_atoi(argv[2]);
	rule->time_to_eat = ft_atoi(argv[3]);
	rule->time_to_sleep = ft_atoi(argv[4]);
	if (rule->num_of_philos <= 0 || rule->num_of_philos > 8191)
		return (print_err_invalid_arg());
	if (rule->time_to_die <= 0 || rule->time_to_eat <= 0 \
	|| rule->time_to_sleep <= 0)
		return (print_err_invalid_arg());
	rule->num_of_each_phil_eat = -1;
	if (argc == 6)
	{
		rule->num_of_each_phil_eat = ft_atoi(argv[5]);
		if (rule->num_of_each_phil_eat <= 0)
			return (print_err_invalid_arg());
	}
	return (1);
}

//how to check PTHREAD_THREAD_MAX?!
