/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 05:00:32 by segan             #+#    #+#             */
/*   Updated: 2023/04/02 06:04:07 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**init_philo(t_rule rule, pthread_mutex_t **forks)
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
			return (free_philo(philo, rule.num_of_philos));
		philo[i]->i = i;
		philo[i]->rule = &rule;
		philo[i]->left_fork = 
		i++;
	}
	return (philo);
}

pthread_mutex_t	**init_mutex(int num_of_forks)
{
	pthread_mutex_t	**mutex;
	int				i;

	i = 0;
	mutex = (pthread_mutex_t **) \
	malloc(sizeof(pthread_mutex_t *) * (num_of_forks));
	if (mutex == NULL)
		return (mutex);
	while (i < num_of_forks)
	{
		mutex[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (mutex[i] == NULL)
			return (free_forks(mutex, num_of_forks));
		pthread_mutex_init(mutex[i++], NULL);
	}
	return (mutex);
}
