/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:46:47 by segan             #+#    #+#             */
/*   Updated: 2023/04/08 14:26:38 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	sleeping(t_philo *philo)
{
	print_philo_stat(philo, philo->whoami, "sleeping");
	usleep(philo->rule->time_to_sleep);
}
