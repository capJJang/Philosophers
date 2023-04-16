/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dying.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:34:20 by segan             #+#    #+#             */
/*   Updated: 2023/04/17 00:01:40 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	am_i_alive(t_philo *philo)
{
	long long		elapsed_time;
	int				alive;

	alive = 1;
	elapsed_time = calc_time(philo->last_eating);
	if (elapsed_time > philo->rule->time_to_die)
		alive = 0;
	return (alive);
}

int	dying(t_philo *philo)
{
	philo->alive = false;
	return_fork(philo);
	return (0);
}
