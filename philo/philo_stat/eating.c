/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:38:15 by segan             #+#    #+#             */
/*   Updated: 2023/04/05 17:06:44 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_fork(t_philo *philo)
{
	struct timeval	end;
	struct timeval	start;
	long int		elapsed_time;

	start = philo->last_stat;
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	gettimeofday(&end, NULL);
	//print "has taken fork"
	elapsed_time = calc_time(end, philo->last_stat);
	if (elapsed_time > philo->rule->time_to_die)
		//print "has died"
	//print "eating"
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
	if (get_fork(philo) == -1)
		return (return_fork(philo));
	//print "eating"
	usleep(philo->rule->time_to_eat);
	return (return_fork(philo));
}
