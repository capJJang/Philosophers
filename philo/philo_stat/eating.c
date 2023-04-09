/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:38:15 by segan             #+#    #+#             */
/*   Updated: 2023/04/09 19:34:01 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	return_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eating(t_philo *philo)
{
	print_philo_stat(philo, philo->whoami, "is eating");
	usleep(philo->rule->time_to_eat * 1000);
	gettimeofday(&philo->last_eating, NULL);
	return (return_fork(philo));
}
