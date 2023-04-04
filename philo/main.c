/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:20:11 by segan             #+#    #+#             */
/*   Updated: 2023/04/04 13:15:43 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_rule			rule;
	pthread_mutex_t	**forks;
	t_philo			**philo;

	if (!argv_validation(argc, argv, &rule))
		return (0);
	//print_rule(rule);
	forks = init_mutex(rule.num_of_philos);
	if (forks == NULL)
		return (0);
	philo = init_philo(rule, forks);
	if (philo == NULL)
		return (free_forks_and_philo(forks, philo, rule.num_of_philos));
	enter_dining_room(philo);
	//free_forks_and_philo(forks, philo, rule.num_of_philos);
}
