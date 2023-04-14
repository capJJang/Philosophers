/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:49:03 by segan             #+#    #+#             */
/*   Updated: 2023/04/14 17:38:48 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	odd_philo_get_fork(t_philo *philo)
{
	usleep(10);
	pthread_mutex_lock(philo->left_fork);
	print_philo_stat(philo, philo->whoami, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_philo_stat(philo, philo->whoami, "has taken a fork");
	return (1);
}

int	even_philo_get_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_philo_stat(philo, philo->whoami, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	print_philo_stat(philo, philo->whoami, "has taken a fork");
	return (1);
}

int	get_fork(t_philo *philo)
{
	if (philo->whoami % 2 == 0)
		return (even_philo_get_fork(philo));
	else
		return (odd_philo_get_fork(philo));
}

int	thinking(t_philo *philo)
{
	print_philo_stat(philo, philo->whoami, "thinking");
	if (get_fork(philo) == 0)
		return (dying(philo));
	return (1);
}
