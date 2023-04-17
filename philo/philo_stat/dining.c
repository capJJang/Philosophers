/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:44:51 by segan             #+#    #+#             */
/*   Updated: 2023/04/17 20:11:50 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*run_dining(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	gettimeofday(&philo->dining_start, NULL);
	philo->last_eating = philo->dining_start;
	while (1)
	{
		if (philo->num_of_each_philo_eat == 0)
			break ;
		if (philo->alive == false)
			break ;
		if (thinking(philo) == 0)
			break ;
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}


void	enter_dining_room(t_philo **philo, int argc)
{
	int				i;
	const int		num_of_philos = philo[0]->rule->num_of_philos;

	i = 0;
	while (i < num_of_philos)
	{
		pthread_create(&philo[i]->thread, NULL, run_dining, philo[i]);
		pthread_detach(philo[i]->thread);
		i += 2;
	}
	i = 1;
	while (i < num_of_philos)
	{
		pthread_create(&philo[i]->thread, NULL, run_dining, philo[i]);
		pthread_detach(philo[i]->thread);
		i += 2;
	}
	if (argc == 6)
		detect_philo_eat_enough(philo, num_of_philos);
	else
		detect_philo_death(philo, num_of_philos);
}
