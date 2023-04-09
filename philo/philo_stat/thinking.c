/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:49:03 by segan             #+#    #+#             */
/*   Updated: 2023/04/08 21:29:29 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	thinking(t_philo *philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	print_philo_stat(philo, philo->whoami, "thinking");
	if (get_fork(philo) == -1)
	{
		return_fork(philo);
		philo->alive = false;
			return (-1);
	}
	return (1);
}
