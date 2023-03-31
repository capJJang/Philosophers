/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 05:00:32 by segan             #+#    #+#             */
/*   Updated: 2023/04/01 05:17:23 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**init_philo(t_rule rule)
{
	t_philo	**philo;
	int		i;

	i = 0;
	philo = (t_philo **)malloc(sizeof(t_philo *) * rule.num_of_philos);
	if (philo == NULL)
		return (philo);
	while (i < rule.num_of_philos)
	{
		philo[i] = (t_philo *)malloc(sizeof(t_philo) * rule.num_of_philos);
		if (philo[i] == NULL)
			return ((t_philo **)free_philo(philo, rule.num_of_philos));
		philo[i]->i = i;
		philo[i]->rule = &rule;
		i++;
	}
	return (philo);
}

void	*init_mutex(int num_of_forks)
{
	pthread_mutex_t	*mutex;
	int				i;

	i = 0;
	mutex = (pthread_mutex_t *) \
	malloc(sizeof(pthread_mutex_t) * (num_of_forks));
	if (mutex == NULL)
		return (mutex);
	while (i < num_of_forks)
		pthread_mutex_init((mutex + (sizeof(pthread_mutex_t) * i)), NULL);
	return (mutex);
}
