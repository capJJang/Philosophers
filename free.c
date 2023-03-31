/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 03:10:15 by segan             #+#    #+#             */
/*   Updated: 2023/04/01 04:37:34 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_forks(pthread_mutex_t *forks, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
		pthread_mutex_destroy(&forks[i++]);
	free(forks);
	return (0);
}

int	free_philo(t_philo **philo, int num_of_philos)
{
	int	i;

	i = 0;
	while (i++ < num_of_philos)
		free(philo[i]);
	free(philo);
	return (0);
}

int	free_forks_and_philo(pthread_mutex_t *forks, t_philo *philo, int philo_cnt)
{
	free_forks(forks, philo_cnt);
	free_philo(philo);
	return (0);
}
