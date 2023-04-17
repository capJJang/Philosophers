/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:49:03 by segan             #+#    #+#             */
/*   Updated: 2023/04/17 21:32:52 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	am_i_alive(t_philo *philo)
{
	long long	elapsed_time;

	if (philo->alive == false)
	{
		return (0);
	}
	elapsed_time = calc_time(philo->last_eating);
	if (elapsed_time > philo->rule->time_to_die)
	{
		philo->alive = false;
		return (0);
	}
	return (1);
}

void	odd_philo_get_fork(t_philo *philo)
{
	if (am_i_alive(philo) == 0)
		return ;
	pthread_mutex_lock(philo->left_fork);
	if (am_i_alive(philo) == 0)
		return ;
	print_philo_stat(philo, philo->whoami, "has taken a fork");
	if (am_i_alive(philo) == 0)
		return ;
	pthread_mutex_lock(philo->right_fork);
	if (am_i_alive(philo) == 0)
		return ;
	print_philo_stat(philo, philo->whoami, "has taken a fork");
	if (am_i_alive(philo) == 0)
		return ;
}

void	even_philo_get_fork(t_philo *philo)
{
	if (am_i_alive(philo) == 0)
		return ;
	pthread_mutex_lock(philo->right_fork);
	if (am_i_alive(philo) == 0)
		return ;
	print_philo_stat(philo, philo->whoami, "has taken a fork");
	if (philo->rule->num_of_philos == 1)
		philo->alive = false;
	if (am_i_alive(philo) == 0)
		return ;
	pthread_mutex_lock(philo->left_fork);
	if (am_i_alive(philo) == 0)
		return ;
	print_philo_stat(philo, philo->whoami, "has taken a fork");
	if (am_i_alive(philo) == 0)
		return ;
}

int	get_fork(t_philo *philo)
{
	if (philo->whoami % 2 == 0)
		even_philo_get_fork(philo);
	else
		odd_philo_get_fork(philo);
	return (am_i_alive(philo));
}

int	thinking(t_philo *philo)
{
	print_philo_stat(philo, philo->whoami, "thinking");
	if (get_fork(philo) == 0 || philo->alive == false)
	{
		philo->alive = false;
		print_philo_stat(philo, philo->whoami, "died");
		return_fork(philo);
		return (0);
	}
	return (1);
}
