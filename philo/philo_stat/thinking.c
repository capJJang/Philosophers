/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:49:03 by segan             #+#    #+#             */
/*   Updated: 2023/04/09 19:31:45 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	odd_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_philo_stat(philo, philo->whoami, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	print_philo_stat(philo, philo->whoami, "has taken a fork");
}

void	even_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_philo_stat(philo, philo->whoami, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_philo_stat(philo, philo->whoami, "has taken a fork");
}

int	am_i_alive(t_philo *philo)
{
	long long	elapsed_time;

	elapsed_time = calc_time(philo->last_eating);
	if (elapsed_time > philo->rule->time_to_die)
		return (0);
	return (1);
}

int	get_fork(t_philo *philo)
{
	if (philo->whoami % 2 == 0)
		even_philo(philo);
	else
		odd_philo(philo);
	return (am_i_alive(philo));
}

int	thinking(t_philo *philo)
{
	print_philo_stat(philo, philo->whoami, "thinking");
	if (get_fork(philo) == 0)
	{
		print_philo_stat(philo, philo->whoami, "died");
		return_fork(philo);
		philo->alive = false;
		return (0);
	}
	return (1);
}
