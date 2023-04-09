/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:44:51 by segan             #+#    #+#             */
/*   Updated: 2023/04/09 20:07:12 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*run_dining(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eating = philo->dining_start;
	while (1)
	{
		if (philo->num_of_each_philo_eat == 0)
			break ;
		if (thinking(philo) == 0)
			break ;
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}

void	kill_philo(t_philo **philo, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
		philo[i++]->alive = false;
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
	kill_philo(philo, num_of_philos);
}

void	detect_philo_eat_enough(t_philo **philo, int num_of_philos)
{
	int		i;
	int		j;
	bool	*eat_enough;
	bool	end_simul;

	eat_enough = (bool *)malloc(sizeof(bool) * num_of_philos);
	i = 0;
	memset(eat_enough, 0, num_of_philos);
	while (1)
	{
		end_simul = true;
		if (philo[i]->num_of_each_philo_eat <= 0)
			eat_enough[i] = true;
		j = 0;
		while (j < num_of_philos)
		{
			if (eat_enough[j] == false)
				end_simul = false;
		}
		if (end_simul == true)
			break ;
	}
	free(eat_enough);
	kill_philo(philo, num_of_philos);
}

void	enter_dining_room(t_philo **philo, int argc)
{
	int				i;
	const int		num_of_philos = philo[0]->rule->num_of_philos;

	i = 0;
	while (i < num_of_philos)
	{
		gettimeofday(&philo[i]->dining_start, NULL);
		pthread_create(&philo[i]->thread, NULL, run_dining, philo[i]);
		pthread_detach(philo[i++]->thread);
	}
	if (argc == 6)
		detect_philo_eat_enough(philo, num_of_philos);
	else
		detect_philo_death(philo, num_of_philos);
}
