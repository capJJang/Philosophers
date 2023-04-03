/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:44:51 by segan             #+#    #+#             */
/*   Updated: 2023/04/03 15:37:34 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*run_dining(void *philo)
{
	(void)philo;
	//while (philo->num_of_each_philo_eat--)
	//{
	//	eating(philo);
	//	thinking(philo);
	//	sleeping(philo);
	//}
	return (NULL);
}

void	enter_dining_room(t_philo **philo)
{
	int			i;
	const int	num_of_philos = philo[0]->rule->num_of_philos;
	bool		join;

	i = 0;
	if (philo[0]->rule->num_of_each_phil_eat == -1)
		join = true;
	else
		join = false;
	while (i < num_of_philos)
	{
		pthread_create(&philo[i]->thread, NULL, run_dining, philo[i]);
		if (join)
			pthread_join(philo[i]->thread, NULL);
		else
			pthread_detach(philo[i]->thread);
	}
}
