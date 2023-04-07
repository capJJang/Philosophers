/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:38:15 by segan             #+#    #+#             */
/*   Updated: 2023/04/07 16:19:10 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_fork(t_philo *philo)
{
	struct timeval	end;
	struct timeval	start;
	long int		elapsed_time;

	if (philo->whoami % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	gettimeofday(&end, NULL);
	//if (elapsed_time > philo->rule->time_to_die)
	//	//print "has died"
	usleep(philo->rule->time_to_eat);
	return (0);
}

void	return_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eating(t_philo *philo)
{
	print_philo_stat(philo->rule->dining_start_time, philo->whoami, "eating");
	usleep(philo->rule->time_to_eat);
	return (return_fork(philo));
}
