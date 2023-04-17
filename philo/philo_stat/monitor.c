/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:36:08 by segan             #+#    #+#             */
/*   Updated: 2023/04/17 20:57:03 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	kill_philo(t_philo **philo, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
		philo[i++]->alive = false;
}

//void	end_simul(t_philo **philo, int num_of_philos)
//{
//	int		i;
//	bool	end_simul;

//	i = 0;
//	end_simul = true;
//	while (1)
//	{
//		if (philo[i]->alive )
//	}

//}

void	detect_philo_death(t_philo **philo, int num_of_philos)
{
	int		i;

	i = 0;
	while (1)
	{
		if (philo[i]->alive == false)
		{
			kill_philo(philo, philo[0]->rule->num_of_philos);
			break ;
		}
		i++;
		if (i == num_of_philos)
		{
			i = 0;
			usleep(100);
		}
	}
}

void	detect_philo_eat_enough(t_philo **philo, int num_of_philos)
{
	int		i;
	bool	*eat_enough;
	bool	end_simul;

	eat_enough = (bool *)malloc(sizeof(bool) * num_of_philos);
	memset(eat_enough, 0, num_of_philos);
	while (1)
	{
		end_simul = true;
		i = 0;
		while (i < num_of_philos)
		{
			if (philo[i]->num_of_each_philo_eat <= 0)
				eat_enough[i++] = true;
		}
		i = 0;
		while (i < num_of_philos)
		{
			if (eat_enough[i++] == false)
				end_simul = false;
		}
		if (end_simul == true)
			return (free(eat_enough));
	}
}
