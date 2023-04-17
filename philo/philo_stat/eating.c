/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:38:15 by segan             #+#    #+#             */
/*   Updated: 2023/04/17 19:25:30 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	return_fork(t_philo *philo)
{
	if (philo->whoami % 2 == 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

void	eating(t_philo *philo)
{
	gettimeofday(&philo->last_eating, NULL);
	print_philo_stat(philo, philo->whoami, "is eating");
	usleep(philo->rule->time_to_eat * 1000);
	philo->num_of_each_philo_eat--;
	return (return_fork(philo));
}
