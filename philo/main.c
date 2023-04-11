/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:20:11 by segan             #+#    #+#             */
/*   Updated: 2023/04/11 18:19:04 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_rule			rule;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*printer;
	t_philo			**philo;

	if (!argv_validation(argc, argv, &rule))
		return (0);
	forks = init_mutex(rule.num_of_philos);
	if (forks == NULL)
		return (0);
	printer = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(printer, NULL);
	if (printer == NULL)
		return ((int) free_forks(forks, rule.num_of_philos));
	philo = init_philo(rule, forks, printer);
	if (philo == NULL)
		return (free_forks_and_philo(forks, philo, rule.num_of_philos));
	enter_dining_room(philo, argc);
	free_forks_and_philo(forks, philo, rule.num_of_philos);
}
