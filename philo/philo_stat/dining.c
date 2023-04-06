/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:44:51 by segan             #+#    #+#             */
/*   Updated: 2023/04/06 15:53:25 by segan            ###   ########.fr       */
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

void	detect_philo_death(t_philo **philo, int num_of_philos)
{
	int	i;

	i = 0;
	while (1)
	{
		if (philo[i]->alive == false)
			break ;
		i++;
		if (i == num_of_philos)
			i = 0;
	}
}

void	detect_philo_eat_enough(t_philo **philo, int num_of_philos)
{
	int		i;
	int		j;
	bool	*eat_enough;

	eat_enough = (bool *)malloc(sizeof(bool) * num_of_philos);
	i = 0;
	memset(eat_enough, 0, num_of_philos);
	while (1)
	{
		if (philo[i]->num_of_each_philo_eat <= 0)
			eat_enough[i] = true;
		j = 0;
		while (j < num_of_philos)
		{
			if (eat_enough[j] ==
		}

	}
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
	if (philo[0]->rule->num_of_each_phil_eat > 0)
		detect_philo_eat_enough(philo, num_of_philos);
	else
		detect_philo_death(philo, num_of_philos);
}
