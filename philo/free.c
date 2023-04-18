/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 03:10:15 by segan             #+#    #+#             */
/*   Updated: 2023/04/18 18:34:31 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	**free_forks(pthread_mutex_t **forks, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		pthread_mutex_destroy(forks[i]);
		free(forks[i++]);
	}
	free(forks);
	return (NULL);
}

t_philo	**free_philo(t_philo **philo, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
		free(philo[i++]);
	free(philo);
	return (NULL);
}

pthread_mutex_t	*free_printer(pthread_mutex_t *printer)
{
	pthread_mutex_destroy(printer);
	free(printer);
	return (NULL);
}

int	free_forks_printer_philo(pthread_mutex_t **forks, pthread_mutex_t *printer, \
t_philo **philo, int philo_cnt)
{
	free_printer(printer);
	free_forks(forks, philo_cnt);
	free_philo(philo, philo_cnt);
	return (0);
}
