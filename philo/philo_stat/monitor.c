/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:36:08 by segan             #+#    #+#             */
/*   Updated: 2023/04/18 23:57:26 by segan            ###   ########.fr       */
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

void	detect_philo_death(t_philo **philo, int num_of_philos)
{
	int		i;

	i = 0;
	while (1)
	{
		if (philo[i]->alive == false)
		{
			print_philo_stat(philo[i], philo[i]->whoami, "died");
			kill_philo(philo, philo[0]->rule->num_of_philos);
			break ;
		}
		i++;
		if (i == num_of_philos)
		{
			i = 0;
			usleep(10);
		}
	}
}

void	detect_philo_eat_enough(t_philo **philo, int num_of_philos)
{
	int		i;
	bool	end_simul;

	while (1)
	{
		end_simul = true;
		i = 0;
		while (i < num_of_philos)
		{
			if (philo[i]->im_full == false)
				end_simul = false;
			i++;
		}
		i = 0;
		if (end_simul == true || philo[0]->rule->someone_died == true)
		{
			print_philo_stat(philo[i], philo[i]->whoami, "died");
			kill_philo(philo, philo[0]->rule->num_of_philos);
			break ;
		}
		usleep(10);
	}
}
