/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 05:00:32 by segan             #+#    #+#             */
/*   Updated: 2023/04/03 12:09:58 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*get_left_fork(pthread_mutex_t **forks, int i)
{
	return (forks[i]);
}

pthread_mutex_t	*get_right_fork(pthread_mutex_t **forks, int i, int cnt)
{
	if (i == cnt - 1)
		return (forks[0]);
	return (forks[i + 1]);
}

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
		philo[i]->num_of_each_philo_eat = rule.num_of_each_phil_eat;
		philo[i]->rule = &rule;
		philo[i]->left_fork = get_left_fork(forks, i);
		philo[i]->right_fork = get_right_fork(forks, i, rule.num_of_philos);
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
