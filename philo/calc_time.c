/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:59:55 by segan             #+#    #+#             */
/*   Updated: 2023/04/05 17:03:29 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	calc_time(struct timeval old_time, struct timeval recent_time)
{
	return ((recent_time.tv_sec - old_time.tv_sec) * 1000000L + \
	(recent_time.tv_usec - old_time.tv_usec));
}
