/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:44:51 by segan             #+#    #+#             */
/*   Updated: 2023/04/05 17:08:58 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*run_dining(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->num_of_each_philo_eat == 0)
			return (NULL);
		if (philo->whoami % 2 == 0)
		{
			eating(philo);
			thinking(philo);
		}
		else
		{
			thinking(philo);
			eating(philo);
		}
		sleeping(philo);
	}
	return (NULL);
}

void	enter_dining_room(t_philo **philo)
{
	struct timeval	init_time;
	int				i;
	const int		num_of_philos = philo[0]->rule->num_of_philos;

	i = 0;
	gettimeofday(&init_time, NULL);
	while (i < num_of_philos)
	{
		pthread_create(&philo[i]->thread, NULL, run_dining, philo[i]);
		pthread_detach(philo[i++]->thread);
	}
}
