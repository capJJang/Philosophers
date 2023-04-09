/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:38:15 by segan             #+#    #+#             */
/*   Updated: 2023/04/09 13:34:30 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_fork(t_philo *philo)
{
	struct timeval	finished_thinking;
	// struct timeval	start;
	long int		elapsed_time;

	if (philo->whoami % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_philo_stat(philo, philo->whoami, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_philo_stat(philo, philo->whoami, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_philo_stat(philo, philo->whoami, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_philo_stat(philo, philo->whoami, "has taken a fork");
	}
	gettimeofday(&finished_thinking, NULL);
	elapsed_time = calc_time()
	if (elapsed_time > philo->rule->time_to_die)
		//print "has died"
	return (0);
}

void	return_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eating(t_philo *philo)
{
	print_philo_stat(philo, philo->whoami, "eating");
	usleep(philo->rule->time_to_eat);
	return (return_fork(philo));
}
